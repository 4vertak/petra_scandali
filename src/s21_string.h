#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
typedef unsigned long s21_size_t;

// возвращает указатель на первое вхождение значения c среди первых n байтов
// s или NULL, если не найдено
void *s21_memchr(const void *str, int c, size_t n);
// сравнивает первые n символов в областях памяти
// int memcmp(const void *str1, const void *str2, size_t n);
// // копирует n байт из области памяти src в dest, которые не должны
// пересекаться, в противном случае результат не определён (возможно как
// правильное копирование, так и нет) void *memcpy(void *dest, const void *src,
// size_t n);
// // заполняет область памяти одним байтом z
// void *memset(void *str, int c, size_t n);
// // дописывает не более n начальных символов строки src (или всю src, если её
// длина меньше) в конец dest char *strncat(char *dest, const char *src, size_t
// n);
// // возвращает адрес символа c в строке s, начиная с головы, или NULL, если
// строка s не содержит символ c char *strchr(const char *str, int c);
// // лексикографическое сравнение строк (возвращает "0", если строки
// одинаковые, положительное, если первая строка больше, и отрицательное, если
// меньше) int strncmp(const char *str1, const char *str2, size_t n);
// // ккопирует до n байт строки из одного места в другое
// char *strncpy(char *dest, const char *src, size_t n);
// // определяет максимальную длину начальной подстроки, состоящей исключительно
// из байтов, не перечисленных в reject size_t strcspn(const char *str1, const
// char *str2);
// // возвращает строковое представление сообщения об ошибке errno (не
// потоко-безопасная) char *strerror(int errnum);
// // возвращает длину строки
// size_t strlen(const char *str);
// // находит первое вхождение любого символа, перечисленного в accept
// char *strpbrk(const char *str1, const char *str2);
// // возвращает адрес символа c в строке s, начиная с хвоста, или NULL, если
// строка s не содержит символ c char *strrchr(const char *str, int c);
// // находит первое вхождение строки needle в haystack
// char *strstr(const char *haystack, const char *needle);
// // преобразует строку в последовательность токенов. Не потоко-безопасная, не
// реентерабельная. char *strtok(char *str, const char *delim);

// // int sscanf(const char *str, const char *format, ...);
// // int sprintf(char *str, const char *format, ...);

#endif