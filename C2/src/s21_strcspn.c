#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t c = 0;
  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        return c;
      }
    }
    c++;
  }
  return c;
}