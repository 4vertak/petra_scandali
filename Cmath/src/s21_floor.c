#include "./s21_math.h"

long double s21_floor(double x) {
  int int_x = x;
  long double res = int_x;
  if (x < 0 && res != x) res--;
  return res;
}