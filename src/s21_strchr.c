#include "s21_string.h"

// возвращает адрес символа c в строке s, начиная с головы, или NULL, если
// строка s не содержит символ c

// ОБА РАБОЧИЕ ФУНКЦИИ!!! причина segfault неправилдьное название strrchr - как
// strchr т.е. обращение шло на эту функцию и на функцию strrchr!!!!

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
