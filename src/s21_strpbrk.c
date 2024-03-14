#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.

char* s21_strpbrk(const char* str, const char* chars) {
  const char* ptr_c;
  while (*str) {
    ptr_c = chars;
    while (*ptr_c) {
      if (*str == *ptr_c) {
        return (char*)str;
      }
      ptr_c++;
    }
    str++;
  }
  return s21_NULL;
}