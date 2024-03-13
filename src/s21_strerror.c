#include "s21_string.h"  // не забудь убрать

#ifndef S21_ERRLIST_H
#define S21_LINUX_ERRLIST_SIZE 134
#define S21_MACOS_ERRLIST_SIZE 107
#define BUFF_SIZE 128

#endif

char *s21_strerror(int errnum) {
  char *res = s21_NULL;
  static char s21_undef[BUFF_SIZE] = {'\0'};
  static const char *const s21_macos_errlist[S21_MACOS_ERRLIST_SIZE] = {MACOS_ERRORS};
  static const char *const s21_linux_errlist[S21_LINUX_ERRLIST_SIZE] = {LINUX_ERRORS};
  if (LINUX) {
    if (errnum < 0 || errnum >= S21_LINUX_ERRLIST_SIZE) {
      s21_sprintf(s21_undef, "Unknown error %d", errnum);  // не забудь убрать
      res = s21_undef;
    } else {
      res = (char *)s21_linux_errlist[errnum];
    }
  } else if (MAC_OS) {
    if (errnum < 0 || errnum >= S21_MACOS_ERRLIST_SIZE) {
      s21_sprintf(s21_undef, "Unknown error %d", errnum);  // не забудь убрать
      res = s21_undef;
    } else {
      res = (char *)s21_macos_errlist[errnum];
    }
  }
  return res;
}