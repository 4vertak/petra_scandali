#include "./test.h"

START_TEST(test_from_decimal_to_int_0) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_scale(&val, 5);
  int res = 1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(test_from_decimal_to_int_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_bit(&val, 127, 1);
  set_scale(&val, 5);
  int res = -1234;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_DECIMAL_TO_INT |=========\033[0m");
  TCase *tc = tcase_create("tc_from_decimal_to_int");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_decimal_to_int_0);
  tcase_add_test(tc, test_from_decimal_to_int_1);
  return s;
}