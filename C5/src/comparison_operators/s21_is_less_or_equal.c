#include "../s21_decimal.h"

// Возвращаемое значение:
// 0 - FALSE
// 1 - TRUE

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_return_value return_value = S21_COMPARISON_FALSE;
  if (s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2))
    return_value = S21_COMPARISON_TRUE;
  return return_value;
}