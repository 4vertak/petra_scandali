#include "./test.h"

START_TEST(test_inverse_matrix_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &B);

  s21_create_matrix(4, 4, &C);

  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 1.0;
  C.matrix[0][2] = 0.0;
  C.matrix[0][3] = 0.0;
  C.matrix[1][0] = -5.0 / 23.0;
  C.matrix[1][1] = -121.0 / 23.0;
  C.matrix[1][2] = 2.0 / 23.0;
  C.matrix[1][3] = 1.0 / 23.0;
  C.matrix[2][0] = -18.0 / 23.0;
  C.matrix[2][1] = -379.0 / 46.0;
  C.matrix[2][2] = 19.0 / 46.0;
  C.matrix[2][3] = -25.0 / 46.0;
  C.matrix[3][0] = 53.0 / 69.0;
  C.matrix[3][1] = 1061.0 / 138.0;
  C.matrix[3][2] = -47.0 / 138.0;
  C.matrix[3][3] = 19.0 / 46.0;

  res = s21_eq_matrix(&C, &B);
#ifdef DEBAG
  print_matrix(&A);
  print_matrix(&B);
  print_matrix(&C);
#endif
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  int res;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(B.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(res, 0);
#ifdef DEBAG
  print_matrix(&A);
  print_matrix(&B);
#endif
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 3, &A);
  init_matrix(1.0, &A);

  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  init_matrix(1.0, &A);

  res = s21_inverse_matrix(&A, &B);
#ifdef DEBAG
  print_matrix(&A);
  print_matrix(&B);
#endif
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_5) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 3, &A);
  init_matrix(1.0, &A);
  s21_remove_matrix(&A);

  res = s21_inverse_matrix(&A, &B);
#ifdef DEBAG
  print_matrix(&A);
  print_matrix(&B);
#endif

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_inverse_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;

  s21_inverse_matrix(&A, &B);

  s21_create_matrix(3, 3, &C);

  C.matrix[0][0] = -3.0 / 5.0;
  C.matrix[0][1] = 0.0;
  C.matrix[0][2] = 1.0 / 5.0;
  ;
  C.matrix[1][0] = -4.0 / 5.0;
  C.matrix[1][1] = 1.0;
  C.matrix[1][2] = -2.0 / 5.0;
  C.matrix[2][0] = 16.0 / 15.0;
  C.matrix[2][1] = -2.0 / 3.0;
  C.matrix[2][2] = 1.0 / 5.0;

  res = s21_eq_matrix(&C, &B);
#ifdef DEBAG
  print_matrix(&C);
  print_matrix(&B);
#endif

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_inverse_matrix_7) {
  matrix_t A = {0};
  matrix_t C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {0};
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
#ifdef DEBAG
  print_matrix(&A);
  print_matrix(&B);
  print_matrix(&C);
#endif
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_inverse_matrix_8) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, 0);
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_inverse_matrix_9) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_inverse_matrix_10) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_inverse_matrix_11) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 2);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_inverse_matrix_12) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_inverse_matrix_13) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (codec1 && codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, 0);

    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&expected);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_inverse_matrix_14) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);
#ifdef DEBAG
  printf("res_valiue =%d\n", res_valiue);
  print_matrix(&m);
#endif
  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

#ifdef DEBAG
  printf("test_inverse_matrix_14\n");
  print_matrix(&res);
  print_matrix(&expected);
#endif
  ck_assert_int_eq(s21_eq_matrix(&expected, &res), 1);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_INVERSE_MATRIX |=========\033[0m");
  TCase *tc = tcase_create("tc_inverse_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_inverse_matrix_1);
  tcase_add_test(tc, test_inverse_matrix_2);
  tcase_add_test(tc, test_inverse_matrix_3);
  tcase_add_test(tc, test_inverse_matrix_4);
  tcase_add_test(tc, test_inverse_matrix_5);
  tcase_add_test(tc, test_inverse_matrix_6);
  tcase_add_test(tc, test_inverse_matrix_7);
  tcase_add_test(tc, test_inverse_matrix_8);
  tcase_add_test(tc, test_inverse_matrix_9);
  tcase_add_test(tc, test_inverse_matrix_10);
  tcase_add_test(tc, test_inverse_matrix_11);
  tcase_add_test(tc, test_inverse_matrix_12);
  tcase_add_test(tc, test_inverse_matrix_13);
  tcase_add_test(tc, test_inverse_matrix_14);

  return s;
}