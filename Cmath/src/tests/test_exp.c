#include "./test.h"

START_TEST(test_exp_1) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST

START_TEST(test_exp_2) {
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
}
END_TEST

START_TEST(test_exp_3) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(test_exp_4) {
  ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001);
}
END_TEST

START_TEST(test_exp_5) {
  ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001);
}
END_TEST

START_TEST(test_exp_6) {
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 0.000001);
}
END_TEST

START_TEST(test_exp_7) {
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));
}
END_TEST

Suite *test_exp(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_EXP  |=========\033[0m");
  TCase *tc = tcase_create("exp_tc");

  tcase_add_test(tc, test_exp_1);
  tcase_add_test(tc, test_exp_2);
  tcase_add_test(tc, test_exp_3);
  tcase_add_test(tc, test_exp_4);
  tcase_add_test(tc, test_exp_5);
  tcase_add_test(tc, test_exp_6);
  tcase_add_test(tc, test_exp_7);
  suite_add_tcase(s, tc);
  return s;
}