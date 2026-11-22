#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                -253,
                                -1,
                                0x0.fffffffffffffp-1022,
                                0x1.fffffffffffffp-1,
                                0.25,
                                0.5,
                                1,
                                2,
                                3.14159,
                                4,
                                25,
                                143,
                                1e-200,
                                1e200};

START_TEST(compare_sqrt) { test_unary_value(s21_sqrt, sqrt, inputs[_i], 0); }
END_TEST

Suite *test_sqrt(void) {
  return test_suite("sqrt", compare_sqrt, TEST_COUNT(inputs));
}
