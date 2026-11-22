#include <stdlib.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  if (!str) return s21_NULL;
  size_t length = s21_strlen(str);
  char *result = malloc(length + 1);
  if (result) {
    for (size_t i = 0; i <= length; ++i) {
      char c = str[i];
      result[i] = (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
    }
  }
  return result;
}
