#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) return s21_NULL;
  if (!trim_chars) trim_chars = "";
  while (*src && s21_strchr(trim_chars, *src)) ++src;
  size_t length = s21_strlen(src);
  while (length && s21_strchr(trim_chars, src[length - 1])) --length;

  char *result = malloc(length + 1);
  if (result) {
    s21_memcpy(result, src, length);
    result[length] = '\0';
  }
  return result;
}
