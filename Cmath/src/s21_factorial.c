#include "./s21_math.h"

long double s21_factorial(long double n){
    long double fact = 1;
    for (int c=1; c<=n; c++){
        fact = fact * c;
    }
    return fact;
}
