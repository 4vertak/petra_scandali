#include "s21_string.h"

// возвращает адрес символа c в строке s, начиная с хвоста, или NULL, если
// строка s не содержит символ c
// char *s21_strrchr(const char *str, int c) {
//   int i = 0;
//   char *p = s21_NULL;
//   while (str + i != s21_NULL) {
//     if (str[i] == c) {
//       p = (char *)(str + i);
//     }
//     i++;
//   }
//   return p;
// }
char *s21_strrchr(const char *str, int symbol) {
  int str_len = 1;
  while (str[str_len] != '\0') {
    str_len++;
  }
  const char *p = s21_NULL;
  for (int i = str_len; p == s21_NULL && i >= 1; i -= 1) {
    if (str[i] == symbol) p = (str + i);
  }
  return (char *)p;
}