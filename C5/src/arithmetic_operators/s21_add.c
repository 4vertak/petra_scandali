#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  if (result) {
    init_decimal_null(result);
    error_code = normalized_decimal(&value_1, &value_2);
    if (!error_code) {
      int pow_val = get_exp(value_2);
      set_exp(result, pow_val);
      if (check_for_zero(value_1) && check_for_zero(value_2)) {
        init_decimal_null(result);
        error_code = S21_ARITHMETIC_OK;
      } else if (get_sign(value_1) && get_sign(value_2)) {
        set_sign(result, 1);
        error_code = handle_add(value_1, value_2, result);
        if (error_code && get_sign(*result))
          error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
        if (error_code && !get_sign(*result))
          error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
      } else if (get_sign(value_1) != get_sign(value_2)) {
        if (get_sign(value_1)) {
          set_sign(&value_1, 0);
          s21_sub(value_2, value_1, result);
        } else {
          set_sign(&value_2, 0);
          s21_sub(value_1, value_2, result);
        }
      } else
        error_code = handle_add(value_1, value_2, result);
    }
  } else {
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
  }
  return error_code;
}

int handle_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  for (int i = 0; i < 96; i++) {
    int bit1 = get_bit(&value_1, i);
    int bit2 = get_bit(&value_2, i);
    if (bit1 + bit2 + error_code == 1) {
      set_bit(result, i, 1);
      error_code = S21_ARITHMETIC_OK;
    } else if (bit1 + bit2 + error_code == 2)
      error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
    else if (bit1 + bit2 + error_code == 3) {
      set_bit(result, i, 1);
      error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
    } else
      error_code = S21_ARITHMETIC_OK;
  }
  return error_code;
}