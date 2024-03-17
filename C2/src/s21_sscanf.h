#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include "./s21_string.h"

#define MAX_LENGTH 4096

typedef struct {
  int format;   //
  int count;    //
  int width;    //
  int length;   //
  int end;      //
  int extr;     //
  int skipws;   //
  char buffer;  //
} setting;

void proc_character(char **src, setting *modified, const char *format);
char *s21_strcpy(char *dest, const char *src);
void trim_space_and_count(char **src, setting *modified);
int setting_mod(char **src, setting *modified, const char *format);
int processformat(va_list args, setting *modified, char **src,
                  const char *format);
int mod_c(va_list args, setting *modified, char **src);
void valid_buff(char **src, setting *modified);
void remove_spaces_and_newlines(char *str);
void process_sign(char *str, int *sign);
int determine_base(char *str, int base);
long convert_str_to_int(char *str, char **strlim, int base);
s21_size_t s21_strspn(const char *str, const char *accept);
int mod_d(va_list args, setting *modified, char **src, int base);
int mod_s(va_list args, setting *modified, char **src);
void valid_buff(char **src, setting *modified);
int mod_u(va_list args, setting *modified, char **src, int base);
void mod_n(va_list args, setting *modified);
char *s21_strstr(const char *haystack, const char *needle);
int delimiter(va_list args, setting *modified, char **src, const char *format);
void mod_percent(char **src, setting *modified, const char *format);

#endif  //  SRC__SSCANF_H_