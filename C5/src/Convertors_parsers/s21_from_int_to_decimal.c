#include "../s21_decimal.h"

// Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка конвертации

// Уточнение про преобразование из числа типа decimal в тип int:
// Если в числе типа decimal есть дробная часть, то её следует отбросить
// (например, 0.9 преобразуется 0)

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_convertors_error_code error_code = S21_CONVERTORS_OK;
  if (dst) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (src < 0) {
      set_sign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;

  } else {
    error_code = S21_CONVERTORS_ERROR;
  }
  return error_code;
}
