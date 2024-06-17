#include "./s21_math.h"

long double s21_sin(double num) {
  long double result = num;
  int status = 1, sign = (-1);
  if (s21_isnan(num) || s21_isinf(num)) {
    status = 0;
  } else {
    num = s21_fmod(num, S21_M_PI * 2.0);

    if (num > (S21_M_PI / 2.0) && num <= S21_M_PI)
      num = (S21_M_PI - num) * (sign = 1);
    else if (num > S21_M_PI && num <= ((S21_M_PI * 3.0) / 2.0))
      num -= S21_M_PI;
    else if (num > ((S21_M_PI * 3.0) / 2.0) && num <= (S21_M_PI * 2.0))
      num = (2.0 * S21_M_PI) - num;
    else
      sign = 1;

    result = (long double)num;
    long double valueTailor = (long double)num;
    for (int i = 1; s21_fabs(valueTailor / result) > 1e-100; i += 1)
      result += (valueTailor = ((-valueTailor) * num * num) /
                               ((2.0 * i + 1) * (2.0 * i)));
  }
  return status ? (result * sign) : S21_NAN;
}