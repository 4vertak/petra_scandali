#include "./test.h"

START_TEST(test_transpose_0) {
  int res = 0;
  matrix_t A = {0};

  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transpose_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};

  s21_create_matrix(2, 3, &A);
  init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  res = s21_transpose(&A, &T);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, SUCCESS);
#ifdef DEBAG
  printf("test_transpose_3\n");
  print_matrix(&T);
  print_matrix(&B);
#endif
  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_transpose_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_transpose(&A, &result), 1);
}
END_TEST

START_TEST(test_transpose_2) {
  // success with unininitialized matrix 3x2
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_3) {
  // success with unininitialized matrix 2x3
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_4) {
  // success with task reference values and 3x2 matrix
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = 5,
  eq_matrix.matrix[1][2] = 6;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_TRANSPOSE |=========\033[0m");
  TCase *tc = tcase_create("tc_transpose");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_transpose_0);
  tcase_add_test(tc, test_transpose_01);
  tcase_add_test(tc, test_transpose_1);
  tcase_add_test(tc, test_transpose_2);
  tcase_add_test(tc, test_transpose_3);
  tcase_add_test(tc, test_transpose_4);

  return s;
}