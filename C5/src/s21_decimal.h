#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEC powf(2.0f, 96.0f) - 1.0
#define MIN_DEC -powf(2.0f, 96.0f) + 1.0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef enum s21_convertors_error_code {
  S21_CONVERTORS_OK,
  S21_CONVERTORS_ERROR,
} s21_convertors_error_code;

typedef enum s21_arithmetic_error_code {
  S21_ARITHMETIC_OK,
  S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF,
  S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF,
  S21_ARITHMETIC_DIV_BY_ZERO,
  S21_ARITHMETIC_NULL,
} s21_arithmetic_error_code;

typedef enum s21_comparison_return_value {
  S21_COMPARISON_FALSE,
  S21_COMPARISON_TRUE,
} s21_comparison_return_value;

typedef enum s21_another_func_error_code {
  S21_ANOTHER_FUNC_OK,
  S21_ANOTHER_FUNC_ERROR,
} s21_another_func_error_code;

// Преобразователи:

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Арифметические операторы:

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Операторы сравнение:

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// Другие функции:

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Помогаторы:

void init_decimal_null(s21_decimal *count);
void init_big_decimal_null(s21_big_decimal *value);
int get_bit(s21_decimal *value, int index);
// Устанавливает или сбрасывает бит в position в соответствии с параметром bit.
void set_bit(s21_decimal *value, int position, int bit);
void set_big_decimal(s21_big_decimal *value_1, s21_decimal value_2);
// Возвращает размер/масштаб числа используя его старший бит (value.bits3 >> 16)
int get_exp(s21_decimal value);
int get_float_exp(float value);
// Устанавливает размер/масштаб числа
void set_exp(s21_decimal *value, int pow);
// Возвращает значение знака числа используя битовую
// маску (1u << 31) для определения знака
int get_sign(s21_decimal value);
// Устанавливает значение знака числа используя
// битовую маску (1u << 31)
// s21_decimal *set_sign(s21_decimal *value, int bit);
void set_sign(s21_decimal *value, int bit);
void shift_left(s21_decimal *value);
void shift_right(s21_decimal *value);
int mul_ten(s21_decimal value_1, s21_decimal *result);
void div_ten(s21_decimal *value);
int normalized_decimal(s21_decimal *value_1, s21_decimal *value_2);

int handle_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int handle_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int check_for_zero(s21_decimal value);

#endif  // SRC_S21_DECIMAL_H_
