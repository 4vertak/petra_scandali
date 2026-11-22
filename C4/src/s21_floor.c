#include "s21_math.h"

long double s21_floor(double x) {
  if (x == 0.0 || !(s21_fabs(x) < 0x1p52)) return x;
  long long whole = (long long)x;
  return whole - (x < whole);
}
