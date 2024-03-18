#include "./s21_math.h"

long double s21_asin(double x) {
  long double res = x;
  if (fabs(x) > 1) {
    res = __builtin_nan("");
  } else if (x > S21_M_PI_4) {
    res = acos(sqrt(1 - x * x));
  } else if (x < -S21_M_PI_4) {
    res = -acos(sqrt(1 - x * x));
  } else {
    long double term = x;
    long double n = 1L;
    while ((term > 0 ? term : -term) > 1E-17) {
      term *= ((2 * n - 1) * (2 * n - 1) / ((2 * n) * (2 * n + 1))) * x * x;
      res += term;
      n++;
    }
  }

  return res;
}

// int main() {
//   long double x = 0;   // 1E-7
//   long double y = -1;  // 1E-8

//   printf("1E-7v2: %Lf\n1E-7orig: %f\n\n", s21_asin(x), asin(x));
//   printf("1E-8 v2: %Lf\n1E-8 orig: %f\n", s21_asin(y), asin(y));

//   return 0;
// }