#include "s21_string.h"

// копирует n байт из области памяти src в dest, которые не должны пересекаться,
// в противном случае результат не определён (возможно как правильное
// копирование, так и нет)

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}