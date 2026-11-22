#ifndef SRC_S21_FORMAT_H_
#define SRC_S21_FORMAT_H_

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

typedef enum {
  S21_INT,
  S21_CHAR,
  S21_SHORT,
  S21_LONG,
  S21_LLONG,
  S21_INTMAX,
  S21_LDOUBLE
} s21_length;

size_t s21_read_decimal(const char **format);
s21_length s21_read_length(const char **format);
void s21_store_signed(va_list *args, s21_length length, intmax_t value);

#endif
