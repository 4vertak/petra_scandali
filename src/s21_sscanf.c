#include "s21_sscanf.h"

#include <string.h>

int _sscanf(const char *str, const char *format, ...) {
  int success_assign = 0, status = 0, ind_form = 0, ind_str = 0, flag = 0;
  char tmp_str[LEN_STR] = {0};
  sscanf_format format_str;
  format_str.count_symb = 0, format_str.spaces = 0;
  va_list input;
  va_start(input, format);
  int len_form = (int)s21_strlen(format), len_str = (int)s21_strlen(str);
  success_assign += check_valid_str(len_str, len_form);
  while (ind_form < len_form) {
    if (format[ind_form] == '%') {
      clear_format_str(&format_str);
      ind_form = fill_format_str(&format_str, format, ind_form);
      if (ind_str >= len_str && format_str.spec != 'n') {
        flag = 1;
      }
      if (format_str.spec == '%' && flag == 0) {
        ind_str = check_percent(str, ind_str, &flag);
      } else if (flag == 0) {
        success_assign += check_valid_data(str, &format_str, len_str);
        if (format_str.asterisk != 1) {
          format_str.arg = va_arg(input, void *);
        }
        if (format_str.spec != 'n') {
          ind_str =
              take_and_assign(str, tmp_str, &format_str, ind_str, &status);
          if (status) {
            success_assign += status;
            s21_memset(format_str.str_to_assign, 0,
                       s21_strlen(format_str.str_to_assign));
          } else if (!status && format_str.asterisk != 1) {
            flag = 1;
          }
        } else {
          add_count_symb(&format_str, ind_str, len_str, len_form, ind_form);
          apply_spec(&format_str);
        }
        format_str.spaces = 0;
      }
    } else {
      ind_str =
          check_valid_char(&format_str, str, ind_str, format[ind_form], &flag);
      ind_form++;
    }
    if (flag == 1) {
      break;
    }
  }
  va_end(input);
  return success_assign;
}

void add_count_symb(sscanf_format *format_str, int ind_str, int len_str,
                    int len_form, int ind_form) {
  if (format_str->spaces == 1 && ind_str != len_str) {
    format_str->count_symb++;
  }
  if (ind_form == len_form && format_str->spaces == 1) {
    while (ind_str < len_str - 1) {
      format_str->count_symb++;
      ind_str++;
    }
  }
}

int check_percent(const char *str, int ind_str, int *flag) {
  while (isspace(str[ind_str])) {
    ind_str++;
  }
  if (str[ind_str] != '%') {
    *flag = 1;
  } else {
    ind_str++;
  }
  return ind_str;
}

int check_valid_char(sscanf_format *format_str, const char *str, int ind_str,
                     char form_char, int *flag) {
  if (isspace(form_char) != 0) {
    format_str->spaces = 1;
  } else {
    while (isspace(str[ind_str]) != 0) {
      ind_str++;
      format_str->count_symb++;
    }
    if (str[ind_str] == form_char) {
      ind_str++;
      format_str->count_symb++;
    } else {
      *flag = 1;
    }
  }
  return ind_str;
}

int check_valid_str(int len_str, int len_form) {
  int success_assign = 0;
  if (len_str == 0) {
    success_assign = -1;
  }
  if (len_form == 0) {
    fprintf(stderr, "zero-length scanf format string\n");
  }
  return success_assign;
}

int check_valid_data(const char *str, sscanf_format *format_str, int len_str) {
  int success_assign = 0;
  if (s21_strchr("dieEfgGouxXp", format_str->spec)) {
    for (int i = 0; i < len_str; i++) {
      success_assign = -1;
      if (isspace(str[i]) == 0) {
        success_assign = 0;
        break;
      }
    }
  }
  return success_assign;
}

int take_and_assign(const char *str, char *tmp_str, sscanf_format *format_str,
                    int ind_str, int *status_count) {
  s21_memset(tmp_str, 0, s21_strlen(tmp_str));
  ind_str = split_str(str, tmp_str, format_str, ind_str);
  if (format_str->asterisk != 1) {
    *status_count = apply_spec(format_str);
  } else {
    *status_count = 0;
  }
  return ind_str;
}

int fill_format_str(sscanf_format *format_str, const char *format, int index) {
  index++;
  if (format[index] == '*') {
    format_str->asterisk = 1;
    index++;
  }
  if (isdigit(format[index])) {
    int ascii_shift = 48;
    format_str->width = 0;
    while (isdigit(format[index]) && format[index]) {
      format_str->width = format_str->width * 10 + format[index] - ascii_shift;
      index++;
    }
  }
  format_str->width_const = format_str->width;
  if (format[index] == 'h' || format[index] == 'l' || format[index] == 'L') {
    format_str->length = format[index];
    index++;
  }
  if (s21_strchr("cdieEfgGosuxXpn%", format[index])) {
    format_str->spec = format[index];
    index++;
  }
  return index;
}

void clear_format_str(sscanf_format *format_str) {
  format_str->asterisk = 0;
  format_str->width = -1;
  format_str->width_const = 0;
  format_str->length = 0;
  format_str->spec = 0;
  format_str->arg = NULL;
}

int split_str(const char *str, char *tmp_str, sscanf_format *format_str,
              int ind_str) {
  int flag_width = 0, flag_break = 1;
  if (format_str->width == 0 || format_str->width == -1) {
    format_str->width = 1;
    flag_width = 1;
  }
  while (((format_str->spec != 'c') || format_str->spaces == 1) &&
         isspace(str[ind_str]) != 0 && str[ind_str]) {
    ind_str++;
    format_str->count_symb++;
  }
  int index_tmp_str = 0;
  if (s21_strchr("dieEfgGouxXp", format_str->spec) &&
      (str[ind_str] == '+' || str[ind_str] == '-')) {
    tmp_str[index_tmp_str] = str[ind_str];
    if (flag_width == 0) {
      format_str->width--;
    }
    ind_str++;
    index_tmp_str++;
  }
  int inf_nan = 0;
  while (str[ind_str] && format_str->width && flag_break) {
    if (!check_numb(str, tmp_str, format_str, ind_str, flag_width, &inf_nan)) {
      break;
    }
    tmp_str[index_tmp_str] = str[ind_str];
    index_tmp_str++;
    ind_str++;
    format_str->count_symb++;
    if (format_str->spec == 'c') {
      flag_break = 0;
    }
    if (flag_width == 0) {
      format_str->width--;
    }
  }
  if (inf_nan) {
    if (inf_nan == 1) {
      s21_strcat(tmp_str, "inf");
    } else {
      s21_strcat(tmp_str, "nan");
    }
    ind_str += 3;
  }
  strcpy(format_str->str_to_assign, tmp_str);
  return ind_str;
}

int check_numb(const char *str, char *tmp_str, sscanf_format *format_str,
               int ind_str, int flag, int *inf_nan) {
  int status = 1;
  if (s21_strchr("dieEfgGouxXp", format_str->spec) && !isdigit(str[ind_str])) {
    if (s21_strchr("dou", format_str->spec)) {
      status = 0;
    }
    if (!check_hex(format_str, tmp_str, str[ind_str], flag)) {
      status = 0;
    }
    if (!check_double(format_str, tmp_str, str[ind_str])) {
      status = 0;
    }
    if (s21_strchr("eEfgG", format_str->spec) &&
        s21_strchr("iInN", str[ind_str])) {
      int res = check_inf_nan(str, ind_str);
      if (res == 1 || res == 2) {
        *inf_nan = res;
      }
      status = 0;
    }
    if (format_str->spec == 'o' &&
        (str[ind_str] == '8' || str[ind_str] == '9')) {
      status = 0;
    }
  }
  if (format_str->spec != 'c' && isspace(str[ind_str])) {
    status = 0;
  }
  return status;
}

int check_hex(sscanf_format *format_str, char *tmp_str, char symbol, int flag) {
  int status = 1;
  if (s21_strchr("ixXp", format_str->spec) &&
      !s21_strchr("xXaAbBcCdDeEfF", symbol)) {
    status = 0;
  }
  if (s21_strchr("ixXp", format_str->spec)) {
    if (s21_strchr("xX", symbol) &&
        ((tmp_str[0] != '0' && tmp_str[1] != '0') || s21_strchr(tmp_str, 'x') ||
         s21_strchr(tmp_str, 'X'))) {
      status = 0;
    }
    if (flag == 0 && (((tmp_str[0] == '-' || tmp_str[0] == '+') &&
                       format_str->width_const < 4) ||
                      ((tmp_str[0] != '-' && tmp_str[0] != '+') &&
                       format_str->width_const < 3))) {
      status = 0;
    }
  }
  if (s21_strchr("ip", format_str->spec) && !s21_strchr("xX", symbol)) {
    if ((tmp_str[0] != '0' || (tmp_str[1] != 'x' && tmp_str[1] != 'X')) &&
        (tmp_str[1] != '0' || (tmp_str[2] != 'x' && tmp_str[2] != 'X'))) {
      status = 0;
    }
  }
  return status;
}

int check_double(sscanf_format *format_str, char *tmp_str, char symbol) {
  int status = 1;
  if (s21_strchr("eEfgG", format_str->spec)) {
    if (!s21_strchr("eE.+-", symbol)) {
      status = 0;
    }
    if (s21_strchr("eE", symbol) &&
        (s21_strchr(tmp_str, 'e') || s21_strchr(tmp_str, 'E'))) {
      status = 0;
    }
    if (symbol == '.' && s21_strchr(tmp_str, '.')) {
      status = 0;
    }
  }
  return status;
}

int check_inf_nan(const char *string, int index_str) {
  int status = 0;
  char tmp_str[LEN] = {0};
  for (int i = 0; i < 3; i++) {
    tmp_str[i] = string[index_str + i];
  }
  char *upper_str = to_upper(tmp_str);
  if (s21_strcmp(upper_str, "INF") == 0) {
    status = 1;
  } else if (s21_strcmp(upper_str, "NAN") == 0) {
    status = 2;
  }
  free(upper_str);
  return status;
}

int apply_spec(sscanf_format *format_str) {
  size_t successful_assignments_count = 0;
  switch (format_str->spec) {
    case 'c':
      successful_assignments_count += assign_spec_c(format_str);
      break;
    case 'd':
    case 'i':
      successful_assignments_count += assign_spec_di(format_str);
      break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
      successful_assignments_count += assign_spec_ouxX(format_str);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      successful_assignments_count += assign_spec_eEfgG(format_str);
      break;
    case 's':
      successful_assignments_count += assign_spec_s(format_str);
      break;
    case 'p':
      successful_assignments_count += assign_spec_p(format_str);
      break;
    case 'n':
      successful_assignments_count += assign_spec_n(format_str);
      break;
    default:
      fprintf(stderr, "unknown conversion type\n");
      break;
  }
  return successful_assignments_count;
}

int assign_spec_c(sscanf_format *format_str) {
  if (format_str->length == 'l') {
    *((wchar_t *)format_str->arg) = format_str->str_to_assign[0];
  } else if (format_str->length == 0) {
    *((char *)format_str->arg) = format_str->str_to_assign[0];
  }
  return 1;
}

int assign_spec_di(sscanf_format *format_str) {
  long int number = 0;
  int status = make_number(format_str, &number);
  if (status == 1) {
    if (format_str->length == 'h') {
      *((short int *)format_str->arg) = number;
    } else if (format_str->length == 'l') {
      *((long int *)format_str->arg) = number;
    } else {
      *((int *)format_str->arg) = number;
    }
  }
  return status;
}

int assign_spec_eEfgG(sscanf_format *format_str) {
  long double number = 0;
  int status = make_double_number(format_str, &number);
  if (status == 1) {
    if (format_str->length == 'L') {
      *((long double *)format_str->arg) = number;
    } else if (format_str->length == 'l') {
      *((double *)format_str->arg) = number;
    } else {
      *((float *)format_str->arg) = (float)number;
    }
  }
  return status;
}

int assign_spec_ouxX(sscanf_format *format_str) {
  long int number = 0;
  int status = make_number(format_str, &number);
  if (status == 1) {
    if (format_str->length == 'h') {
      *((unsigned short int *)format_str->arg) = number;
    } else if (format_str->length == 'l') {
      *((unsigned long int *)format_str->arg) = number;
    } else {
      *((unsigned int *)format_str->arg) = number;
    }
  }
  return status;
}

int assign_spec_s(sscanf_format *format_str) {
  if (format_str->length == 0) {
    strcpy(format_str->arg, format_str->str_to_assign);
  } else if (format_str->length == 'l') {
    int length = (int)s21_strlen(format_str->str_to_assign);
    wchar_t *p = (wchar_t *)format_str->arg;
    for (int i = 0; i < length; i++) {
      *p = format_str->str_to_assign[i];
      p++;
    }
    *p = '\0';
  }
  return 1;
}

int assign_spec_p(sscanf_format *format_str) {
  long int number = 0;
  make_number(format_str, &number);
  *((int *)format_str->arg) = (int)number;
  return 1;
}

int make_number(sscanf_format *format_str, long int *number) {
  int sign = 1, index = 0, status = 1, shift_str = 0, flag = 0;
  char digits[LEN_STR] = "0123456789ABCDEF";
  char *upper_str_to_assign = to_upper(format_str->str_to_assign);
  int length = (int)s21_strlen(format_str->str_to_assign);
  int sys_num = get_sys(format_str, &shift_str);
  if (get_sign(format_str, &sign)) {
    index++;
  }
  index += shift_str;
  for (; index < length; index++) {
    int position = 0;
    position = s21_strchr(digits, upper_str_to_assign[index]) - digits;
    if (position < sys_num) {
      *number = sys_num * *number + position;
      flag = 1;
    } else {
      break;
    }
  }
  *number *= sign;
  if (flag == 0) {
    status = 0;
    if ((length == 2 || length == 3) && sys_num == 16) {
      status = 1;
    }
  }
  free(upper_str_to_assign);
  return status;
}

int get_sign(sscanf_format *format_str, int *sign) {
  int status = 0;
  if (format_str->str_to_assign[0] == '-' ||
      format_str->str_to_assign[0] == '+') {
    if (format_str->str_to_assign[0] == '-') {
      *sign = -1;
    }
    status = 1;
  }
  return status;
}

int get_sys(sscanf_format *format_str, int *shift_str) {
  int sys_num = 10, index = 0;
  if (format_str->str_to_assign[index] == '+' ||
      format_str->str_to_assign[index] == '-') {
    index++;
  }
  if (format_str->spec == 'o' ||
      (format_str->str_to_assign[index] == '0' &&
       format_str->str_to_assign[index + 1] != 'x')) {
    sys_num = 8;
  }
  if (format_str->spec == 'x' || format_str->spec == 'X' ||
      format_str->spec == 'p') {
    sys_num = 16;
  }
  if (format_str->str_to_assign[index] == '0' &&
      (format_str->str_to_assign[index + 1] == 'x' ||
       format_str->str_to_assign[index + 1] == 'X')) {
    sys_num = 16;
    *shift_str = 2;
  }
  return sys_num;
}

int make_double_number(sscanf_format *format_str, long double *number) {
  int sign = 1, index_str = 0, status = 1, sys_num = 10, index_point = -1,
      flag = 0;
  char digits[LEN_STR] = "0123456789";
  int length = (int)s21_strlen(format_str->str_to_assign);
  if (get_sign(format_str, &sign)) {
    index_str++;
  }
  for (; index_str < length; index_str++) {
    if (format_str->str_to_assign[index_str] == '.') {
      index_point = index_str;
      index_str++;
    }
    if (s21_strchr(digits, format_str->str_to_assign[index_str])) {
      int position = 0;
      position =
          s21_strchr(digits, format_str->str_to_assign[index_str]) - digits;
      if (position < sys_num) {
        *number = sys_num * *number + position;
        flag = 1;
      }
    } else {
      break;
    }
  }
  *number *= sign * make_point_e(format_str, index_point, length);
  if (flag == 0 || length == 0) {
    if (make_inf_nan(format_str, sign)) {
      *number = make_inf_nan(format_str, sign);
    } else {
      status = 0;
    }
  }
  return status;
}

long double make_point_e(sscanf_format *format_str, int ind_point, int len) {
  long double multiplier = 1.0;
  int sign_e = 1, power = 0;
  int index_e = is_e(format_str, &sign_e, &power);
  if (ind_point != -1 && index_e) {
    multiplier *=
        (1 / pow(10, index_e - ind_point - 1)) * pow(10, power * sign_e);
  }
  if (ind_point != -1 && !index_e) {
    multiplier /= pow(10, len - ind_point - 1);
  }
  if (ind_point == -1 && index_e) {
    multiplier *= pow(10, power * sign_e);
  }
  return multiplier;
}

long double make_inf_nan(sscanf_format *format_str, int sign) {
  long double number = 0;
  if (s21_strstr(format_str->str_to_assign, "inf")) {
    number = sign * INFINITY;
  } else if (s21_strstr(format_str->str_to_assign, "nan")) {
    if (sign == 1) {
      number = -NAN;
    } else {
      number = NAN;
    }
  }
  return number;
}

int is_e(sscanf_format *format_str, int *sign_e, int *power) {
  int index_e = 0, sys_num = 10;
  char digits[LEN_STR] = "0123456789";
  if (s21_strchr(format_str->str_to_assign, 'e')) {
    index_e =
        s21_strchr(format_str->str_to_assign, 'e') - format_str->str_to_assign;
  }
  if (s21_strchr(format_str->str_to_assign, 'E')) {
    index_e =
        s21_strchr(format_str->str_to_assign, 'E') - format_str->str_to_assign;
  }
  int length = (int)s21_strlen(format_str->str_to_assign);
  for (int i = index_e + 1; i < length; i++) {
    int position = 0;
    if (format_str->str_to_assign[i] == '-' ||
        format_str->str_to_assign[i] == '+') {
      if (format_str->str_to_assign[i] == '-') {
        *sign_e = -1;
      }
      i++;
    }
    position = s21_strchr(digits, format_str->str_to_assign[i]) - digits;
    if (position < sys_num) {
      *power = sys_num * *power + position;
    } else {
      break;
    }
  }
  return index_e;
}

int assign_spec_n(sscanf_format *format_str) {
  *((int *)format_str->arg) = (int)format_str->count_symb;
  return 1;
}

void *to_upper(const char *str) {
  char *result;
  result = NULL;
  if (str != NULL) {
    size_t length = s21_strlen(str);
    result = calloc(length + 1, sizeof(char));
    if (result != NULL) {
      for (size_t i = 0; i < length + 1; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
          result[i] = str[i] - 32;
        } else {
          result[i] = str[i];
        }
      }
      result[length] = '\0';
    }
  }
  return (void *)result;
}