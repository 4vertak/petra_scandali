#include "s21_string.h"

// возвращает адрес символа c в строке s, начиная с хвоста, или NULL, если
// строка s не содержит символ c
char *s21_strchr(const char *str, int c) {
    int i = 0;
    char *p = s21_NULL;
    while (str + i != s21_NULL) {
        if (str[i] == c) {
            p = (char*)(str + i);
        }
        i++;
    }
    return p;
}