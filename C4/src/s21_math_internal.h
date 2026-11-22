#ifndef SRC_S21_MATH_INTERNAL_H_
#define SRC_S21_MATH_INTERNAL_H_

#include "s21_math.h"

#define S21_PI_2L 1.570796326794896619231321691639751442L
// Split ln(2) so that k * HI is exact during exponential range reduction.
#define S21_LN2_HI 0x1.62e42fefa0000p-1L
#define S21_LN2_LO 1.64659495828970812809844307550013436e-12L

// Write a positive finite double as a mantissa in [1, 2) times 2^exponent.
int s21_normalize(double *mantissa);
long double s21_scale(long double value, int exponent);
long double s21_atan_positive(long double x);
long double s21_exp_reduced(long double x);
long double s21_positive_power(double base, long double exponent);
void s21_sincos(double x, long double *sine, long double *cosine);

#endif  // SRC_S21_MATH_INTERNAL_H_
