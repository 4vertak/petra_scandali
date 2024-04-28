#include "./test.h"

START_TEST(test_is_greater_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 11);
  setScale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 10);
  setScale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(test_is_greater_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

Suite *test_is_greater(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_IS_GREATER |=========\033[0m");
  TCase *tc = tcase_create("tc_is_greater");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_is_greater_0);
  tcase_add_test(tc, test_is_greater_1);
  tcase_add_test(tc, test_is_greater_2);
  tcase_add_test(tc, test_is_greater_3);
  tcase_add_test(tc, test_is_greater_4);
  tcase_add_test(tc, test_is_greater_5);
  tcase_add_test(tc, test_is_greater_6);
  tcase_add_test(tc, test_is_greater_7);
  tcase_add_test(tc, test_is_greater_8);
  return s;
}