
#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  va_list params;
  va_start(params, format);
  int counter = 0;
  for (int i = 0; format[i] != '\0'; i += 1) {
    if (format[i] == '%') {
      setting modified = {"xxxxx", INT_MIN, INT_MIN, 'x'};
      i = parce_setting_mode(i, format, &modified, &params);
      if (format[i] == 'n') {
        *(va_arg(params, int *)) = counter;
      } else {
        counter += insertStringBySettingifier(str + counter, format[i],
                                              modified, &params);
      }
    } else {
      str[counter] = format[i];
      str[counter += 1] = '\0';
    }
  }
  va_end(params);
  return counter;
}

int parce_setting_mode(int i, const char *format, setting *modified,
                       va_list *params) {
  for (i += 1; s21_strchr("-+ #0", format[i]); i += 1)
    (modified->flag)[5 - s21_strlen(s21_strchr("-+ #0", format[i]))] = 'o';
  for (; s21_strchr("0123456789", format[i]); i += 1)
    modified->width = (modified->width * 10) + (format[i] - 48);
  for (; format[i] == '*'; i += 1) modified->width = va_arg(*params, int);
  if (format[i] == '.') {
    for (i += 1; format[i] == '-'; i += 1) continue;
    for (; s21_strchr("0123456789", format[i]); i += 1)
      modified->precision = (modified->precision * 10) + (format[i] - 48);
    for (; format[i] == '*'; i += 1) modified->precision = va_arg(*params, int);
    modified->precision < 0 ? modified->precision = 0 : 0;
  }
  for (; s21_strchr("hlL", format[i]); i += 1) modified->type = format[i];
  return i;
}

int setBasePrecisionValue(int precision, int spec) {
  if (precision < 0) {
    s21_strchr("diouxX", spec) ? precision = 1 : 0;
    s21_strchr("eEfgG", spec) ? precision = 6 : 0;
    s21_strchr("p", spec) ? precision = 16 : 0;
  }
  return precision;
}

int insertStringBySettingifier(char *str, char spec, setting modified,
                               va_list *params) {
  char *flag = modified.flag;
  int indent = 0, precision = setBasePrecisionValue(modified.precision, spec);
  if (spec == '%') {
    s21_strcat(str, "%");
  } else if (spec == 'c') {
    return fspec_c(str + indent, params, flag, modified.width, modified.type);
  } else if (s21_strchr("di", spec)) {
    if (modified.type == 'h')
      fspec_di_short(str + indent, va_arg(*params, int), precision, flag);
    else if (modified.type == 'l')
      fspec_di_long(str + indent, va_arg(*params, long int), precision, flag);
    else
      fspec_di(str + indent, va_arg(*params, int), precision, flag);
  } else if (spec == 'p') {
    fspec_p(str + indent, va_arg(*params, void *));
  } else if (spec == 's') {
    fspec_s(str + indent, params, precision, modified.type);
  } else if (spec == 'f') {
    if (modified.type == 'L')
      fspec_f_long(str + indent, va_arg(*params, long double), precision, flag,
                   0);
    else
      fspec_f(str + indent, va_arg(*params, double), precision, flag, 0);
  } else if (s21_strchr("gG", spec)) {
    if (modified.type == 'L')
      fspec_gG_long(str + indent, va_arg(*params, long double), precision, flag,
                    spec);
    else
      fspec_gG(str + indent, va_arg(*params, double), precision, flag, spec);
  } else if (s21_strchr("eE", spec)) {
    if (modified.type == 'L')
      fspec_eEL(str + indent, va_arg(*params, long double), precision, flag,
                spec, 0);
    else
      fspec_eE(str + indent, va_arg(*params, double), precision, flag, spec, 0);
  } else if (s21_strchr("xX", spec)) {
    if (modified.type == 'h')
      fspec_xXou_short(str + indent, va_arg(*params, int),
                       spec == 'x' ? 32 : 16, precision, flag);
    else if (modified.type == 'l')
      fspec_xXou_long(str + indent, va_arg(*params, long int),
                      spec == 'x' ? 32 : 16, precision, flag);
    else
      fspec_xXou(str + indent, va_arg(*params, int), spec == 'x' ? 32 : 16,
                 precision, flag);
  } else if (spec == 'o') {
    if (modified.type == 'h')
      fspec_xXou_short(str + indent, va_arg(*params, unsigned int), 8,
                       precision, flag);
    else if (modified.type == 'l')
      fspec_xXou_long(str + indent, va_arg(*params, long unsigned int), 8,
                      precision, flag);
    else
      fspec_xXou(str + indent, va_arg(*params, unsigned int), 8, precision,
                 flag);
  } else if (spec == 'u') {
    if (modified.type == 'h')
      fspec_xXou_short(str + indent, va_arg(*params, unsigned int), 10,
                       precision, flag);
    else if (modified.type == 'l')
      fspec_xXou_long(str + indent, va_arg(*params, long unsigned int), 10,
                      precision, flag);
    else
      fspec_xXou(str + indent, va_arg(*params, unsigned int), 10, precision,
                 flag);
  }
  s21_strchr("n%c", spec) ? 0 : s21_conf(str + indent, modified, spec);
  return s21_strlen(str);
}

char *adjust_width_space(char *str, setting modified, char spec) {
  if (should_proc(modified, spec, str)) {
    trim_zero(str);
  }
  adjust_width(str, modified, spec);
  return str;
}

int should_proc(setting modified, char spec, char *str) {
  if (s21_strcmp(modified.flag, "xxxxx") || modified.width >= 0 ||
      modified.type != 'x') {
    if (s21_strchr("gG", spec) && modified.flag[3] != 'o') {
      if (!(s21_strlen(str) == 1 && str[0] == '0')) {
        return 1;
      }
    }
  }
  return 0;
}

void trim_zero(char *str) {
  for (int i = (s21_strlen(str) - 1); str[i] == '0'; str[i] = '\0', i -= 1) {
    continue;
  }
}

void adjust_width(char *str, setting modified, char spec) {
  char *tmp = str;
  char filler = ' ';
  int count_fill = modified.width > 0 ? modified.width - s21_strlen(str) : 0;

  if (modified.flag[4] == 'o') {
    tmp[0] == '-' ? tmp += 1 : 0;
    s21_strchr("cs", spec) ? 0 : (filler = '0');
  } else if (modified.flag[0] == 'o') {
    tmp += s21_strlen(tmp);
  }

  if (count_fill > 0) {
    for (s21_memmove(tmp + count_fill, tmp, s21_strlen(tmp) + 1);
         count_fill != 0;) {
      tmp[count_fill - 1] = filler;
      count_fill -= 1;
    }
  }
}

// char *s21_conf(char *str, setting modified, char spec) {
//   if (s21_strcmp(modified.flag, "xxxxx") || modified.width >= 0 ||
//       modified.type != 'x') {
//     if (s21_strchr("gG", spec) && modified.flag[3] != 'o') {
//       if (!(s21_strlen(str) == 1 && str[0] == '0')) {
//         for (int i = (s21_strlen(str) - 1); str[i] == '0';
//              str[i] = '\0', i -= 1)
//           continue;
//       }
//     }
//   }
//   char *tmp = str;
//   char filler = ' ';
//   int countFill = modified.width > 0 ? modified.width - s21_strlen(str) : 0;
//   if (modified.flag[4] == 'o') {
//     tmp[0] == '-' ? tmp += 1 : 0;
//     s21_strchr("cs", spec) ? 0 : (filler = '0');
//   } else if (modified.flag[0] == 'o') {
//     tmp += s21_strlen(tmp);
//   }
//   if (countFill > 0) {
//     for (s21_memmove(tmp + countFill, tmp, s21_strlen(tmp) + 1);
//          countFill != 0;) {
//       tmp[countFill - 1] = filler;
//       countFill -= 1;
//     }
//   }
//   return str;
// }

int fspec_c(char *str, va_list *params, char *flag, int precision, char type) {
  int counter = 0;
  precision = precision < 1 ? 1 : precision;
  if (type == 'l') {
    wchar_t w_c = va_arg(*params, wchar_t);
    counter = wcstombs(str + counter, &w_c, 512);
  } else {
    str[counter++] = va_arg(*params, int);
    str[counter] = '\0';
  }
  if (flag[0] != 'o' && precision - counter > 0) {
    s21_memmove(str + (precision - counter), str, counter + 1);
    for (int i = 0; i < precision - counter; i += 1) str[i] = ' ';
    counter = precision;
  }
  for (int i = counter; flag[0] == 'o' && i < (precision); i += 1)
    str[counter++] = ' ';
  return counter;
}

char *fspec_s(char *str, va_list *params, int precision, char type) {
  if (type == 'l') {
    wcstombs(str, va_arg(*params, wchar_t *), 512);
  } else {
    s21_strcat(str, va_arg(*params, char *));
  }
  precision < 0 ? precision = s21_strlen(str) : 0;
  str[precision] = '\0';
  return str;
}

char *fspec_p(char *str, int *variable) {
  int *tmp = variable;
  if (tmp == NULL) {
    s21_strcat(str, "0x0");
  } else {
    for (int i = s21_strlen(str); tmp != 0;
         tmp = ((void *)(((size_t)tmp) >> 4)), i += 1) {
      unsigned int last_spec = ((size_t)tmp) % 0x10;
      last_spec < 10 ? (str[i] = ('0' + last_spec))
                     : (str[i] = ('a' + (last_spec - 10)));
      str[i + 1] = '\0';
    }
    s21_strcat(str, "x0");
    s21_strrev(str);
  }
  return str;
}

char *fspec_xXou(char *str, unsigned int number, int format, int precision,
                 char *flag) {
  int len_str = 0, type = 97, numb = number;
  format == 32 ? format /= 2 : (type = 65);
  for (; (len_str < precision - 1) || (number / format) != 0;
       number /= format, len_str += 1)
    str[len_str] = (number % format) < 10 ? (number % format) + 48
                                          : ((number % format) - 10) + type;
  str[len_str++] = number < 10 ? number + 48 : (number - 10) + type;
  (flag[3] == 'o' && format == 8 && number != 0) ? str[len_str++] = '0' : 0;
  str[len_str] = '\0';
  (flag[3] == 'o' && format == 16 && type == 65 && numb != 0)
      ? s21_strcat(str, "X0")
      : 0;
  (flag[3] == 'o' && format == 16 && type == 97 && numb != 0)
      ? s21_strcat(str, "x0")
      : 0;
  s21_strrev(str);
  return str;
}

char *fspec_eEL(char *str, long double number, int precision, char *flag,
                int spec, int ptr_accuracy) {
  int len_str = 0;
  int len_num = 0;
  int result = 0;
  int ptr_precision = precision;
  char flagX[10] = "xxxxx";
  char flag1[10] = "xoxxx";
  if (number != 0) {
    for (int tmp = len_num = fabsl(number) < 1    ? 1
                             : fabsl(number) < 10 ? 0
                                                  : (-1);
         tmp != 0; len_num += tmp)
      tmp = ((fabsl(number) * powl(10, len_num)) < 1 ||
             10 < fabsl(number) * powl(10, len_num))
                ? tmp
                : 0;
  }
  fspec_di(str,
           (ptr_precision == 0 ? (roundl(number * powl(10, len_num)))
                               : (number * powl(10, len_num))),
           1, flag);
  (ptr_precision != 0 || flag[3] == 'o')
      ? s21_strcat(str, (localeconv()->decimal_point))
      : 0;
  for (len_str = s21_strlen(str); number < 0; number *= (-1)) continue;
  for (result = len_num; (precision != 0 && (len_num + 1) <= 0);
       precision -= 1) {
    if (precision == 1)
      fspec_di(str + (len_str++),
               roundl(fmodl((roundl(number) * powl(10, len_num += 1)), 10)), 1,
               flagX);
    else
      fspec_di(str + (len_str++), fmodl((number * powl(10, len_num += 1)), 10),
               1, flagX);
  }
  for (int tmp = len_num + 1; precision != 0; precision -= 1) {
    if (precision == 1)
      fspec_di(str + (len_str++),
               roundl(fmodl((number * powl(10, (tmp++))), 10)), 1, flagX);
    else
      fspec_di(str + (len_str++), fmodl((number * powl(10, (tmp++))), 10), 1,
               flagX);
  }
  if (ptr_accuracy == 1 && flag[3] != 'o') {
    for (int i = s21_strlen(str) - 1; s21_strchr("0.", str[i]); str[i--] = '\0')
      continue;
    for (int i = s21_strlen(str) - 1;
         s21_strchr((localeconv()->decimal_point), str[i]);)
      str[i--] = '\0';
  }
  len_str = s21_strlen(str);
  str[len_str++] = spec;
  str[len_str] = '\0';
  fspec_di(str + (len_str), -result, 2, flag1);
  return str;
}

char *fspec_f_long(char *str, long double number, int afterpoint, char *flag,
                   int ptr_accuracy) {
  char flagX[10] = "xxxxx";
  int len_str = 0, minus = 0, ptr_precision = afterpoint, k3 = 0;
  for (; number < 0; number *= (-1), minus = 1) continue;
  long double tmp =
      ceill((number - truncl(number)) * powl(10, afterpoint) - 0.5);
  for (; ((afterpoint != 0) || ((tmp / 10) > 1) || (fmodl(tmp, 10) > 1));
       afterpoint -= 1, tmp /= 10) {
    str[len_str++] = ((int)fmodl(tmp, 10)) + 48;
    str[len_str] = '\0';
  }
  tmp == 1 ? k3 = 1 : 0;
  (ptr_precision != 0 || flag[3] == 'o')
      ? str[len_str++] = (localeconv()->decimal_point)[0]
      : 0;
  ptr_precision == 0 ? number = roundl(number) : 0;
  for (tmp = k3 == 1 ? round(number) : number; ((tmp / 10) >= 1);
       tmp /= 10, str[len_str] = '\0')
    str[len_str++] = ((int)fmodl(tmp, 10)) + 48;
  fspec_di(str + len_str, fmodl(tmp, 10), 1, flagX);
  minus == 1 ? s21_strcat(str, "-") : 0;
  len_str = s21_strlen(str);
  if (str[len_str - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o')) {
    str[len_str++] = flag[1] == 'o' ? '+' : ' ';
    str[len_str] = '\0';
  }
  s21_strrev(str);
  if (ptr_accuracy == 1 && flag[3] != 'o') {
    int i = s21_strlen(str) - 1;
    for (; s21_strchr("0", str[i]); str[i--] = '\0') continue;
    str[i] == (localeconv()->decimal_point)[0] ? str[i] = '\0' : 0;
  }
  return str;
}

char *fspec_gG_long(char *str, long double number, int precision, char *flag,
                    int spec) {
  int len_num = 0;
  precision == 0 ? precision = 1 : 0;
  if (number == 0) {
    fspec_f_long(str, number, precision - 1, flag, 1);
  } else {
    for (int tmp = len_num = fabsl(number) < 1    ? 1
                             : fabsl(number) < 10 ? 0
                                                  : (-1);
         tmp != 0; len_num += tmp)
      tmp = ((fabsl(number) * powl(10, len_num)) < 1 ||
             10 < fabsl(number) * powl(10, len_num))
                ? tmp
                : 0;
    if (len_num <= 0)
      (precision + len_num <= 0)
          ? fspec_eEL(str, number, precision - 1, flag, spec - 2, 1)
          : fspec_f_long(str, number, (precision - 1) + len_num, flag, 1);
    else
      (precision - 1) <= len_num
          ? fspec_eEL(str, number, precision - 1, flag, spec - 2, 1)
          : fspec_f_long(str, number, len_num + (precision - 1), flag, 1);
  }
  return str;
}

char *fspec_di(char *str, int number, int precision, char *flag) {
  int len_str = 0, minus = number < 0 ? (number *= (-1)) : 0;
  if (number < 0) {
    for (; ((len_str < precision) || (-(number / 10) != 0) ||
            (-(number % 10) != 0));
         number /= 10)
      str[len_str++] = (-(number % 10)) + 48;
  } else {
    for (; ((len_str < precision) || ((number / 10) != 0) ||
            ((number % 10) != 0));
         number /= 10)
      str[len_str++] = (number % 10) + 48;
  }
  minus != 0 ? str[len_str++] = '-' : 0;
  if (str[len_str - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o'))
    str[len_str++] = flag[1] == 'o' ? '+' : ' ';
  str[len_str] = '\0';
  s21_strrev(str);
  return str;
}

char *fspec_xXou_long(char *str, long unsigned int number, int format,
                      int precision, char *flag) {
  int len_str = 0, type = 97, numb = number;
  format == 32 ? format /= 2 : (type = 65);
  for (; (len_str < precision - 1) || (number / format) != 0;
       number /= format, len_str += 1)
    str[len_str] = (number % format) < 10 ? (number % format) + 48
                                          : ((number % format) - 10) + type;
  str[len_str++] = number < 10 ? number + 48 : (number - 10) + type;
  (flag[3] == 'o' && format == 8 && number != 0) ? str[len_str++] = '0' : 0;
  str[len_str] = '\0';
  (flag[3] == 'o' && format == 16 && type == 65 && numb != 0)
      ? s21_strcat(str, "X0")
      : 0;
  (flag[3] == 'o' && format == 16 && type == 97 && numb != 0)
      ? s21_strcat(str, "x0")
      : 0;
  s21_strrev(str);
  return str;
}

char *fspec_di_long(char *str, long int number, int precision, char *flag) {
  int len_str = 0;
  long int minus = number < 0 ? (number *= (-1)) : 0;
  if (number < 0) {
    for (; ((len_str < precision) || (-(number / 10) != 0) ||
            (-(number % 10) != 0));
         number /= 10)
      str[len_str++] = (-(number % 10)) + 48;
  } else {
    for (; ((len_str < precision) || ((number / 10) != 0) ||
            ((number % 10) != 0));
         number /= 10)
      str[len_str++] = (number % 10) + 48;
  }
  minus != 0 ? str[len_str++] = '-' : 0;
  if (str[len_str - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o'))
    str[len_str++] = flag[1] == 'o' ? '+' : ' ';
  str[len_str] = '\0';
  s21_strrev(str);
  return str;
}

char *fspec_xXou_short(char *str, short unsigned int number, int format,
                       int precision, char *flag) {
  int len_str = 0, type = 97, numb = number;
  format == 32 ? format /= 2 : (type = 65);
  for (; (len_str < precision - 1) || (number / format) != 0;
       number /= format, len_str += 1)
    str[len_str] = (number % format) < 10 ? (number % format) + 48
                                          : ((number % format) - 10) + type;
  str[len_str++] = number < 10 ? number + 48 : (number - 10) + type;
  (flag[3] == 'o' && format == 8 && number != 0) ? str[len_str++] = '0' : 0;
  str[len_str] = '\0';
  (flag[3] == 'o' && format == 16 && type == 65 && numb != 0)
      ? s21_strcat(str, "X0")
      : 0;
  (flag[3] == 'o' && format == 16 && type == 97 && numb != 0)
      ? s21_strcat(str, "x0")
      : 0;
  s21_strrev(str);
  return str;
}

char *fspec_di_short(char *str, short int number, int precision, char *flag) {
  int len_str = 0, minus = number < 0 ? (number *= (-1)) : 0;
  if (number < 0) {
    for (; ((len_str < precision) || (-(number / 10) != 0) ||
            (-(number % 10) != 0));
         number /= 10)
      str[len_str++] = (-(number % 10)) + 48;
  } else {
    for (; ((len_str < precision) || ((number / 10) != 0) ||
            ((number % 10) != 0));
         number /= 10)
      str[len_str++] = (number % 10) + 48;
  }
  minus != 0 ? str[len_str++] = '-' : 0;
  if (str[len_str - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o'))
    str[len_str++] = flag[1] == 'o' ? '+' : ' ';
  str[len_str] = '\0';
  s21_strrev(str);
  return str;
}

char *fspec_eE(char *str, double number, int precision, char *flag, int spec,
               int ptr_accuracy) {
  char flagX[10] = "xxxxx";
  char flag1[10] = "xoxxx";
  int len_str = 0, len_num = 0, result = 0, ptr_precision = precision;
  if (number != 0) {
    for (int tmp = len_num = fabs(number) < 1    ? 1
                             : fabs(number) < 10 ? 0
                                                 : (-1);
         tmp != 0; len_num += tmp)
      tmp = ((fabs(number) * pow(10, len_num)) < 1 ||
             10 < fabs(number) * pow(10, len_num))
                ? tmp
                : 0;
  }
  fspec_di(str,
           (ptr_precision == 0 ? (round(number * pow(10, len_num)))
                               : (number * pow(10, len_num))),
           1, flag);
  (ptr_precision != 0 || flag[3] == 'o')
      ? s21_strcat(str, (localeconv()->decimal_point))
      : 0;
  for (len_str = s21_strlen(str); number < 0; number *= (-1)) continue;
  for (result = len_num; (precision != 0 && (len_num + 1) <= 0);
       precision -= 1) {
    if (precision == 1)
      fspec_di(str + (len_str++),
               fmod((round(number) * pow(10, len_num += 1)), 10), 1, flagX);
    else
      fspec_di(str + (len_str++), fmod((number * pow(10, len_num += 1)), 10), 1,
               flagX);
  }
  for (int tmp = len_num + 1; precision != 0; precision -= 1)
    precision == 1
        ? fspec_di(str + (len_str++),
                   round(fmod((number * pow(10, (tmp++))), 10)), 1, flagX)
        : fspec_di(str + (len_str++), fmod((number * pow(10, (tmp++))), 10), 1,
                   flagX);
  if (ptr_accuracy == 1 && flag[3] != 'o') {
    for (int i = s21_strlen(str) - 1; s21_strchr("0", str[i]); str[i--] = '\0')
      continue;
    for (int i = s21_strlen(str) - 1;
         s21_strchr((localeconv()->decimal_point), str[i]);)
      str[i--] = '\0';
  }
  len_str = s21_strlen(str);
  str[len_str++] = spec;
  str[len_str] = '\0';
  fspec_di(str + (len_str), -result, 2, flag1);
  return str;
}

char *fspec_f(char *str, double number, int afterpoint, char *flag,
              int ptr_accuracy) {
  char flagX[10] = "xxxxx";
  int len_str = 0, minus = 0, ptr_precision = afterpoint, k3 = 0;
  for (; number < 0; number *= (-1), minus = 1) continue;
  double tmp = ceil((number - trunc(number)) * pow(10, afterpoint) - 0.5);
  for (; ((afterpoint != 0) || ((tmp / 10) > 1) || (fmod(tmp, 10) > 1));
       afterpoint -= 1, tmp /= 10) {
    str[len_str++] = ((int)fmod(tmp, 10)) + 48;
    str[len_str] = '\0';
  }
  tmp == 1 ? k3 = 1 : 0;
  (ptr_precision != 0 || flag[3] == 'o')
      ? str[len_str++] = (localeconv()->decimal_point)[0]
      : 0;
  ptr_precision == 0 ? number = round(number) : 0;
  for (tmp = k3 == 1 ? round(number) : number; (tmp / 10 >= 1);
       tmp /= 10, str[len_str] = '\0')
    str[len_str++] = ((int)fmod(tmp, 10)) + 48;
  fspec_di(str + len_str, fmod(tmp, 10), 1, flagX);
  minus == 1 ? s21_strcat(str, "-") : 0;
  len_str = s21_strlen(str);
  if (str[len_str - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o')) {
    str[len_str++] = flag[1] == 'o' ? '+' : ' ';
    str[len_str] = '\0';
  }
  s21_strrev(str);
  if (ptr_accuracy == 1 && flag[3] != 'o') {
    int i = s21_strlen(str) - 1;
    for (; s21_strchr("0", str[i]); str[i--] = '\0') continue;
    str[i] == (localeconv()->decimal_point)[0] ? str[i] = '\0' : 0;
  }
  return str;
}
char *fspec_gG(char *str, double number, int precision, char *flag, int spec) {
  int len_num = 0;
  precision = (precision == 0) ? 1 : precision;

  if (number == 0) {
    fspec_f(str, number, precision - 1, flag, 1);
  } else {
    for (int tmp = len_num = (fabs(number) < 1)    ? 1
                             : (fabs(number) < 10) ? 0
                                                   : -1;
         tmp != 0; len_num += tmp) {
      tmp = ((fabs(number) * pow(10, len_num)) < 1 ||
             10 < fabs(number) * pow(10, len_num))
                ? tmp
                : 0;
    }

    if (len_num <= 0) {
      (precision + len_num <= 0)
          ? fspec_eE(str, number, precision - 1, flag, spec - 2, 1)
          : fspec_f(str, number, (precision - 1) + len_num, flag, 1);
    } else {
      len_num > 4 ? fspec_eE(str, number, precision - 1, flag, spec - 2, 1)
                  : fspec_f(str, number, len_num + (precision - 1), flag, 1);
    }
  }

  return str;
}