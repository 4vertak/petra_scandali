#include "s21_string.h"

// возвращает адрес символа c в строке s, начиная с головы, или NULL, если
// строка s не содержит символ c
char *s21_strchr(const char *str, int c) {
    int i = 0;
    while (str[i] != s21_NULL) {
        if (str[i] == c) {
            return str + i;
        }
        i++;
    }
    return s21_NULL;
}  