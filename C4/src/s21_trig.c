#include <stdint.h>

#include "s21_math_internal.h"

// floor((2/pi) * 2^1280), in base 2^32, least significant word first.
// Even DBL_MAX leaves at least 256 fractional bits for quadrant reduction.
static const uint32_t s21_two_over_pi[] = {
    0x9af4361d, 0xf0cfbc20, 0xfc7b6bab, 0x56033046, 0x1f8d5d08, 0x6bfb5fb1,
    0x8a5292ea, 0x3d0739f7, 0xebe5f17b, 0x7527bac7, 0x9e5fea2d, 0x4f463f66,
    0x27cb09b7, 0x6d367ecf, 0x5a0a6d1f, 0xef2f118b, 0xde05980f, 0x1ff897ff,
    0xbdf9283b, 0x9c845f8b, 0x835339f4, 0x3991d639, 0xb45f7e41, 0xe99c7026,
    0x2ebb4484, 0xe88235f5, 0xb129a73e, 0xfe1deb1c, 0x09d1921c, 0x06492eea,
    0x424dd2e0, 0xb7246e3a, 0xdebbc561, 0xfe5163ab, 0x3c439041, 0xdb629599,
    0xf534ddc0, 0xfc2757d1, 0x4e441529, 0xa2f9836e,
};
enum { S21_PI_WORDS = sizeof(s21_two_over_pi) / sizeof(s21_two_over_pi[0]) };

static unsigned s21_bit(const uint32_t *words, int bit) {
  return (words[bit / 32] >> (bit % 32)) & 1u;
}

// Return the nearest quadrant modulo four and the signed angle within it.
static unsigned s21_reduce_angle(double x, long double *angle) {
  int exponent = s21_normalize(&x);
  uint64_t significand = (uint64_t)(x * 0x1p52);
  uint32_t product[S21_PI_WORDS + 2] = {0};
  for (int j = 0; j < 2; ++j) {
    uint32_t digit = (uint32_t)significand;
    uint64_t carry = 0;
    for (int i = 0; i < S21_PI_WORDS; ++i) {
      uint64_t sum =
          (uint64_t)digit * s21_two_over_pi[i] + product[i + j] + carry;
      product[i + j] = (uint32_t)sum;
      carry = sum >> 32;
    }
    product[S21_PI_WORDS + j] = (uint32_t)carry;
    significand >>= 32;
  }

  int point = 32 * S21_PI_WORDS + 52 - exponent;
  unsigned round_up = s21_bit(product, point - 1);
  unsigned quadrant = s21_bit(product, point) + 2 * s21_bit(product, point + 1);
  int whole_words = point / 32;
  if (round_up) {
    // Complement before converting to floating point to retain tiny remainders.
    uint64_t carry = 1;
    for (int i = 0; i <= whole_words; ++i) {
      uint64_t digit = (uint64_t)(~product[i]) + carry;
      product[i] = (uint32_t)digit;
      carry = digit >> 32;
    }
  }
  long double fraction = 0;
  for (int i = 0; i < whole_words; ++i) {
    fraction = (fraction + product[i]) * 0x1p-32L;
  }
  uint32_t unit = UINT32_C(1) << (point % 32);
  fraction = (fraction + (product[whole_words] & (unit - 1))) / unit;
  *angle = (round_up ? -fraction : fraction) * S21_PI_2L;
  return (quadrant + round_up) % 4;
}

void s21_sincos(double x, long double *sine, long double *cosine) {
  if (!__builtin_isfinite(x)) {
    *sine = S21_NAN;
    *cosine = S21_NAN;
    return;
  }
  long double angle = s21_fabs(x);
  unsigned quadrant = 0;
  if (angle > S21_PI_2L * 0.5L) quadrant = s21_reduce_angle(angle, &angle);

  // Evaluate both Taylor polynomials on [-pi/4, pi/4] using Horner's rule.
  long double square = -angle * angle;
  long double sin_poly = 1;
  long double cos_poly = 1;
  for (int n = 10; n > 0; --n) {
    sin_poly = 1 + square * sin_poly / (2 * n * (2 * n + 1));
    cos_poly = 1 + square * cos_poly / (2 * n * (2 * n - 1));
  }
  long double s = angle * sin_poly;
  *sine = (quadrant & 1) ? cos_poly : s;
  *cosine = (quadrant & 1) ? s : cos_poly;
  if (quadrant >= 2) *sine = -*sine;
  if (quadrant == 1 || quadrant == 2) *cosine = -*cosine;
  if (__builtin_signbit(x)) *sine = -*sine;
}
