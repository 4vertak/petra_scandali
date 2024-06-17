#include "./s21_math.h"

long double s21_tan(double num) {
  int status = 1;
  if (s21_isnan(num) || s21_isinf(num)) status = 0;
  return status ? (s21_sin(num) / s21_cos(num)) : S21_NAN;
}