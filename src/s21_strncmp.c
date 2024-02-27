#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.
// лексикографическое сравнение строк (возвращает "0", если строки
// одинаковые, положительное, если первая строка больше, и отрицательное, если
// меньше)

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
 while (n > 0) {
if (*str1 != *str2 || *str1 == '\0' || *str2 == '\0') {
return (*str1 - *str2);
}
str1++;
str2++;
n--;
}
return 0;
}
