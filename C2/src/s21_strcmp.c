#include "./s21_string.h"

int s21_strcmp(char* str1, char* str2) {
  while (*str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}