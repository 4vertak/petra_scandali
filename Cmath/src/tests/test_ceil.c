#include "./test.h"

START_TEST(test_ceil_1) {
  double x = 1.1;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_2) {
  double x = 0.9;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_3) {
  double x = 0;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_4) {
  double x = -1.9;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_5) {
  double x = -1.1;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_6) {
  double x = 1;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

Suite *test_ceil(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_CEIL  |=========\033[0m");
  TCase *tc = tcase_create("ceil_tc");

  tcase_add_test(tc, test_ceil_1);
  tcase_add_test(tc, test_ceil_2);
  tcase_add_test(tc, test_ceil_3);
  tcase_add_test(tc, test_ceil_4);
  tcase_add_test(tc, test_ceil_5);
  tcase_add_test(tc, test_ceil_6);
  suite_add_tcase(s, tc);
  return s;
}