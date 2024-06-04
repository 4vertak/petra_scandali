#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  s21_matrix_error_code error_code = S21_MATRIX_OK;
  double determinant = 0.0;
  s21_determinant(A, &determinant);
  if (matrix_validation(A) || result == NULL) {
    error_code = S21_MATRIX_INCORRECT_MATRIX;
  } else if (A->rows != A->columns || determinant == 0) {
    error_code = S21_MATRIX_CALCULATION_ERROR;
  } else {
    if (A->rows == 1) {
      error_code = s21_create_matrix(A->rows, A->rows, result);
      if (error_code == S21_MATRIX_OK)
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
      return error_code;
    }
    matrix_t tmp = {0};
    error_code = s21_calc_complements(A, &tmp);
    if (error_code == S21_MATRIX_OK) {
      matrix_t tmp_transpose = {0};
      error_code = s21_transpose(&tmp, &tmp_transpose);
      if (error_code == S21_MATRIX_OK) {
        s21_mult_number(&tmp_transpose, 1 / determinant, result);
      }
      s21_remove_matrix(&tmp_transpose);
    }
    s21_remove_matrix(&tmp);
  }
  return error_code;
}