#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include <stdbool.h>

#include "s21_format.h"

typedef enum {
  S21_SCAN_OK,
  S21_SCAN_MISMATCH,
  S21_SCAN_INPUT_FAILURE
} s21_scan_status;

typedef struct {
  char conversion;
  s21_length length;
  size_t width, position;
  bool suppress, allocate, inverted;
  const char *set, *set_end;
} s21_scan_spec;

s21_scan_status s21_scan_integer(const char **input, s21_scan_spec spec,
                                 va_list *args);
s21_scan_status s21_scan_float(const char **input, s21_scan_spec spec,
                               va_list *args);

#endif
