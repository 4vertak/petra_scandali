#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  s21_matrix_error_code error_code = S21_MATRIX_OK;
  if (matrix_validation(A)) {
    error_code = S21_MATRIX_INCORRECT_MATRIX;
  } else if (A->rows != A->columns || result == NULL) {
    error_code = S21_MATRIX_CALCULATION_ERROR;
  } else {
    *result = 0.0;
    *result = calc_determinant(A);
  }
  return error_code;
}
