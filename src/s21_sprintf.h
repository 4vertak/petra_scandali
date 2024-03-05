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

int parce_setting_mode(int i, const char *format, setting *modified,
                       va_list *params);
int proc_setting_mode(char *str, char symbol, setting config, va_list *params);
int format_string(char *str, va_list *params, char *flag, int accuracy,
                  char type);
char *adjust_width_space(char *str, setting modified, char symbol);

int should_proc(setting modified, char symbol, char *str);

void trim_zero(char *str);

void adjust_width(char *str, setting modified, char symbol);

char *str_formating(char *str, va_list *params, int accuracy, char type);
char *convert_int_to_str(char *str, int number, int accuracy, char *flag);
char *long_len(char *str, long int number, int accuracy, char *flag);

char *short_len(char *str, short int number, int accuracy, char *flag);
char *convert_unsig_to_str(char *str, unsigned int number, int format,
                           int accuracy, char *flag);
char *long_convert_unsig_to_str(char *str, unsigned long int number, int format,
                                int accuracy, char *flag);
char *short_convert_unsig_to_str(char *str, unsigned short int number,
                                 int format, int accuracy, char *flag);

#endif  // S21_SPRINTF_H_
