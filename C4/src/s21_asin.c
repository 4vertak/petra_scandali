#include "s21_math_internal.h"

long double s21_asin(double x) {
  long double magnitude = s21_fabs(x);
  if (!(magnitude <= 1)) return S21_NAN;
  long double angle = S21_PI_2L;
  if (magnitude < 1) {
    long double adjacent = s21_sqrt((1 - magnitude) * (1 + magnitude));
    angle = s21_atan_positive(magnitude / adjacent);
  }
  return __builtin_signbit(x) ? -angle : angle;
}
