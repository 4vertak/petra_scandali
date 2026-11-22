#include "test.h"

static const double bases[] = {TEST_SPECIAL_VALUES,
                               -1,
                               1,
                               0.5,
                               -0.5,
                               2,
                               -2,
                               3,
                               -3,
                               4,
                               1e-20,
                               -1e-20,
                               0x1.fffffffffffffp-1,
                               0x1.0000000000001p0,
                               -0x1.0000000000001p0};
static const double exponents[] = {TEST_SPECIAL_VALUES,
                                   1,
                                   -1,
                                   2,
                                   -2,
                                   3,
                                   -3,
                                   0.5,
                                   -0.5,
                                   0.4,
                                   1.1,
                                   1e-16,
                                   0x1.fffffffffffffp0,
                                   64,
                                   -64,
                                   65,
                                   -65,
                                   1023,
                                   1024,
                                   -1074,
                                   -1075,
                                   -537.5,
                                   0x1.fffffffffffffp52,
                                   -0x1.fffffffffffffp52,
                                   0x1p53,
                                   0x1p63};

START_TEST(compare_pow) {
  double x = bases[_i / TEST_COUNT(exponents)];
  double y = exponents[_i % TEST_COUNT(exponents)];
  test_binary_value(s21_pow, pow, x, y, 0);
}
END_TEST

// A large exponent amplifies rounding errors in the logarithm of the base.
static const double precision_cases[][2] = {
    {0x1.5d6e38f67e07p0, -0x1.f54de7b352473p10},
    {0x1.88c8489d9881ap-1, 0x1.4c7ce49b9afa5p11},
    {0x1.4a3d55dff37f3p0, -0x1.3adff9b4533ffp11},
    {0x1.4b02d3cd30e9ep0, -0x1.4a2c48f675f2cp11},
    {0x1.4a99b49caf9e3p0, -0x1.49afc632b42a9p11},
    {0x1.4dbd1ea5af58p0, -0x1.31debdf20440cp11},
};

START_TEST(compare_pow_precision) {
  test_binary_value(s21_pow, pow, precision_cases[_i][0],
                    precision_cases[_i][1], 0);
}
END_TEST

Suite *test_pow(void) {
  Suite *suite =
      test_suite("pow", compare_pow, TEST_COUNT(bases) * TEST_COUNT(exponents));
  TCase *precision = tcase_create("precision");
  tcase_add_loop_test(precision, compare_pow_precision, 0,
                      TEST_COUNT(precision_cases));
  suite_add_tcase(suite, precision);
  return suite;
}
