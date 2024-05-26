#include "./test.h"

START_TEST(test_from_int_to_decimal_0) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  // printf("res = %d\ntmp = %d\n", res, tmp);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(test_from_int_to_decimal_1) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  // printf("res = %d\ntmp = %d\n", res, tmp);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(test_from_int_to_decimal_2) {
  int src = -2147483647;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  return_value = s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);

  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_3) {
  int src = -0;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_4) {
  int src = 101;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_5) {
  int src = -31325;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_6) {
  int src = 49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_7) {
  int src = -49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_8) {
  int src = -49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_INT_TO_DECIMAL |=========\033[0m");
  TCase *tc = tcase_create("tc_from_int_to_decimal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_int_to_decimal_0);
  tcase_add_test(tc, test_from_int_to_decimal_1);
  tcase_add_test(tc, test_from_int_to_decimal_2);
  tcase_add_test(tc, test_from_int_to_decimal_3);
  tcase_add_test(tc, test_from_int_to_decimal_4);
  tcase_add_test(tc, test_from_int_to_decimal_5);
  tcase_add_test(tc, test_from_int_to_decimal_6);
  tcase_add_test(tc, test_from_int_to_decimal_7);
  tcase_add_test(tc, test_from_int_to_decimal_8);
  return s;
}