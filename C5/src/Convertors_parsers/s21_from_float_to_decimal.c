#include "./../s21_decimal.h"

// Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка конвертации

// Уточнение про преобразование числа типа float:
// Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение, равное
// 0 Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
// или равны бесконечности, вернуть ошибку При обработке числа с типом float
// преобразовывать все содержащиеся в нём значимые десятичные цифры. Если таких
// цифр больше 7, то значение числа округляется к ближайшему, у которого не
// больше 7 значимых цифр.

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_convertors_error_code error_code = S21_CONVERTORS_OK;
  if (dst != NULL) {
    init_decimal_null(dst);
    if (isinf(src) || isnan(src)) {
      error_code = S21_CONVERTORS_ERROR;
    } else {
      if (src != 0) {
        int exp = 0;
        int power = 0;
        float tmp = 0;
        int sign = (*(int *)&src & (1 << 31)) >> 31;
        double tmp_src = (double)fabs(src);
        for (; power < 29 && (int)tmp_src / (int)pow(2, 21) == 0;
             tmp_src *= 10, power++) {
        }
        if (power > 28) {
          init_decimal_null(dst);
          error_code = S21_CONVERTORS_ERROR;
        } else {
          exp = get_float_exp(src);
          set_sign(dst, sign);
          tmp_src = (float)round(tmp_src);
          for (; fmod(tmp_src, 10) == 0 && power > 0; power--, tmp_src /= 10) {
          }
          tmp = tmp_src;
          exp = get_float_exp(tmp);
          set_bit(dst, exp, 1);
          for (int i = exp - 1, j = 22; j >= 0; i--, j--)
            if ((*(int *)&tmp & (1 << j)) != 0) set_bit(dst, i, 1);
          set_exp(dst, power);
        }
      }
    }
  } else {
    error_code = S21_CONVERTORS_ERROR;
  }
  return error_code;
}
