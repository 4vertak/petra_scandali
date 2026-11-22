#include "s21_math_internal.h"

long double s21_pow_int(double base, long long exponent) {
  unsigned long long power = (unsigned long long)exponent;
  long double factor = base;
  if (exponent < 0) {
    power = 0ULL - power;
    if (base == 0.0) {
      return __builtin_signbit(base) && (power & 1) ? S21_NINF : S21_INF;
    }
    factor = 1.0L / factor;
  }
  // Squaring a rounded value close to one amplifies its error at large powers.
  if (power > 64 && base != 0 && __builtin_isfinite(base)) {
    long double result = s21_positive_power(s21_fabs(base), exponent);
    return base < 0 && (power & 1) ? -result : result;
  }
  long double result = 1;
  while (power != 0) {
    if (power & 1) result *= factor;
    power >>= 1;
    if (power != 0) factor *= factor;
  }
  return result;
}
