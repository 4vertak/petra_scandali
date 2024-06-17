#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  s21_matrix_error_code error_code = S21_MATRIX_OK;
  if (matrix_validation(A) || result == NULL) {
    error_code = S21_MATRIX_INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error_code = S21_MATRIX_CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double determinant = 0;
        s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
        calc_minor(i, j, A, &minor);
        s21_determinant(&minor, &determinant);
        result->matrix[i][j] = pow(-1, (i + j)) * determinant;
        s21_remove_matrix(&minor);
      }
    }
  }
  return error_code;
}