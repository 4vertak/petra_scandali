#include "s21_math_internal.h"

long double s21_log(double x) {
  if (x == 0.0) return S21_NINF;
  if (x < 0.0) return S21_NAN;
  if (!__builtin_isfinite(x)) return x;

  int exponent = s21_normalize(&x);
  if (x > 1.4142135623730950488L) {
    x *= 0.5;
    ++exponent;
  }
  // log(x) = 2 atanh((x - 1)/(x + 1)), with |ratio| < 0.172.
  long double ratio = (x - 1.0L) / (x + 1.0L);
  long double square = ratio * ratio;
  long double tail = 0;
  for (int n = 33; n >= 3; n -= 2) tail = 1.0L / n + square * tail;
  long double log_mantissa = 2 * (ratio + ratio * square * tail);
  return exponent * S21_LN2_HI + (log_mantissa + exponent * S21_LN2_LO);
}
