#include "../s21_decimal.h"

// Возвращаемое значение:
// 0 - FALSE
// 1 - TRUE

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_return_value return_value = S21_COMPARISON_TRUE;
  int sign_value_1 = get_sign(value_1);
  int sign_value_2 = get_sign(value_2);

  if (sign_value_1 == !sign_value_2) {
    int flag_null_value_1 =
        (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0)
            ? 1
            : 0;
    int flag_null_value_2 =
        (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
            ? 1
            : 0;
    return_value = (flag_null_value_1 == 0 && flag_null_value_2 == 0)
                       ? S21_COMPARISON_FALSE
                       : S21_COMPARISON_TRUE;
  } else {
    s21_big_decimal big_value_1, big_value_2;
    init_big_decimal_null(&big_value_1);
    init_big_decimal_null(&big_value_2);
    normalized_decimal(&value_1, &value_2);
    set_big_decimal(&big_value_1, value_1);
    set_big_decimal(&big_value_2, value_2);
    for (int t = 6; t >= 0 && return_value; t--) {
      if (big_value_1.bits[t] != big_value_2.bits[t]) {
        return_value = S21_COMPARISON_FALSE;
      }
    }
  }
  return return_value;
}
