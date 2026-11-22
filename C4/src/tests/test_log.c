#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                -1,
                                1,
                                0x1.fffffffffffffp-1,
                                0x1.0000000000001p0,
                                0.5,
                                2,
                                1.414213562373095,
                                1.4142135623730951,
                                1e-250,
                                1e250,
                                0.123456,
                                0.1234567891,
                                0.987451,
                                0.215488,
                                S21_EXP,
                                35,
                                707107,
                                987565.9874641214,
                                123456789};

START_TEST(compare_log) { test_unary_value(s21_log, log, inputs[_i], 0); }
END_TEST

Suite *test_log(void) {
  return test_suite("log", compare_log, TEST_COUNT(inputs));
}
