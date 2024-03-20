#include "./s21_math.h"

long double s21_asin(double x) {
  long double result = x;
  if (s21_fabs(x) > 1) {
    result = S21_NAN;
  } else if (x > S21_M_PI_4) {
    result = s21_acos(sqrt(1 - x * x));  // не забудь переделать sqrt
  } else if (x < -S21_M_PI_4) {
    result = -s21_acos(sqrt(1 - x * x));  // не забудь переделать sqrt
  } else {
    long double temp = x;
    long double coef = 0;
    long double n = 1L;
    while (s21_fabs(temp) > ACCURACY) {
      coef = (2 * n - 1) * (2 * n - 1) / ((2 * n) * (2 * n + 1));
      temp *= coef * x * x;
      result += temp;
      n++;
    }
  }
  return result;
}
