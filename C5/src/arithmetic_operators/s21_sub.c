#include "../s21_decimal.h"

// Функции возвращают код ошибки:
// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

// Уточнение про числа, не вмещающиеся в мантиссу: При получении чисел, не
// вмещающихся в мантиссу при арифметических операциях, использовать банковское
// округление (например, 79,228,162,514,264,337,593,543,950,335 - 0.6 =
// 79,228,162,514,264,337,593,543,950,334)

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  init_decimal_null(result);
  int error = normalized_decimal(&value_1, &value_2);
  int sign_value_1 = get_bit(&value_1, 127);
  int sign_value_2 = get_bit(&value_2, 127);
  if (!error) {
    int exp_value = get_exp(value_1);
    set_exp(result, exp_value);
    if (sign_value_1 && sign_value_2) {
      if (s21_is_less(value_1, value_2)) {
        handle_sub(value_1, value_2, result);
        set_sign(result, 1);
      } else
        handle_sub(value_2, value_1, result);
    } else if (sign_value_1 && !sign_value_2) {
      set_sign(result, 1);
      set_sign(&value_1, 0);
      error_code = handle_add(value_1, value_2, result);
      if (error_code) error_code++;
    } else if (!sign_value_1 && sign_value_2) {
      set_sign(&value_2, 0);
      error_code = handle_add(value_1, value_2, result);
    } else {
      if (s21_is_less(value_1, value_2)) {
        handle_sub(value_2, value_1, result);
        set_sign(result, 1);
      } else
        handle_sub(value_1, value_2, result);
    }
  } else
    error_code = error;

  return error_code;
}

int handle_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int rest = 0;
  for (int i = 0; i <= 96; i++) {
    int bit1 = get_bit(&value_1, i);
    int bit2 = get_bit(&value_2, i);
    if (bit1 - bit2 - rest == 1) {
      set_bit(result, i, 1);
      rest = 0;
    } else if (bit1 - bit2 - rest == 0)
      rest = 0;
    else if (bit1 - bit2 - rest == -1) {
      rest = 1;
      set_bit(result, i, 1);
    } else if (bit1 - bit2 - rest == 3)
      rest = 1;
  }
  return rest;
}