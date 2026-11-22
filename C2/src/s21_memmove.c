#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *to = dest;
  const unsigned char *from = src;
  if (to == from) return dest;

  // Only a destination starting inside the source needs a backward copy.
  for (s21_size_t i = 1; i < n; ++i) {
    if (to == from + i) {
      while (n > 0) {
        --n;
        to[n] = from[n];
      }
      return dest;
    }
  }
  for (s21_size_t i = 0; i < n; ++i) to[i] = from[i];
  return dest;
}
