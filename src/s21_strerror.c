#include "s21_string.h"

#ifndef S21_ERRLIST_H
#define S21_ERRLIST_SIZE 134
#define BUFF_SIZE 128

#endif

char *s21_strerror(int errnum) {
    char *res = s21_NULL;
    static char s21_undef[BUFF_SIZE] = {'\0'}; //s21_NULL
    static const char* const s21_errlist[S21_ERRLIST_SIZE] = {LINUX_ERRORS};
    if (errnum < 0 || errnum >= S21_ERRLIST_SIZE) {
        s21_sprintf(s21_undef, "Unknown error: %d", errnum);
        res = s21_undef;
    } else {
        res = (char*)s21_errlist[errnum];
    }
    return res;
}