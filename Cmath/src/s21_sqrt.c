#include "./s21_math.h"

long double s21_sqrt(double x) {
  long double res = check_sqrt(x);
  if (res != S21_INF) {
    if (x > 0) {
      long double x_0 = 1.0;
      for (int i = 0; i < 100; i++) {
        res = x_0 - ((x_0 * x_0 - x) / (2 * x_0));
        if (s21_fabs((res - x_0)) <= 1e-14) {
          break;
        }
        x_0 = res;
      }
    }
  }
  return res;
}

long double check_sqrt(double x) {
  return (x == 0) ? 0 : (x == S21_INF) ? S21_INF : S21_NAN;
}