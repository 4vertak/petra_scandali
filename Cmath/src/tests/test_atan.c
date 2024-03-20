#include "./test.h"

START_TEST(test_atan_0) {
  double num = 10;
  for (long double i = 0.00000001; i < 10000; i = i * 3) {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    double x = s21_atan(num);
    double y = atan(num);
    snprintf(str1, sizeof(str1), "%.6lf", x);
    snprintf(str2, sizeof(str1), "%.6lf", y);
    ck_assert_str_eq(str1, str2);
    num -= i;
  }
}
END_TEST

START_TEST(test_atan_1) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(0);
  double y = atan(0);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-0);
  double y = atan(-0);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_3) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(1.0);
  double y = atan(1.0);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_4) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-1);
  double y = atan(-1);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_5) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(314);
  double y = atan(314);
  snprintf(str1, sizeof(str1), "%16.6lf", x);
  snprintf(str2, sizeof(str1), "%16.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_6) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-314);
  double y = atan(-314);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_7) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(3141592653);
  double y = atan(3141592653);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_8) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-3141592653);
  double y = atan(-3141592653);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_9) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(0.5);
  double y = atan(0.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_10) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-0.5);
  double y = atan(-0.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_11) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(2.5);
  double y = atan(2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_12) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-2.5);
  double y = atan(-2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_13) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(3141.592653589);
  double y = atan(3141.592653589);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_14) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-3141.592653589);
  double y = atan(-3141.592653589);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_15) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(1.0E-7);
  double y = atan(1.0E-7);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_16) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-1.0E-7);
  double y = atan(-1.0E-7);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_17) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(0.3425443513423432432432);
  double y = atan(0.3425443513423432432432);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_18) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  double x = s21_atan(-0.3425443513423432432432);
  double y = atan(-0.3425443513423432432432);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_atan(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ATAN |=========\033[0m");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, test_atan_0);
  tcase_add_test(tc, test_atan_1);
  tcase_add_test(tc, test_atan_2);
  tcase_add_test(tc, test_atan_3);
  tcase_add_test(tc, test_atan_4);
  tcase_add_test(tc, test_atan_5);
  tcase_add_test(tc, test_atan_6);
  tcase_add_test(tc, test_atan_7);
  tcase_add_test(tc, test_atan_8);
  tcase_add_test(tc, test_atan_9);
  tcase_add_test(tc, test_atan_10);
  tcase_add_test(tc, test_atan_11);
  tcase_add_test(tc, test_atan_12);
  tcase_add_test(tc, test_atan_13);
  tcase_add_test(tc, test_atan_14);
  tcase_add_test(tc, test_atan_15);
  tcase_add_test(tc, test_atan_16);
  tcase_add_test(tc, test_atan_17);
  tcase_add_test(tc, test_atan_18);

  suite_add_tcase(s, tc);
  return s;
}