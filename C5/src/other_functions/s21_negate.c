#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_another_func_error_code error_code = S21_ANOTHER_FUNC_OK;
  if (!result) {
    error_code = S21_ANOTHER_FUNC_ERROR;
  } else {
    *result = value;
    set_sign(result, !get_sign(*result));
    if (!valid_decimal(value)) {
      error_code = S21_ANOTHER_FUNC_ERROR;
    }
  }
  return error_code;
}
