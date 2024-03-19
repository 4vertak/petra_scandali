#include "./s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0.0;
  int sign = 1;
  if (x < 0) {
    sign = -1;
    x = s21_fabs(x);
  }
  if (y < 0) y = s21_fabs(y);
  if (y == 0) {
    res =  __builtin_nan("");
  } else if (x == y) {
    res = 0;
  } else if (x < y) {
    res = x;
  } else {
   long double quotient = x / y;
    result = (long double)x - quotient * (long double)y;
    result = result * sign;
  }
  return result;
}
