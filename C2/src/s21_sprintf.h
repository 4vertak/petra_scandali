#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdbool.h>

#include "s21_format.h"

typedef struct {
  int width, precision;
  bool left, plus, space, alternate, zero;
  s21_length length;
  char conversion;
} s21_print_spec;

// Reserve a complete field and return its length and the start of its payload.
int s21_print_field(char *out, int room, s21_print_spec spec,
                    const char *prefix, size_t payload_length, char **payload);
const char *s21_print_sign(s21_print_spec spec, bool negative);
char *s21_uint_digits(char *end, uintmax_t value, unsigned base, bool upper);
int s21_print_float(char *out, int room, s21_print_spec spec,
                    long double value);

#endif
