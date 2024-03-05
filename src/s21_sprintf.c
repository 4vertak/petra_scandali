
#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list params;
  va_start(params, format);
  int counter = 0;
  for (int i = 0; format[i] != '\0'; i += 1) {
    if (format[i] == '%') {
      setting modified = {"xxxxx", INT_MIN, INT_MIN, 'x'};
      i = parce_setting_mode(i, format, &modified, &params);
      counter += proc_setting_mode(str + counter, format[i], modified, &params);
    } else {
      str[counter++] = format[i];
      str[counter] = '\0';
    }
  }
  va_end(params);
  return counter;
}

// ПАРСЕР выполняет поиск и обработку модификаторов формата строки в переменной
// format и сохранение их в структуре modified.

int parce_setting_mode(int i, const char *format, setting *modified,
                       va_list *params) {
  // В цикле for сначала увеличивается значение i на 1, а затем проверяется,
  // является ли символ в строке format на позиции i одним из символов
  // -/+/пробел. Если это так, то соответствующий элемент в массиве flag
  // структуры modified устанавливается в символ 'o'.

  for (i++; s21_strchr("-+ ", format[i]); i++) {
    (modified->flag)[5 - s21_strlen(s21_strchr("-+ ", format[i]))] = 'o';
    i++;
  }
  // В цикле проверяется, является ли символ в строке format на
  // позиции i цифрой 0-9. Если это так, то значение width структуры modified
  // умножается на 10 и прибавляется значение символа в строке format.

  while (s21_strchr("0123456789", format[i])) {
    modified->width = (modified->width * 10) + (format[i] - '0');
    i++;
  }
  // В цикле проверяется, равен ли символ в строке format на позиции
  // i звездочке '*'. Если это так, то значение width структуры modified
  // устанавливается в значение аргумента типа int из переменной params.

  while (format[i] == '*') {
    modified->width = va_arg(*params, int);
    i += 1;
  }

  // Если символ в строке format i равен '.'
  if (format[i] == '.') {
    // Проверяется, является ли следующий символ в строке format символом '-'
    for (i += 1; format[i] == '-'; i += 1) continue;

    // В цикле проверяется, является ли символ в строке format на позиции i
    // цифрой 0-9. При этом значение accuracy структуры modified умножается на
    // 10 и прибавляется значение символа в строке format.

    for (; s21_strchr("0123456789", format[i]); i += 1)
      modified->accuracy = (modified->accuracy * 10) + (format[i] - '0');

    // В цикле проверяется, равен ли символ в строке format на позиции i
    // звездочке '*'.  Если это так, то значение accuracy структуры modified
    // устанавливается в значение аргумента типа int из переменной params.

    for (; format[i] == '*'; i += 1) modified->accuracy = va_arg(*params, int);
    modified->accuracy < 0 ? modified->accuracy = 0 : 0;
  }
  // проверяется, является ли символ в строке format на i одним из символов
  // 'hl'. Если это так, то значение type структуры modified устанавливается в
  // текущий символ.

  while (s21_strchr("hl", format[i])) {
    modified->type = format[i];
    i++;
  }

  return i;
}

// Обработка параметров форматирования строки.
int proc_setting_mode(char *str, char symbol, setting modified,
                      va_list *params) {
  char *flag = modified.flag;
  int indent = 0;
  int accuracy = modified.accuracy;
  // точность по умолчанию
  if (accuracy < 0) {
    if (s21_strchr("du", symbol)) {
      accuracy = 1;
    } else if (s21_strchr("f", symbol)) {
      accuracy = 6;
    } else {
      accuracy = 0;
    }
  }
  // если символ форматирования равен '%', он добавляется к строке.
  if (symbol == '%') {
    s21_strcat(str, "%");
  }
  // если символ форматирования равен 'c'
  else if (symbol == 'c') {
    return format_string(str + indent, params, flag, modified.width,
                         modified.type);
  }
  // если символ форматирования 'd' или 'i'
  else if (s21_strchr("di", symbol)) {
    // и если тип аргумента равен 'h', вызывается функция short_len для
    // форматирования аргумента.
    if (modified.type == 'h')
      short_len(str + indent, va_arg(*params, int), accuracy, flag);
    // и если тип аргумента равен 'l', вызывается функция long_len для
    // форматирования аргумента.
    else if (modified.type == 'l')
      long_len(str + indent, va_arg(*params, long int), accuracy, flag);
    // и если тип аргумента не равен 'h' или 'l'
    else
      convert_int_to_str(str + indent, va_arg(*params, int), accuracy, flag);
  }
  // если символ форматирования равен 'p', вызывается функция...
  // else if (symbol == 'p') {
  //
  // }
  // если символ форматирования равен 's'
  else if (symbol == 's') {
    str_formating(str + indent, params, accuracy, modified.type);
  }
  // если символ форматирования 'f'вызывается функция...
  // else if (symbol == 'f') {
  // }
  // else if (s21_strchr("gG", symbol)) {
  // } else if (s21_strchr("eE", symbol)) {
  // } else if (s21_strchr("xX", symbol)) {
  // }
  else if (symbol == 'o') {
    // и если тип конфигурации равен 'h', вызывается функция
    // short_convert_unsig_to_str для форматирования аргумента.
    if (modified.type == 'h')
      short_convert_unsig_to_str(str + indent, va_arg(*params, unsigned int), 8,
                                 accuracy, flag);

    // и если тип конфигурации равен 'l', вызывается функция
    // long_convert_unsig_to_str для форматирования аргумента.
    else if (modified.type == 'l')
      long_convert_unsig_to_str(
          str + indent, va_arg(*params, long unsigned int), 8, accuracy, flag);

    // иначе вызывается функция convert_unsig_to_str для форматирования
    // аргумента
    else
      convert_unsig_to_str(str + indent, va_arg(*params, unsigned int), 8,
                           accuracy, flag);
  } else if (symbol == 'u') {
    if (modified.type == 'h')
      short_convert_unsig_to_str(str + indent, va_arg(*params, unsigned int),
                                 10, accuracy, flag);
    else if (modified.type == 'l')
      long_convert_unsig_to_str(
          str + indent, va_arg(*params, long unsigned int), 10, accuracy, flag);
    else
      convert_unsig_to_str(str + indent, va_arg(*params, unsigned int), 10,
                           accuracy, flag);
  }
  (s21_strchr("n%c", symbol)) ? 0 : adjust_width_space(str + indent, modified, symbol);
  return s21_strlen(str);
}

char *adjust_width_space(char *str, setting modified, char symbol) {
  if (should_proc(modified, symbol, str)) {
    trim_zero(str);
  }
  adjust_width(str, modified, symbol);
  return str;
}

int should_proc(setting modified, char symbol, char *str) {
  if (s21_strcmp(modified.flag, "xxxxx") || modified.width >= 0 ||
      modified.type != 'x') {
    if (s21_strchr("gG", symbol) && modified.flag[3] != 'o') {
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

void adjust_width(char *str, setting modified, char symbol) {
  char *tmp = str;
  char filler = ' ';
  int count_fill = modified.width > 0 ? modified.width - s21_strlen(str) : 0;

  if (modified.flag[4] == 'o') {
    tmp[0] == '-' ? tmp += 1 : 0;
    s21_strchr("cs", symbol) ? 0 : (filler = '0');
  } else if (modified.flag[0] == 'o') {
    tmp += s21_strlen(tmp);
  }

  fill_space(tmp, count_fill, filler);
}

void fill_space(char *tmp, int count_fill, char filler) {
  if (count_fill > 0) {
    for (s21_memmove(tmp + count_fill, tmp, s21_strlen(tmp) + 1);
         count_fill != 0;) {
      tmp[count_fill - 1] = filler;
      count_fill -= 1;
    }
  }
}

int format_string(char *str, va_list *params, char *flag, int accuracy,
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

char *str_formating(char *str, va_list *params, int accuracy, char type) {
  if (type == 'l') {
    wcstombs(str, va_arg(*params, wchar_t *), 512);
  } else {
    s21_strcat(str, va_arg(*params, char *));
  }
  accuracy < 0 ? accuracy = s21_strlen(str) : 0;
  str[accuracy] = '\0';
  return str;
}

char *convert_unsig_to_str(char *str, unsigned int number, int format,
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
  s21_strrev(str);
  return str;
}

char *convert_int_to_str(char *str, int number, int accuracy, char *flag) {
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
  s21_strrev(str);
  return str;
}

char *long_convert_unsig_to_str(char *str, long unsigned int number, int format,
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
  s21_strrev(str);
  return str;
}

char *long_len(char *str, long int number, int accuracy, char *flag) {
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
  s21_strrev(str);
  return str;
}

char *short_convert_unsig_to_str(char *str, short unsigned int number,
                                 int format, int accuracy, char *flag) {
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
  s21_strrev(str);
  return str;
}

char *short_len(char *str, short int number, int accuracy, char *flag) {
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
  s21_strrev(str);
  return str;
}
