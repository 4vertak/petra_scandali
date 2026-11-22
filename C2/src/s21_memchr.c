#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *bytes = str;
  for (s21_size_t i = 0; i < n; ++i) {
    if (bytes[i] == (unsigned char)c) return (void *)(bytes + i);
  }
  return s21_NULL;
}
