#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

Suite *test_abs(void);
Suite *test_fabs(void);
Suite *test_fmod(void);
Suite *test_asin(void);
Suite *test_acos(void);
Suite *test_atan(void);

#endif  // SRC_TESTS_TEST_H_