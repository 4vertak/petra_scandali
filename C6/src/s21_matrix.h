#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum s21_matrix_error_code {
  S21_MATRIX_OK,
  S21_MATRIX_INCORRECT_MATRIX,
  S21_MATRIX_CALCULATION_ERROR,
} s21_matrix_error_code;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Арифметические функции:
// Сложение матриц:
//  C(i,j) = A(i,j) + B(i,j).

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//  вычитание матриц: C(i,j) = A(i,j) - B(i,j).

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число. У
// B = m × n = λ × A, элементы которой определяются равенствами B = λ × A(i,j).

int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// Умножение двух матриц :
// Произведением матрицы A = m × k на матрицу B = k × n
// называется матрица C = m × n = A × B
// C(i, j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) × B(k,j).
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы:

// Транспонирование матрицы А заключается в замене строк этой матрицы ее
// столбцами с сохранением их номеров.

int s21_transpose(matrix_t *A, matrix_t *result);

// Обратная матрица

// Матрицу A в степени -1 называют обратной к квадратной матрице А, если
// произведение этих матриц равняется единичной матрице.
// Обратной матрицы не существует, если определитель равен 0.
// Обратная матрица находится по формуле $`A^{-1}=\frac{1} {|A|} × A_*^T`$

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Другие функции:

// Минор матрицы и матрица алгебраических дополнений:

// Минором M(i,j) называется определитель (n-1)-го порядка,
// полученный вычёркиванием из матрицы A i-й строки и j-го столбца.

// Алгебраическим дополнением элемента матрицы является
// значение минора умноженное на -1^(i+j).

int s21_calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы:

// Определитель (детерминант) - это число, которое ставят в соответствие
// каждой квадратной матрице и вычисляют из элементов по специальным формулам.
// Tip:определитель может быть вычислен только для квадратной матрицы.

// Определитель матрицы равен сумме произведений элементов строки(столбца) на
// соответствующие алгебраические дополнения.

int s21_determinant(matrix_t *A, double *result);

// Помогаторы:

int matrix_validation(matrix_t *A);
int matrix_size_validation(matrix_t *A, matrix_t *B);
int matrix_value_validation(matrix_t *A);
double calc_determinant(matrix_t *A);
void calc_minor(int row, int col, matrix_t *A, matrix_t *result);

#endif  //  SRC_S21_MATRIX_H_
