#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_another_func_error_code error_code = S21_ANOTHER_FUNC_OK;
  // Если указатель на decimal является NULL
  if (!result) {
    error_code = S21_ANOTHER_FUNC_ERROR;
  } else {
    // Инициализация результата как нулевого числа типа s21_decimal
    init_decimal_null(result);

    // Получение показателя степени числа value
    int power = get_exp(value);

    // Получение знака числа value
    int sign = get_bit(&value, 127);
    float float_value = 0;

    // Инициализация единицы в виде числа типа s21_decimal
    s21_decimal decimal_one = {0};
    s21_from_int_to_decimal(1, &decimal_one);

    while (power > 1) {
      div_ten(&value);
      power--;
    }

    // Если показатель степени не равен 0
    if (power != 0) {
      // Сохранение исходного значения числа value
      s21_decimal tmp_value = value;

      // Деление числа value на 10
      div_ten(&value);

      // Вычисление остатка от деления исходного значения на 10
      s21_decimal rest_value = {0};
      s21_sub(tmp_value, value, &rest_value);

      // Преобразование остатка в число с плавающей запятой
      s21_from_decimal_to_float(rest_value, &float_value);

      // Если модуль значения больше 0.5
      if (fabs(float_value) > 0.5) {
        // Изменение значения числа в зависимости от знака
        if (sign)
          s21_sub(value, decimal_one, &value);
        else
          s21_add(value, decimal_one, &value);
      }
      // Если модуль значения равен 0.5
      else if (fabsl(float_value) == 0.5) {
        // Если младший бит value равен 1
        if (get_bit(&value, 0) == 1) {
          // Изменение значения value в зависимости от знака
          if (sign)
            s21_sub(value, decimal_one, &value);
          else
            s21_add(value, decimal_one, &value);
        }
      }
    }

    // Копирование битов value в результат
    for (int i = 0; i < 4; i++) result->bits[i] = value.bits[i];
  }
  return error_code;
}