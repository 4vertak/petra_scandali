#include "./test.h"

START_TEST(s21_asin_0) {
  // ck_assert_ldouble_eq_tol(s21_asin(1.000000), asin(1.000000), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.866025), asin(0.866025), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.707107), asin(0.707107), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.000000), asin(0.000000), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.500000), asin(-0.500000), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.707107), asin(-0.707107), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.866025), asin(-0.866025), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-1.000000), asin(-1.000000), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.866025), asin(-0.866025), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.707107), asin(-0.707107), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.000000), asin(-0.000000), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.500000), asin(0.500000), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.866025), asin(0.866025), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.445738), asin(-0.445738), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.123456), asin(0.123456), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.123456), asin(-0.123456), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.1111), asin(0.1111), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.7), asin(0.7), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.85), asin(0.85), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.9999999), asin(0.9999999), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.2), asin(-0.2), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(0.66666), asin(0.66666), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.787), asin(-0.787), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-0.9), asin(-0.9), 1e-6);
  // ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  // ck_assert_ldouble_nan(s21_asin(10));
  // ck_assert_ldouble_nan(s21_asin(-1.0011));
  double testcases[] = {1.000000,  0.866025,  0.707107,  0.000000,  -0.500000,
                        -0.866025, -0.707107, -0.000000, -0.445738, 0.123456,
                        -0.123456, 0,         0.1111,    0.5,       0.7,
                        0.85,      0.9999999, 1,         -1,        -0.2,
                        -0.66666,  -0.787,    -0.9,      -1,        10,
                        -1.0011};
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; i++) {
    long double result = s21_asin(testcases[i]);
    double expected = asin(testcases[i]);
    snprintf(str1, sizeof(str1), "%.6Lf", result);
    snprintf(str2, sizeof(str1), "%.6lf", expected);
    ck_assert_str_eq(str1, str2);
    // ck_assert_ldouble_eq_tol(expected, result, 0.000001);
  }
}
END_TEST

START_TEST(s21_asin_1) {
  srand(time(NULL));

  size_t n = 10;
  double lowerBorder = -1;
  double upperBorder = 1;
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  for (size_t i = 0; i < n; i++) {
    double arg =
        lowerBorder + (rand() / (double)RAND_MAX) * (upperBorder - lowerBorder);
    long double result = s21_asin(arg);
    double expected = asin(arg);
    snprintf(str1, sizeof(str1), "%.6Lf", result);
    snprintf(str2, sizeof(str1), "%.6lf", expected);
    ck_assert_str_eq(str1, str2);
    // ck_assert_ldouble_eq_tol(expected, result, 0.000001);
  }
}
END_TEST

START_TEST(s21_asin_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double result = s21_asin(NAN);
  double expected = asin(NAN);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_asin(+INFINITY);
  expected = asin(+INFINITY);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_asin(-INFINITY);
  expected = asin(-INFINITY);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_asin(-8);
  expected = asin(-8);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_asin(1.0000000001);
  expected = asin(1.0000000001);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);
}
END_TEST

Suite *test_asin(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21ASIN |=========\033[0m");
  TCase *tc = tcase_create("asin_tc");

  tcase_add_test(tc, s21_asin_0);
  tcase_add_test(tc, s21_asin_1);
  tcase_add_test(tc, s21_asin_2);
  suite_add_tcase(s, tc);
  return s;
}