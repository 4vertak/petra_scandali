#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_return_value return_value = S21_COMPARISON_FALSE;
  int sign_value_1 = get_sign(value_1);
  int sign_value_2 = get_sign(value_2);
  if (s21_is_equal(value_1, init_decimal_null()) &&
      s21_is_equal(value_2, init_decimal_null())) {
    return_value = S21_COMPARISON_FALSE;
  } else if (sign_value_1 == 1 && sign_value_2 == 0) {
    return_value = S21_COMPARISON_TRUE;
  } else if (sign_value_1 == 0 && sign_value_2 == 1) {
    return_value = S21_COMPARISON_FALSE;
  } else if (sign_value_1 == 1 && sign_value_2 == 1) {
    return_value = handle_is_less(s21_abs(value_2), s21_abs(value_1));
  } else {
    return_value = handle_is_less(value_1, value_2);
  }
  return return_value;
}
