#include "./s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *ptr_dest = dest;
  while (*dest) {
    dest++;
  }
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return ptr_dest;
}