#include "../s21_decimal.h"

// Функция выполняет операцию отрицания

int s21_negate(s21_decimal value, s21_decimal *result) {
  // Всегда будет возвращать 0
  s21_another_func_error_code error_code = S21_ANOTHER_FUNC_OK;

  // присваеваем значение value в result
  *result = value;

  // изменяет старший бит в массиве битов result->bits[3]
  result->bits[3] = value.bits[3] ^ 1 << 31;

  return error_code;
}