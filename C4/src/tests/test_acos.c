#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                0.866025,
                                -0.866025,
                                0.707107,
                                -0.707107,
                                0.5,
                                -0.5,
                                0.7,
                                0.85,
                                -0.69,
                                -0.9,
                                0.123456,
                                -0.123456,
                                0.99999991,
                                0.9999995,
                                0x1.fffffffffffffp-1,
                                -0x1.fffffffffffffp-1,
                                1,
                                -1,
                                0x1.0000000000001p0,
                                -1.0011,
                                8};

START_TEST(compare_acos) { test_unary_value(s21_acos, acos, inputs[_i], 0); }
END_TEST

Suite *test_acos(void) {
  return test_suite("acos", compare_acos, TEST_COUNT(inputs));
}
