#include "./s21_math.h"

// возвращает абсолютное значение числа, то есть значение без учета его знака

int s21_abs(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}

// еще можно тернарные операции  return x < 0 ? -x : x;