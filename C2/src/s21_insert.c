#include <stdint.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str) return s21_NULL;
  size_t length = s21_strlen(src);
  size_t added = s21_strlen(str);
  if (start_index > length || added > SIZE_MAX - length - 1) return s21_NULL;

  char *result = malloc(length + added + 1);
  if (result) {
    s21_memcpy(result, src, start_index);
    s21_memcpy(result + start_index, str, added);
    s21_memcpy(result + start_index + added, src + start_index,
               length - start_index + 1);
  }
  return result;
}
