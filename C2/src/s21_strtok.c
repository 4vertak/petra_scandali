#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next;
  if (str) next = str;
  if (!next) return s21_NULL;

  while (*next && s21_strchr(delim, *next)) ++next;
  char *token = *next ? next : s21_NULL;
  next += s21_strcspn(next, delim);
  if (*next) {
    *next++ = '\0';
  } else {
    next = s21_NULL;
  }
  return token;
}
