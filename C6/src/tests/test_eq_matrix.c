#include "./test.h"

void def_eq_matrix_test(matrix_t *A, matrix_t *B, int rows_A, int columns_A,
                        int rows_B, int columns_B, int value_1, int value_2,
                        int check_return_value) {
  s21_create_matrix(rows_A, columns_A, A);
  init_matrix(value_1, A);
  s21_create_matrix(rows_B, columns_B, B);
  init_matrix(value_2, B);
  int return_value = s21_eq_matrix(A, B);
#ifdef DEBAG
  printf("***********| == |***********\n");
  print_matrix(A);
  printf("***********| == |***********\n");
  print_matrix(B);
#endif
  if (A != NULL) s21_remove_matrix(A);
  if (B != NULL) s21_remove_matrix(B);
  ck_assert_int_eq(return_value, check_return_value);
}

// SUCCESS eq_matrix
START_TEST(test_eq_matrix_1) {
  matrix_t A;
  matrix_t B;
  int rows_A = 2;
  int columns_A = 2;
  int rows_B = 2;
  int columns_B = 2;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = SUCCESS;
  def_eq_matrix_test(&A, &B, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST

// FAILURE eq_matrix size A != B
START_TEST(test_eq_matrix_2) {
  matrix_t A;
  matrix_t B;
  int rows_A = 2;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 2;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = FAILURE;
  def_eq_matrix_test(&A, &B, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST
// FAILURE B == NULL
START_TEST(test_eq_matrix_3) {
  matrix_t A;
  //   matrix_t B;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = FAILURE;
  def_eq_matrix_test(&A, NULL, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST
// FAILURE value_1 < value_2
START_TEST(test_eq_matrix_4) {
  matrix_t A;
  matrix_t B;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.21;
  double value_2 = 1.12;
  int check_return_value = SUCCESS;
  def_eq_matrix_test(&A, &B, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST

// FAILURE A == NULL
START_TEST(test_eq_matrix_5) {
  //   matrix_t A;
  matrix_t B;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = FAILURE;
  def_eq_matrix_test(NULL, &B, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST

// FAILURE A == B
START_TEST(test_eq_matrix_6) {
  //   matrix_t A;
  //   matrix_t B;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = FAILURE;
  def_eq_matrix_test(NULL, NULL, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST

START_TEST(test_eq_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test_eq_matrix_8) {
  matrix_t A;
  matrix_t B;
  int rows_A = rand() % 100 + 1;
  int columns_A = rand() % 100 + 1;
  int rows_B = rand() % 100 + 1;
  int columns_B = rand() % 100 + 1;
  double value_1 = 1.0;
  double value_2 = 1.0;
  int check_return_value = FAILURE;
  def_eq_matrix_test(&A, &B, rows_A, columns_A, rows_B, columns_B, value_1,
                     value_2, check_return_value);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_EQ_MATRIX |=========\033[0m");
  TCase *tc = tcase_create("tc_eq_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_eq_matrix_1);
  tcase_add_test(tc, test_eq_matrix_2);
  tcase_add_test(tc, test_eq_matrix_3);
  tcase_add_test(tc, test_eq_matrix_4);
  tcase_add_test(tc, test_eq_matrix_5);
  tcase_add_test(tc, test_eq_matrix_6);
  tcase_add_test(tc, test_eq_matrix_7);
  tcase_add_test(tc, test_eq_matrix_8);

  return s;
}