#include "s21_math.h"

long double s21_cos(double x) {
  int d = (int)x / S21_M_PI;
  x -= d * S21_M_PI;
  char sign = 1;
  if (d % 2 != 0) sign = -1;
  long double res = 1.0;
  long double part = 1.0;
  for (int n = 1; n <= 8; n++) {
    part *= x * x / (2 * n * (2 * n - 1));
    if (n % 2 == 0) {
      res += part;
    } else {
      res -= part;
    }
  }
  return sign * res;
}