#include "./test.h"

START_TEST(test_from_decimal_to_float_0) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  // setScale(&val, 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(test_from_decimal_to_float_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  setBit(&val, 127, 1);
  // setScale(&val, 5);
  float res = -1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_DECIMAL_TO_FLOAT |=========\033[0m");
  TCase *tc = tcase_create("tc_from_decimal_to_float");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_decimal_to_float_0);
  tcase_add_test(tc, test_from_decimal_to_float_1);
  return s;
}