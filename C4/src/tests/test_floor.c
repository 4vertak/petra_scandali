#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                -0.1,
                                0.1,
                                -1,
                                1,
                                -1.1,
                                1.1,
                                2147483648.25,
                                -2147483649.75,
                                0x1.fffffffffffffp51,
                                -0x1.fffffffffffffp51,
                                0x1p52,
                                -0x1p52};

START_TEST(compare_floor) { test_unary_value(s21_floor, floor, inputs[_i], 1); }
END_TEST

Suite *test_floor(void) {
  return test_suite("floor", compare_floor, TEST_COUNT(inputs));
}
