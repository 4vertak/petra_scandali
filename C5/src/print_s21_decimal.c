#include "./s21_decimal.h"

void print_s21_decimal(int value) {
  int i;
  int digit;
  int remainder;

  for (i = 0; i < 21; i++) {
    remainder = value % 10;
    value = value / 10;
    digit = remainder + '0';
    printf("%c", digit);
  }
  printf("\n");
}