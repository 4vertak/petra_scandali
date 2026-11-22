#include "test.h"

static const double inputs[] = {
    TEST_SPECIAL_VALUES, TEST_ANGLES, 1.1, -1.1, 10.1, -10.1};

START_TEST(compare_cos) { test_unary_value(s21_cos, cos, inputs[_i], 0); }
END_TEST

Suite *test_cos(void) {
  return test_suite("cos", compare_cos, TEST_COUNT(inputs));
}
