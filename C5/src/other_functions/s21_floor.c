#include "../s21_decimal.h"

// функция выполняет округление числа decimal до ближайшего
// меньшего целого значения

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_another_func_error_code error_code = S21_ANOTHER_FUNC_OK;
  if (!result) {
    // Если указатель на decimal является NULL
    error_code = S21_ANOTHER_FUNC_ERROR;
  } else {
    // инициализаируем нулевым значением
    init_decimal_null(result);
    // Получаем знак числа value.
    int sign_value = get_sign(value);
    s21_decimal decimal_one = {0};
    // Преобразуем целое число 1 в десятичное и сохраняем в переменную
    // decimal_one.
    s21_from_int_to_decimal(1, &decimal_one);
    // j,htpftvz значение value и сохраняем результат в переменную result.
    s21_truncate(value, result);
    // Если значение value минус и result не равен исходному значению value, то
    if (sign_value == 1 && !s21_is_equal(value, *result)) {
      // вычитаем из результата единицу для получения значения floor(value).
      s21_sub(*result, decimal_one, result);
    }
    // Устанавливаем знак результата.
    set_sign(result, sign_value);
  }
  return error_code;
}