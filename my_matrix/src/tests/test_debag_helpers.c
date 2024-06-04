#include "./test.h"

void init_matrix(double number, matrix_t *A) {
  if (!matrix_validation(A)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = number;
        number++;
      }
    }
  }
}

void print_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) printf("| %12.7f ", A->matrix[i][j]);
      printf("|\n");
    }
    printf("\n");
  }
}

void set_value(double value, int rows, int columns, matrix_t *A) {
  A->matrix[rows][columns] = value;
}