#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_another_func_error_code code = S21_ANOTHER_FUNC_OK;
  if (!result) {
    code = S21_ANOTHER_FUNC_ERROR;
  } else if (!valid_decimal(value)) {
    code = S21_ANOTHER_FUNC_ERROR;
  } else {
    *result = init_decimal_null();
    int exp = get_exp(value);
    s21_decimal temp = value;
    temp.bits[3] = 0;
    temp = decimal_bin_div(temp, all_ten_pows[exp], NULL);
    *result = temp;
    if (get_sign(value) == 1) {
      set_sign(result, 1);
    }
  }
  return code;
}
