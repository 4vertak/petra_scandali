#include "./s21_string.h"

char *s21_strrev(char *str) {
  int len = s21_strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
  return str;
}
