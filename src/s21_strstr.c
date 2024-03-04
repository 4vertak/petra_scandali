#include "s21_string.h"

// Находит первое вхождение всей строки
//  needle (не включая завершающий нулевой символ), которая появляется в строке
//  haystack.

char* s21_strstr(const char* haystack, const char* needle) {
  if (*needle == '\0') return (char*)haystack;

  for (int i = 0; haystack[i] != '\0'; i++) {
    if (haystack[i] == needle[0]) {
      int j = 0;
      while (needle[j] != '\0' && haystack[i + j] != '\0' &&
             haystack[i + j] == needle[j])
        j++;
      if (needle[j] == '\0') return (char*)&haystack[i];
    }
  }
  return NULL;
}