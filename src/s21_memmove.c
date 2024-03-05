#include "./s21_string.h"

// void *s21_memmove(void *dest, const void *src, s21_size_t n) {
//   char *d = (char *)dest;
//   const char *s = (const char *)src;
//   if (d <= s || d >= s + n) {
//     while (n--) {
//       *d++ = *s++;
//     }
//   } else {
//     d += n - 1;
//     s += n - 1;
//     while (n--) {
//       *d-- = *s--;
//     }
//   }
//   return dest;
// }

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = dest;
  const unsigned char *s = src;

  if (d == s) {
    return d;
  }

  if (s < d && s + n > d) {
    s += n;
    d += n;
    while (n--) {
      *(--d) = *(--s);
    }
  } else {
    while (n--) {
      *d++ = *s++;
    }
  }

  return dest;
}