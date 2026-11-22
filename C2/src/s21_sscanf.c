#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif
#include "s21_sscanf.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <wchar.h>

#include "s21_string.h"

static bool read_spec(const char **format, s21_scan_spec *spec) {
  const char *p = *format;
  size_t number = s21_read_decimal(&p);
  if (*p == '$') {
    if (!number || number > NL_ARGMAX) return false;
    spec->position = number;
    ++p;
  } else {
    p = *format;
  }
  if (*p == '*') {
    spec->suppress = true;
    ++p;
  }
  spec->width = s21_read_decimal(&p);
  if (*p == 'm') {
    spec->allocate = true;
    ++p;
  }
  spec->length = s21_read_length(&p);
  if (!*p || !s21_strchr("cCsS[diuoxXpaAeEfFgGn%", *p)) return false;
  spec->conversion = *p++;
  if (spec->conversion == 'C' || spec->conversion == 'S') {
    spec->conversion = spec->conversion == 'C' ? 'c' : 's';
    spec->length = S21_LONG;
  }
  if (spec->allocate && !s21_strchr("cs[", spec->conversion)) return false;
  if (!spec->width) spec->width = spec->conversion == 'c' ? 1 : SIZE_MAX;
  if (spec->conversion == '[') {
    spec->inverted = *p == '^';
    if (spec->inverted) ++p;
    spec->set = p;
    if (*p == ']') ++p;
    while (*p && *p != ']') ++p;
    if (!*p) return false;
    spec->set_end = p++;
  }
  *format = p;
  return true;
}

static bool in_scanset(s21_scan_spec spec, unsigned char c) {
  const char *p = spec.set;
  unsigned char previous = 0;
  while (p < spec.set_end) {
    unsigned char current = (unsigned char)*p++;
    if (current == '-' && previous && p < spec.set_end) {
      current = (unsigned char)*p++;
      if ((previous <= c && c <= current) || (previous > current && c == '-'))
        return !spec.inverted;
    }
    if (current == c) return !spec.inverted;
    previous = current;
  }
  return spec.inverted;
}

static s21_scan_status store_text(const char *src, size_t count,
                                  s21_scan_spec spec, va_list *args) {
  bool wide = spec.length == S21_LONG;
  bool terminate = spec.conversion != 'c';
  void *buffer = NULL;
  if (spec.allocate) {
    size_t unit = wide ? sizeof(wchar_t) : sizeof(char);
    if (count <= SIZE_MAX / unit - (size_t)terminate)
      buffer = malloc((count + terminate) * unit);
    if (!buffer) {
      errno = ENOMEM;
      return S21_SCAN_INPUT_FAILURE;
    }
  }
  if (wide) {
    wchar_t *dest = spec.allocate ? buffer : va_arg(*args, wchar_t *);
    mbstate_t initial = {0};
    mbsrtowcs(dest, &src, count, &initial);
    if (terminate) dest[count] = L'\0';
    if (spec.allocate) *va_arg(*args, wchar_t **) = dest;
  } else {
    char *dest = spec.allocate ? buffer : va_arg(*args, char *);
    s21_memcpy(dest, src, count);
    if (terminate) dest[count] = '\0';
    if (spec.allocate) *va_arg(*args, char **) = dest;
  }
  return S21_SCAN_OK;
}

static s21_scan_status scan_text(const char **input, s21_scan_spec spec,
                                 va_list *args) {
  const char *p = *input;
  bool wide = spec.length == S21_LONG;
  mbstate_t state = {0};
  size_t count = 0, decoded = 0;
  // Match input bytes. A wide field's width counts complete characters.
  while (count < spec.width && *p) {
    unsigned char c = (unsigned char)*p;
    if (spec.conversion == 's' && isspace(c)) break;
    if (spec.conversion == '[' && !in_scanset(spec, c)) break;
    decoded = wide ? mbrtowc(NULL, p, 1, &state) : 1;
    if (decoded == (size_t)-1) break;
    ++p;
    if (decoded != (size_t)-2) ++count;
  }
  if (decoded == (size_t)-1 || decoded == (size_t)-2) {
    errno = EILSEQ;
    return S21_SCAN_INPUT_FAILURE;
  }
  if (!count || (spec.conversion == 'c' && count != spec.width))
    return S21_SCAN_MISMATCH;
  s21_scan_status status = S21_SCAN_OK;
  if (!spec.suppress) status = store_text(*input, count, spec, args);
  if (status == S21_SCAN_OK) *input = p;
  return status;
}

static s21_scan_status match_literal(const char **input, char literal) {
  if (!**input) return S21_SCAN_INPUT_FAILURE;
  if (**input != literal) return S21_SCAN_MISMATCH;
  ++*input;
  return S21_SCAN_OK;
}

static s21_scan_status scan_conversion(const char **input, const char *start,
                                       s21_scan_spec spec, va_list *args) {
  char c = spec.conversion;
  if (c == 'n') {
    if (!spec.suppress) s21_store_signed(args, spec.length, *input - start);
    return S21_SCAN_OK;
  }
  if (c != 'c' && c != '[')
    while (isspace((unsigned char)**input)) ++*input;
  if (!**input) return S21_SCAN_INPUT_FAILURE;
  if (c == '%') return match_literal(input, '%');
  if (c == 's' || c == 'c' || c == '[') return scan_text(input, spec, args);
  if (s21_strchr("aAeEfFgG", c)) return s21_scan_float(input, spec, args);
  return s21_scan_integer(input, spec, args);
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list first, args;
  va_start(first, format);
  va_copy(args, first);
  size_t next = 1;
  const char *input = str;
  int assigned = 0;
  bool converted = false;
  s21_scan_status status = S21_SCAN_OK;
  while (status == S21_SCAN_OK && *format) {
    if (isspace((unsigned char)*format)) {
      do ++format;
      while (isspace((unsigned char)*format));
      while (isspace((unsigned char)*input)) ++input;
    } else if (*format != '%') {
      status = match_literal(&input, *format++);
    } else {
      ++format;
      s21_scan_spec spec = {0};
      if (!read_spec(&format, &spec)) break;
      bool takes_argument = !spec.suppress && spec.conversion != '%';
      if (takes_argument && spec.position) {
        if (spec.position < next) {
          va_end(args);
          va_copy(args, first);
          next = 1;
        }
        // XSI permits consuming skipped pointer arguments as void *.
        while (next < spec.position) {
          (void)va_arg(args, void *);
          ++next;
        }
      }
      status = scan_conversion(&input, str, spec, &args);
      if (status == S21_SCAN_OK && spec.conversion != '%') {
        converted = true;
        if (!spec.suppress) {
          ++next;
          if (spec.conversion != 'n') ++assigned;
        }
      }
    }
  }
  va_end(args);
  va_end(first);
  return status == S21_SCAN_INPUT_FAILURE && !converted ? EOF : assigned;
}
