#include "../s21_matrix.h"

int matrix_validation(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}

int matrix_size_validation(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

int matrix_value_validation(matrix_t *A) {
  s21_matrix_error_code error_code = S21_MATRIX_OK;
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if (isinf(A->matrix[m][n]) || isnan(A->matrix[m][n])) {
        error_code = S21_MATRIX_CALCULATION_ERROR;
        break;
      }
    }
  }
  return error_code;
}

double calc_determinant(matrix_t *A) {
  double determinant = 0.0;
  if (A->rows == 1) {
    determinant = A->matrix[0][0];
  } else {
    matrix_t minor = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < A->columns; i++) {
      calc_minor(0, i, A, &minor);
      if (i % 2 == 1) {
        determinant -= A->matrix[0][i] * calc_determinant(&minor);
      } else {
        determinant += A->matrix[0][i] * calc_determinant(&minor);
      }
    }
    s21_remove_matrix(&minor);
  }
  return determinant;
}

void calc_minor(int row, int col, matrix_t *A, matrix_t *result) {
  int minor_row = 0;
  int minor_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    minor_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
}
