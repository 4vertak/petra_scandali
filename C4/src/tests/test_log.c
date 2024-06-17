#include "./test.h"

START_TEST(s21_log_TEST) {
    ck_assert_ldouble_eq_tol(s21_log(35), log(35), 6);
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), 6);
    ck_assert_ldouble_eq_tol(s21_log(123456), log(123456), 6);
    ck_assert_ldouble_eq_tol(s21_log(123456789), log(123456789), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.123), log(0.123), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.12456), log(0.123456), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.1234567), log(0.1234567), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.12345678), log(.12345678), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.123456789), log(0.12456789), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.1234567891), log(0.1234567891), 6);
    ck_assert_ldouble_eq_tol(s21_log(0.1234567891234567), log(0.1234567891234567), 6);
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(786), log(786), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.866025), log(0.866025), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.707107), log(0.707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(78967456), log(78967456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(707107), log(707107), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(5738), log(5738), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.445738), log(0.445738), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.876412), log(0.876412), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.987451), log(0.987451), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.987565), log(0.987565), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.799415), log(0.799415), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.456123), log(0.456123), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.216875), log(0.216875), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.978464), log(0.978464), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.215488), log(0.215488), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.755422), log(0.755422), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(76412), log(76412), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(987451.98465), log(987451.98465), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(987565.9874641213656), log(987565.9874641213656), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(799415.5649), log(799415.5649), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(456123.97904), log(456123.97904), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(216875.6649), log(216875.6649), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(9), log(9), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(88), log(88), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(5422), log(5422), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.123456), log(0.123456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(123456), log(123456), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
    ck_assert_ldouble_nan(s21_log(-1));
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.1234), log(0.1234), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(0.9876), log(0.9876), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(S21_EXP), log(S21_EXP), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(123), log(123), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(547893), log(547893), 1e-6);
}
END_TEST

Suite *test_log(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21LOG |=========\033[0m");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, s21_log_TEST);
  suite_add_tcase(s, tc);
  return s;
}