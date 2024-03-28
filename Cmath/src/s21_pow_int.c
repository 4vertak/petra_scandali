#include "s21_math.h"

long double s21_pow_int(double base, long long exp) {
  long double result = 1;
  int sign = (exp > 0);
  exp *= sign ? 1 : -1;
  for (long long int i = 0; i < exp; i++)
    result = sign ? result * base : result / base;
  return result;
}