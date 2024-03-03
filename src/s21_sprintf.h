#ifndef SRC_HEADERS_S21_SPRINTF_H_
#define SRC_HEADERS_S21_SPRINTF_H_

#include <limits.h>
#include <stdarg.h>

#include "./s21_string.h"

typedef struct {
  char flag[10];
  int width;
  int accuracy;
  char type;
} setting;

int parce_setting_mode(int x, const char *format, setting *config,
                       va_list *params);
int proc_setting_mode(char *str, char symbol, setting config, va_list *params);
int modifier_c(char *str, va_list *params, char *flag, int accuracy, char type);
char *s21_conf(char *str, setting config);
char *str_to_str(char *str, va_list *params, int accuracy, char type);
char *int_to_str(char *str, int number, int accuracy, char *flag);
char *long_length(char *str, long int number, int accuracy, char *flag);
void reverse_str(char str[]);
char *short_length(char *str, short int number, int accuracy, char *flag);
char *u_to_str(char *str, unsigned int number, int format, int accuracy,
               char *flag);
char *long_u_to_str(char *str, unsigned long int number, int format,
                    int accuracy, char *flag);
char *short_u_to_str(char *str, unsigned short int number, int format,
                     int accuracy, char *flag);
char *s21_strcat(char *dest, const char *src);
void *s21_memmove(void *dest, const void *src, s21_size_t n);

#endif  // S21_SPRINTF_H_