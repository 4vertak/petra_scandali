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

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  if (result == NULL) {
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
  } else if ((check_for_zero(value_1) && check_for_zero(value_2)) ||
             check_for_zero(value_2)) {
    init_decimal_null(result);
    error_code = S21_ARITHMETIC_DIV_BY_ZERO;
  } else {
    if (check_for_zero(value_1) && !check_for_zero(value_2)) {
      init_decimal_null(result);
      error_code = S21_ARITHMETIC_OK;
    } else {
      int exp = -1, pos = 0;
      int exp_value_1 = get_exp(value_1);
      int exp_value_2 = get_exp(value_2);
      if (exp_value_1 < exp_value_2) {
        normalized_decimal(&value_1, &value_2);
        exp_value_1 = get_exp(value_1);
        exp_value_2 = get_exp(value_2);
      }
      int sign_1 = get_bit(&value_1, 127);
      int sign_2 = get_bit(&value_2, 127);
      init_decimal_null(result);
      set_exp(&value_1, 0);
      set_exp(&value_2, 0);
      set_sign(&value_1, 0);
      set_sign(&value_2, 0);
      if (s21_is_equal(value_2, *result))
        error_code = S21_ARITHMETIC_DIV_BY_ZERO;
      for (int i = 95; i >= 0; i--)
        if (pos == 0 && get_bit(&value_2, i)) pos = i;
      s21_decimal tmp_value_2 = value_2;
      while (s21_is_greater_or_equal(value_1, tmp_value_2) &&
             error_code == S21_ARITHMETIC_OK) {
        do {
          if (exp != -1) shift_left(&tmp_value_2);
          exp++;
        } while (s21_is_less_or_equal(tmp_value_2, value_1) && exp <= 95 - pos);
        s21_decimal tmp = {0};
        set_bit(&tmp, exp - 1, 1);
        s21_add(tmp, *result, result);
        shift_right(&tmp_value_2);
        s21_sub(value_1, tmp_value_2, &value_1);
        set_sign(&value_2, 0);
        exp = -1;
        tmp_value_2 = value_2;
      }
      if (sign_1 != sign_2) set_bit(result, 127, 1);
      set_exp(result, exp_value_1 - exp_value_2);
    }
  }
  return error_code;
}
