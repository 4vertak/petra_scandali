#include <limits.h>

#include "test.h"

static const int inputs[] = {0,     1,       -1,       314,    -314,
                             -1234, INT_MAX, -INT_MAX, INT_MIN};

START_TEST(compare_abs) {
  int x = inputs[_i];
  // The magnitude of INT_MIN is unrepresentable. The project returns INT_MIN.
  int expected = x == INT_MIN ? INT_MIN : abs(x);
  ck_assert_int_eq(s21_abs(x), expected);
}
END_TEST

Suite *test_abs(void) {
  return test_suite("abs", compare_abs, TEST_COUNT(inputs));
}
