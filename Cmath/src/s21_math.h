#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <math.h>    // не забудь убрать)
#include <stdio.h>   // не забудь убрать)
#include <stdlib.h>  // не забудь убрать)

#define S21_INF 1.0 / 0.0
#define S21_M_PI 3.14159265358979323846     // pi
#define S21_M_PI_2 1.57079632679489661923   // pi/2
#define S21_M_PI_4 0.785398163397448309616  // pi/4
#define ACCURACY 1E-50
#define S21_NAN __builtin_nan("")
#define s21_isnan(x) __builtin_isnan(x)
#define s21_isinf(x) __builtin_isinf_sign(x)

#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_LN2 0.693147180559945309417232
#define S21_EXP 2.71828182845904523536028747

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(long long int x);
long double s21_pow_int(double base, long long exp);
long double s21_exp(double x);

#endif  // SRC_S21_MATH_H_
