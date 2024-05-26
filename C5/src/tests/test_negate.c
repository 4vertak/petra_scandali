#include "./test.h"

START_TEST(test_negate_1) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_negate_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src = {0};
  s21_from_float_to_decimal(a, &src);
  s21_decimal res = {0};
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  snprintf(str1, sizeof(str1), "%.28lf", -10.1234e5);
  snprintf(str2, sizeof(str2), "%.28lf", res_a);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_negate_3) {
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(value_1, result), 1);
}
END_TEST

START_TEST(test_negate_4) {
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_2), 1);
}
END_TEST

START_TEST(test_negate_5) {
  s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
  s21_decimal result;
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_negate_6) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_negate_7) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_from_float_to_decimal(a, &src);
  s21_decimal res;
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_int_eq(-10.1234e5, res_a);
}
END_TEST

Suite *test_negate(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_NEGATE |=========\033[0m");
  TCase *tc = tcase_create("tc_negate");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);
  tcase_add_test(tc, test_negate_3);
  tcase_add_test(tc, test_negate_4);
  tcase_add_test(tc, test_negate_5);
  tcase_add_test(tc, test_negate_6);
  tcase_add_test(tc, test_negate_7);

  return s;
}