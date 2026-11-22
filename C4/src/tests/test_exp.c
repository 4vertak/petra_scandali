#include "test.h"

static const double inputs[] = {TEST_SPECIAL_VALUES,
                                -747,
                                -746,
                                -745.2,
                                -745,
                                -744,
                                -710,
                                -709,
                                -10,
                                -1,
                                -0.5,
                                -1e-16,
                                1e-16,
                                0.5,
                                1,
                                10,
                                100,
                                709,
                                709.782712893384,
                                0x1.62e42fefa39f0p9,
                                710,
                                25048.369};

START_TEST(compare_exp) { test_unary_value(s21_exp, exp, inputs[_i], 0); }
END_TEST

Suite *test_exp(void) {
  return test_suite("exp", compare_exp, TEST_COUNT(inputs));
}
