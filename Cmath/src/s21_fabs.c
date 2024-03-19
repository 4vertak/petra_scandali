#include "./s21_math.h"

long double s21_fabs(long double x) {
    long double result = x;
    if (result < 0.0) result = -result; // или просто меняем знак)))
    return result;
}
