#include "./test.h"

START_TEST(test_is_less_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 11);
  setScale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  setScale(&val1, 10);
  setScale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 1);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 1);
  setBit(&val1, 83, 1);
  setScale(&val1, 12);
  setScale(&val2, 11);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_9) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 1);
  setBit(&val1, 83, 1);
  setBit(&val2, 83, 1);
  setScale(&val1, 10);
  setScale(&val2, 11);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_10) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 1);
  setBit(&val1, 83, 1);
  setScale(&val1, 10);
  setScale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_11) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 0);
  setBit(&val1, 83, 1);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_12) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

Suite *test_is_less(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_IS_LESS |=========\033[0m");
  TCase *tc = tcase_create("tc_is_less");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_is_less_0);
  tcase_add_test(tc, test_is_less_1);
  tcase_add_test(tc, test_is_less_2);
  tcase_add_test(tc, test_is_less_3);
  tcase_add_test(tc, test_is_less_4);
  tcase_add_test(tc, test_is_less_5);
  tcase_add_test(tc, test_is_less_6);
  tcase_add_test(tc, test_is_less_7);
  tcase_add_test(tc, test_is_less_8);
  tcase_add_test(tc, test_is_less_9);
  tcase_add_test(tc, test_is_less_10);
  tcase_add_test(tc, test_is_less_11);
  tcase_add_test(tc, test_is_less_12);
  return s;
}