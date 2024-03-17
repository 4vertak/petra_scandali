#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  if (*str == '\0') return s21_NULL;
  while ((*str != '\0') && (*str != c)) {
    str++;
  }
  if (*str == c) {
    return (char *)str;
  } else {
    return s21_NULL;
  }
}
