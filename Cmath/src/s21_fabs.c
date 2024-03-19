#include "./s21_math.h"

long double s21_fabs(long double x) {
    long double result = x;
    unsigned long long *ptr = (unsigned long long *)&result; //переопределение типа на unsigned long long для изменения битового представления числа
    *ptr &= ~(1ULL << 63); // сброс старшего бита
    // if (result < 0.0) result = -result; // или просто меняем знак)))
    return result;
}
