#include "./test.h"

START_TEST(test_from_int_to_decimal_fail1) {
  int number = -2147483648;
  int result = s21_from_int_to_decimal(number, NULL);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok1) {
  int number = -2147483648;
  // Converted the Int32 value -2147483648 to the Decimal value -2147483648.
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok2) {
  int number = -2147483647;
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok3) {
  int number = -214748364;
  // Converted the Int32 value -214748364 to the Decimal value -214748364.
  s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok4) {
  int number = -214748;
  // Converted the Int32 value -214748 to the Decimal value -214748.
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok5) {
  int number = -1000;
  // Converted the Int32 value -1000 to the Decimal value -1000.
  s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok6) {
  int number = -1;
  // Converted the Int32 value -1 to the Decimal value -1.
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok7) {
  int number = 0;
  // Converted the Int32 value 0 to the Decimal value 0.
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok8) {
  int number = 1;
  // Converted the Int32 value 1 to the Decimal value 1.
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok9) {
  int number = 1000;
  // Converted the Int32 value 1000 to the Decimal value 1000.
  s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok10) {
  int number = 214748;
  // Converted the Int32 value 214748 to the Decimal value 214748.
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok11) {
  int number = 214748364;
  // Converted the Int32 value 214748364 to the Decimal value 214748364.
  s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok12) {
  int number = 2147483646;
  // Converted the Int32 value 2147483646 to the Decimal value 2147483646.
  s21_decimal decimal_check = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok13) {
  int number = 2147483647;
  // Converted the Int32 value 2147483647 to the Decimal value 2147483647.
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  int sign_check = get_sign(decimal_check);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_int_to_decimal_ok_random1) {
  int num = s21_random_int(1, INT_MAX - 1);
  s21_decimal decimal_check1 = {{num, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int code = s21_from_int_to_decimal(num, &result);
  int sign_check = get_sign(decimal_check1);
  int sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check1), 1);
  ck_assert_int_eq(sign_check, sign_result);

  s21_decimal decimal_check2 = {{num, 0x0, 0x0, 0x80000000}};

  code = s21_from_int_to_decimal(-num, &result);
  sign_check = get_sign(decimal_check2);
  sign_result = get_sign(result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check2), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_INT_TO_DECIMAL |=========\033[0m");
  TCase *tc = tcase_create("tc_from_int_to_decimal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_int_to_decimal_fail1);

  tcase_add_test(tc, test_from_int_to_decimal_ok1);
  tcase_add_test(tc, test_from_int_to_decimal_ok2);
  tcase_add_test(tc, test_from_int_to_decimal_ok3);
  tcase_add_test(tc, test_from_int_to_decimal_ok4);
  tcase_add_test(tc, test_from_int_to_decimal_ok5);
  tcase_add_test(tc, test_from_int_to_decimal_ok6);
  tcase_add_test(tc, test_from_int_to_decimal_ok7);
  tcase_add_test(tc, test_from_int_to_decimal_ok8);
  tcase_add_test(tc, test_from_int_to_decimal_ok9);
  tcase_add_test(tc, test_from_int_to_decimal_ok10);
  tcase_add_test(tc, test_from_int_to_decimal_ok11);
  tcase_add_test(tc, test_from_int_to_decimal_ok12);
  tcase_add_test(tc, test_from_int_to_decimal_ok13);

  tcase_add_loop_test(tc, test_from_int_to_decimal_ok_random1, 0,
                      NUM_RANDOM_TEST);

  return s;
}

int s21_random_int(int min, int max) {
  if (min < 0) {
    min = 0;
  }
  if (max < 0) {
    max = -max;
  }
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}