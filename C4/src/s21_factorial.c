#include <float.h>

#include "s21_math.h"

long double s21_factorial(long long x) {
  // For n >= 4, n! exceeds 2^n.
  if (x < 0 || x >= LDBL_MAX_EXP) return S21_INF;
  long double result = 1;
  for (long long i = 2; i <= x; ++i) result *= i;
  return result;
}
