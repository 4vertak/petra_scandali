#include "test.h"

static const double inputs[] = {
    TEST_SPECIAL_VALUES, TEST_ANGLES, -2, 0.79, 1, 90, 120, -120};

START_TEST(compare_tan) { test_unary_value(s21_tan, tan, inputs[_i], 0); }
END_TEST

Suite *test_tan(void) {
  return test_suite("tan", compare_tan, TEST_COUNT(inputs));
}
