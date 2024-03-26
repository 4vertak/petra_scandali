#include "./s21_math.h"

long double s21_acos(double x) {
  long double acos;
  acos = S21_M_PI_2 - s21_asin(x);
  return acos;
}
