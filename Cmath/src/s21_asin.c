#include "./s21_math.h"

long double s21_asin(double x) {
  long double res = x;
  if (fabs(x) > 1) {
    res = __builtin_nan("");
  } else if (x > M_PI_4) {
    res = s21_acos(sqrt(1 - x * x));
  } else if (x < -M_PI_4) {
    res = -s21_acos(sqrt(1 - x * x));
  } else {
    long double initial_value = x;
    long double n = 1L;
    for (; (initial_value > 0 ? initial_value : -initial_value) > 1E-17; n++) {
    initial_value = (pow(-1, n) * s21_factorial(2*n-1) * x * x) / (s21_factorial(2*n) * (2*n + 1));
    res += initial_value;
}
  }
  return res;
}
