#include "./s21_math.h"

long double s21_sqrt(long double x) {
if (x < 0) {
printf("Невозможно найти квадратный корень из отрицательного числа\n");
return -1.0;
}
if (x == 0) {
return 0;
}

long double oldApproximation;
long double approximation = x;
do {
oldApproximation = approximation;
approximation = (oldApproximation + x / oldApproximation) / 2.0;
} while (oldApproximation != approximation);
return approximation;
}