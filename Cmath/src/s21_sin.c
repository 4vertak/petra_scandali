#include "./s21_math.h"

long double s21_sin(double x) {
    double sum = 0;
    double term = x;
    int n = 1;
    for (int i = 1; i <= 10; i++) {
        sum += term;
        n += 2;
        term *= -1 * x * x / (n * (n - 1));
    }
    return sum;
}