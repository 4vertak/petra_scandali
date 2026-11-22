#include <float.h>
#include <stdint.h>
#include <string.h>

#include "s21_math_internal.h"

_Static_assert(sizeof(double) == sizeof(uint64_t) && FLT_RADIX == 2 &&
                   DBL_MANT_DIG == 53 && DBL_MAX_EXP == 1024,
               "s21_math requires IEEE 754 binary64 double");

static double s21_from_bits(uint64_t bits) {
  double value;
  memcpy(&value, &bits, sizeof(value));
  return value;
}

int s21_normalize(double *mantissa) {
  int adjustment = 0;
  if (*mantissa < DBL_MIN) {
    *mantissa *= 0x1p52;
    adjustment = -52;
  }
  uint64_t bits;
  memcpy(&bits, mantissa, sizeof(bits));
  int exponent = (int)(bits >> 52) - 1023;
  *mantissa = s21_from_bits((bits & UINT64_C(0x000fffffffffffff)) |
                            UINT64_C(0x3ff0000000000000));
  return exponent + adjustment;
}

static double s21_normal_power_of_two(int exponent) {
  return s21_from_bits((uint64_t)(exponent + 1023) << 52);
}

long double s21_scale(long double value, int exponent) {
  // Keep the final factor normal even at the ends of the long double range.
  while (exponent > 1023) {
    value *= 0x1p512L;
    exponent -= 512;
  }
  while (exponent < -1022) {
    value *= 0x1p-512L;
    exponent += 512;
  }
  return value * s21_normal_power_of_two(exponent);
}
