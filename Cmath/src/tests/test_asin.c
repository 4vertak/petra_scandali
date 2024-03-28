#include "./test.h"

START_TEST(s21_asin_TEST) {
    ck_assert_ldouble_eq_tol(s21_asin(1.000000), asin(1.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.866025), asin(0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.707107), asin(0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.000000), asin(0.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.500000), asin(-0.500000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.707107), asin(-0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.866025), asin(-0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-1.000000), asin(-1.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.866025), asin(-0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.707107), asin(-0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.000000), asin(-0.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.500000), asin(0.500000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.866025), asin(0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.445738), asin(-0.445738), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.123456), asin(0.123456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.123456), asin(-0.123456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.1111), asin(0.1111), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.7), asin(0.7), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.85), asin(0.85), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.9999999), asin(0.9999999), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.2), asin(-0.2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(0.66666), asin(0.66666), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.787), asin(-0.787), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-0.9), asin(-0.9), 1e-6);
    ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
    ck_assert_ldouble_nan(s21_asin(10));
    ck_assert_ldouble_nan(s21_asin(-1.0011));
}
END_TEST

Suite *test_asin(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21ASIN |=========\033[0m");
  TCase *tc = tcase_create("asin_tc");

  tcase_add_test(tc, s21_asin_TEST);
  suite_add_tcase(s, tc);
  return s;
}