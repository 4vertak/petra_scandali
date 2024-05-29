#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  s21_matrix_error_code error_code = S21_MATRIX_INCORRECT_MATRIX;
  if (rows > 0 && columns > 0) {
    if ((result->matrix = (double **)calloc(rows, sizeof(double *)))) {
      result->columns = columns;
      result->rows = rows;
      for (int i = 0; i < rows; i += 1) {
        if (!(result->matrix[i] = (double *)calloc(columns, sizeof(double)))) {
          for (int j = 0; j < i; j += 1) free(result->matrix[j]);
          free(result->matrix);
          error_code = S21_MATRIX_ALLOC_FAIL;
        }
      }
      if (error_code == S21_MATRIX_INCORRECT_MATRIX) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < columns; j++) result->matrix[i][j] = 0;
        }
        error_code = S21_MATRIX_OK;
      }
    } else
      error_code = S21_MATRIX_ALLOC_FAIL;
  }
  return error_code;
}