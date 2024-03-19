#include "./s21_math.h"

// возвращает абсолютное значение числа, то есть значение без учета его знака

// НЕ зАБЫТЬ asin fabs sqrt - заменить на функции s21_...

long double s21_atan(double x) {
  long double result = 0;
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
    temp = x;
  } else {
    temp = -x;
  }
  result = temp;
  if (!ind_direct) {  // Устанавливается начальное значение результата
    if (x > 0) {
      result += S21_M_PI_2;
    } else {
      result -= S21_M_PI_2;
    }
  }
  long double coefficient = 1L;
  long double n = 1L;
  while (s21_ld_abs(coefficient * temp) > ACCURACY && n < 20) {
    coefficient = 1.0L / (2 * n + 1);
    temp *= -x * x;
    result +=
        coefficient * init_val;  // Добавление следующего члена ряда Тейлора
    n++;
  }
  // }
  return result;
}

// используем разложение ряда Тейлора - позволяет приближенно вычислять
// значения функций в окрестности заданной точки и находить их разложения в
// бесконечную сумму))) f(x) = f(a) + f'(a)(x-a)/1! + f''(a)(x-a)^2/2! +
// f'''(a)*(x-a)^3/3! + ...
