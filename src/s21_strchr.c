#include "s21_string.h"

// возвращает адрес символа c в строке s, начиная с головы, или NULL, если
// строка s не содержит символ c

// поиск ошибки segfault используется индекс указателя на текущий символ - ВЫВОД
// ошибка segfault) char *s21_strchr(const char *str, int c) {
//   s21_size_t i = 0;
//   while (*str) {
//     if (str[i] == c) {
//       return (void *)&str[i];
//     }
//     i++;
//   }
//   return s21_NULL;
// }

// поиск ошибки segfault использую указатель на текущий символ  первый вариант
// char *s21_strchr(const char *str, int c) {
//     while (*str) {
//         if (*str == c) {
//             return (char *)str;
//         }
//         str++;
//     }
//     return s21_NULL;
// }
// поиск ошибки segfault использую указатель на текущий символ  второй вариант -
// более правильная логика обработки
char *s21_strchr(const char *str, int c) {
  if (*str == '\0') return s21_NULL;
  while ((*str != '\0') && (*str != c)) {
    str++;
  }
  if (*str == c) {
    return (char *)str;
  } else {
    return s21_NULL;
  }
}
