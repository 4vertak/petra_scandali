#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  s21_size_t i = 0;
  while (++i < n && result == 0) {
    result = *((char *)str1 + i) - *((char *)str2 + i);
  }
  return result;
}