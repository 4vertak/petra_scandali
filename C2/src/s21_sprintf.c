#include "s21_sprintf.h"

#include <errno.h>
#include <limits.h>
#include <wchar.h>

#include "s21_string.h"

static bool read_spec(const char **format, va_list *args,
                      s21_print_spec *spec) {
  const char *p = *format;
  while (*p && s21_strchr("-+ #0", *p)) {
    switch (*p++) {
      case '-':
        spec->left = true;
        break;
      case '+':
        spec->plus = true;
        break;
      case ' ':
        spec->space = true;
        break;
      case '#':
        spec->alternate = true;
        break;
      case '0':
        spec->zero = true;
        break;
    }
  }
  size_t width;
  if (*p == '*') {
    ++p;
    int argument = va_arg(*args, int);
    if (argument < 0) spec->left = true;
    width = argument < 0 ? 0U - (unsigned)argument : (unsigned)argument;
  } else {
    width = s21_read_decimal(&p);
  }
  size_t precision = 0;
  if (*p == '.') {
    if (*++p == '*') {
      ++p;
      spec->precision = va_arg(*args, int);
    } else {
      precision = s21_read_decimal(&p);
      if (precision <= INT_MAX) spec->precision = (int)precision;
    }
  }
  if (width > INT_MAX || precision > INT_MAX) {
    errno = EOVERFLOW;
    return false;
  }
  spec->width = (int)width;
  spec->length = s21_read_length(&p);
  if (!*p || !s21_strchr("cdiuoxXfeEgGFspn%", *p)) {
    errno = EINVAL;
    return false;
  }
  spec->conversion = *p++;
  *format = p;
  return true;
}

int s21_print_field(char *out, int room, s21_print_spec spec,
                    const char *prefix, size_t payload_length, char **payload) {
  size_t prefix_length = s21_strlen(prefix);
  if (payload_length > (size_t)room || prefix_length > room - payload_length ||
      spec.width > room) {
    errno = EOVERFLOW;
    return -1;
  }
  int length = (int)(prefix_length + payload_length);
  int pad = spec.width > length ? spec.width - length : 0;
  if (!spec.left && !spec.zero) {
    s21_memset(out, ' ', pad);
    out += pad;
  }
  s21_memcpy(out, prefix, prefix_length);
  out += prefix_length;
  if (!spec.left && spec.zero) {
    s21_memset(out, '0', pad);
    out += pad;
  }
  *payload = out;
  if (spec.left) s21_memset(out + payload_length, ' ', pad);
  return length + pad;
}

const char *s21_print_sign(s21_print_spec spec, bool negative) {
  if (negative) return "-";
  if (spec.plus) return "+";
  return spec.space ? " " : "";
}

char *s21_uint_digits(char *end, uintmax_t value, unsigned base, bool upper) {
  const char *alphabet = upper ? "0123456789ABCDEF" : "0123456789abcdef";
  do {
    *--end = alphabet[value % base];
    value /= base;
  } while (value);
  return end;
}

static intmax_t signed_argument(va_list *args, s21_length length) {
  switch (length) {
    case S21_CHAR:
      return (signed char)va_arg(*args, int);
    case S21_SHORT:
      return (short)va_arg(*args, int);
    case S21_LONG:
      return va_arg(*args, long);
    case S21_LLONG:
      return va_arg(*args, long long);
    case S21_INTMAX:
      return va_arg(*args, intmax_t);
    default:
      return va_arg(*args, int);
  }
}

static uintmax_t unsigned_argument(va_list *args, s21_length length) {
  switch (length) {
    case S21_CHAR:
      return (unsigned char)_Generic(+(unsigned char)0,
          int: va_arg(*args, int),
          unsigned int: va_arg(*args, unsigned int));
    case S21_SHORT:
      return (unsigned short)_Generic(+(unsigned short)0,
          int: va_arg(*args, int),
          unsigned int: va_arg(*args, unsigned int));
    case S21_LONG:
      return va_arg(*args, unsigned long);
    case S21_LLONG:
      return va_arg(*args, unsigned long long);
    case S21_INTMAX:
      return va_arg(*args, uintmax_t);
    default:
      return va_arg(*args, unsigned int);
  }
}

static int print_bytes(char *out, int room, s21_print_spec spec,
                       const char *bytes, size_t count) {
  spec.zero = false;
  char *payload;
  int length = s21_print_field(out, room, spec, "", count, &payload);
  if (length >= 0) s21_memcpy(payload, bytes, count);
  return length;
}

static int print_integer(char *out, int room, s21_print_spec spec,
                         va_list *args) {
  char c = spec.conversion;
  unsigned base = c == 'o' ? 8 : (s21_strchr("xXp", c) ? 16 : 10);
  const char *prefix = "";
  uintmax_t value;
  if (c == 'd' || c == 'i') {
    intmax_t signed_value = signed_argument(args, spec.length);
    value = (uintmax_t)signed_value;
    if (signed_value < 0) value = 0 - value;
    prefix = s21_print_sign(spec, signed_value < 0);
  } else if (c == 'p') {
    void *pointer = va_arg(*args, void *);
#if defined(__linux__)
    if (!pointer) return print_bytes(out, room, spec, "(nil)", 5);
#endif
    value = (uintptr_t)pointer;
    prefix = "0x";
  } else {
    value = unsigned_argument(args, spec.length);
    if (base == 16 && spec.alternate && value) prefix = c == 'X' ? "0X" : "0x";
  }
  char buffer[sizeof(uintmax_t) * CHAR_BIT], *end = buffer + sizeof(buffer);
  char *digits = s21_uint_digits(end, value, base, c == 'X');
  if (value == 0 && spec.precision == 0 && c != 'p') digits = end;
  int count = (int)(end - digits);
  int zeros = spec.precision > count ? spec.precision - count : 0;
  if (c == 'o' && spec.alternate && !zeros && (!count || *digits != '0'))
    ++zeros;
  if (spec.precision >= 0) spec.zero = false;
  char *payload;
  int length =
      s21_print_field(out, room, spec, prefix, (size_t)count + zeros, &payload);
  if (length >= 0) {
    s21_memset(payload, '0', zeros);
    s21_memcpy(payload + zeros, digits, count);
  }
  return length;
}

static size_t wide_bytes(const wchar_t *str, size_t limit, char *out) {
  mbstate_t state = {0};
  size_t count = 0;
  while (count < limit) {
    char bytes[MB_LEN_MAX];
    size_t n = wcrtomb(bytes, *str, &state);
    if (n == (size_t)-1) return SIZE_MAX;
    bool last = *str++ == L'\0';
    if (last) --n;
    if (n > limit - count) break;
    if (out) s21_memcpy(out + count, bytes, n);
    count += n;
    if (last) break;
  }
  return count;
}

static int print_text(char *out, int room, s21_print_spec spec, va_list *args) {
  if (spec.conversion == 'c') {
    char bytes[MB_LEN_MAX];
    size_t count = 1;
    if (spec.length == S21_LONG) {
      mbstate_t state = {0};
      count = wcrtomb(bytes, (wchar_t)va_arg(*args, wint_t), &state);
      if (count == (size_t)-1) return -1;
    } else {
      bytes[0] = (unsigned char)va_arg(*args, int);
    }
    return print_bytes(out, room, spec, bytes, count);
  }

  size_t limit = spec.precision < 0 ? SIZE_MAX : (size_t)spec.precision;
  if (spec.length == S21_LONG) {
    const wchar_t *str = va_arg(*args, wchar_t *);
    size_t count = wide_bytes(str, limit, NULL);
    if (count == SIZE_MAX) return -1;
    char *payload;
    spec.zero = false;
    int length = s21_print_field(out, room, spec, "", count, &payload);
    if (length >= 0) wide_bytes(str, count, payload);
    return length;
  }
  const char *str = va_arg(*args, char *);
  size_t count = 0;
  while (count < limit && str[count]) ++count;
  return print_bytes(out, room, spec, str, count);
}

static int print_conversion(char *out, int written, s21_print_spec spec,
                            va_list *args) {
  int room = INT_MAX - written;
  char c = spec.conversion;
  if (c == 'n') {
    s21_store_signed(args, spec.length, written);
    return 0;
  }
  if (c == '%') return print_bytes(out, room, spec, "%", 1);
  if (c == 's' || c == 'c') return print_text(out, room, spec, args);
  if (s21_strchr("fFeEgG", c)) {
    long double value = spec.length == S21_LDOUBLE ? va_arg(*args, long double)
                                                   : va_arg(*args, double);
    return s21_print_float(out, room, spec, value);
  }
  return print_integer(out, room, spec, args);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int written = 0;
  bool ok = true;
  while (ok && *format) {
    if (*format == '%') {
      ++format;
      s21_print_spec spec = {.precision = -1};
      ok = read_spec(&format, &args, &spec);
      if (ok) {
        int n = print_conversion(str + written, written, spec, &args);
        if (n < 0)
          ok = false;
        else
          written += n;
      }
    } else if (written == INT_MAX) {
      errno = EOVERFLOW;
      ok = false;
    } else {
      str[written++] = *format++;
    }
  }
  str[written] = '\0';
  va_end(args);
  return ok ? written : -1;
}
