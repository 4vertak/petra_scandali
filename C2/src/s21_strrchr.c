#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last = s21_NULL;
  do {
    if (*str == (char)c) last = str;
  } while (*str++);
  return (char *)last;
}
