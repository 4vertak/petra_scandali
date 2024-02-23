#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.
// лексикографическое сравнение строк (возвращает "0", если строки
// одинаковые, положительное, если первая строка больше, и отрицательное, если
// меньше)

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  s21_size_t i = 0;
  while (++i < n && *str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
    result = *((char *)str1 + i) - *((char *)str2 + i);
  }
  if (*str1 != *str2) result = *str1 - *str2;
  return result;
}