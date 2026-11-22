#include "s21_math_internal.h"

long double s21_sqrt(double x) {
  if (x < 0.0) return S21_NAN;
  if (x == 0.0 || !__builtin_isfinite(x)) return x;

  int exponent = s21_normalize(&x);
  if (exponent % 2 != 0) {
    x *= 2;
    --exponent;
  }
  // Newton iteration on [1, 4) converges uniformly, including for subnormals.
  long double root = 1.0L;
  for (int i = 0; i < 7; ++i) root = (root + x / root) * 0.5L;
  return s21_scale(root, exponent / 2);
}
