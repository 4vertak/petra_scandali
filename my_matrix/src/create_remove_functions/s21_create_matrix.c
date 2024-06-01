#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  s21_matrix_error_code error_code = S21_MATRIX_OK;
  if (result == NULL || rows <= 0 || columns <= 0) {
    error_code = S21_MATRIX_INCORRECT_MATRIX;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return error_code;
}