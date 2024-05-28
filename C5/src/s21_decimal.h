#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEC                                 \
  {                                             \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0 } \
  }
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

#define MAX_BITS 128
#define MAX_BLOCK_BITS 32
#define MAX_BLOCK_NUMBER 96

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  s21_decimal decimals[2];
} s21_big_decimal;

typedef union decimal_bit_3 {
  int part_decimal;
  struct {
    uint32_t empty_bits_0_15 : 16;
    uint32_t power : 8;
    uint32_t empty_bits_24_30 : 7;
    uint32_t sign : 1;
  } parts;
} decimal_bit_3;

typedef enum s21_arithmetic_error_code {
  S21_ARITHMETIC_OK,
  S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF,
  S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF,
  S21_ARITHMETIC_DIV_BY_ZERO,
  S21_ARITHMETIC_ERROR,
} s21_arithmetic_error_code;

typedef enum s21_comparison_return_value {
  S21_COMPARISON_FALSE,
  S21_COMPARISON_TRUE,
} s21_comparison_return_value;

typedef enum s21_convertors_error_code {
  S21_CONVERTORS_OK,
  S21_CONVERTORS_ERROR,
} s21_convertors_error_code;

typedef enum s21_another_func_error_code {
  S21_ANOTHER_FUNC_OK,
  S21_ANOTHER_FUNC_ERROR,
} s21_another_func_error_code;

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
int s21_is_less_handle(s21_decimal value_1, s21_decimal value_2);

// Преобразователи:

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Другие функции:

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Помогаторы:

int valid_decimal(s21_decimal value);
// зануляем децимал)
s21_decimal init_decimal_null(void);

// Возвращает значение знака числа используя битовую маску
int get_sign(s21_decimal value);
// Возвращает размер/масштаб числа используя его старший бит (value.bits3 >> 16)
int get_exp(s21_decimal value);
// Устанавливает значение знака числа используя битовую маску (1u << 31)
void set_sign(s21_decimal *value, int sign);
// Устанавливает размер/масштаб числа
void set_exp(s21_decimal *value, int power);
// Устанавливает decimal в big_decimal
s21_big_decimal set_big_decimal(s21_decimal value_1);
// Возвращает бит по index
int get_bit(s21_decimal value, int index);
// Устанавливает значение 1 для бита номер index в числе decimal
s21_decimal set_bit(s21_decimal value, int index);
// Возвращает ближайший к старшему биту установленный бит (который имеет
// значение 1 числа decimal
int decimal_get_bit(s21_decimal value);
// проверяет на нуль decimal
int check_zero(s21_decimal value);
// сравнение decimal
int decimal_compare(s21_decimal value_1, s21_decimal value_2);

// Помогаторы convertors_operatos:

// возвращает число  c 0 - 9 в виде decimal, соответствующее цифре в виде char
// спасибо хорошему челу)))
s21_decimal decimal_get_char(char c);
s21_decimal s21_float_string_to_decimal(char *str);

// Помогаторы arithmetis_operators:

int handle_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int handle_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int handle_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int handle_div(s21_big_decimal big_value_2, s21_big_decimal res,
               s21_big_decimal remainder, s21_decimal *result);
int div_exp(s21_big_decimal *res, s21_big_decimal big_value,
            s21_big_decimal *remainder);

void normalized_decimal(s21_decimal value_1, s21_decimal value_2,
                        s21_big_decimal *big_value_1,
                        s21_big_decimal *big_value_2);
s21_decimal s21_abs(s21_decimal value_1);

s21_decimal decimal_bin_add(s21_decimal value_1, s21_decimal value_2);
s21_decimal decimal_bin_sub(s21_decimal value_1, s21_decimal value_2);
s21_decimal decimal_bin_div(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *remainder);
s21_big_decimal decimal_bin_mul(s21_decimal value_1, s21_decimal value_2);

s21_big_decimal big_decimal_add(s21_big_decimal value_1,
                                s21_big_decimal value_2);
s21_big_decimal big_decimal_bin_sub(s21_big_decimal value_1,
                                    s21_big_decimal value_2);
s21_big_decimal big_decimal_bin_div(s21_big_decimal value_1,
                                    s21_big_decimal value_2,
                                    s21_big_decimal *remainder);
s21_big_decimal big_decimal_bin_mul(s21_big_decimal value_1,
                                    s21_decimal value_2);

// помогаторы binary_operators

s21_decimal decimal_shift_left(s21_decimal value, int shift);
s21_decimal decimal_shift_right(s21_decimal value, int shift);
s21_decimal decimal_shift_left_one(s21_decimal value);
s21_decimal decimal_shift_right_one(s21_decimal value);
s21_big_decimal big_decimal_shift_left(s21_big_decimal value, int shift);
s21_big_decimal big_decimal_shift_right(s21_big_decimal value, int shift);
int handle_is_less(s21_decimal value_1, s21_decimal value_2);

// Степени числа 10 спасибо хорошо челу)))
static const s21_decimal all_ten_pows[39] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
    [29] = {{0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x1}},
    [30] = {{0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0xC}},
    [31] = {{0x80000000, 0xC0914B26, 0x37BE2022, 0x7E}},
    [32] = {{0x0, 0x85ACEF81, 0x2D6D415B, 0x4EE}},
    [33] = {{0x0, 0x38C15B0A, 0xC6448D93, 0x314D}},
    [34] = {{0x0, 0x378D8E64, 0xBEAD87C0, 0x1ED09}},
    [35] = {{0x0, 0x2B878FE8, 0x72C74D82, 0x134261}},
    [36] = {{0x0, 0xB34B9F10, 0x7BC90715, 0xC097CE}},
    [37] = {{0x0, 0xF436A0, 0xD5DA46D9, 0x785EE10}},
    [38] = {{0x0, 0x98A2240, 0x5A86C47A, 0x4B3B4CA8}}};

#endif  //  SRC_S21_DECIMAL_H_
