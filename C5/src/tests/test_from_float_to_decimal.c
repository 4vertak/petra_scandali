#include "./test.h"

START_TEST(test_from_float_to_decimal_0) {
  s21_decimal val = {{0, 0, 0, 0}};
  float res = 0.;
  float tmp = -1234.56789;
  s21_from_float_to_decimal(tmp, &val);
  printf(" ");
  s21_from_decimal_to_float(val, &res);
  ck_assert_float_eq(res, tmp);
}
END_TEST

START_TEST(test_from_float_to_decimal_1) {
  s21_decimal val = {{0, 0, 0, 0}};
  float res = 0.;
  float tmp = 1234.56789;
  s21_from_float_to_decimal(tmp, &val);
  printf(" ");
  s21_from_decimal_to_float(val, &res);
  ck_assert_float_eq(res, tmp);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_FLOAT_TO_DECIMAL |=========\033[0m");
  TCase *tc = tcase_create("tc_from_float_to_decimal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_float_to_decimal_0);
  tcase_add_test(tc, test_from_float_to_decimal_1);
  return s;
}