#include "./s21_math.h"

long double s21_asin(double x) {
    long double asin;
    if (x == 1) {
        asin = S21_M_PI_2;
    } else if (x == -1) {
        asin = - S21_M_PI_2;
    } else if ((x > 1) || (x < -1)) {
        asin = S21_NAN;
    } else if ((x < 1) && (x > -1)) {
        asin = s21_atan(x / s21_sqrt(1 - x * x));
    }
    return asin;
}