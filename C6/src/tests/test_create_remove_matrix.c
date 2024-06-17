#include "./test.h"

void def_create_remove_matrix_test(int rows, int columns,
                                   int check_return_value, matrix_t *result) {
  int error_code = s21_create_matrix(rows, columns, result);
  if (result == NULL) {
    ck_assert_int_eq(error_code, check_return_value);
  } else {
    double number = 1.0;
    init_matrix(number, result);
#ifdef DEBAG
    print_matrix(result);
#endif
    s21_remove_matrix(result);
    ck_assert_int_eq(error_code, check_return_value);
    if (result->matrix != NULL) {
      printf("FREE_ALLOC_FAIL");
    }
  }
}

// valid_martix

START_TEST(test_create_remove_matrix_0) {
  matrix_t result = {0};
  int rows = 8;
  int columns = 8;
  int check_return_value = S21_MATRIX_OK;
  def_create_remove_matrix_test(rows, columns, check_return_value, &result);
}
END_TEST

// valid_martix_1

START_TEST(test_create_remove_matrix_1) {
  matrix_t result = {0};
  int rows = 1;
  int columns = 8;
  int check_return_value = S21_MATRIX_OK;
  def_create_remove_matrix_test(rows, columns, check_return_value, &result);
}
END_TEST
// valid_martix_1

START_TEST(test_create_remove_matrix_2) {
  matrix_t result = {0};
  int rows = 8;
  int columns = 2;
  int check_return_value = S21_MATRIX_OK;
  def_create_remove_matrix_test(rows, columns, check_return_value, &result);
}
END_TEST

// invalid_matrix rows = 0
START_TEST(test_create_remove_matrix_3) {
  matrix_t result = {0};
  int rows = 0;
  int columns = 8;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_create_remove_matrix_test(rows, columns, check_return_value, &result);
}
END_TEST

// invalid_matrix columns = 0
START_TEST(test_create_remove_matrix_4) {
  matrix_t result = {0};
  int rows = 8;
  int columns = 0;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_create_remove_matrix_test(rows, columns, check_return_value, &result);
}
END_TEST

// invalid_matrix & rows = 0
START_TEST(test_create_remove_matrix_5) {
  matrix_t result = {0};
  int rows = 0;
  int columns = 0;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_create_remove_matrix_test(rows, columns, check_return_value, &result);
}
END_TEST

// invalid_matrix result = NULL
START_TEST(test_create_remove_matrix_6) {
  int rows = 8;
  int columns = 0;
  int check_return_value = S21_MATRIX_INCORRECT_MATRIX;
  def_create_remove_matrix_test(rows, columns, check_return_value, NULL);
}
END_TEST

Suite *test_create_remove_matrix(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_CREATE_REMOVE_MATRIX |=========\033[0m");
  TCase *tc = tcase_create("tc_create_remove_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_create_remove_matrix_0);
  tcase_add_test(tc, test_create_remove_matrix_1);
  tcase_add_test(tc, test_create_remove_matrix_2);
  tcase_add_test(tc, test_create_remove_matrix_3);
  tcase_add_test(tc, test_create_remove_matrix_4);
  tcase_add_test(tc, test_create_remove_matrix_5);
  tcase_add_test(tc, test_create_remove_matrix_6);

  return s;
}
