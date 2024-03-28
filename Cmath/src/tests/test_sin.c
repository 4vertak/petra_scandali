#include "./test.h"

START_TEST(test_sin_1) {
  float x = 1.0 / 0.0;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_2) {
  float x = 1.2;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_3) {
  float x = -4;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_4) {
  float x = 5;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_5) {
  float x = M_PI / 2.0;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_6) {
  float x = -M_PI / 6.0;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_7) {
  float x = -M_PI / 4.0;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_8) {
  float x = -M_PI / 2.0;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(test_sin_9) {
  float x = 0.79;
  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

Suite *test_sin(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_SIN  |=========\033[0m");
  TCase *tc = tcase_create("sin_tc");

  tcase_add_test(tc, test_sin_1);
  tcase_add_test(tc, test_sin_2);
  tcase_add_test(tc, test_sin_3);
  tcase_add_test(tc, test_sin_4);
  tcase_add_test(tc, test_sin_5);
  tcase_add_test(tc, test_sin_6);
  tcase_add_test(tc, test_sin_7);
  tcase_add_test(tc, test_sin_8);
  tcase_add_test(tc, test_sin_9);
  suite_add_tcase(s, tc);
  return s;
}