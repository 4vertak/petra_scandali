#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>

#include "./s21_string.h"

#define MY_INT_MIN (-2147483647 - 1)

typedef struct {
  char flag[10];
  int width;
  int precision;
  char type;
} setting;

int parce_setting_mode(int i, const char *format, setting *modified,
                       va_list *params);
int proc_setting_mode(char *str, char spec, setting modified, va_list *params);
char *adjust_width_space(char *str, setting modified, char spec);
int should_proc(setting modified, char spec, char *str);
void trim_zero(char *str);
void adjust_width(char *str, setting modified, char spec);
int fspec_c(char *str, va_list *params, char *flag, int precision, char type);
char *fspec_s(char *str, va_list *params, int precision, char type);
char *fspec_p(char *str, int *variable);
char *fspec_xXou(char *str, unsigned int number, int format, int precision,
                 char *flag);
char *fspec_eE(char *str, double number, int precision, char *flag, int spec,
               int ptr_accuracy);
char *fspec_eEL(char *str, long double number, int precision, char *flag,
                int spec, int ptr_accuracy);
char *fspec_di(char *str, int number, int precision, char *flag);
char *fspec_xXou_long(char *str, long unsigned int number, int format,
                      int precision, char *flag);
char *fspec_di_long(char *str, long int number, int precision, char *flag);
char *fspec_xXou_short(char *str, short unsigned int number, int format,
                       int precision, char *flag);
char *fspec_di_short(char *str, short int number, int precision, char *flag);
char *fspec_f_long(char *str, long double number, int decimal_ptr, char *flag,
                   int ptr_accuracy);
char *fspec_gG_long(char *str, long double number, int precision, char *flag,
                    int spec);
char *fspec_xXou_long(char *str, long unsigned int number, int format,
                      int precision, char *flag);
char *fspec_gG(char *str, double number, int precision, char *flag, int spec);
char *fspec_f(char *str, double number, int decimal_ptr, char *flag,
              int ptr_accuracy);

#endif  // S21_SPRINTF_H_
