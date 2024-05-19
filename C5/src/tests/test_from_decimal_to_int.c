#include "./test.h"

START_TEST(test_from_decimal_to_int_0) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_exp(&val, 5);
  int res = 1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(test_from_decimal_to_int_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_bit(&val, 127, 1);
  set_exp(&val, 5);
  int res = -1234;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(test_from_decimal_to_int_2) {
  s21_decimal value = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_int_to_decimal(res, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);

  s21_from_decimal_to_int(value, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
  ck_assert_int_eq(*dst, res);
}
END_TEST
START_TEST(test_from_decimal_to_int_3) {
  s21_decimal value = {{0, 0, 0, 0}};
  int res = -128;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_int_to_decimal(res, &value);
  ck_assert_int_eq(value.bits[0], 128);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 2147483648);

  s21_from_decimal_to_int(value, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
  ck_assert_int_eq(*dst, res);
}
END_TEST
START_TEST(test_from_decimal_to_int_4) {
  s21_decimal value = {{0, 0, 0, 0}};
  int res = 127;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_int_to_decimal(res, &value);
  ck_assert_int_eq(value.bits[0], 127);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);

  s21_from_decimal_to_int(value, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
  ck_assert_int_eq(*dst, res);
}
END_TEST
START_TEST(test_from_decimal_to_int_5) {
  s21_decimal value = {{0, 0, 0, 0}};
  int res = -2147483648;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_int_to_decimal(res, &value);
  ck_assert_int_eq(value.bits[0], 2147483648);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 2147483648);

  s21_from_decimal_to_int(value, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
  ck_assert_int_eq(*dst, res);
}
END_TEST
START_TEST(test_from_decimal_to_int_6) {
  s21_decimal value = {{0, 0, 0, 0}};
  int res = 2147483647;
  int tmp = 0.;
  int *dst = &tmp;
  s21_from_int_to_decimal(2147483647, &value);
  ck_assert_int_eq(value.bits[0], 2147483647);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);

  s21_from_decimal_to_int(value, dst);
  // printf("dst = %d\ntmp = %d\n", *dst, res);
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
  tcase_add_test(tc, test_from_decimal_to_int_2);
  tcase_add_test(tc, test_from_decimal_to_int_3);
  tcase_add_test(tc, test_from_decimal_to_int_4);
  tcase_add_test(tc, test_from_decimal_to_int_5);
  tcase_add_test(tc, test_from_decimal_to_int_6);

  return s;
}