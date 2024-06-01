#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

// #define DEBAG

Suite *test_create_remove_matrix(void);
// Арифметические операторы:
Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);

// Операторы сравнение:
Suite *test_eq_matrix(void);

// // Преобразователи:
Suite *test_transpose(void);
Suite *test_inverse_matrix(void);

// // // Другие функции:
Suite *test_determinant(void);
Suite *test_calc_complements(void);

// Помогаторы:

void init_matrix(double number, matrix_t *A);
void print_matrix(matrix_t *A);
void set_value(double value, int rows, int columns, matrix_t *A);
double random_value(double min, double max);

#endif  // SRC_TESTS_TEST_H_