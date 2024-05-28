#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  s21_convertors_error_code error_code = S21_CONVERTORS_OK;
  if (!dst) {
    error_code = S21_CONVERTORS_ERROR;
  } else if (!valid_decimal(src)) {
    error_code = S21_CONVERTORS_ERROR;
    *dst = 0.0;
  } else if (s21_is_equal(src, init_decimal_null())) {
    int sign = get_sign(src);
    if (sign == 1) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    error_code = S21_CONVERTORS_OK;
  } else {
    *dst = 0.0;
    double temp = 0.0;
    int sign = get_sign(src);
    int exp = get_exp(src);
    for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
      if (get_bit(src, i) != 0) {
        temp += pow(2.0, i);
      }
    }
    double exp_ten = pow(10, exp);
    temp /= exp_ten;
    if (sign == 1) {
      temp *= -1.0;
    }
    *dst = (float)temp;
  }
  return error_code;
}
