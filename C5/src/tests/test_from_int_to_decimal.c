#include "./test.h"

START_TEST(test_from_int_to_decimal_0) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(test_from_int_to_decimal_1) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_INT_TO_DECIMAL |=========\033[0m");
  TCase *tc = tcase_create("tc_from_int_to_decimal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_int_to_decimal_0);
  tcase_add_test(tc, test_from_int_to_decimal_1);
  return s;
}