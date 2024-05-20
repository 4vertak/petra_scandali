#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEC powf(2.0f, 96.0f) - 1.0
#define MIN_DEC -powf(2.0f, 96.0f) + 1.0

// Двоичное представление Decimal состоит из 1-разрядного знака, 96-разрядного
// целого числа и коэффициента масштабирования, используемого для деления целого
// числа и указания того, какая его часть является десятичной дробью.
// Коэффициент масштабирования неявно равен числу 10, возведенному в степень в
// диапазоне от 0 до 28.

// Decimal число может быть реализовано в виде четырехэлементного массива
// 32-разрядных целых чисел со знаком (int bits[4];). bits[0], bits[1], и
// bits[2] содержат младшие, средние и старшие 32 бита 96-разрядного целого
// числа соответственно. bits[3] содержит коэффициент масштабирования и знак, и
// состоит из следующих частей:

// Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю;
// Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который
// указывает степень 10 для разделения целого числа; Биты с 24 по 30 не
// используются и должны быть равны нулю; Бит 31 содержит знак; 0 означает
// положительный, а 1 означает отрицательный.

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

// Преобразователи:

// Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка конвертации

typedef enum s21_convertors_error_code {
  S21_CONVERTORS_OK,
  S21_CONVERTORS_ERROR,
} s21_convertors_error_code;

// Уточнение про преобразование числа типа float:
// Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение, равное
// 0 Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
// или равны бесконечности, вернуть ошибку При обработке числа с типом float
// преобразовывать все содержащиеся в нём значимые десятичные цифры. Если таких
// цифр больше 7, то значение числа округляется к ближайшему, у которого не
// больше 7 значимых цифр.

// Уточнение про преобразование из числа типа decimal в тип int: Если в числе
// типа decimal есть дробная часть, то её следует отбросить (например, 0.9
// преобразуется 0)

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Арифметические операторы:

// Функции возвращают код ошибки:
// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

typedef enum s21_arithmetic_error_code {
  S21_ARITHMETIC_OK,
  S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF,  // number is too large or equal to
                                             // infinity
  S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF,  // number is too small or equal
  // to negative infinity
  S21_ARITHMETIC_DIV_BY_ZERO,
} s21_arithmetic_error_code;

// Уточнение про числа, не вмещающиеся в мантиссу: При получении чисел, не
// вмещающихся в мантиссу при арифметических операциях, использовать банковское
// округление (например, 79,228,162,514,264,337,593,543,950,335 - 0.6 =
// 79,228,162,514,264,337,593,543,950,334)

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Операторы сравнение:

// Возвращаемое значение:
// 0 - FALSE
// 1 - TRUE

typedef enum s21_comparison_return_value {
  S21_COMPARISON_FALSE,
  S21_COMPARISON_TRUE,
} s21_comparison_return_value;

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// Другие функции:

// Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка вычисления

typedef enum s21_another_func_error_code {
  S21_ANOTHER_FUNC_OK,
  S21_ANOTHER_FUNC_ERROR,
} s21_another_func_error_code;

// int s21_floor(s21_decimal value, s21_decimal *result);
// int s21_round(s21_decimal value, s21_decimal *result);
// int s21_truncate(s21_decimal value, s21_decimal *result);
// int s21_negate(s21_decimal value, s21_decimal *result);

// Помогаторы:

void init_decimal_null(s21_decimal *count);
void init_big_decimal_null(s21_big_decimal *value);
int get_bit(s21_decimal *value, int index);
void set_bit(s21_decimal *value, int position,
             int bit);  // Устанавливает или сбрасывает бит в position в
// соответствии с параметром bit.
void set_big_decimal(s21_big_decimal *value_1, s21_decimal value_2);
int get_exp(s21_decimal value);  // Возвращает размер/масштаб числа используя
                                 // его старший бит (value.bits3 >> 16)
int get_float_exp(float value);
void set_exp(s21_decimal *value,
             int pow);  // Устанавливает размер/масштаб числа
int get_sign(
    s21_decimal value);  // Возвращает значение знака числа используя битовую
                         // маску (1u << 31) для определения знака
s21_decimal *set_sign(s21_decimal *value,
                      int bit);  // Устанавливает значение знака числа используя
                                 // битовую маску (1u << 31)
void shift_left(s21_decimal *value);
void shift_right(s21_decimal *value);
int mul_ten(s21_decimal value_1, s21_decimal *result);
void div_ten(s21_decimal *value);
int normalized_decimal(s21_decimal *value_1, s21_decimal *value_2);

int handle_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int handle_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  // SRC_S21_DECIMAL_H_
