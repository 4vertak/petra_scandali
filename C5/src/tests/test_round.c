#include "./test.h"

START_TEST(test_round_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_round_1) {
  s21_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_2) {
  s21_decimal val = {{3, 3, 3, 0}};
  s21_decimal res = {0};
  setScale(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_3) {
  s21_decimal val = {{7, 7, 7, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  setScale(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_4) {
  s21_decimal val = {{25, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_5) {
  s21_decimal val = {{26, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_6) {
  s21_decimal val = {{115, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_7) {
  s21_decimal val = {{118, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_8) {
  s21_decimal val = {{125, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_9) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  setScale(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 13;
  ck_assert_float_eq(need, fres);
}
END_TEST

Suite *test_round(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_ROUND |=========\033[0m");
  TCase *tc = tcase_create("tc_round");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_round_0);
  tcase_add_test(tc, test_round_1);
  tcase_add_test(tc, test_round_2);
  tcase_add_test(tc, test_round_3);
  tcase_add_test(tc, test_round_4);
  tcase_add_test(tc, test_round_5);
  tcase_add_test(tc, test_round_6);
  tcase_add_test(tc, test_round_7);
  tcase_add_test(tc, test_round_8);
  tcase_add_test(tc, test_round_9);
  return s;
}