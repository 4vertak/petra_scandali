#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

#define LEN_STR 1000
#define LEN 100

int _sscanf(const char *str, const char *format, ...);

typedef struct sscanf_format_str {
  int asterisk;
  int width;
  int width_const;
  char length;
  char spec;
  char str_to_assign[LEN_STR];
  void *arg;
  int count_symb;
  int spaces;
} sscanf_format;

void add_count_symb(sscanf_format *format_str, int ind_str, int len_str,
                    int len_form, int ind_form);
int check_percent(const char *str, int ind_str, int *flag);
int check_valid_char(sscanf_format *format_str, const char *str, int ind_str,
                     char form_char, int *flag);
int check_valid_str(int len_str, int len_form);
int check_valid_data(const char *str, sscanf_format *format_str, int len_str);
int take_and_assign(const char *str, char *tmp_str, sscanf_format *format_str,
                    int ind_str, int *status_count);
int fill_format_str(sscanf_format *format_str, const char *format, int index);
void clear_format_str(sscanf_format *format_str);
int split_str(const char *str, char *tmp_str, sscanf_format *format_str,
              int ind_str);
int check_numb(const char *str, char *tmp_str, sscanf_format *format_str,
               int ind_str, int flag, int *inf_nan);
int check_hex(sscanf_format *format_str, char *tmp_str, char symbol, int flag);
int check_double(sscanf_format *format_str, char *tmp_str, char symbol);
int check_inf_nan(const char *string, int index_str);
int apply_spec(sscanf_format *format_str);
int assign_spec_c(sscanf_format *format_str);
int assign_spec_di(sscanf_format *format_str);
int assign_spec_eEfgG(sscanf_format *format_str);
int assign_spec_ouxX(sscanf_format *format_str);
int assign_spec_s(sscanf_format *format_str);
int assign_spec_p(sscanf_format *format_str);
int make_number(sscanf_format *format_str, long int *number);
int get_sign(sscanf_format *format_str, int *sign);
int get_sys(sscanf_format *format_str, int *shift_str);
int make_double_number(sscanf_format *format_str, long double *number);
long double make_point_e(sscanf_format *format_str, int ind_point, int len);
long double make_inf_nan(sscanf_format *format_str, int sign);
int is_e(sscanf_format *format_str, int *sign_e, int *power);
int assign_spec_n(sscanf_format *format_str);
void *to_upper(const char *str);

#endif  //  SRC__SSCANF_H_