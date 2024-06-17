#include "./test.h"

START_TEST(test_tan_1) {
  float x = 1.0 / 0.0;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_2) {
  float x = 1;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_3) {
  float x = 0;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_4) {
  float x = -2;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_5) {
  float x = 90;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_6) {
  float x = 120;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_7) {
  float x = -M_PI / 4.0;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_8) {
  float x = -120;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(test_tan_9) {
  float x = 0.79;
  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

Suite *test_tan(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_TAN  |=========\033[0m");
  TCase *tc = tcase_create("tan_tc");

  tcase_add_test(tc, test_tan_1);
  tcase_add_test(tc, test_tan_2);
  tcase_add_test(tc, test_tan_3);
  tcase_add_test(tc, test_tan_4);
  tcase_add_test(tc, test_tan_5);
  tcase_add_test(tc, test_tan_6);
  tcase_add_test(tc, test_tan_7);
  tcase_add_test(tc, test_tan_8);
  tcase_add_test(tc, test_tan_9);
  suite_add_tcase(s, tc);
  return s;
}