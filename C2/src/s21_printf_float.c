#include <fenv.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>

#include "s21_sprintf.h"
#include "s21_string.h"

// A binary long double has at most LDBL_MANT_DIG significant bits.
// Multiplying its significand by 5^k needs at most one extra decimal digit
// per negative binary exponent. The positive range needs MAX_10_EXP + 1.
#define DECIMAL_CAPACITY \
  (2 * LDBL_MANT_DIG - LDBL_MIN_EXP + LDBL_MAX_10_EXP + 2)
#define LIMB_BASE 1000000000U

typedef struct {
  char digits[DECIMAL_CAPACITY];
  int length, exponent;
} decimal;

typedef struct {
  uint32_t limbs[(DECIMAL_CAPACITY + 8) / 9];
  int used;
} big_integer;

static void multiply_add(big_integer *number, uint32_t factor, uint32_t add) {
  uint64_t carry = add;
  for (int i = 0; i < number->used; ++i) {
    uint64_t product = (uint64_t)number->limbs[i] * factor + carry;
    number->limbs[i] = product % LIMB_BASE;
    carry = product / LIMB_BASE;
  }
  if (carry) number->limbs[number->used++] = (uint32_t)carry;
}

static void trim_digits(decimal *number) {
  while (number->length > 1 && number->digits[number->length - 1] == '0')
    --number->length;
}

static void exact_decimal(long double magnitude, decimal *number) {
  int exponent;
  long double fraction = frexpl(magnitude, &exponent);
  big_integer integer = {.limbs = {0}, .used = 1};
  for (int i = 0; i < LDBL_MANT_DIG && fraction != 0; ++i) {
    fraction *= 2;
    unsigned bit = fraction >= 1;
    multiply_add(&integer, 2, bit);
    fraction -= bit;
    --exponent;
  }
  int places = exponent < 0 ? -exponent : 0;
  // M * 2^-k = (M * 5^k) / 10^k. Group powers to keep extremes inexpensive.
  while (exponent > 0) {
    int step = exponent > 29 ? 29 : exponent;
    multiply_add(&integer, 1U << step, 0);
    exponent -= step;
  }
  while (exponent <= -12) {
    multiply_add(&integer, 244140625U, 0);  // 5^12
    exponent += 12;
  }
  while (exponent++ < 0) multiply_add(&integer, 5, 0);

  char *out = number->digits;
  for (int i = integer.used - 1; i >= 0; --i) {
    char group[9], *end = group + sizeof(group);
    char *start = s21_uint_digits(end, integer.limbs[i], 10, false);
    if (i != integer.used - 1)
      while (start != group) *--start = '0';
    s21_memcpy(out, start, (size_t)(end - start));
    out += end - start;
  }
  number->length = (int)(out - number->digits);
  number->exponent = number->length - places - 1;
  trim_digits(number);
}

static void round_decimal(decimal *number, int64_t keep, bool negative) {
  if (keep >= number->length || number->digits[0] == '0') return;
  int mode = fegetround();
  bool up =
      (mode == FE_UPWARD && !negative) || (mode == FE_DOWNWARD && negative);
  if (mode == FE_TONEAREST && keep >= 0) {
    char next = number->digits[keep];
    bool odd = keep > 0 && (number->digits[keep - 1] - '0') % 2;
    up = next > '5' || (next == '5' && (keep + 1 < number->length || odd));
  }
  if (keep <= 0) {
    number->digits[0] = up ? '1' : '0';
    number->exponent = up ? (int)(number->exponent - keep + 1) : 0;
    number->length = 1;
  } else {
    number->length = (int)keep;
    if (up) {
      int i = number->length;
      while (i && number->digits[i - 1] == '9') number->digits[--i] = '0';
      if (i) {
        ++number->digits[i - 1];
      } else {
        number->digits[0] = '1';
        ++number->exponent;
      }
    }
    trim_digits(number);
  }
}

// Copy positions in the significand, filling missing places on either side.
static void write_digits(char *out, const decimal *number, int first,
                         size_t n) {
  if (first < 0) {
    size_t zeros = (size_t)-first < n ? (size_t)-first : n;
    s21_memset(out, '0', zeros);
    out += zeros;
    n -= zeros;
    first += (int)zeros;
  }
  if (n && first < number->length) {
    size_t available = (size_t)(number->length - first);
    size_t count = n < available ? n : available;
    s21_memcpy(out, number->digits + first, count);
    out += count;
    n -= count;
  }
  s21_memset(out, '0', n);
}

static char *exponent_suffix(char *end, int exponent, bool upper) {
  unsigned magnitude = (unsigned)(exponent < 0 ? -exponent : exponent);
  char *start = s21_uint_digits(end, magnitude, 10, false);
  if (end - start < 2) *--start = '0';
  *--start = exponent < 0 ? '-' : '+';
  *--start = upper ? 'E' : 'e';
  return start;
}

int s21_print_float(char *out, int room, s21_print_spec spec,
                    long double value) {
  bool negative = signbit(value);
  bool upper = spec.conversion >= 'A' && spec.conversion <= 'Z';
  const char *sign = s21_print_sign(spec, negative);
  char *body;
  if (!isfinite(value)) {
    const char *word =
        isnan(value) ? (upper ? "NAN" : "nan") : (upper ? "INF" : "inf");
    spec.zero = false;
    int length = s21_print_field(out, room, spec, sign, 3, &body);
    if (length >= 0) s21_memcpy(body, word, 3);
    return length;
  }

  decimal number;
  exact_decimal(fabsl(value), &number);
  int64_t precision = spec.precision < 0 ? 6 : spec.precision;
  char conversion = (char)tolower((unsigned char)spec.conversion);
  if (conversion == 'g' && precision == 0) precision = 1;
  int64_t keep = precision;
  if (conversion == 'e') ++keep;
  if (conversion == 'f') keep += number.exponent + 1;
  round_decimal(&number, keep, negative);

  bool scientific = conversion == 'e';
  if (conversion == 'g') {
    scientific = number.exponent < -4 || number.exponent >= precision;
    if (!spec.alternate && precision > number.length) precision = number.length;
    precision -= scientific ? 1 : number.exponent + 1;
    if (precision < 0) precision = 0;
  }
  int exponent = scientific ? 0 : number.exponent;
  size_t whole = exponent > 0 ? (size_t)exponent + 1 : 1;
  const char *point = localeconv()->decimal_point;
  size_t point_size = precision || spec.alternate ? s21_strlen(point) : 0;
  char suffix[sizeof(int) * CHAR_BIT + 2], *end = suffix + sizeof(suffix);
  char *tail = scientific ? exponent_suffix(end, number.exponent, upper) : end;
  size_t fraction = (size_t)precision;
  size_t size = whole + point_size + fraction + (size_t)(end - tail);
  int length = s21_print_field(out, room, spec, sign, size, &body);
  if (length >= 0) {
    write_digits(body, &number, exponent < 0 ? exponent : 0, whole);
    body += whole;
    s21_memcpy(body, point, point_size);
    write_digits(body + point_size, &number, exponent + 1, fraction);
    s21_memcpy(body + point_size + fraction, tail, (size_t)(end - tail));
  }
  return length;
}
