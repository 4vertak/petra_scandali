#include "test.h"

static const double inputs[] = {
    TEST_SPECIAL_VALUES, TEST_ANGLES, 1.2, -4, 5, 0.79};

START_TEST(compare_sin) { test_unary_value(s21_sin, sin, inputs[_i], 0); }
END_TEST

Suite *test_sin(void) {
  return test_suite("sin", compare_sin, TEST_COUNT(inputs));
}
