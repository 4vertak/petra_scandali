#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_ptr = (unsigned char *)str;
  unsigned char c_ptr = (unsigned char)c;
  s21_size_t tmp = n;
  while (tmp-- > 0) {
    *str_ptr++ = c_ptr;
  }
  return str;
}