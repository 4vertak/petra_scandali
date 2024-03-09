#include "s21_string.h"

// Вычисляет длину строки str, не включая завершающий нулевой символ.

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;

  while (*str != '\0') {
      count++;
      str++;
  }

  return count;
  // s21_size_t l = 0;
  // for (; str[l];) {
  //   l += 1;
  // }
  // return l;
}
