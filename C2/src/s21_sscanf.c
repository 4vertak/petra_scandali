#include "s21_sscanf.h"

#include <ctype.h>
#include <limits.h>
#include <wchar.h>
#include <wctype.h>

#include "s21_string.h"

static bool read_spec(const char **format, s21_scan_spec *spec) {
  const char *p = *format;
  if (*p == '*') {
    spec->suppress = true;
    ++p;
  }
  spec->width = s21_read_decimal(&p);
  spec->length = s21_read_length(&p);
  if (!*p || !s21_strchr("cdiuoxXpaAeEfFgGsn%[", *p)) return false;
  spec->conversion = *p++;
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

static wchar_t set_character(const char **position, const char *end, bool wide,
                             mbstate_t *state) {
  wchar_t c = (unsigned char)**position;
  size_t n = 1;
  if (wide) {
    n = mbrtowc(&c, *position, (size_t)(end - *position), state);
    if (n == (size_t)-1 || n == (size_t)-2) {
      *position = end;
      return WEOF;
    }
  }
  *position += n;
  return c;
}

static bool in_scanset(s21_scan_spec spec, wchar_t c) {
  const char *p = spec.set;
  bool wide = spec.length == S21_LONG;
  mbstate_t state = {0};
  wchar_t previous = 0;
  while (p < spec.set_end) {
    wchar_t current = set_character(&p, spec.set_end, wide, &state);
    if (current == L'-' && previous && p < spec.set_end) {
      current = set_character(&p, spec.set_end, wide, &state);
      if ((previous <= c && c <= current) || (previous > current && c == L'-'))
        return !spec.inverted;
    }
    if (current == c) return !spec.inverted;
    previous = current;
  }
  return spec.inverted;
}

static s21_scan_status scan_text(const char **input, s21_scan_spec spec,
                                 va_list *args) {
  const char *p = *input;
  bool wide = spec.length == S21_LONG;
  mbstate_t state = {0};
  size_t count = 0;
  while (count < spec.width && *p) {
    wchar_t c = (unsigned char)*p;
    size_t bytes = 1;
    if (wide) {
      bytes = mbrtowc(&c, p, MB_CUR_MAX, &state);
      if (bytes == (size_t)-1 || bytes == (size_t)-2)
        return S21_SCAN_INPUT_FAILURE;
    }
    if (spec.conversion == 's' &&
        (wide ? iswspace(c) : isspace((unsigned char)c)))
      break;
    if (spec.conversion == '[' && !in_scanset(spec, c)) break;
    p += bytes;
    ++count;
  }
  if (!count || (spec.conversion == 'c' && count != spec.width))
    return S21_SCAN_MISMATCH;
  if (!spec.suppress) {
    if (wide) {
      wchar_t *dest = va_arg(*args, wchar_t *);
      const char *src = *input;
      mbstate_t initial = {0};
      mbsrtowcs(dest, &src, count, &initial);
      if (spec.conversion != 'c') dest[count] = L'\0';
    } else {
      char *dest = va_arg(*args, char *);
      s21_memcpy(dest, *input, count);
      if (spec.conversion != 'c') dest[count] = '\0';
    }
  }
  *input = p;
  return S21_SCAN_OK;
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
  va_list args;
  va_start(args, format);
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
      status = scan_conversion(&input, str, spec, &args);
      if (status == S21_SCAN_OK) {
        converted = true;
        if (!spec.suppress && spec.conversion != 'n' && spec.conversion != '%')
          ++assigned;
      }
    }
  }
  va_end(args);
  return status == S21_SCAN_INPUT_FAILURE && !converted ? EOF : assigned;
}
