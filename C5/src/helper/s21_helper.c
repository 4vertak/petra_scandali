#include "../s21_decimal.h"

int get_bit(s21_decimal *value, int index) {
  int num_bit = index / 32;
  int position = index % 32;
  return (value->bits[num_bit] & (1 << position)) >> position;
}

// Устанавливает или сбрасывает бит в position в соответствии с параметром bit.
// Если position / 32 < 4 и bit, то бит в position = 1 с
// помощью операции |=(1u << (pos % 32)). Если же position / 32 < 4 и !bit, то
// бит в position = 0 с помощью операции &=~(1u << (pos % 32))
s21_decimal *set_bit(s21_decimal *value, int position, int bit) {
  if (position / 32 < 4 && bit) {
    value->bits[position / 32] |= (1 << (position % 32));
  } else if (position / 32 < 4 && !bit) {
    value->bits[position / 32] &= ~(1 << (position % 32));
  }
  return value;
}

// Возвращает размер/масштаб числа используя его старший бит (value.bits3 >> 16)

int get_exp(s21_decimal value) {
  int power = 0, n = 0;
  for (int i = 16; i <= 23; i++) {
    power += pow(2, n) * get_bit(&value, i + 96);
    n++;
  }
  return power;
}

int get_scale(s21_decimal value) {
  int result = (char)(value.bits[3] >> 16);
  return result;
}

// Устанавливает размер/масштаб числа

s21_decimal *set_scale(s21_decimal *value, int scale) {
  if (scale >= 0 && scale <= 28) {
    int sign = get_sign(*value);  // получаем знак
    value->bits[3] &=
        ~(0xFF << 16);  // Устанавливает масштаб путём инвертирования битов
    value->bits[3] |= (scale << 16);  // присвоения нового значения scale.
    if (sign) set_sign(value, 1);  // если бит знака 1 то устанавливаем его
  }
  return value;
}

// Возвращает значение знака числа используя битовую маску (1u << 31) для
// определения знака
int get_sign(s21_decimal value) {
  int result = !!(value.bits[3] & (1u << 31));
  return result;
}

// Устанавливает значение знака числа используя битовую маску (1u << 31)
s21_decimal *set_sign(s21_decimal *value, int bit) {
  if (bit) {
    value->bits[3] |=
        (1u << 31);  // если знак минус (бит 1) то добавляем битовую маску
  } else {
    value->bits[3] &= ~(1u << 31);  // иначе инвертируем битовую маску
  }
  return value;
}