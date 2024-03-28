#include <time.h>

#include "./test.h"

START_TEST(test_atan_0) {
  double num = 10;
  for (long double i = 0.00000001; i < 10000; i = i * 3) {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    long double x = s21_atan(num);
    double y = atan(num);
    snprintf(str1, sizeof(str1), "%.6Lf", x);
    snprintf(str2, sizeof(str1), "%.6lf", y);
    ck_assert_str_eq(str1, str2);
    // ck_assert_ldouble_eq_tol(y, x, 0.000001);
    num -= i;
  }
}
END_TEST

START_TEST(test_atan_1) {
  srand(time(NULL));
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  size_t n = 10;

  double lb = 0;
  double ub = 0;

  int category = rand() % 100;
  if (category < 95) {
    lb = -10;
    ub = 10;
  } else if (category < 99) {
    lb = -1000;
    ub = 1000;
  } else {
    lb = -1e100;
    ub = 1e100;
  }

  for (size_t i = 0; i < n; i++) {
    double arg = lb + (rand() / (double)RAND_MAX) * (ub - lb);
    long double x = s21_atan(arg);
    double y = atan(arg);
    snprintf(str1, sizeof(str1), "%.14Lf", x);
    snprintf(str2, sizeof(str1), "%.14lf", y);
    ck_assert_str_eq(str1, str2);
    // ck_assert_ldouble_eq_tol(y, x, 0.000001);
  }
}
END_TEST

START_TEST(test_atan_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(NAN);
  snprintf(str1, sizeof(str1), "%.17Lf", x);
  snprintf(str2, sizeof(str1), "%.17lf", NAN);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_eq_tol(NAN, x, 0.000001);

  x = s21_atan(+INFINITY);
  snprintf(str1, sizeof(str1), "%.17Lf", x);
  snprintf(str2, sizeof(str1), "%.17lf", S21_M_PI_2);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_eq_tol( S21_M_PI_2, x, 0.000001);

  x = s21_atan(-INFINITY);
  snprintf(str1, sizeof(str1), "%.17Lf", x);
  snprintf(str2, sizeof(str1), "%.17lf", -S21_M_PI_2);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_eq_tol(-S21_M_PI_2, x, 0.000001);
}
END_TEST

START_TEST(test_atan_3) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(1.0);
  double y = atan(1.0);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_4) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-1);
  double y = atan(-1);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_5) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(314);
  double y = atan(314);
  snprintf(str1, sizeof(str1), "%16.6Lf", x);
  snprintf(str2, sizeof(str1), "%16.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_6) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-314);
  double y = atan(-314);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_7) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(3141592653);
  double y = atan(3141592653);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_8) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-3141592653);
  double y = atan(-3141592653);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_9) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(0.5);
  double y = atan(0.5);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_10) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-0.5);
  double y = atan(-0.5);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_11) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(2.5);
  double y = atan(2.5);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_12) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-2.5);
  double y = atan(-2.5);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_13) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(3141.592653589);
  double y = atan(3141.592653589);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_14) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-3141.592653589);
  double y = atan(-3141.592653589);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_15) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(1.0E-7);
  double y = atan(1.0E-7);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_16) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-1.0E-7);
  double y = atan(-1.0E-7);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_17) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(0.3425443513423432432432);
  double y = atan(0.3425443513423432432432);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_atan_18) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double x = s21_atan(-0.3425443513423432432432);
  double y = atan(-0.3425443513423432432432);
  snprintf(str1, sizeof(str1), "%.6Lf", x);
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