#include "../s21_decimal.h"

// Функция выполняет операцию обрезания;)

int s21_truncate(s21_decimal value, s21_decimal *result) {
  // инициализаируем нулевым значением
  init_decimal_null(result);
  // Всегда будет возвращать 0
  s21_another_func_error_code error_code = S21_ANOTHER_FUNC_OK;

  // получаем масштаб/степень value
  int power = get_exp(value);
  // получаем знак value
  int sign_value = get_sign(value);
  //   присваиваем значение value в result
  *result = value;
  // Если степень числа не нулевая, то обрезаниеб чик-чик;), до целого значения
  if (power) {
    for (int i = power; i > 0; i--) {
      // путем деления на 10 power раз
      div_ten(result);
    }
    float float_value = 0.0;
    // Преобразобразуем децимал в float
    s21_from_decimal_to_float(*result, &float_value);

    // Установка степени числа в 0
    set_exp(result, 0);

    // Установка знака числа
    set_sign(result, sign_value);
  }
  return error_code;
}