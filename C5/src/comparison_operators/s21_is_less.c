#include "../s21_decimal.h"

// Возвращаемое значение:
// 0 - FALSE
// 1 - TRUE

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_return_value return_value = S21_COMPARISON_TRUE;
  int sign_value_1 = get_sign(value_1);
  int sign_value_2 = get_sign(value_2);
  if ((sign_value_1 == 1) && (sign_value_2 == 0)) {
    int flag_null_value_1 =
        (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0)
            ? 1
            : 0;
    int flag_null_value_2 =
        (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
            ? 1
            : 0;
    return_value = (flag_null_value_1 == 1 && flag_null_value_2 == 1)
                       ? S21_COMPARISON_FALSE
                       : S21_COMPARISON_TRUE;
  } else if ((sign_value_1 == 0) && (sign_value_2 == 1)) {
    return_value = S21_COMPARISON_FALSE;
  } else {
    s21_big_decimal big_value_1, big_value_2;
    init_big_decimal_null(&big_value_1);
    init_big_decimal_null(&big_value_2);
    normalized_decimal(&value_1, &value_2);
    set_big_decimal(&big_value_1, value_1);
    set_big_decimal(&big_value_2, value_2);
    if (s21_is_equal(value_1, value_2)) {
      return_value = S21_COMPARISON_FALSE;
    } else {
      for (int i = 6; i >= 0; i--) {
        if ((sign_value_1 == 1 && big_value_1.bits[i] < big_value_2.bits[i]) ||
            (sign_value_1 == 0 && big_value_1.bits[i] > big_value_2.bits[i])) {
          return_value = S21_COMPARISON_FALSE;
          break;
        } else if ((sign_value_1 == 1 &&
                    big_value_1.bits[i] > big_value_2.bits[i]) ||
                   (sign_value_1 == 0 &&
                    big_value_1.bits[i] < big_value_2.bits[i])) {
          return_value = S21_COMPARISON_TRUE;
          break;
        }
      }
    }
  }
  return return_value;
}
