#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *test_memchr(void);
Suite *test_memcmp(void);

#endif  // SRC_TESTS_TEST_H_