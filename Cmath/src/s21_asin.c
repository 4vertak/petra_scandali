#include "./s21_math.h"

long double s21_factorial(long double n){
    long double fact = 1;
    for (int c=1; c<=n; c++){
        fact = fact * c;
    }
    return fact;
}


long double s21_asin(double x) {
  long double res = x;
  if (fabs(x) > 1) {
    res = __builtin_nan("");
  } else if (x > M_PI_4) {
    res = s21_acos(sqrt(1 - x * x));
  } else if (x < -M_PI_4) {
    res = -s21_acos(sqrt(1 - x * x));
  } else {
    long double initial_value = x;
    long double n = 1L;
    for (; (initial_value > 0 ? initial_value : -initial_value) > 1E-17; n++) {
    // initial_value *= ((2 * n - 1) * (2 * n - 1) / ((2 * n) * (2 * n + 1))) * x * x;
    initial_value = (pow(-1, n) * s21_factorial(2*n-1) * x * x) / (s21_factorial(2*n) * (2*n + 1));
    res += initial_value;
}
    
  }

  return res;
}

long double s21_acos(double x) {
long double result = 0;
if (fabs(x) > 1) {
result = __builtin_nan("");
} else if (x > M_PI_4) {
result = s21_asin(sqrt(1 - x * x));
} else if (x < -M_PI_4) {
result = M_PI - s21_asin(sqrt(1 - x * x));
} else {
result = M_PI_2 - s21_asin(x);
}
return result;
}

// int main() {
//   long double x = 0;   // 1E-7
//   long double y = -1;  // 1E-8

//   printf("1E-7v2: %Lf\n1E-7orig: %f\n\n", s21_asin(x), asin(x));
//   printf("1E-8 v2: %Lf\n1E-8 orig: %f\n", s21_asin(y), asin(y));

//   return 0;
// }
