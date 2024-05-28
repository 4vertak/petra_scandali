#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_convertors_error_code error_code = S21_CONVERTORS_OK;

  if (!dst) {
    error_code = S21_CONVERTORS_ERROR;
  } else {
    *dst = init_decimal_null();
    int sign;
    if (src < 0) {
      sign = 1;
      if (src != INT_MIN) {
        src = -src;
      }
    } else {
      sign = 0;
    }
    dst->bits[0] = src;
    set_sign(dst, sign);
  }
  return error_code;
}
