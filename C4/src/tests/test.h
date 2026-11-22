#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

#define TEST_COUNT(a) ((int)(sizeof(a) / sizeof((a)[0])))
#define TEST_SPECIAL_VALUES                                             \
  0.0, -0.0, INFINITY, -INFINITY, NAN, DBL_MIN, -DBL_MIN, DBL_TRUE_MIN, \
      -DBL_TRUE_MIN, DBL_MAX, -DBL_MAX
#define TEST_ANGLES                                                        \
  S21_M_PI_4, -S21_M_PI_4, 0x1.921fb54442d19p-1, S21_M_PI_2, -S21_M_PI_2,  \
      0x1.921fb54442d17p0, 0x1.921fb54442d19p0, S21_M_PI, -S21_M_PI,       \
      2 * S21_M_PI, 3 * S21_M_PI_2, -3 * S21_M_PI_2, S21_M_PI / 6,         \
      -S21_M_PI / 6, 0x1p21, -0x1p40, 1e20, -1e100, 0x1.23456789abcdep512, \
      1e300

Suite *test_suite(const char *name, const TTest *test, int count);
void test_unary_value(long double (*actual)(double),
                      double (*reference)(double), double x, int exact);
void test_binary_value(long double (*actual)(double, double),
                       double (*reference)(double, double), double x, double y,
                       int exact);

Suite *test_abs(void);
Suite *test_acos(void);
Suite *test_asin(void);
Suite *test_atan(void);
Suite *test_ceil(void);
Suite *test_cos(void);
Suite *test_exp(void);
Suite *test_fabs(void);
Suite *test_floor(void);
Suite *test_fmod(void);
Suite *test_log(void);
Suite *test_pow(void);
Suite *test_sin(void);
Suite *test_sqrt(void);
Suite *test_tan(void);
Suite *test_factorial(void);
Suite *test_pow_int(void);

#endif  // SRC_TESTS_TEST_H_
