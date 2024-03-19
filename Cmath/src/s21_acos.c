#include "./s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (s21_fabs(x) > 1) {
    result = __builtin_nan("");
  } else if (x > S21_M_PI_4) {
    result = s21_asin(sqrt(1 - x * x)); //Не забудь переделать sqrt
  } else if (x < -S21_M_PI_4) {
    result = S21_M_PI - s21_asin(sqrt(1 - x * x)); //Не забудь переделать sqrt
  } else {
    result = S21_M_PI_2 - s21_asin(x);
  }
  return result;
}
