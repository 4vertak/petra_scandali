#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_convertors_error_code error_code = S21_CONVERTORS_OK;

  if (!dst) {
    error_code = S21_CONVERTORS_ERROR;
  } else if (!valid_decimal(src)) {
    error_code = S21_CONVERTORS_ERROR;
    *dst = 0;
  } else {
    *dst = 0;
    s21_decimal truncated_decimal = init_decimal_null();
    s21_truncate(src, &truncated_decimal);
    s21_decimal int_max_decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
    s21_decimal int_min_decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};

    if (s21_is_less(truncated_decimal, int_min_decimal) ==
        S21_COMPARISON_TRUE) {
      error_code = S21_CONVERTORS_ERROR;
    } else if (s21_is_greater(truncated_decimal, int_max_decimal) ==
               S21_COMPARISON_TRUE) {
      error_code = S21_CONVERTORS_ERROR;
    } else {
      for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
        if (get_bit(truncated_decimal, i) != 0) {
          *dst += pow(2, i);
        }
      }
      if (get_sign(src) == 1 && *dst != -2147483648) {
        *dst = -*dst;
      }
    }
  }
  return error_code;
}
