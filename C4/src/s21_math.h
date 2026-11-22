#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_INF (__builtin_huge_val())
#define S21_NINF (-S21_INF)
#define S21_INF_POS S21_INF
#define S21_INF_NEG S21_NINF
#define S21_NAN (__builtin_nan(""))
#define S21_M_PI 3.14159265358979323846
#define S21_M_PI_2 1.57079632679489661923
#define S21_M_PI_4 0.785398163397448309616
#define S21_LN2 0.693147180559945309417232
#define S21_EXP 2.71828182845904523536028747
#define S21_EXPON 1.7976931348623158e+308
#define s21_isnan(x) __builtin_isnan(x)
#define s21_isinf(x) __builtin_isinf_sign(x)
#define S21_IS_NAN(x) s21_isnan(x)
#define S21_IS_INF(x) (__builtin_isinf(x) != 0)

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
long double s21_pow(double base, double exponent);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_factorial(long long x);
long double s21_pow_int(double base, long long exponent);

#endif  // SRC_S21_MATH_H_
