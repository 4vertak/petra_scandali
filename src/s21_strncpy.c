#include "s21_string.h"

//   Копирует до n символов из строки, на которую указывает src, в dest.

// char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
//   int src_length = s21_strlen(src);
//   int cpy_length = n > src_length
//                        ? (src_length + 1)
//                        : n;  // comparison of integer expressions of
//                        different
//                              // signedness: ‘int’ and ‘s21_size_t’
//   for (int x = 0; x < cpy_length;
//        x += 1) {  // таже ошибка
//     dest[x] = src[x];
//   }
//   return dest;
// }

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  // s21_strlen(src) - не использую, т.е. исключаю зависимость при проверке от
  // s21_strlen вместо этого бегу по строке до конца или до n
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  // добавил проверку если в src не хватает символов для копирования или если её
  // длина меньше n, то в dest добавляются '\0'/нуль)))
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}