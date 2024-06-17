#include "./s21_math.h"

long double s21_log(double x) {
    if (x == S21_INF_POS) {
        return x;
    }
    if (x == 0) {
        return S21_INF_NEG;
    }
    if (x == 1) {
        return 0;
    }
    if (x < 0 || x == S21_INF_NEG) {
        return S21_NAN;
    }

    long double log = 0, compare = 0;
    int n_iterations= 0;
    for (; x >= S21_EXP; n_iterations++) {
        x /= S21_EXP;
    }
    for (int i = 0; i < 100; i++) {
        compare = log;
        log = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    log += n_iterations;
    return log;
}
