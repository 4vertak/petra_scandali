#include "./test.h"

START_TEST(s21_acos_0) {
  //     ck_assert_ldouble_eq_tol(s21_acos(1.000000), acos(1.000000), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.866025), acos(0.866025), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.707107), acos(0.707107), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.000000), acos(0.000000), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.500000), acos(-0.500000), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.707107), acos(-0.707107), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.866025), acos(-0.866025), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.866025), acos(-0.866025), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.707107), acos(-0.707107), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.000000), acos(-0.000000), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.500000), acos(0.500000), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.707107), acos(0.707107), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.866025), acos(0.866025), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.445738), acos(-0.445738), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.123456), acos(0.123456), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.123456), acos(-0.123456), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.00001), acos(0.00001), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.7), acos(0.7), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.85), acos(0.85), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(0.99999991), acos(0.99999991), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.9), acos(-0.9), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.69), acos(-0.69), 1e-6);
  //     ck_assert_ldouble_eq_tol(s21_acos(-0.2), acos(-0.2), 1e-6);
  //     ck_assert_ldouble_nan(s21_acos(10000));;
  //     ck_assert_ldouble_nan(s21_acos(-1.0011));
  // }
  double testcases[] = {1.000000,  0.866025,   0.707107,  0.000000,  -0.500000,
                        -0.866025, -0.707107,  -0.000000, -0.445738, 0.123456,
                        -0.123456, 0,          0.00001,   0.5,       0.7,
                        0.85,      0.99999991, 1,         -1,        -0.9,
                        -0.69,     -0.2,       10000,     -1.0011,   0.9999995};
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; i++) {
    long double result = s21_acos(testcases[i]);
    double expected = acos(testcases[i]);
    snprintf(str1, sizeof(str1), "%.6Lf", result);
    snprintf(str2, sizeof(str1), "%.6lf", expected);
    ck_assert_str_eq(str1, str2);
    // ck_assert_ldouble_eq_tol(expected, result, 0.000001);
  }
}
END_TEST

START_TEST(s21_acos_1) {
  srand(time(NULL));

  size_t n = 10;
  double lowerBorder = -1;
  double upperBorder = 1;
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  for (size_t i = 0; i < n; i++) {
    double arg =
        lowerBorder + (rand() / (double)RAND_MAX) * (upperBorder - lowerBorder);
    long double result = s21_acos(arg);
    double expected = acos(arg);
    snprintf(str1, sizeof(str1), "%.6Lf", result);
    snprintf(str2, sizeof(str1), "%.6lf", expected);
    ck_assert_str_eq(str1, str2);
    // ck_assert_ldouble_eq_tol(expected, result, 0.000001);
  }
}
END_TEST

START_TEST(s21_acos_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double result = s21_acos(NAN);
  double expected = acos(NAN);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_acos(+INFINITY);
  expected = acos(+INFINITY);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_acos(-INFINITY);
  expected = acos(-INFINITY);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_acos(-8);
  expected = acos(-8);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);

  result = s21_acos(1.0000000001);
  expected = acos(1.0000000001);
  snprintf(str1, sizeof(str1), "%.17Lf", result);
  snprintf(str2, sizeof(str1), "%.17lf", expected);
  ck_assert_str_eq(str1, str2);
  // ck_assert_ldouble_nan(result);
}
END_TEST

Suite *test_acos(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21ACOS |=========\033[0m");
  TCase *tc = tcase_create("acos_tc");
  tcase_add_test(tc, s21_acos_0);
  tcase_add_test(tc, s21_acos_1);
  tcase_add_test(tc, s21_acos_2);
  suite_add_tcase(s, tc);
  return s;
}