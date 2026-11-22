#include <limits.h>

#include "test.h"

static const long long inputs[] = {-1, 0, 1, 2, 3, 8, 12, LLONG_MAX};

START_TEST(compare_factorial) {
  long long x = inputs[_i];
  if (x < 0 || x == LLONG_MAX) {
    ck_assert(s21_factorial(x) == INFINITY);
  } else {
    ck_assert_ldouble_eq_tol(s21_factorial(x), tgammal(x + 1), 1e-8L);
  }
}
END_TEST

Suite *test_factorial(void) {
  return test_suite("factorial", compare_factorial, TEST_COUNT(inputs));
}
