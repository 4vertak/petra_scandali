#include "./s21_math.h"

// возвращает абсолютное значение числа, то есть значение без учета его знака

int s21_abs(int x) { return x > 0 ? x : -x; }