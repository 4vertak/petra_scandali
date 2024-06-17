#include "../s21_matrix.h"

// SUCCESS 1
// FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;
  if (matrix_validation(A) || matrix_validation(B) ||
      !matrix_size_validation(A, B)) {
    return_value = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          return_value = FAILURE;
          break;
        }
      }
    }
  }
  return return_value;
}