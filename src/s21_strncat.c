#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_length = 0;
  while (dest[dest_length] != '\0') {
    dest_length++;
  }

  s21_size_t src_length = 0;
  while (src[src_length] != '\0' && src_length < n) {
    dest[dest_length + src_length] = src[src_length];
    src_length++;
  }
  dest[dest_length + src_length] = '\0';

  return dest;
}