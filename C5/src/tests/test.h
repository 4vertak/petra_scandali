#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3
#define NUM_RANDOM_TEST 25

typedef union float_cast_test {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } parts;
  uint32_t bytes;
  int int32_bytes;
} float_cast_test;

typedef union test_decimal_bytes {
  struct s21_decimal d;
  struct {
    uint32_t part0;
    uint32_t part1;
    uint32_t part2;
    uint32_t empty2 : 16;
    uint32_t power : 8;
    uint32_t empty1 : 7;
    uint32_t sign : 1;
  } parts;
} test_decimal_bytes;

// Арифметические операторы:
Suite *test_ad(void);
Suite *test_sub(void);
Suite *test_mul(void);
Suite *test_div(void);

// Операторы сравнение:
Suite *test_is_less(void);
Suite *test_is_less_or_equal(void);
Suite *test_is_greater(void);
Suite *test_is_greater_or_equal(void);
Suite *test_is_equal(void);
Suite *test_is_not_equal(void);

// // Преобразователи:
Suite *test_from_int_to_decimal(void);
Suite *test_from_float_to_decimal(void);
Suite *test_from_decimal_to_int(void);
Suite *test_from_decimal_to_float(void);

// // // Другие функции:
Suite *test_floor(void);
Suite *test_round(void);
Suite *test_truncate(void);
Suite *test_negate(void);

int s21_random_int(int min, int max);

int test_decimal_is_full_equal(s21_decimal value_1, s21_decimal value_2);

#endif  // SRC_TESTS_TEST_H_