#include "./s21_math.h"

// возвращает абсолютное значение числа, то есть значение без учета его знака

long double s21_atan(double x) {
  long double result = 0;

  if (fabs(x) > 0.4 && fabs(x) < 10) {
    result = asin(
        x * sqrt(1 / (1 + x * x)));  //  Если абсолютное значение
                                     //  числа больше 0.4 и меньше 10
                                     //  - формула для вычисления арксинуса.
  } else {
    int ind_direct =
        (fabs(x) < 1);  // Определение переменной индикатора направления, в
                        // зависимости от абсолютного значения x
    if (ind_direct) {  // Адаптация x в зависимости от значения индикатора
                       // направления
      x = x;
    } else {
      x = 1 / x;
    }
    long double init_val;
    if (ind_direct) {  // Определение начального значения в зависимости от
                       // индикатора направления
      init_val = x;
    } else {
      init_val = -x;
    }
    result = init_val;
    if (!ind_direct) {  // Устанавливается начальное значение результата
      if (x > 0) {
        result += S21_M_PI_2;
      } else {
        result -= S21_M_PI_2;
      }
    }
    long double coefficient = 1L;
    long double n = 1L;
    while (s21_ld_abs(coefficient * init_val) > ACCURACY && n < 20) {
      coefficient = 1.0L / (2 * n + 1);
      init_val *= -x * x;
      result +=
          coefficient * init_val;  // Добавление следующего члена ряда Тейлора
      n++;
    }
  }
  return result;
}

// используем разложение ряда Тейлора - позволяет приближенно вычислять
// значения функций в окрестности заданной точки и находить их разложения в
// бесконечную сумму))) f(x) = f(a) + f'(a)(x-a)/1! + f''(a)(x-a)^2/2! +
// f'''(a)*(x-a)^3/3! + ...