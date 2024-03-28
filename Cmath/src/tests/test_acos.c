#include "./test.h"

START_TEST(s21_acos_TEST) {
    ck_assert_ldouble_eq_tol(s21_acos(1.000000), acos(1.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.866025), acos(0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.707107), acos(0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.000000), acos(0.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.500000), acos(-0.500000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.707107), acos(-0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.866025), acos(-0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.866025), acos(-0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.707107), acos(-0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.000000), acos(-0.000000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.500000), acos(0.500000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.707107), acos(0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.866025), acos(0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.445738), acos(-0.445738), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.123456), acos(0.123456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.123456), acos(-0.123456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.00001), acos(0.00001), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.7), acos(0.7), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.85), acos(0.85), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(0.99999991), acos(0.99999991), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.9), acos(-0.9), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.69), acos(-0.69), 1e-6);
    ck_assert_ldouble_eq_tol(s21_acos(-0.2), acos(-0.2), 1e-6);
    ck_assert_ldouble_nan(s21_acos(10000));;
    ck_assert_ldouble_nan(s21_acos(-1.0011));
}
END_TEST

Suite *test_acos(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21ACOS |=========\033[0m");
  TCase *tc = tcase_create("acos_tc");

  tcase_add_test(tc, s21_acos_TEST);
  suite_add_tcase(s, tc);
  return s;
}