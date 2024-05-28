#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  if (!result) {
    error_code = S21_ARITHMETIC_ERROR;
  } else if (!valid_decimal(value_1) || !valid_decimal(value_2)) {
    error_code = S21_ARITHMETIC_ERROR;
  } else {
    *result = init_decimal_null();
    s21_decimal res = init_decimal_null();

    int sign_value_1 = get_sign(value_1);
    int sign_value_2 = get_sign(value_2);

    if (sign_value_1 == 0 && sign_value_2 == 0) {
      error_code = handle_mul(value_1, value_2, &res);
    } else if (sign_value_1 == 0 && sign_value_2 == 1) {
      error_code = handle_mul(value_1, s21_abs(value_2), &res);
      s21_negate(res, &res);
    } else if (sign_value_1 == 1 && sign_value_2 == 0) {
      error_code = handle_mul(s21_abs(value_1), value_2, &res);
      s21_negate(res, &res);
    } else if (sign_value_1 == 1 && sign_value_2 == 1) {
      error_code = handle_mul(s21_abs(value_1), s21_abs(value_2), &res);
    }
    if (error_code == S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF) {
      if (get_sign(res) == 1) {
        error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
      }
    }
    if (error_code == S21_ARITHMETIC_OK &&
        s21_is_not_equal(value_1, init_decimal_null()) &&
        s21_is_not_equal(value_2, init_decimal_null()) &&
        s21_is_equal(res, init_decimal_null())) {
      error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
    }
    *result = res;
  }
  return error_code;
}
