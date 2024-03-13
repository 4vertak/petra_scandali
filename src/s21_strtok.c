#include "s21_string.h"

char* s21_strtok(char *str, const char *delim) {
    static char* next_token = s21_NULL;
    if (str == s21_NULL && s21_strlen(delim) == 0) { //света: добавила проверку на НУЛЛ + пустую строку
        return s21_NULL;
    }
    if (str != s21_NULL) {
        next_token = str;
    }
    // if (next_token == s21_NULL) {  // закомментила, потому что не используется
    //     return s21_NULL;
    // }
    char* token_start = next_token;
    char* token_end = s21_NULL;
    while (*next_token != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*next_token == *d) {
                if (token_end != s21_NULL) {
                    *next_token = '\0';
                    next_token++;
                    return token_start;
                } else {
                    token_start++;
                    next_token++;
                    break;
                }
            }
            d++;
        }
        if (*d == '\0') {
            if (token_end == s21_NULL) {
                token_end = next_token;
            }
            next_token++;
        }
    }
    if (token_end != s21_NULL) {
        return token_start;
    } else {
        return s21_NULL;
    }
}
