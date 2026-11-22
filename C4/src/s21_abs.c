#include <limits.h>

#include "s21_math.h"

int s21_abs(int x) { return (x < 0 && x != INT_MIN) ? -x : x; }
