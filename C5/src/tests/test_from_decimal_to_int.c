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

START_TEST(test_from_decimal_to_int_7) {
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 1, 0}};
  return_value = s21_from_decimal_to_int(value_1, &temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_8) {
  int src = 0;
  int temp = 100;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_9) {
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {
      {0x80000000, 0, 0, 0}};  //??? граничное значение но пока нет переполнения
  return_value = s21_from_decimal_to_int(value_1, &temp);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_10) {
  int src = 133;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0x85, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_11) {
  s21_decimal value = {{49135648, 0, 0, 0}};
  set_sign(&value, 1);
  set_exp(&value, 1);
  int array;
  int check = -4913564;
  int return_value = s21_from_decimal_to_int(value, &array);
  ck_assert_int_eq(array, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_12) {
  s21_decimal value = {{49135648, 0, 0, 0}};
  set_exp(&value, 1);
  int array;
  int check = 4913564;
  int return_value = s21_from_decimal_to_int(value, &array);
  ck_assert_int_eq(array, check);
  ck_assert_int_eq(return_value, 0);
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
  tcase_add_test(tc, test_from_decimal_to_int_7);
  tcase_add_test(tc, test_from_decimal_to_int_8);
  tcase_add_test(tc, test_from_decimal_to_int_9);
  tcase_add_test(tc, test_from_decimal_to_int_10);
  tcase_add_test(tc, test_from_decimal_to_int_11);
  tcase_add_test(tc, test_from_decimal_to_int_12);

  return s;
}