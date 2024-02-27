#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
typedef unsigned long long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

// дописывает не более n начальных символов строки src (или всю src, если её
// длина меньше) в конец dest
// char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// ккопирует до n байт строки из одного места в другое
// char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// определяет максимальную длину начальной подстроки, состоящей исключительно
// из байтов, не перечисленных в reject
// s21_size_t s21_strcspn(const char *str1, const char *str2);

// возвращает строковое представление сообщения об ошибке errno (не
// потоко-безопасная) char *strerror(int errnum);

// возвращает длину строки
s21_size_t s21_strlen(const char *str);

// находит первое вхождение любого символа, перечисленного в accept
// char *s21_strpbrk(const char *str1, const char *str2);

// возвращает адрес символа c в строке s, начиная с хвоста, или NULL, если
// строка s не содержит символ c
char *s21_strrchr(const char *str, int c);

// находит первое вхождение строки needle в haystack
// char *s21_strstr(const char *haystack, const char *needle);

// преобразует строку в последовательность токенов. Не потоко-безопасная, не
// реентерабельная.
// char *s21_strtok(char *str, const char *delim);

// int s21_sscanf(const char *str, const char *format, ...);
// int s21_sprintf(char *str, const char *format, ...);

#endif  // SRC_S21_STRING_H_