#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                0.34254435134234324,
                                -0.34254435134234324,
                                0.4142135623730950,
                                0.4142135623730951,
                                0.5,
                                -0.5,
                                0x1.fffffffffffffp-1,
                                -0x1.fffffffffffffp-1,
                                1,
                                -1,
                                0x1.0000000000001p0,
                                -0x1.0000000000001p0,
                                2.5,
                                -2.5,
                                314,
                                -314,
                                3141.592653589,
                                -3141.592653589,
                                3141592653,
                                -3141592653,
                                1e-7,
                                -1e-7};

START_TEST(compare_atan) { test_unary_value(s21_atan, atan, inputs[_i], 0); }
END_TEST

Suite *test_atan(void) {
  return test_suite("atan", compare_atan, TEST_COUNT(inputs));
}
