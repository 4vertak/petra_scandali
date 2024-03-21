#include "./s21_math.h"

// возвращает абсолютное значение числа, то есть значение без учета его знака

// НЕ зАБЫТЬ sqrt - заменить на функции s21_...

long double s21_atan(double x) {
  long double result = 0;
  if (s21_fabs(x) > 0.4 && s21_fabs(x) < 10) {
    result = s21_asin(x * sqrt(1 / (1 + x * x)));  // не забудь поменять sqrt  
  } else {
    int dir_val = (s21_fabs(x) < 1);
    if (dir_val) {
      x = x;
    } else {
      x = 1 / x;
    }
    long double temp;
    if (dir_val) {
      temp = x;
    } else {
      temp = -x;
    }
    result = temp;
    if (!dir_val) {
      if (x > 0) {
        result += S21_M_PI_2;
      } else {
        result -= S21_M_PI_2;
      }
    }
    long double coef = 1L;
    long double n = 1L;
    while (s21_fabs(coef * temp) > ACCURACY && n < 20) {
      coef = 1.0L / (2 * n + 1);
      temp *= -x * x;
      result += coef * temp;
      n++;
    }
  }
  return result;
}
