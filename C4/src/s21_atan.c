#include "s21_math_internal.h"

long double s21_atan_positive(long double x) {
  int reciprocal = x > 1;
  if (reciprocal) x = 1.0L / x;
  long double offset = 0;
  if (x > 0.4142135623730950488L) {
    x = (x - 1) / (x + 1);
    offset = S21_PI_2L * 0.5L;
  }
  long double square = -x * x;
  long double power = x;
  long double sum = x;
  long double previous;
  int n = 1;
  do {
    previous = sum;
    power *= square;
    n += 2;
    sum += power / n;
  } while (sum != previous);
  sum += offset;
  return reciprocal ? S21_PI_2L - sum : sum;
}

long double s21_atan(double x) {
  if (s21_isnan(x)) return x;
  long double angle = s21_atan_positive(s21_fabs(x));
  return __builtin_signbit(x) ? -angle : angle;
}
