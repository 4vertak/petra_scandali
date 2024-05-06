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
  s21_convertors_error_code  error_code = S21_CONVERTORS_ERROR;
  int sign = 0, scale = 0;
  int exponent;
  double tmp;

  // Получить показатель степени числа с плавающей запятой.
  exponent = ((*((int *)&src) & ~(1u << 31)) >> 23) - 127;
  tmp = (double)src;

  // Проверка наличия входных данных и отсутствия бесконечности.
  if (dst && src != 0 && !isinf(src)) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;

    // Определение знака числа.
    if (src < 0) {
      src *= -1;
      sign = 1;
    }

    // Нормализация числа и определение масштаба.
    while (scale < 28 && (int)tmp / (int)pow(2, 21) == 0) {
      tmp *= 10;
      scale++;
    }

    // Проверка допустимости масштаба и показателя степени.
    if (scale <= 28 && (exponent > -94 && exponent < 96)) {
      float mantissa;
      tmp = (float)tmp;

      // Извлечение битов мантиссы.
      mantissa = tmp;
      exponent = ((*((int *)&mantissa) & ~(1u << 31)) >> 23) - 127;
      set_bit(dst, exponent, 1);
      for (int i = exponent - 1, j = 22; j >= 0; i--, j--) {
        if (((*((int *)&mantissa)) & (1 << j)) != 0) {
          set_bit(dst, i, 1);
        }
      }

      // Установка знака и масштаба.
      set_sign(dst, sign);
      set_scale(dst, scale);
      error_code = S21_CONVERTORS_OK;
    }
  }
  return error_code;
}
