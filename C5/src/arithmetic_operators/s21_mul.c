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

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int exp_first = 0;
  int exp_second = 0;
  exp_first = get_exp(value_1);
  exp_second = get_exp(value_2);
  init_decimal_null(result);
  s21_decimal tmp_res;
  init_decimal_null(&tmp_res);
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  int shift = 0;
  for (int i = 95; i >= 0; i--) {
    s21_decimal tmp_second;
    init_decimal_null(&tmp_second);
    tmp_second = value_2;
    if (get_bit(&value_1, 95 - i)) {
      int t = 95 - i;
      for (int j = 0; j < t; j++) {
        shift_left(&tmp_second);
      }
      error_code = s21_add(tmp_second, tmp_res, &tmp_res);
    }
    shift++;
  }

  for (int i = 95; i >= 0; i--) {
    set_bit(result, i, get_bit(&tmp_res, i));
  }

  if (get_sign(value_1) == 1 && get_sign(value_2) == 1) {
    set_sign(result, 0);
  } else if (get_sign(value_1) == 0 && get_sign(value_2) == 0) {
    set_sign(result, 0);
  } else if ((get_sign(value_1) == 0 && get_sign(value_2) == 1) ||
             (get_sign(value_1) == 1 && get_sign(value_2) == 0)) {
    set_sign(result, 1);
  }

  if ((exp_first + exp_second) > 28 && get_sign(*result))
    error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
  if ((exp_first + exp_second) > 28 && !get_sign(*result))
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;

  set_exp(result, exp_first + exp_second);

  return error_code;
}
