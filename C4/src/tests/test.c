#include "test.h"

Suite *test_suite(const char *name, const TTest *test, int count) {
  Suite *suite = suite_create(name);
  TCase *cases = tcase_create(name);
  tcase_add_loop_test(cases, test, 0, count);
  suite_add_tcase(suite, cases);
  return suite;
}

static int test_matches(long double actual, double expected, int exact) {
  if (isnan(expected)) return isnan(actual);
  if (actual == expected) return !!signbit(actual) == !!signbit(expected);
  if (exact || !isfinite(actual) || !isfinite(expected) || actual == 0 ||
      expected == 0) {
    return 0;
  }
  // Allow one double ULP, including for subnormals and near DBL_MAX.
  double magnitude = fabs(expected);
  double nearest = nextafter(magnitude, INFINITY);
  double ulp = isinf(nearest) ? magnitude - nextafter(magnitude, 0)
                              : nearest - magnitude;
  return fabsl(actual - expected) <= ulp;
}

void test_unary_value(long double (*actual)(double),
                      double (*reference)(double), double x, int exact) {
  long double result = actual(x);
  double expected = reference(x);
  ck_assert_msg(test_matches(result, expected, exact),
                "x=%a: got %.21Lg, expected %.17g", x, result, expected);
}

void test_binary_value(long double (*actual)(double, double),
                       double (*reference)(double, double), double x, double y,
                       int exact) {
  long double result = actual(x, y);
  double expected = reference(x, y);
  ck_assert_msg(test_matches(result, expected, exact),
                "x=%a, y=%a: got %.21Lg, expected %.17g", x, y, result,
                expected);
}

int main(void) {
  Suite *suites[] = {test_abs(),    test_acos(), test_asin(), test_atan(),
                     test_ceil(),   test_cos(),  test_exp(),  test_fabs(),
                     test_floor(),  test_fmod(), test_log(),  test_pow(),
                     test_sin(),    test_sqrt(), test_tan(),  test_factorial(),
                     test_pow_int()};
  SRunner *runner = srunner_create(suites[0]);
  for (int i = 1; i < TEST_COUNT(suites); ++i) {
    srunner_add_suite(runner, suites[i]);
  }
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures ? EXIT_FAILURE : EXIT_SUCCESS;
}
