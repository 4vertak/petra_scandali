#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                0.866025,
                                -0.866025,
                                0.707107,
                                -0.707107,
                                0.5,
                                -0.5,
                                0.1111,
                                -0.2,
                                0.66666,
                                -0.787,
                                -0.9,
                                0.9999999,
                                0x1.fffffffffffffp-1,
                                -0x1.fffffffffffffp-1,
                                1,
                                -1,
                                0x1.0000000000001p0,
                                -1.0011,
                                8};

START_TEST(compare_asin) { test_unary_value(s21_asin, asin, inputs[_i], 0); }
END_TEST

Suite *test_asin(void) {
  return test_suite("asin", compare_asin, TEST_COUNT(inputs));
}
