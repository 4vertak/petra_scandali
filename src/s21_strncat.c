#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

// char *s21_strncat(char *dest, const char *src, s21_size_t n) {
//   int src_length = s21_strlen(src); / длина строки

//   for (s21_size_t x = 0; x < n && src[x] != '\0'; x += 1) { //если x меньше n
//   и src !=0, то x++ и
//     dest[src_length + x] = src[x];
//     dest[src_length + x + 1] = '\0';
//   }

//   for (s21_size_t x = 0, src_length = s21_strlen(src); x < n && src[x] !=
//   '\0';
//        x += 1) {
//     dest[src_length + x] = src[x];
//     dest[src_length + x + 1] = '\0'; // я тут запутался в индексах))
//   }
//   return dest;
// }

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  // s21_strlen(src) - не использую, т.е. исключаю зависимость при проверке от
  // s21_strlen вместо этого бегу по строке до конца или до n
  // просто явно считаю длину строки, реально наверху ошибка из-за индекса

  s21_size_t dest_length = 0;
  while (dest[dest_length] != '\0') {
    dest_length++;
  }

  s21_size_t src_length = 0;
  while (src[src_length] != '\0' && src_length < n) {
    dest[dest_length + src_length] = src[src_length];
    src_length++;
  }
  dest[dest_length + src_length] = '\0';

  return dest;
}