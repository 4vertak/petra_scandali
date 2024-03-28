#include "./test.h"

START_TEST(test_cos_1) {
  ck_assert_double_eq_tol(s21_cos(1.1), cos(1.1), 1e-6);
}
END_TEST

START_TEST(test_cos_2) {
  ck_assert_double_eq_tol(s21_cos(10.1), cos(10.1), 1e-6);
}
END_TEST

START_TEST(test_cos_3) {
  ck_assert_double_eq_tol(s21_cos(-10.1), cos(-10.1), 1e-6);
}
END_TEST

START_TEST(test_cos_4) {
  ck_assert_double_eq_tol(s21_cos(-1.1), cos(-1.1), 1e-6);
}
END_TEST

START_TEST(test_cos_5) {
  ck_assert_double_eq_tol(s21_cos(S21_M_PI), cos(S21_M_PI), 1e-6);
}
END_TEST

START_TEST(test_cos_6) {
  ck_assert_double_eq_tol(s21_cos(0), cos(0), 1e-6);
}
END_TEST

START_TEST(test_cos_7) {
  ck_assert_double_eq_tol(s21_cos(1), cos(1), 1e-6);
}
END_TEST

Suite *test_cos(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_COS  |=========\033[0m");
  TCase *tc = tcase_create("cos_tc");

  tcase_add_test(tc, test_cos_1);
  tcase_add_test(tc, test_cos_2);
  tcase_add_test(tc, test_cos_3);
  tcase_add_test(tc, test_cos_4);
  tcase_add_test(tc, test_cos_5);
  tcase_add_test(tc, test_cos_6);
  tcase_add_test(tc, test_cos_7);
  suite_add_tcase(s, tc);
  return s;
}