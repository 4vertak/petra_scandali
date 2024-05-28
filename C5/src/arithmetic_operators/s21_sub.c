#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  if (!result) {
    error_code = S21_ARITHMETIC_ERROR;
  } else if (!valid_decimal(value_1) || !valid_decimal(value_2)) {
    error_code = S21_ARITHMETIC_ERROR;
  } else {
    *result = init_decimal_null();
    s21_decimal temp = init_decimal_null();
    int sign_value_1 = get_sign(value_1);
    int sign_value_2 = get_sign(value_2);

    if (sign_value_1 == 0 && sign_value_2 == 0) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        error_code = handle_sub(value_1, value_2, &temp);
      } else {
        error_code = handle_sub(value_2, value_1, &temp);
        s21_negate(temp, &temp);
      }
    } else if (sign_value_1 == 0 && sign_value_2 == 1) {
      error_code = s21_add(value_1, s21_abs(value_2), &temp);
    } else if (sign_value_1 == 1 && sign_value_2 == 0) {
      error_code = s21_add(s21_abs(value_1), value_2, &temp);
      s21_negate(temp, &temp);
    } else if (sign_value_1 == 1 && sign_value_2 == 1) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        error_code = handle_sub(s21_abs(value_2), s21_abs(value_1), &temp);
      } else {
        error_code = handle_sub(s21_abs(value_1), s21_abs(value_2), &temp);
        s21_negate(temp, &temp);
      }
    }
    if (get_sign(temp) == 1 &&
        error_code == S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF) {
      error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
    }
    *result = temp;
  }
  return error_code;
}