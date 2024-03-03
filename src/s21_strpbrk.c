#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.

// char* s21_strpbrk(const char* str1, const char* str2) {
//   s21_size_t str_length = s21_strlen(str1);
//   s21_size_t shift = 0;//(индекс для сдвига про строке)
//   int status = 0; // если =1 то найден одинаковй символ

//   for (shift = 0; status == 0 && shift < str_length; shift += 1) { //ищем
//   есть ли одинаковый символ и если есть status = 1
//     if (s21_strchr(str2, str1[shift])) status = 1;
//   }
// возвращаем символ или NULL;
//   return (char*)(status ? (str1 + shift) : s21_NULL);
// }

char* s21_strpbrk(const char* str, const char* chars) {
  // s21_strlen(src) - не использую, т.е. исключаю зависимость при
  // проверке, просто бегу до конца строки
  const char* ptr_c;
  while (*str) {
    ptr_c = chars;
    while (*ptr_c) {
      // s21_strchr  - не использую, т.е. исключаю зависимость при проверке.
      // перебираю циклом равен ли символ в str символу в chars.
      if (*str == *ptr_c) {  // Если символы совпадают, возвращаем указатель на
                             // символ в str.
        return (char*)str;
      }
      ptr_c++;
    }
    str++;
  }
  return s21_NULL;
}