#include "./s21_math.h"

long double s21_asin(double x) {
  long double res = x;
  if (fabs(x) > 1) { // не забудь переделать fabs
    res = __builtin_nan("");
  } else if (x > S21_M_PI_4) {
    res = s21_acos(sqrt(1 - x * x)); // не забудь переделать sqrt
  } else if (x < -S21_M_PI_4) { 
    res = -s21_acos(sqrt(1 - x * x)); // не забудь переделать sqrt
  } else {
    long double initial_value = x;
    long double n = 1L;
    for (; (initial_value > 0 ? initial_value : -initial_value) > ACCURACY; n++) {
    initial_value = (pow(-1, n) * s21_factorial(2*n-1) * x * x) / (s21_factorial(2*n) * (2*n + 1)); //не забудь pow переделать
    res += initial_value;
}
  }
  return res;
}
