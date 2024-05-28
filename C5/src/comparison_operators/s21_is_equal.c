#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_return_value return_value = S21_COMPARISON_TRUE;
  s21_decimal temp_value_1 = value_1;
  int exp_value_1 = get_exp(value_1);
  int sign_value_1 = get_sign(value_1);
  if (exp_value_1 > 0 && valid_decimal(value_1)) {
    s21_decimal remainder = init_decimal_null();
    s21_decimal tmp = value_1;
    tmp.bits[3] = 0;
    while (exp_value_1 > 0) {
      tmp = decimal_bin_div(tmp, all_ten_pows[1], &remainder);
      if (check_zero(remainder)) {
        --exp_value_1;
        temp_value_1 = tmp;
      } else {
        break;
      }
    }
    set_exp(&temp_value_1, exp_value_1);
    set_sign(&temp_value_1, sign_value_1);
  }
  s21_decimal temp_value_2 = value_2;
  int exp_value_2 = get_exp(value_2);
  int sign_value_2 = get_sign(value_2);
  if (exp_value_2 > 0 && valid_decimal(value_2)) {
    s21_decimal remainder = init_decimal_null();
    s21_decimal tmp = value_2;
    tmp.bits[3] = 0;
    while (exp_value_2 > 0) {
      tmp = decimal_bin_div(tmp, all_ten_pows[1], &remainder);
      if (check_zero(remainder)) {
        --exp_value_2;
        temp_value_2 = tmp;
      } else {
        break;
      }
    }
    set_exp(&temp_value_2, exp_value_2);
    set_sign(&temp_value_2, sign_value_2);
  }
  if (temp_value_1.bits[0] == 0 && temp_value_1.bits[1] == 0 &&
      temp_value_1.bits[2] == 0 && temp_value_2.bits[0] == 0 &&
      temp_value_2.bits[1] == 0 && temp_value_2.bits[2] == 0) {
    return_value = S21_COMPARISON_TRUE;
  } else {
    return_value = temp_value_1.bits[0] == temp_value_2.bits[0] &&
                   temp_value_1.bits[1] == temp_value_2.bits[1] &&
                   temp_value_1.bits[2] == temp_value_2.bits[2] &&
                   temp_value_1.bits[3] == temp_value_2.bits[3];
  }
  return return_value;
}
