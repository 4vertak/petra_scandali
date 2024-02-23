#include "s21_string.h"

// возвращает адрес символа c в строке s, начиная с головы, или NULL, если
// строка s не содержит символ c

char *s21_strchr(const char *str, int c) {
  s21_size_t i = 0;
  while (*str) {
    if (str[i] == c) {
      return (void *)&str[i];
    }
    i++;
  }
  return s21_NULL;
}