#include "./test.h"

START_TEST(test_negate_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  int sign_before = getSign(val);
  s21_negate(val, &res);
  int sign_after = getSign(res);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(test_negate_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  int sign_before = getSign(val);
  s21_negate(val, &res);
  int sign_after = getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(test_negate_2) {
  s21_decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  int sign_before = getSign(val);
  s21_negate(val, &res);
  int sign_after = getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(test_negate_3) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  int sign_before = getSign(val);
  s21_negate(val, &res);
  int sign_after = getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

Suite *test_negate(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_NEGATE |=========\033[0m");
  TCase *tc = tcase_create("tc_negate");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_negate_0);
  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);
  tcase_add_test(tc, test_negate_3);
  return s;
}