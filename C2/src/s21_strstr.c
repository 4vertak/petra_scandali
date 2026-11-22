#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (!*needle) return (char *)haystack;
  s21_size_t length = s21_strlen(needle);
  for (; *haystack; ++haystack) {
    if (s21_strncmp(haystack, needle, length) == 0) return (char *)haystack;
  }
  return s21_NULL;
}
