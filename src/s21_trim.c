#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  int count = 0;

  if (src == s21_NULL) {
    return s21_NULL;
  }

  int src_length = 0, trim_chars_length = 0;
  while (src[src_length] != '\0') {
    src_length++;
  }
  if (trim_chars == s21_NULL) {
    res = malloc((src_length + 1) * sizeof(char));
    for (int i = 0; i < src_length; i++) {
      res[i] = src[i];
    }
    ((char *)res)[src_length] = '\0';
    return res;
  }
  while (trim_chars[trim_chars_length] != '\0') {
    trim_chars_length++;
  }

  for (int i = 0; i < src_length; i++) {
    int is_trim_char = 0;
    for (int j = 0; j < trim_chars_length; j++) {
      if (src[i] == trim_chars[j]) {
        is_trim_char = 1;
        break;
      }
    }
    if (!is_trim_char) {
      count++;
    }
  }
  res = malloc((count + 1) * sizeof(char));
  int c = 0;

  if (res != s21_NULL) {
    for (int i = 0; i < src_length; i++) {
      int is_trim_char = 0;
      for (int j = 0; j < trim_chars_length; j++) {
        if (src[i] == trim_chars[j]) {
          is_trim_char = 1;
          break;
        }
      }
      if (!is_trim_char) {
        ((char *)res)[c] = src[i];
        c++;
      }
    }
    ((char *)res)[count] = '\0';
  }

  return res;
}
