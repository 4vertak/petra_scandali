#include "./test.h"
void init_matrix(double number, matrix_t *A) {
  for (int i = 0; i < A->rows; number++, i++) {
    for (int j = 0; j < A->columns; j++) A->matrix[j][j] = number;
  }
}
void print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) printf("| %1.0f |", A->matrix[i][j]);
    printf("\n");
  }
}

void test_add(int rows, int columns) {
  matrix_t result = {0};
  int error_code = s21_create_matrix(rows, columns, &result);
  double number = 1.0;
  init_matrix(number, &result);
#ifdef DEBAG
  print_matrix(&result);
#endif
  ck_assert_int_eq(error_code, S21_MATRIX_OK);
  s21_remove_matrix(&result);
  if (result.matrix != NULL) {
    printf("REALLOC_FAIL");
  }
}

START_TEST(test_create_remove_matrix_0) {
  int rows = 8;
  int columns = 8;
  test_add(rows, columns);
}
END_TEST

Suite *test_create_remove_matrix(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ADD |=========\033[0m");
  TCase *tc = tcase_create("tc_add");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_create_remove_matrix_0);

  return s;
}
