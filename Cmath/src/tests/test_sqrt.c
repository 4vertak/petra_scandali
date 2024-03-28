#include "./test.h"

START_TEST(test_sqrt_1) { ck_assert_int_eq(s21_sqrt(25), sqrt(25)); }
END_TEST

START_TEST(test_sqrt_2) { ck_assert_int_eq(s21_sqrt(143), sqrt(143)); }
END_TEST

START_TEST(test_sqrt_3) { ck_assert_int_eq(s21_sqrt(-253), sqrt(-253)); }
END_TEST

START_TEST(test_sqrt_4) {
  ;
  ck_assert_int_eq(s21_sqrt(0.0), sqrt(0.0));
}
END_TEST

START_TEST(test_sqrt_5) {
  double x = 0.0 / 0.0;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(test_sqrt_6) {
  double x = 1.79769e+308;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(test_sqrt_7) {
  double x = 2.22507e-308;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(test_sqrt_8) {
  double x = INFINITY;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(test_sqrt_9) {
  double x = 3.14159f;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

Suite *test_sqrt(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_SQRT  |=========\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  tcase_add_test(tc, test_sqrt_1);
  tcase_add_test(tc, test_sqrt_2);
  tcase_add_test(tc, test_sqrt_3);
  tcase_add_test(tc, test_sqrt_4);
  tcase_add_test(tc, test_sqrt_5);
  tcase_add_test(tc, test_sqrt_6);
  tcase_add_test(tc, test_sqrt_7);
  tcase_add_test(tc, test_sqrt_8);
  tcase_add_test(tc, test_sqrt_9);
  suite_add_tcase(s, tc);
  return s;
}