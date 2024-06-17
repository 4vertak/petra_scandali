#include "./s21_math.h"
// приближенноe вычислениe квадратного корня числа `x` типа long double с заданной точностью
long double s21_sqrt(double x) {
  long double func = total_sqrt(x);
  if (func != S21_INF) {
    if (x > 0) {
      long double iks = 1.0;
      for (int i = 0; i < 100; i++) {
        func = iks - ((iks * iks - x) / (2 * iks));
        if (s21_fabs((func - iks)) <= 1e-14) {
          break;
        }
        iks = func;
      }
    }
  }
  return func;
}

long double total_sqrt(double x) {
  return (x == 0) ? 0 : (x == S21_INF) ? S21_INF : S21_NAN;
}