#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  int len_needle = s21_strlen(needle);
  int len_haystack = s21_strlen(haystack);
  char* res = s21_NULL;
  if (len_needle == 0) {
    res = (char*)haystack;
  } else {
    for (int i = 0; i < len_haystack; i++) {
      if (haystack[i] == needle[0]) {
        int j = 0;
        while (j != len_needle && haystack[i + j] != '\0' &&
               haystack[i + j] == needle[j])
          j++;
        if (j == len_needle) {
          res = (char*)&haystack[i];
          break;
        }
      }
    }
  }
  return res;
}