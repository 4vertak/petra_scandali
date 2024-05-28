#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;

  if (!result) {
    error_code = S21_ARITHMETIC_ERROR;
  } else if (!valid_decimal(value_1) || !valid_decimal(value_2)) {
    error_code = S21_ARITHMETIC_ERROR;
  } else if (s21_is_equal(value_2, init_decimal_null())) {
    error_code = S21_ARITHMETIC_DIV_BY_ZERO;
  } else {
    *result = init_decimal_null();
    int sign_value_1 = get_sign(value_1);
    int sign_value_2 = get_sign(value_2);
    s21_big_decimal big_value_1;
    s21_big_decimal big_value_2;
    normalized_decimal(value_1, value_2, &big_value_1, &big_value_2);

    s21_big_decimal remainder = set_big_decimal(init_decimal_null());
    s21_big_decimal temp;
    temp = big_decimal_bin_div(big_value_1, big_value_2, &remainder);

    if (temp.decimals[0].bits[3] != 0 || !check_zero(temp.decimals[1])) {
      if (sign_value_1 != sign_value_2) {
        error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
      } else {
        error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
      }
    } else {
      error_code = handle_div(big_value_2, temp, remainder, result);
      if (sign_value_1 != sign_value_2) {
        set_sign(result, 1);
      }
      if (get_sign(*result) == 1 &&
          error_code == S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF) {
        error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
      }
      if (error_code == S21_ARITHMETIC_OK &&
          s21_is_not_equal(value_1, init_decimal_null()) &&
          s21_is_equal(*result, init_decimal_null())) {
        error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
      }
    }
  }

  return error_code;
}