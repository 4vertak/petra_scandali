#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                1,
                                -1,
                                S21_M_PI,
                                -S21_M_PI,
                                314,
                                -314,
                                1e-7,
                                -1e-7,
                                -0.5,
                                1.5,
                                -1.5,
                                1234.567891,
                                -1234.567891,
                                -0.1,
                                S21_M_PI_2,
                                -S21_M_PI_2};

START_TEST(compare_fabs) { test_unary_value(s21_fabs, fabs, inputs[_i], 1); }
END_TEST

Suite *test_fabs(void) {
  return test_suite("fabs", compare_fabs, TEST_COUNT(inputs));
}
