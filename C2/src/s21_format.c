#include "s21_format.h"

size_t s21_read_decimal(const char **format) {
  size_t number = 0;
  while (**format >= '0' && **format <= '9') {
    unsigned digit = (unsigned)(*(*format)++ - '0');
    number = number > (SIZE_MAX - digit) / 10 ? SIZE_MAX : number * 10 + digit;
  }
  return number;
}

s21_length s21_read_length(const char **format) {
  const char *p = *format;
  s21_length length = S21_INT;
  switch (*p) {
    case 'h':
      length = *++p == 'h' ? S21_CHAR : S21_SHORT;
      if (length == S21_CHAR) ++p;
      break;
    case 'l':
      length = *++p == 'l' ? S21_LLONG : S21_LONG;
      if (length == S21_LLONG) ++p;
      break;
    case 'L':
      length = S21_LDOUBLE;
      ++p;
      break;
    case 'j':
      length = S21_INTMAX;
      ++p;
      break;
    case 'z':
      length = _Generic((size_t)0,
          unsigned char: S21_CHAR,
          unsigned short: S21_SHORT,
          unsigned int: S21_INT,
          unsigned long: S21_LONG,
          unsigned long long: S21_LLONG);
      ++p;
      break;
    case 't':
      length = _Generic((ptrdiff_t)0,
          signed char: S21_CHAR,
          short: S21_SHORT,
          int: S21_INT,
          long: S21_LONG,
          long long: S21_LLONG);
      ++p;
      break;
    default:
      break;
  }
  *format = p;
  return length;
}

void s21_store_signed(va_list *args, s21_length length, intmax_t value) {
  switch (length) {
    case S21_CHAR:
      *va_arg(*args, signed char *) = (signed char)value;
      break;
    case S21_SHORT:
      *va_arg(*args, short *) = (short)value;
      break;
    case S21_LONG:
      *va_arg(*args, long *) = (long)value;
      break;
    case S21_LLONG:
      *va_arg(*args, long long *) = (long long)value;
      break;
    case S21_INTMAX:
      *va_arg(*args, intmax_t *) = value;
      break;
    default:
      *va_arg(*args, int *) = (int)value;
      break;
  }
}
