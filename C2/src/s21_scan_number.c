#include <ctype.h>
#include <locale.h>
#include <stdlib.h>

#include "s21_sscanf.h"
#include "s21_string.h"

static unsigned digit_value(char c) {
  if (c >= '0' && c <= '9') return (unsigned)(c - '0');
  if (c >= 'a' && c <= 'f') return (unsigned)(c - 'a') + 10;
  if (c >= 'A' && c <= 'F') return (unsigned)(c - 'A') + 10;
  return 16;
}

static void store_unsigned(va_list *args, s21_length length, uintmax_t value) {
  switch (length) {
    case S21_CHAR:
      *va_arg(*args, unsigned char *) = (unsigned char)value;
      break;
    case S21_SHORT:
      *va_arg(*args, unsigned short *) = (unsigned short)value;
      break;
    case S21_LONG:
      *va_arg(*args, unsigned long *) = (unsigned long)value;
      break;
    case S21_LLONG:
      *va_arg(*args, unsigned long long *) = (unsigned long long)value;
      break;
    case S21_INTMAX:
      *va_arg(*args, uintmax_t *) = value;
      break;
    default:
      *va_arg(*args, unsigned int *) = (unsigned int)value;
      break;
  }
}

static bool word_at(const char *p, size_t width, const char *word) {
  while (*word && width && tolower((unsigned char)*p) == *word) {
    ++p;
    ++word;
    --width;
  }
  return !*word;
}

s21_scan_status s21_scan_integer(const char **input, s21_scan_spec spec,
                                 va_list *args) {
  const char *p = *input;
  const char c = spec.conversion;
  if (c == 'p' && word_at(p, spec.width, "(nil)")) {
    if (!spec.suppress) *va_arg(*args, void **) = NULL;
    *input += 5;
    return S21_SCAN_OK;
  }
  bool negative = *p == '-';
  size_t i = negative || *p == '+';
  unsigned base = s21_strchr("xXp", c) ? 16 : (c == 'o' ? 8 : 10);
  if (i < spec.width && p[i] == '0') {
    if (c == 'i') base = 8;
    if ((base == 16 || c == 'i') && i + 1 < spec.width &&
        (p[i + 1] == 'x' || p[i + 1] == 'X')) {
      i += 2;
      base = 16;
    }
  }
  size_t first = i;
  uintmax_t value = 0;
  while (i < spec.width && digit_value(p[i]) < base) {
    unsigned digit = digit_value(p[i++]);
    value = value > (UINTMAX_MAX - digit) / base ? UINTMAX_MAX
                                                 : value * base + digit;
  }
  if (i == first) return S21_SCAN_MISMATCH;
  if (!spec.suppress) {
    if (c == 'd' || c == 'i') {
      intmax_t result;
      if (value > INTMAX_MAX)
        result = negative ? INTMAX_MIN : INTMAX_MAX;
      else
        result = negative ? -(intmax_t)value : (intmax_t)value;
      s21_store_signed(args, spec.length, result);
    } else if (c == 'p') {
      *va_arg(*args, void **) = (void *)(uintptr_t)value;
    } else {
      store_unsigned(args, spec.length, negative ? 0 - value : value);
    }
  }
  *input += i;
  return S21_SCAN_OK;
}

static size_t special_float(const char *p, size_t width) {
  if (word_at(p, width, "inf")) {
    if (width > 3 && tolower((unsigned char)p[3]) == 'i')
      return word_at(p, width, "infinity") ? 8 : 0;
    return 3;
  }
  if (!word_at(p, width, "nan")) return 0;
  size_t i = 3;
  if (i < width && p[i] == '(') {
    ++i;
    while (i < width && (isalnum((unsigned char)p[i]) || p[i] == '_')) ++i;
    if (i == width || p[i] != ')') return 0;
    ++i;
  }
  return i;
}

static size_t float_token(const char *p, size_t width) {
  size_t i = *p == '+' || *p == '-';
  if (i == width) return 0;
  if (isalpha((unsigned char)p[i])) {
    size_t n = special_float(p + i, width - i);
    return n ? i + n : 0;
  }

  bool hex =
      width - i >= 2 && p[i] == '0' && (p[i + 1] == 'x' || p[i + 1] == 'X');
  if (hex) i += 2;
  unsigned base = hex ? 16 : 10;
  size_t first = i;
  while (i < width && digit_value(p[i]) < base) ++i;
  bool has_digits = i != first;
  const char *point = localeconv()->decimal_point;
  size_t point_size = s21_strlen(point);
  if (point_size <= width - i && !s21_strncmp(p + i, point, point_size)) {
    i += point_size;
    first = i;
    while (i < width && digit_value(p[i]) < base) ++i;
    has_digits = has_digits || i != first;
  }
  if (!has_digits) return 0;
  if (i < width && tolower((unsigned char)p[i]) == (hex ? 'p' : 'e')) {
    ++i;
    if (i < width && (p[i] == '+' || p[i] == '-')) ++i;
    first = i;
    while (i < width && digit_value(p[i]) < 10) ++i;
    if (first == i) return 0;
  }
  return i;
}

s21_scan_status s21_scan_float(const char **input, s21_scan_spec spec,
                               va_list *args) {
  const char *p = *input;
  size_t n = float_token(p, spec.width);
  if (!n) return S21_SCAN_MISMATCH;
  if (!spec.suppress) {
    char local[128], *allocated = NULL;
    // strto* needs a terminator only when the field width cuts the token.
    if (n == spec.width && p[n]) {
      char *field = local;
      if (n >= sizeof(local)) {
        allocated = malloc(n + 1);
        if (!allocated) return S21_SCAN_INPUT_FAILURE;
        field = allocated;
      }
      s21_memcpy(field, p, n);
      field[n] = '\0';
      p = field;
    }
    if (spec.length == S21_LDOUBLE)
      *va_arg(*args, long double *) = strtold(p, NULL);
    else if (spec.length == S21_LONG)
      *va_arg(*args, double *) = strtod(p, NULL);
    else
      *va_arg(*args, float *) = strtof(p, NULL);
    free(allocated);
  }
  *input += n;
  return S21_SCAN_OK;
}
