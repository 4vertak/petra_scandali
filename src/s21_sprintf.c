
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
      counter += proc_setting_mode(str + counter, format[i], modified, &params);
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
  // ищем флаги "-+ ".Если уесть, то в массиве flag в modified устанавливаем
  // 'o'.
  for (i += 1; s21_strchr("-+ ", format[i]); i += 1)
    (modified->flag)[5 - s21_strlen(s21_strchr("-+ ", format[i]))] = 'o';
  // ищем ширину "0123456789".Если уесть, то в массиве flag в modified
  // устанавливаем 'o'.
  for (; s21_strchr("0123456789", format[i]); i += 1)
    modified->width = (modified->width * 10) + (format[i] - 48);

  for (; format[i] == '*'; i += 1) modified->width = va_arg(*params, int);
  if (format[i] == '.') {
    for (i += 1; format[i] == '-'; i += 1) continue;
    for (; s21_strchr("0123456789", format[i]); i += 1)
      modified->accuracy = (modified->accuracy * 10) + (format[i] - 48);
    for (; format[i] == '*'; i += 1) modified->accuracy = va_arg(*params, int);
    modified->accuracy < 0 ? modified->accuracy = 0 : 0;
  }
  for (; s21_strchr("hlL", format[i]); i += 1) modified->type = format[i];
  return i;
}
// обработка флагов
int proc_setting_mode(char *str, char symbol, setting modified,
                      va_list *params) {
  char *flag = modified.flag;
  int indent = 0;
  int accuracy = modified.accuracy;
  if (accuracy < 0) {
    if (s21_strchr("du", symbol)) {
      accuracy = 1;
    } else if (s21_strchr("f", symbol)) {
      accuracy = 6;
    } else {
      accuracy = 0;
    }
  }
  if (symbol == '%') {
    s21_strcat(str, "%");
  } else if (symbol == 'c') {
    return modifier_c(str + indent, params, flag, modified.width,
                      modified.type);
  } else if (s21_strchr("di", symbol)) {
    if (modified.type == 'h')
      short_length(str + indent, va_arg(*params, int), accuracy, flag);
    else if (modified.type == 'l')
      long_length(str + indent, va_arg(*params, long int), accuracy, flag);
    else
      int_to_str(str + indent, va_arg(*params, int), accuracy, flag);
  } else if (symbol == 's') {
    str_to_str(str + indent, params, accuracy, modified.type);
  } else if (symbol == 'u') {
    if (modified.type == 'h')
      short_u_to_str(str + indent, va_arg(*params, unsigned int), 10, accuracy,
                     flag);
    else if (modified.type == 'l')
      long_u_to_str(str + indent, va_arg(*params, long unsigned int), 10,
                    accuracy, flag);
    else
      u_to_str(str + indent, va_arg(*params, unsigned int), 10, accuracy, flag);
  }
  (s21_strchr("n%c", symbol)) ? 0 : s21_conf(str + indent, modified);
  return s21_strlen(str);
}

char *s21_conf(char *str, setting modified) {
  char *aux = str;
  char filler = ' ';
  int filling_counter =
      modified.width > 0 ? modified.width - s21_strlen(str) : 0;
  if (filling_counter > 0) {
    for (s21_memmove(aux + filling_counter, aux, s21_strlen(aux) + 1);
         filling_counter != 0;) {
      aux[filling_counter - 1] = filler;
      filling_counter -= 1;
    }
  }
  return str;
}

void reverse_str(char str[]) {
  int length = s21_strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = temp;
  }
}

int modifier_c(char *str, va_list *params, char *flag, int accuracy,
               char type) {
  int counter = 0;
  accuracy = accuracy < 1 ? 1 : accuracy;
  if (type == 'l') {
    wchar_t w_c = va_arg(*params, wchar_t);
    counter = wcstombs(str + counter, &w_c, 512);
  } else {
    str[counter++] = va_arg(*params, int);
    str[counter] = '\0';
  }
  if (flag[0] != 'o' && accuracy - counter > 0) {
    s21_memmove(str + (accuracy - counter), str, counter + 1);
    for (int x = 0; x < accuracy - counter; x += 1) str[x] = ' ';
    counter = accuracy;
  }
  for (int x = counter; flag[0] == 'o' && x < (accuracy); x += 1)
    str[counter++] = ' ';
  return counter;
}

char *str_to_str(char *str, va_list *params, int accuracy, char type) {
  if (type == 'l') {
    wcstombs(str, va_arg(*params, wchar_t *), 512);
  } else {
    s21_strcat(str, va_arg(*params, char *));
  }
  accuracy < 0 ? accuracy = s21_strlen(str) : 0;
  str[accuracy] = '\0';
  return str;
}

char *u_to_str(char *str, unsigned int number, int format, int accuracy,
               char *flag) {
  int lenStr = 0, type = 97, numb = number;
  format == 32 ? format /= 2 : (type = 65);
  for (; (lenStr < accuracy - 1) || (number / format) != 0;
       number /= format, lenStr += 1)
    str[lenStr] = (number % format) < 10 ? (number % format) + 48
                                         : ((number % format) - 10) + type;
  str[lenStr++] = number < 10 ? number + 48 : (number - 10) + type;
  (flag[3] == 'o' && format == 8 && number != 0) ? str[lenStr++] = '0' : 0;
  str[lenStr] = '\0';
  (flag[3] == 'o' && format == 16 && type == 65 && numb != 0)
      ? s21_strcat(str, "X0")
      : 0;
  (flag[3] == 'o' && format == 16 && type == 97 && numb != 0)
      ? s21_strcat(str, "x0")
      : 0;
  reverse_str(str);
  return str;
}

char *int_to_str(char *str, int number, int accuracy, char *flag) {
  int lenStr = 0, minus = number < 0 ? (number *= (-1)) : 0;
  if (number < 0) {
    for (; ((lenStr < accuracy) || (-(number / 10) != 0) ||
            (-(number % 10) != 0));
         number /= 10)
      str[lenStr++] = (-(number % 10)) + 48;
  } else {
    for (;
         ((lenStr < accuracy) || ((number / 10) != 0) || ((number % 10) != 0));
         number /= 10)
      str[lenStr++] = (number % 10) + 48;
  }
  minus != 0 ? str[lenStr++] = '-' : 0;
  if (str[lenStr - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o'))
    str[lenStr++] = flag[1] == 'o' ? '+' : ' ';
  str[lenStr] = '\0';
  reverse_str(str);
  return str;
}

char *long_u_to_str(char *str, long unsigned int number, int format,
                    int accuracy, char *flag) {
  int lenStr = 0, type = 97, numb = number;
  format == 32 ? format /= 2 : (type = 65);
  for (; (lenStr < accuracy - 1) || (number / format) != 0;
       number /= format, lenStr += 1)
    str[lenStr] = (number % format) < 10 ? (number % format) + 48
                                         : ((number % format) - 10) + type;
  str[lenStr++] = number < 10 ? number + 48 : (number - 10) + type;
  (flag[3] == 'o' && format == 8 && number != 0) ? str[lenStr++] = '0' : 0;
  str[lenStr] = '\0';
  (flag[3] == 'o' && format == 16 && type == 65 && numb != 0)
      ? s21_strcat(str, "X0")
      : 0;
  (flag[3] == 'o' && format == 16 && type == 97 && numb != 0)
      ? s21_strcat(str, "x0")
      : 0;
  reverse_str(str);
  return str;
}

char *long_length(char *str, long int number, int accuracy, char *flag) {
  int lenStr = 0;
  long int minus = number < 0 ? (number *= (-1)) : 0;
  if (number < 0) {
    for (; ((lenStr < accuracy) || (-(number / 10) != 0) ||
            (-(number % 10) != 0));
         number /= 10)
      str[lenStr++] = (-(number % 10)) + 48;
  } else {
    for (;
         ((lenStr < accuracy) || ((number / 10) != 0) || ((number % 10) != 0));
         number /= 10)
      str[lenStr++] = (number % 10) + 48;
  }
  minus != 0 ? str[lenStr++] = '-' : 0;
  if (str[lenStr - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o'))
    str[lenStr++] = flag[1] == 'o' ? '+' : ' ';
  str[lenStr] = '\0';
  reverse_str(str);
  return str;
}

char *short_u_to_str(char *str, short unsigned int number, int format,
                     int accuracy, char *flag) {
  int lenStr = 0, type = 97, numb = number;
  format == 32 ? format /= 2 : (type = 65);
  for (; (lenStr < accuracy - 1) || (number / format) != 0;
       number /= format, lenStr += 1)
    str[lenStr] = (number % format) < 10 ? (number % format) + 48
                                         : ((number % format) - 10) + type;
  str[lenStr++] = number < 10 ? number + 48 : (number - 10) + type;
  (flag[3] == 'o' && format == 8 && number != 0) ? str[lenStr++] = '0' : 0;
  str[lenStr] = '\0';
  (flag[3] == 'o' && format == 16 && type == 65 && numb != 0)
      ? s21_strcat(str, "X0")
      : 0;
  (flag[3] == 'o' && format == 16 && type == 97 && numb != 0)
      ? s21_strcat(str, "x0")
      : 0;
  reverse_str(str);
  return str;
}

char *short_length(char *str, short int number, int accuracy, char *flag) {
  int lenStr = 0, minus = number < 0 ? (number *= (-1)) : 0;
  if (number < 0) {
    for (; ((lenStr < accuracy) || (-(number / 10) != 0) ||
            (-(number % 10) != 0));
         number /= 10)
      str[lenStr++] = (-(number % 10)) + 48;
  } else {
    for (;
         ((lenStr < accuracy) || ((number / 10) != 0) || ((number % 10) != 0));
         number /= 10)
      str[lenStr++] = (number % 10) + 48;
  }
  minus != 0 ? str[lenStr++] = '-' : 0;
  if (str[lenStr - 1] != '-' && (flag[1] == 'o' || flag[2] == 'o'))
    str[lenStr++] = flag[1] == 'o' ? '+' : ' ';
  str[lenStr] = '\0';
  reverse_str(str);
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *ptr_dest = dest;
  while (*dest) {
    dest++;
  }
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';

  return ptr_dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  const char *s = (const char *)src;

  if (d <= s || d >= s + n) {
    while (n--) {
      *d++ = *s++;
    }
  } else {
    d += n - 1;
    s += n - 1;
    while (n--) {
      *d-- = *s--;
    }
  }

  return dest;
}