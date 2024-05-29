#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct s21_matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum s21_matrix_error_code {
  S21_MATRIX_OK,
  S21_MATRIX_INCORRECT_MATRIX,
  S21_MATRIX_CALCULATION_ERROR,
  S21_MATRIX_ALLOC_FAIL,
} s21_matrix_error_code;

// Арифметические операторы:

// int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// Операторы сравнение:

// int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Операторы создания и удаления:

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// Другие функции:
// int s21_determinant(matrix_t *A, double *result);
// int s21_calc_complements(matrix_t *A, matrix_t *result);

// операторы трансформации:
// int s21_transpose(matrix_t *A, matrix_t *result);
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Помогаторы:

#endif  //  SRC_S21_MATRIX_H_
