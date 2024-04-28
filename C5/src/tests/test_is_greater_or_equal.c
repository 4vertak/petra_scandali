#include "./test.h"

START_TEST(test_is_greater_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 11);
  setScale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 10);
  setScale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_greater_or_equal_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

Suite *test_is_greater_or_equal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_IS_GREATER_OR_EQUAL |=========\033[0m");
  TCase *tc = tcase_create("tc_is_greater_or_equal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_is_greater_or_equal_0);
  tcase_add_test(tc, test_is_greater_or_equal_1);
  tcase_add_test(tc, test_is_greater_or_equal_2);
  tcase_add_test(tc, test_is_greater_or_equal_3);
  tcase_add_test(tc, test_is_greater_or_equal_4);
  tcase_add_test(tc, test_is_greater_or_equal_5);
  tcase_add_test(tc, test_is_greater_or_equal_6);
  tcase_add_test(tc, test_is_greater_or_equal_7);
  return s;
}