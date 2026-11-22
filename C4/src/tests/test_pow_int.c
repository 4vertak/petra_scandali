#include <limits.h>

#include "test.h"

static const struct {
  double base;
  long long exponent;
} inputs[] = {
    {2, -1},
    {2, 10},
    {-3, 5},
    {-3, 4},
    {-2, -3},
    {NAN, 0},
    {NAN, 65},
    {-0.0, -3},
    {-0.0, -2},
    {0.0, -2},
    {-0.0, 65},
    {-INFINITY, -65},
    {-1, LLONG_MIN},
    {-1, LLONG_MAX},
    {1, LLONG_MAX},
    {2, -16000},
    {1.5, 2000},
    {0x1.0000000000001p0, 4503599627370496LL},
    {0x1.fffffffffffffp-1, 9007199254740992LL},
};

START_TEST(compare_pow_int) {
  double base = inputs[_i].base;
  long long exponent = inputs[_i].exponent;
  long double result = s21_pow_int(base, exponent);
  // Derive parity from the integer even if long double cannot represent it.
  long double expected =
      base == -1 ? (exponent % 2 ? -1 : 1) : powl(base, (long double)exponent);
  if (isnan(expected)) {
    ck_assert(isnan(result));
  } else if (expected == 0 || isinf(expected)) {
    ck_assert(result == expected && !!signbit(result) == !!signbit(expected));
  } else {
    ck_assert_msg(fabsl(result - expected) <= fabsl(expected) * DBL_EPSILON,
                  "base=%a, exponent=%lld: got %.21Lg, expected %.21Lg", base,
                  exponent, result, expected);
  }
}
END_TEST

Suite *test_pow_int(void) {
  return test_suite("pow_int", compare_pow_int, TEST_COUNT(inputs));
}
