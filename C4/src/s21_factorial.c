#include "s21_math.h"

long double s21_factorial(long long int x) {
  if (x == 1 || x == 0) return 1;
  if (x < 0) return S21_INF_POS;
  long double res = x * s21_factorial(x - 1);
  return res;
}