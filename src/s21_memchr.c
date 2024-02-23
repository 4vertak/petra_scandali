#include "s21_string.h"

// возвращает указатель на первое вхождение значения c среди первых n байтов s
// или NULL, если не найдено
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *str_ptr = (unsigned char *)str;
  unsigned char c_ptr = (unsigned char)c;
  s21_size_t tmp = n;
  while (--tmp > 0 && *str_ptr++ != c_ptr) {
    if (*str_ptr == c_ptr && n != 0) {
      return (void *)str_ptr;
      break;
    }
  }
  return s21_NULL;
}