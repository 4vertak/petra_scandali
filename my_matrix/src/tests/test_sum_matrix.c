#include "./test.h"

void def_sum_matrix_test(matrix_t *A, matrix_t *B, matrix_t *C, int rows_A,
                         int columns_A, int rows_B, int columns_B, int value_1,
                         int value_2, int check_return_value) {
  s21_create_matrix(rows_A, columns_A, A);
  init_matrix(value_1, A);
  s21_create_matrix(rows_B, columns_B, B);
  init_matrix(value_2, B);
  int return_value = s21_sum_matrix(A, B, C);
#ifdef DEBAG
  print_matrix(A);
  printf("+++++++++++++\n");
  print_matrix(B);
  printf("=============\n");
  print_matrix(C);
#endif
  if (A != NULL) s21_remove_matrix(A);
  if (B != NULL) s21_remove_matrix(B);
  if (C != NULL) s21_remove_matrix(C);
  ck_assert_int_eq(return_value, check_return_value);
}

START_TEST(test_sum_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int rows_A = 2;
  int columns_A = 2;
  int rows_B = 2;
  int columns_B = 2;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = S21_MATRIX_OK;
  def_sum_matrix_test(&A, &B, &C, rows_A, columns_A, rows_B, columns_B, value_1,
                      value_2, check_return_value);
}
END_TEST

// FAILURE eq_matrix size A != B
START_TEST(test_sum_matrix_2) {
  // printf("test_sum_matrix_2\n");
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int rows_A = 2;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 2;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = S21_MATRIX_CALCULATION_ERROR;
  def_sum_matrix_test(&A, &B, &C, rows_A, columns_A, rows_B, columns_B, value_1,
                      value_2, check_return_value);
}
END_TEST
// FAILURE B == NULL
START_TEST(test_sum_matrix_3) {
  // printf("test_sum_matrix_3\n");
  matrix_t A = {0};
  ;
  //   matrix_t B;
  matrix_t C = {0};
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_sum_matrix_test(&A, NULL, &C, rows_A, columns_A, rows_B, columns_B,
                      value_1, value_2, check_return_value);
}
END_TEST
// FAILURE value_1 < value_2
START_TEST(test_sum_matrix_4) {
  // printf("test_sum_matrix_4\n");
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.21;
  double value_2 = 1.12;
  int check_return_value = S21_MATRIX_OK;
  def_sum_matrix_test(&A, &B, &C, rows_A, columns_A, rows_B, columns_B, value_1,
                      value_2, check_return_value);
}
END_TEST

// FAILURE A == NULL
START_TEST(test_sum_matrix_5) {
  // printf("test_sum_matrix_5\n");
  //   matrix_t A;
  matrix_t B = {0};
  ;
  matrix_t C = {0};
  ;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_sum_matrix_test(NULL, &B, &C, rows_A, columns_A, rows_B, columns_B,
                      value_1, value_2, check_return_value);
}
END_TEST

// FAILURE A == B
START_TEST(test_sum_matrix_6) {
  //   matrix_t A;
  //   matrix_t B;
  // printf("test_sum_matrix_6\n");
  matrix_t C = {0};
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double value_1 = 1.0e-7;
  double value_2 = 1.0e-7;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_sum_matrix_test(NULL, NULL, &C, rows_A, columns_A, rows_B, columns_B,
                      value_1, value_2, check_return_value);
}
END_TEST

START_TEST(test_sum_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int result = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(S21_MATRIX_INCORRECT_MATRIX, result);
}
END_TEST

START_TEST(test_sum_matrix_8) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  init_matrix(1.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_9) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  init_matrix(0.0, &A);

  s21_create_matrix(4, 4, &B);
  init_matrix(2.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_10) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  init_matrix(-3.0, &A);

  s21_create_matrix(4, 4, &B);
  init_matrix(5.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_11) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  init_matrix(5.0, &A);

  s21_create_matrix(4, 4, &B);
  init_matrix(-3.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_12) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  init_matrix(1.0, &A);

  s21_create_matrix(4, 2, &B);
  init_matrix(1.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 8.0;
  X.matrix[2][0] = 10.0;
  X.matrix[2][1] = 12.0;
  X.matrix[3][0] = 14.0;
  X.matrix[3][1] = 16.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_13) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  init_matrix(-1.0, &A);

  s21_create_matrix(4, 2, &B);
  init_matrix(3.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 8.0;
  X.matrix[2][0] = 10.0;
  X.matrix[2][1] = 12.0;
  X.matrix[3][0] = 14.0;
  X.matrix[3][1] = 16.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_14) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  init_matrix(4.0, &A);

  s21_create_matrix(4, 2, &B);
  init_matrix(-2.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 8.0;
  X.matrix[2][0] = 10.0;
  X.matrix[2][1] = 12.0;
  X.matrix[3][0] = 14.0;
  X.matrix[3][1] = 16.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_sum_matrix_15) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 2, &A);

  s21_create_matrix(4, 3, &B);

  res = s21_sum_matrix(&A, &B, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 2);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_SUM_MATRIX |=========\033[0m");
  TCase *tc = tcase_create("tc_sum_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sum_matrix_1);
  tcase_add_test(tc, test_sum_matrix_2);
  tcase_add_test(tc, test_sum_matrix_3);
  tcase_add_test(tc, test_sum_matrix_4);
  tcase_add_test(tc, test_sum_matrix_5);
  tcase_add_test(tc, test_sum_matrix_6);
  tcase_add_test(tc, test_sum_matrix_7);
  tcase_add_test(tc, test_sum_matrix_8);
  tcase_add_test(tc, test_sum_matrix_9);
  tcase_add_test(tc, test_sum_matrix_10);
  tcase_add_test(tc, test_sum_matrix_11);
  tcase_add_test(tc, test_sum_matrix_12);
  tcase_add_test(tc, test_sum_matrix_13);
  tcase_add_test(tc, test_sum_matrix_14);
  tcase_add_test(tc, test_sum_matrix_15);

  return s;
}