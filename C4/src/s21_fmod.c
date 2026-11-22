#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (s21_isinf(x) || s21_isnan(x) || s21_isnan(y) || y == 0.0) {
    return S21_NAN;
  }
  long double remainder = s21_fabs(x);
  long double divisor = s21_fabs(y);
  if (remainder < divisor) return x;

  // Binary long division keeps the subtraction exact even if x/y overflows.
  long double step = divisor;
  while (step <= remainder * 0.5L) step *= 2;
  for (; step >= divisor; step *= 0.5L) {
    if (remainder >= step) remainder -= step;
  }
  return __builtin_signbit(x) ? -remainder : remainder;
}
