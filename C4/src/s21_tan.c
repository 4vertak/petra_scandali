#include "s21_math_internal.h"

long double s21_tan(double x) {
  long double sine, cosine;
  s21_sincos(x, &sine, &cosine);
  return sine / cosine;
}
