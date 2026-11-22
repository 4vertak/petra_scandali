#include "test.h"

static const double dividends[] = {TEST_SPECIAL_VALUES,
                                   1,
                                   -1,
                                   314,
                                   -314,
                                   314159,
                                   -314159.2,
                                   0.7,
                                   -0.7,
                                   1.5,
                                   -1.5,
                                   1570.796326,
                                   -1570.796326,
                                   3,
                                   -3,
                                   0.34254435134234324,
                                   -0.34254435134234324,
                                   0.3,
                                   0.1,
                                   -3.1,
                                   0.5,
                                   S21_M_PI,
                                   1e-7,
                                   -1e-7,
                                   0x1.0000000000001p64,
                                   0x0.0000000000003p-1022};
static const double divisors[] = {
    TEST_SPECIAL_VALUES, 3, -3, 2.5, -2.5, 1e-200, 0x0.0000000000003p-1022};

START_TEST(compare_fmod) {
  double x = dividends[_i / TEST_COUNT(divisors)];
  double y = divisors[_i % TEST_COUNT(divisors)];
  test_binary_value(s21_fmod, fmod, x, y, 1);
}
END_TEST

Suite *test_fmod(void) {
  return test_suite("fmod", compare_fmod,
                    TEST_COUNT(dividends) * TEST_COUNT(divisors));
}
