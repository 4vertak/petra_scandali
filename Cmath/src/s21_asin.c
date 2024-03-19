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
    long double temp = x;
    long double n = 1L;
    for (; (temp > 0 ? temp : -temp) > ACCURACY; n++) {
    temp = (pow(-1, n) * s21_factorial(2*n-1) * x * x) / (s21_factorial(2*n) * (2*n + 1)); //не забудь pow переделать
    res += temp;
}
  }
  return res;
}
