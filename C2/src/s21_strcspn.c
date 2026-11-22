#include "s21_string.h"

s21_size_t s21_strcspn(const char *str, const char *reject) {
  s21_size_t i = 0;
  while (str[i] && !s21_strchr(reject, str[i])) ++i;
  return i;
}
