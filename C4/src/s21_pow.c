#include <float.h>

#include "s21_math_internal.h"

long double s21_positive_power(double base, long double exponent) {
  double mantissa = base;
  int binary_exponent = s21_normalize(&mantissa);
  if (mantissa == 1.0) {
    // Keep exact powers of two exact, including at the underflow boundary.
    long double power = (long double)binary_exponent * exponent;
    if (power <= LDBL_MIN_EXP - LDBL_MANT_DIG - 1) return 0;
    if (power >= LDBL_MAX_EXP) return S21_INF;
    if (power == (int)power) return s21_scale(1, (int)power);
  }
  return s21_exp_reduced(exponent * s21_log(base));
}

long double s21_pow(double base, double exponent) {
  if (exponent == 0.0 || base == 1.0) return 1;
  if (s21_isnan(base) || s21_isnan(exponent)) return S21_NAN;

  double magnitude = s21_fabs(base);
  if (s21_isinf(exponent)) {
    if (magnitude == 1) return 1;
    return (magnitude > 1) == (exponent > 0) ? S21_INF : 0;
  }

  int integer_exponent = s21_floor(exponent) == exponent;
  int odd = integer_exponent && s21_fabs(exponent) < 0x1p53 &&
            (long long)exponent % 2 != 0;
  long double result;
  if (base == 0.0 || s21_isinf(base)) {
    result = (base == 0.0) == (exponent > 0) ? 0 : S21_INF;
  } else if (base < 0 && !integer_exponent) {
    result = S21_NAN;
  } else if (integer_exponent && s21_fabs(exponent) <= 64) {
    result = (double)s21_pow_int(magnitude, (long long)exponent);
  } else {
    result = (double)s21_positive_power(magnitude, exponent);
  }
  return __builtin_signbit(base) && odd ? -result : result;
}
