#include "./s21_math.h"

// returns the nearest integer not less than the given value

long double s21_ceil(double x) {
  int int_x = (int)x;
  long double res = int_x;
  if (x > 0 && res != x) res++;
  return res;
}
