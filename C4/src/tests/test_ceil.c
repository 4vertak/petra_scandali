#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                0.9,
                                -0.1,
                                -1.9,
                                -1.1,
                                1,
                                -1,
                                1.1,
                                -1.125,
                                2147483648.25,
                                -2147483649.75,
                                0x1.fffffffffffffp51,
                                -0x1.fffffffffffffp51,
                                0x1p52,
                                -0x1p52};

START_TEST(compare_ceil) { test_unary_value(s21_ceil, ceil, inputs[_i], 1); }
END_TEST

Suite *test_ceil(void) {
  return test_suite("ceil", compare_ceil, TEST_COUNT(inputs));
}
