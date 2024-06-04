#include "./s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0.0;
  return (pow_total(base, exp, &res)) ? pow_A(base, exp) : res;
}

long double pow_A(double base, double exp) {
  long double res = 0.0;
  if ((long long int)exp == exp) {
    res = s21_Bpow(base, exp);
  } else {
    res = s21_Cpow(base, exp);
  }
  return res;
}

long double s21_Bpow(double base, double exp) {
  long double res = 1.0;
  if (exp > 0) {
    for (; exp >= 1; exp--) {
      res *= base;
    }
  } else {
    for (; exp <= -1; exp++) {
      res /= base;
    }
  }
  return res;
}

long double s21_Cpow(double base, double exp) {
  long double res = s21_exp(exp * s21_log(s21_fabs(base)));
  if (!is_fin(res)) {
    res = S21_EXPON;
  }
  if (base < 0 && ((long long int)exp & 1) == 0) {
    res = (exp > 0) ? -res : S21_NAN;
  }
  return res;
}

int pow_total(double base, double exp, long double *res) {
  long double tol = 1e-14;
  int ok = 1;
  int b_is_nan = s21_isnan(base);
  int b_is_fin = is_fin(base);
  int e_is_nan = s21_isnan(exp);
  int e_is_fin = is_fin(exp);
  int e_lim = s21_fabs(exp - s21_floor(exp)) <= tol;
  if (b_is_fin && !b_is_nan && base > 0 && base <= tol && e_lim &&
      ((int)exp) < 0 && ((int)exp) % 2) {
    *res = S21_INF;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && base > 0 && base <= tol && e_lim &&
      ((int)exp) < 0 && ((int)exp) % 2) {
    *res = S21_NINF;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && s21_fabs(base) < tol && e_is_fin &&
      ((e_lim && !(((int)exp) % 2)) || !e_lim)) {
    if (base == 0) {
      if (exp == 0) {
        *res = 1;
      } else if (exp > 0) {
        *res = 0;
      } else {
        *res = S21_INF;
      }
    }
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && s21_fabs(base) < tol && !e_is_nan && !e_is_fin &&
      exp < 0) {
    *res = S21_INF;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && base > 0 && base <= tol && e_lim &&
      ((int)exp) % 2) {
    *res = +0;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && base < 0 && base >= -tol && e_lim &&
      ((int)exp) % 2) {
    *res = -0;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && s21_fabs(base + 1) < tol && !e_is_fin &&
      !e_is_nan) {
    *res = 1;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && s21_fabs(base - 1) < tol) {
    *res = 1;
    ok = 0;
  }
  if (s21_fabs(exp) < tol) {
    *res = 1;
    ok = 0;
  }
  if (ok && b_is_fin && base < -tol && e_is_fin && !e_lim) {
    *res = S21_NAN;
    ok = 0;
  }
  if (b_is_fin && !b_is_nan && base < 0 && base >= -tol && e_lim &&
      ((int)exp) % 2) {
    *res = -0;
    ok = 0;
  }
  if (exp > 0 && b_is_fin && !b_is_nan && s21_fabs(base) < tol &&
      ((!e_lim && s21_fabs(exp) > tol) || (e_lim && !(((int)exp) % 2)))) {
    *res = +0;
    ok = 0;
  }
  if (ok && s21_fabs(base) - 1 < tol && !e_is_nan && !e_is_fin && exp < 0) {
    *res = S21_INF;
    ok = 0;
  }
  if (ok && s21_fabs(base) - 1 > tol && !e_is_nan && !e_is_fin && exp < 0) {
    *res = +0;
    ok = 0;
  }
  if (ok && s21_fabs(base) - 1 < tol && !e_is_nan && !e_is_fin && exp > 0) {
    *res = +0;
    ok = 0;
  }
  if (ok && s21_fabs(base) - 1 > tol && !e_is_nan && !e_is_fin && exp > 0) {
    *res = S21_INF;
    ok = 0;
  }
  if (!b_is_nan && !b_is_fin && base < 0 && e_lim && exp < 0 &&
      ((int)exp) % 2 && ok) {
    *res = -0;
    ok = 0;
  }
  if (!b_is_nan && !b_is_fin && base < 0 &&
      ((!e_lim && exp < 0) || (e_lim && exp < 0 && !(((int)exp) % 2)))) {
    *res = +0;
    ok = 0;
  }
  if (!b_is_nan && !b_is_fin && base < 0 &&
      (e_lim && exp > 0 && ((int)exp) & 1)) {
    *res = S21_NINF;
    ok = 0;
  }
  if (!b_is_nan && !b_is_fin && base < 0 &&
      ((!e_lim && exp > 0) || (e_lim && exp > 0 && !(((int)exp) % 2)))) {
    *res = S21_INF;
    ok = 0;
  }
  if (!b_is_nan && !b_is_fin && base > 0 && exp < -tol) {
    *res = +0;
    ok = 0;
  }
  if (!b_is_nan && !b_is_fin && base > 0 && exp > tol) {
    *res = S21_INF;
    ok = 0;
  }
  if ((b_is_nan && exp) || (base != 1 && e_is_nan)) {
    *res = S21_NAN;
    ok = 0;
  }
  return ok;
}