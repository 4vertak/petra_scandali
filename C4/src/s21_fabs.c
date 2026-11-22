#include "s21_math.h"

long double s21_fabs(double x) { return __builtin_signbit(x) ? -x : x; }
