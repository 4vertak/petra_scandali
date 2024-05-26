#include "../s21_decimal.h"

int check_for_zero(s21_decimal value) {
  s21_another_func_error_code error_code =
      (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0)
          ? S21_ANOTHER_FUNC_ERROR
          : S21_ANOTHER_FUNC_OK;

  return error_code;
}

void init_decimal_null(s21_decimal *value) {
  for (int i = 0; i < 4; i++) value->bits[i] = 0;
}

void init_big_decimal_null(s21_big_decimal *value) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = 0;
  }
}

int get_bit(s21_decimal *value, int index) {
  int num_bit = index / 32;
  int position = index % 32;
  return (value->bits[num_bit] & (1 << position)) >> position;
}

// Устанавливает или сбрасывает бит в position в соответствии с параметром bit.
// Если position / 32 < 4 и bit, то бит в position = 1 с
// помощью операции |=(1u << (pos % 32)). Если же position / 32 и !bit, то
// бит в position = 0 с помощью операции &=~(1u << (pos % 32))

void set_bit(s21_decimal *value, int position, int bit) {
  // if (bit)
  //   value->bits[position / 32] |= (1 << position % 32);
  // else
  //   value->bits[position / 32] &= ~(1 << position % 32);
  int num_bit = position / 32;
  int pos = position % 32;
  if (bit)
    value->bits[num_bit] |= (1 << pos);
  else
    value->bits[num_bit] &= ~(1 << pos);
}

// Возвращает размер/масштаб числа используя его старший бит (value.bits3 >> 16)

int get_exp(s21_decimal value) {
  // int result = (char)(value.bits[3] >> 16);
  // return result;

  int power = 0, n = 0;
  for (int i = 16; i <= 23; i++) {
    power += pow(2, n) * get_bit(&value, i + 96);
    n++;
  }
  return power;
}

int get_float_exp(float count) {
  int n = 7, power = 0;
  for (int i = 30; i >= 23; i--) {
    power += pow(2, n) * ((*(int *)&count & (1 << i)) >> i);
    n--;
  }
  power -= 127;
  return power;
}

// Устанавливает размер/масштаб числа

void set_exp(s21_decimal *value, int scale) {
  // if (scale >= 0 && scale <= 28) {
  //   int sign = get_sign(*value);  // получаем знак
  //   value->bits[3] &=
  //       ~(0xFF << 16);  // Устанавливает масштаб путём инвертирования битов
  //   value->bits[3] |= (scale << 16);  // присвоения нового значения scale.
  //   if (sign) set_sign(value, 1);  // если бит знака 1 то устанавливаем его
  // }
  // return value;
  for (int i = 15; i <= 23; i++) {
    set_bit(value, i + 97, scale & (1 << (i - 15)));
  }
}

// Возвращает значение знака числа используя битовую маску (1u << 31) для
// определения знака
int get_sign(s21_decimal value) {
  // int result = !!(value.bits[3] & (1u << 31));
  // return result;
  return (value.bits[3] & (1 << 31)) >> 31;
}

// Устанавливает значение знака числа используя битовую маску (1u << 31)
// s21_decimal *set_sign(s21_decimal *value, int bit) {
//   if (bit) {
//     value->bits[3] |=
//         (1u << 31);  // если знак минус (бит 1) то добавляем битовую маску
//   } else {
//     value->bits[3] &= ~(1u << 31);  // иначе инвертируем битовую маску
//   }
//   return value;
// }
void set_sign(s21_decimal *value, int bit) {
  if (bit)
    value->bits[3] |= (1 << 31);
  else
    value->bits[3] &= ~(1 << 31);
}

void shift_left(s21_decimal *value) {
  s21_decimal tmp = {0};
  for (int i = 1; i <= 96; i++)
    if (get_bit(value, i - 1)) set_bit(&tmp, i, 1);
  value->bits[0] = tmp.bits[0];
  value->bits[1] = tmp.bits[1];
  value->bits[2] = tmp.bits[2];
}

void shift_right(s21_decimal *value) {
  s21_decimal tmp = {0};
  for (int i = 0; i <= 96; i++)
    if (get_bit(value, i + 1)) set_bit(&tmp, i, 1);
  value->bits[0] = tmp.bits[0];
  value->bits[1] = tmp.bits[1];
  value->bits[2] = tmp.bits[2];
}

void div_ten(s21_decimal *value) {
  int exp = -1;
  int exp_value = get_exp(*value);
  int sign = get_bit(value, 127);
  s21_decimal sum = {0};
  s21_decimal ten = {0};
  s21_from_int_to_decimal(10, &ten);
  if (sign) set_bit(value, 127, 0);
  set_exp(value, 0);
  while (s21_is_greater_or_equal(*value, ten)) {
    s21_from_int_to_decimal(10, &ten);
    do {
      if (exp != -1) shift_left(&ten);
      exp++;
    } while (s21_is_less_or_equal(ten, *value) && exp <= 91);
    s21_decimal dst = {0};
    set_bit(&dst, exp - 1, 1);
    s21_add(dst, sum, &sum);
    shift_right(&ten);
    s21_sub(*value, ten, value);
    exp = -1;
    s21_from_int_to_decimal(10, &ten);
  }
  if (sign) set_bit(&sum, 127, 1);
  if (exp_value != 0) set_exp(&sum, exp_value - 1);
  value->bits[0] = sum.bits[0];
  value->bits[1] = sum.bits[1];
  value->bits[2] = sum.bits[2];
  value->bits[3] = sum.bits[3];
}

int mul_ten(s21_decimal value_1, s21_decimal *result) {
  int array_2[100] = {0}, array_4[100] = {0};
  int error = 0;
  int power = get_exp(value_1);
  int sign = get_bit(&value_1, 127);
  init_decimal_null(result);
  for (int j = 3; j <= 99; j++) {
    array_2[j - 2] = get_bit(&value_1, j - 3);
    array_4[j] = get_bit(&value_1, j - 3);
  }
  int rest = 0;
  for (int j = 1; j <= 95; j++) {
    if (array_2[j] + array_4[j] + rest == 1) {
      set_bit(result, j, 1);
      rest = 0;
    } else if (array_2[j] + array_4[j] + rest == 2)
      rest = 1;
    else if (array_2[j] + array_4[j] + rest == 3) {
      set_bit(result, j, 1);
      rest = 1;
    } else
      rest = 0;
  }
  set_sign(result, sign);
  set_exp(result, power + 1);
  if (rest && get_bit(&value_1, 127))
    error = 2;
  else if (rest)
    error = 1;
  return error;
}

int normalized_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  int power_1 = get_exp(*value_1);
  int power_2 = get_exp(*value_2);
  s21_decimal tmp_1 = *value_1;
  s21_decimal tmp_2 = *value_2;
  int return_value = 0;
  while (power_1 != power_2 && return_value == 0) {
    tmp_1 = *value_1;
    tmp_2 = *value_2;
    if (power_1 > power_2 && power_2 < 28) {
      return_value = mul_ten(*value_2, value_2);
      power_2++;
    } else if (power_1 < power_2 && power_1 < 28) {
      return_value = mul_ten(*value_1, value_1);
      power_1++;
    } else if (power_2 > 28) {
      div_ten(value_2);
      power_2--;
    } else if (power_1 > 28) {
      div_ten(value_1);
      power_1--;
    }
  }
  if (return_value && power_1 > 3 && power_2 > 3) {
    *value_1 = tmp_1;
    *value_2 = tmp_2;
    power_1 = get_exp(*value_1);
    power_2 = get_exp(*value_2);
    while (power_1 != power_2) {
      if (power_1 < power_2) {
        div_ten(value_2);
        power_2--;
      } else {
        div_ten(value_1);
        power_1--;
      }
    }
    return_value = 0;
  }
  return return_value;
}

void set_big_decimal(s21_big_decimal *value_1, s21_decimal value_2) {
  for (int t = 0; t < 3; t++) {
    value_1->bits[t] = value_2.bits[t];
  }
  value_1->bits[7] = value_2.bits[3];
}

s21_decimal s21_decimal_get_max(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  return result;
}