#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_another_func_error_code error_code = S21_ANOTHER_FUNC_OK;
  if (!result) {
    error_code = S21_ANOTHER_FUNC_ERROR;
  } else if (!valid_decimal(value)) {
    error_code = S21_ANOTHER_FUNC_ERROR;
  } else {
    *result = init_decimal_null();
    int sign = get_sign(value);
    s21_decimal fractional;
    s21_decimal value_unsigned_truncated;
    s21_decimal value_unsigned = s21_abs(value);
    s21_truncate(value_unsigned, &value_unsigned_truncated);
    s21_sub(value_unsigned, value_unsigned_truncated, &fractional);
    s21_decimal decimal_float_0_5 = {{0x5, 0x0, 0x0, 0x10000}};
    s21_decimal decimal_digit_one = init_decimal_null();
    decimal_digit_one.bits[0] = 1;
    if (s21_is_equal(fractional, decimal_float_0_5)) {
      if (((value_unsigned_truncated.bits[0] & 1) != 1)) {
        value_unsigned_truncated = value_unsigned_truncated;
      } else {
        value_unsigned_truncated =
            decimal_bin_add(value_unsigned_truncated, decimal_digit_one);
      }
    } else if (s21_is_greater(fractional, decimal_float_0_5)) {
      value_unsigned_truncated =
          decimal_bin_add(value_unsigned_truncated, decimal_digit_one);
    } else {
      value_unsigned_truncated = value_unsigned_truncated;
    }
    *result = value_unsigned_truncated;
    set_sign(result, sign);
  }
  return error_code;
}
