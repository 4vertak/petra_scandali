#include <float.h>

#include "s21_math_internal.h"

long double s21_exp_reduced(long double x) {
  if (s21_isnan(x)) return x;
  const long double ln2 = S21_LN2_HI + S21_LN2_LO;
  if (x > (LDBL_MAX_EXP + 1) * ln2) return S21_INF;
  if (x < (LDBL_MIN_EXP - LDBL_MANT_DIG - 1) * ln2) return 0;

  int k = (int)(x / ln2 + (x < 0 ? -0.5L : 0.5L));
  long double r = (x - k * S21_LN2_HI) - k * S21_LN2_LO;
  long double term = 1;
  long double sum = 1;
  long double previous;
  int n = 0;
  do {
    previous = sum;
    term *= r / ++n;
    sum += term;
  } while (sum != previous);
  return s21_scale(sum, k);
}

long double s21_exp(double x) { return (double)s21_exp_reduced(x); }
