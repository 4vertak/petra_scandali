#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  if (!*str) return -1;
  int res = 0;
  setting modified = {0, 0, 0, 0, 0, 0, 0, '\0'};
  char tmp_value[MAX_LENGTH];
  char *tmp = tmp_value;
  trim_space_and_count(&tmp, &modified);
  if (!*tmp) modified.end = 1;
  tmp = s21_strcpy(tmp - modified.count, str);
  modified.count = 0;
  va_list args;
  va_start(args, format);

  while (*format) {
    if (setting_mod(&tmp, &modified, format)) {
      format++;
      continue;
    }
    if (modified.format) {
      if ((int)*format > 47 && (int)*format < 58) {
        modified.width = modified.width * 10 + (int)*format - 48;
        format++;
        continue;
      }
      res += processformat(args, &modified, &tmp, format);
    } else {
      proc_character(&tmp, &modified, format);
    }
    if (delimiter(args, &modified, &tmp, format)) {
      if (!res && modified.end) res = -1;
      break;
    }
    format++;
  }

  va_end(args);
  return res;
}

void proc_character(char **src, setting *modified, const char *format) {
  if (*format == ' ' || *format == '\t' || *format == '\n' || *format == '\r') {
    while (*format == **src) {
      (*src)++;
      modified->count++;
    }
  } else if (**src == *format) {
    (*src)++;
    modified->count++;
  } else {
    modified->skipws = 1;
  }
}

char *s21_strcpy(char *dest, const char *src) {
  char *saved = dest;
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return saved;
}

void trim_space_and_count(char **src, setting *modified) {
  while (**src == ' ' || **src == '\n' || **src == '\t' || **src == '\r' ||
         **src == '\f') {
    (*src)++;
    modified->count++;
  }
}

int setting_mod(char **src, setting *modified, const char *format) {
  int res = 0;
  if (*format == '%' && !modified->format) {
    // Увеличение счетчика результатов
    res++;
    // Установка формата
    modified->format = 1;
    modified->length = 0;
    modified->extr = 0;

    if (modified->buffer) {
      (*src)[s21_strlen(*src)] = modified->buffer;
      modified->buffer = '\0';
    }
    // Установка ширины поля
    modified->width = 0;
  }

  return res;
}

int mod_c(va_list args, setting *modified, char **src) {
  int res = 0;
  // Установка ширины поля
  if (!modified->width) modified->width = 2;
  // Обработка символа
  if (!modified->extr) {
    res++;
    if (modified->length == 2)
      mbtowc((wchar_t *)va_arg(args, wchar_t *), *src, modified->width);
    else
      *(char *)va_arg(args, char *) = **src;
  }
  // Обработка символа с отрицательным значением
  if (**src < 0 && modified->length == 2) {
    (*src)++;
    modified->count++;
  }
  (*src)++;
  modified->count++;
  modified->format = 0;
  return res;
}

void valid_buff(char **src, setting *modified) {
  trim_space_and_count(src, modified);
  if (!modified->buffer && modified->width &&
      modified->width < (int)s21_strlen(*src)) {
    modified->buffer = *(*src + modified->width);
    *(*src + modified->width) = '\0';
  }
}

void remove_spaces_and_newlines(char *str) {
  while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
         *str == '\f')
    str++;
}

void process_sign(char *str, int *sign) {
  if (*str == '+') str++;
  if (*str == '-') {
    *sign = -1;
    str++;
  }
}

int determine_base(char *str, int base) {
  if (base == 0 && *str == '0' && *(str + 1) == 'x')
    base = 16;
  else if (base == 0 && *str == '0')
    base = 8;
  else if (base == 0)
    base = 10;
  if (base == 16 && *str == '0' && *(str + 1) == 'x') str += 2;
  return base;
}

long convert_str_to_int(char *str, char **strlim, int base) {
  char *start = str;
  long int res = 0;
  int sign = 1;
  remove_spaces_and_newlines(str);
  process_sign(str, &sign);
  // Определение основания системы счисления
  base = determine_base(str, base);
  // Обработка десятичной системы счисления
  if (base == 10) {
    for (; *str >= '0' && *str <= '9'; str++, res *= 10) res += *str - 48;
    res /= 10;
  }
  // Установка указателя на начало строки
  if (strlim) *strlim = start + (str - start);
  return sign * res;
}

s21_size_t s21_strspn(const char *str, const char *accept) {
  const char *ptr;
  size_t len = 0;

  for (const char *s = str; *s; s++) {
    for (ptr = accept; *ptr; ptr++) {
      if (*s == *ptr) {
        len++;
        break;
      }
    }
    if (*ptr == '\0') {
      break;
    }
  }
  return len;
}

int mod_d(va_list args, setting *modified, char **src, int base) {
  int result = 0;
  char *endptr;

  // Проверяем буфер
  valid_buff(src, modified);

  // Проверяем и конвертируем строку в число
  if (convert_str_to_int(*src, s21_NULL, base) ||
      *(*src + s21_strspn(*src, "\n\t \f\r+-")) == '0') {
    if (!modified->extr) {
      result++;
      if (modified->length == 1)
        *(short int *)va_arg(args, void *) =
            convert_str_to_int(*src, &endptr, base);
      else if (modified->length == 2)
        *(long int *)va_arg(args, void *) =
            convert_str_to_int(*src, &endptr, base);
      else
        *(int *)va_arg(args, void *) = convert_str_to_int(*src, &endptr, base);
    } else {
      convert_str_to_int(*src, &endptr, base);
    }
    modified->count += endptr - *src;
    *src = endptr;
  } else {
    modified->skipws = 1;
  }
  modified->format = 0;
  return result;
}

int mod_s(va_list args, setting *modified, char **src) {
  // Инициализация переменных
  int res = 0;
  char *new_str = malloc(sizeof(new_str));

  // Проверка на успешное выделение памяти
  if (new_str) {
    trim_space_and_count(src, modified);

    // Создание новой строки
    int i = 0;
    for (; **src && **src != ' ' && **src != '\n' && **src != '\t' &&
           **src != '\r' && **src != '\f' &&
           (modified->width == 0 || i < modified->width);
         i++, (*src)++) {
      new_str[i] = **src;
      new_str = realloc(new_str, (i + 2) * sizeof(new_str));
    }
    new_str[i] = '\0';

    // Копирование аргументов в новый список
    va_list tmp_list;
    va_copy(tmp_list, args);
    int k = s21_strlen(new_str) + 1;
    for (int j = 0; j < k; j++) {
      if (!modified->extr) {
        if (!modified->length)
          *((char *)va_arg(tmp_list, char *) + j) = new_str[j];
        if (j + 1 < k) {
          va_end(tmp_list);
          va_copy(tmp_list, args);
        }
      }
    }
    va_end(args);
    va_copy(args, tmp_list);

    // Преобразование строки в wchar_t
    if (modified->length == 2 && !modified->extr)
      mbstowcs((wchar_t *)va_arg(args, wchar_t *), new_str, k);

    // Освобождение памяти
    free(new_str);

    // Увеличение счетчика символов
    if (!modified->extr) res++;
    modified->count += k - 1;
    modified->format = 0;

    va_end(tmp_list);
  }

  // Возврат результата
  return res;
}

int mod_u(va_list args, setting *modified, char **src, int base) {
  int res = 0;
  char *strlim;
  valid_buff(src, modified);
  // Чтение целого числа из строки
  if (convert_str_to_int(*src, s21_NULL, base) ||
      *(*src + s21_strspn(*src, "\n\t \f\r+")) == '0') {
    if (!modified->extr) {
      if (convert_str_to_int(*src, s21_NULL, base) || **src == '0') res++;
      if (modified->length == 1)
        *(short unsigned *)va_arg(args, void *) =
            convert_str_to_int(*src, &strlim, base);
      else if (modified->length == 2)
        *(long unsigned *)va_arg(args, void *) =
            convert_str_to_int(*src, &strlim, base);
      else
        *(unsigned *)va_arg(args, void *) =
            convert_str_to_int(*src, &strlim, base);
    } else {
      convert_str_to_int(*src, &strlim, base);
    }
    modified->count += strlim - *src;
    *src = strlim;
  } else {
    modified->skipws = 1;
  }
  modified->format = 0;
  return res;
}

void mod_n(va_list args, setting *modified) {
  if (!modified->extr) {
    if (modified->length == 1)
      *(short int *)va_arg(args, void *) = modified->count;
    else if (modified->length == 2)
      *(long int *)va_arg(args, void *) = modified->count;
    else
      *(int *)va_arg(args, void *) = modified->count;
  }
  modified->format = 0;
}

int processformat(va_list args, setting *modified, char **src,
                  const char *format) {
  int res = 0;
  switch (*format) {
    case 'c':
      res += mod_c(args, modified, src);
      break;
    case 'd':
      res += mod_d(args, modified, src, 10);
      break;
    case 'i':
      res += mod_d(args, modified, src, 0);
      break;
    case 's':
      res += mod_s(args, modified, src);
      break;
    case 'u':
      res += mod_u(args, modified, src, 10);
      break;
    case 'n':
      mod_n(args, modified);
      break;
    case '%':
      mod_percent(src, modified, format);
      break;
    case 'h':
      modified->length = 1;
      break;
    case '*':
      modified->extr = 1;
      break;
    case 'l':
      modified->length = 2;
      break;
    case 'L':
      modified->length = 3;
      break;
  }
  return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int len_needle = s21_strlen(needle);
  int len_haystack = s21_strlen(haystack);
  char *res = s21_NULL;
  if (len_needle == 0) {
    res = (char *)haystack;
  } else {
    for (int i = 0; i < len_haystack; i++) {
      if (haystack[i] == needle[0]) {
        int j = 0;
        while (j != len_needle && haystack[i + j] != '\0' &&
               haystack[i + j] == needle[j])
          j++;
        if (j == len_needle) {
          res = (char *)&haystack[i];
          break;
        }
      }
    }
  }
  return res;
}

int delimiter(va_list args, setting *modified, char **src, const char *format) {
  int res = 0;
  va_list backup;
  va_copy(backup, args);
  if ((!**src && !modified->buffer &&
       (s21_strstr(format, "%n") != s21_strchr(format, '%') ||
        !s21_strstr(format, "%n"))) ||
      !va_arg(backup, void *) || modified->skipws) {
    res = 1;
  }
  va_end(backup);
  return res;
}

void mod_percent(char **src, setting *modified, const char *format) {
  trim_space_and_count(src, modified);
  if (*format == **src) {
    modified->count++;
    (*src)++;
  } else {
    modified->skipws = 1;
  }
  modified->format = 0;
}
