#include "./s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (fabs(x) > 1) {
    result = __builtin_nan("");
  } else if (x > M_PI_4) {
    result = s21_asin(sqrt(1 - x * x));
  } else if (x < -M_PI_4) {
    result = M_PI - s21_asin(sqrt(1 - x * x));
  } else {
    result = M_PI_2 - s21_asin(x);
  }
  return result;
}
