#include "./test.h"

START_TEST(test_abs_1) {
  double di = 1.0 / 0.0;
  ck_assert_int_eq(s21_abs((int)di), abs((int)di));
}
END_TEST

Suite *test_abs(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ABS  |=========\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, test_abs_1);
  suite_add_tcase(s, tc);
  return s;
}