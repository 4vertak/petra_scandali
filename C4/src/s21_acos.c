#include "s21_math_internal.h"

long double s21_acos(double x) {
  if (x > 0.5 && x <= 1) {
    // Half-angle form preserves the small result near the endpoint x = 1.
    return 2 * s21_atan_positive(s21_sqrt((1.0L - x) / (1.0L + x)));
  }
  return S21_PI_2L - s21_asin(x);
}
