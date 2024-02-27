#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_strlen(void);
Suite *test_memset(void);
Suite *test_strncmp(void);
Suite *test_strchr(void);

#endif  // SRC_TESTS_TEST_H_