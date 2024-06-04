#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_error_code error_code = S21_MATRIX_OK;
  if (matrix_validation(A) || matrix_validation(B) || result == NULL) {
    error_code = S21_MATRIX_INCORRECT_MATRIX;
  } else if (matrix_value_validation(A) || matrix_value_validation(B) ||
             !(A->columns == B->rows)) {
    error_code = S21_MATRIX_CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < B->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error_code;
}
