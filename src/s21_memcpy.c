#include "s21_string.h"

// копирует n байт из области памяти src в dest, которые не должны пересекаться,
// в противном случае результат не определён (возможно как правильное
// копирование, так и нет)

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_ptr = (unsigned char *)dest;
  unsigned char *src_ptr = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; ++i) {
    *dest_ptr++ = *src_ptr++;
  }
  return dest;
}