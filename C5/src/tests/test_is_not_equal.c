#include "./test.h"

START_TEST(test_is_not_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 127, 1);
  setBit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val2, 3, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val2, 127, 1);
  setBit(&val1, 33, 1);
  setBit(&val2, 33, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 3, 1);
  setBit(&val2, 3, 1);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 3, 1);
  setBit(&val2, 4, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setScale(&val1, 3);
  setScale(&val2, 3);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setBit(&val1, 3, 1);
  setBit(&val2, 4, 1);
  setScale(&val1, 3);
  setScale(&val2, 3);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_7) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  setScale(&val1, 3);
  setScale(&val2, 2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(test_is_not_equal_8) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_IS_NOT_EQUAL |=========\033[0m");
  TCase *tc = tcase_create("tc_is_not_equal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_is_not_equal_0);
  tcase_add_test(tc, test_is_not_equal_1);
  tcase_add_test(tc, test_is_not_equal_2);
  tcase_add_test(tc, test_is_not_equal_3);
  tcase_add_test(tc, test_is_not_equal_4);
  tcase_add_test(tc, test_is_not_equal_5);
  tcase_add_test(tc, test_is_not_equal_6);
  tcase_add_test(tc, test_is_not_equal_7);
  tcase_add_test(tc, test_is_not_equal_8);
  return s;
}