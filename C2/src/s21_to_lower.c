#include "s21_string.h"

void *s21_to_lower(const char *str) {
  static char copy_str[MAX_LENGTH];
  s21_size_t str_length = s21_strlen(str);

  if (copy_str != s21_NULL) {
    s21_strncpy(copy_str, str, str_length + 1);
    for (char *i = copy_str; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') {
        *i += 32;
      }
    }
  }
  return (void *)copy_str;
}