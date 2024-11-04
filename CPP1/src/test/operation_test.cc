#include "./main_test.h"

TEST(tests_operations, sum_matrix_1) {
  S21Matrix array_1(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_1(i, j) = 1.0;

  S21Matrix array_2(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_2(i, j) = 1.0;
  array_1.SumMatrix(array_2);
  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), 2);
    }
  }
}

// if incorrect matrix size

TEST(tests_operations, sum_matrix_2) {
  S21Matrix array_1(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_1(i, j) = 1.0;
  S21Matrix array_2 = S21Matrix(5, 5);
  EXPECT_THROW(array_1.SumMatrix(array_2), std::invalid_argument);
}

TEST(tests_operations, sum_matrix_3) {
  S21Matrix array_1(2, 3);
  int count = 1.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
      count++;
    }
  }

  S21Matrix array_2(2, 3);
  int count1 = 1.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      array_2(i, j) = count1;
      count1++;
    }
  }

  double matrix_res[2][3] = {{2, 4, 6}, {8, 10, 12}};
  array_1.SumMatrix(array_2);
  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), matrix_res[i][j]);
    }
  }
}

TEST(tests_operations, sub_matrix_1) {
  S21Matrix array_1(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_1(i, j) = 1.0;
  S21Matrix array_2(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_2(i, j) = 1.0;
  array_1.SubMatrix(array_2);
  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), 0);
    }
  }
}

// if incorrect matrix size

TEST(tests_operations, sub_matrix_2) {
  S21Matrix array_1(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_1(i, j) = 1.0;
  S21Matrix array_2 = S21Matrix(5, 5);
  EXPECT_THROW(array_1.SubMatrix(array_2), std::invalid_argument);
}

TEST(tests_operations, sub_matrix_3) {
  S21Matrix array_1(2, 3);
  int count = 1.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
      count++;
    }
  }

  S21Matrix array_2(2, 3);
  int count2 = 1.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      array_2(i, j) = count2;
      count2++;
    }
  }

  array_1.SubMatrix(array_2);
  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), 0);
    }
  }
}

TEST(tests_operations, mul_number_1) {
  S21Matrix array_1(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_1(i, j) = 1.0;
  array_1.MulNumber(0);
  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), 0);
    }
  }
}

TEST(tests_operations, mul_number_3) {
  S21Matrix array_1(2, 3);
  S21Matrix array_2(2, 3);
  int count = 1.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
      array_2(i, j) = count * 10;
      count++;
    }
  }

  array_1.MulNumber(10);
  for (int i = 0; i < array_1.get_rows(); ++i) {
    for (int j = 0; j < array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), array_2(i, j));
    }
  }
}

TEST(tests_operations, mul_matrix_1) {
  S21Matrix array_1(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array_1(i, j) = 1.0;
  S21Matrix array_2 = S21Matrix(5, 5);
  EXPECT_THROW(array_1.MulMatrix(array_2), std::invalid_argument);
}

TEST(tests_operations, mul_matrix_2) {
  S21Matrix array_1 = S21Matrix(1, 3);
  S21Matrix array_2 = S21Matrix(3, 2);
  array_1.MulMatrix(array_2);
  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), 0);
    }
  }
  EXPECT_EQ(array_1.get_rows(), 1);
  EXPECT_EQ(array_1.get_cols(), 2);
}

TEST(tests_operations, mul_matrix_4) {
  S21Matrix array_1(2, 3);
  int count = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
      count++;
    }

  S21Matrix array_2(3, 2);
  array_2(0, 0) = 7.0;
  array_2(0, 1) = 8.0;
  array_2(1, 0) = 9.0;
  array_2(1, 1) = 1.0;
  array_2(2, 0) = 2.0;
  array_2(2, 1) = 3.0;

  double proizv[2][2] = {{31, 19}, {85, 55}};
  array_1.MulMatrix(array_2);

  for (int i = 0; i != array_1.get_rows(); ++i) {
    for (int j = 0; j != array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), proizv[i][j]);
    }
  }
  EXPECT_EQ(array_1.get_cols(), 2);
  EXPECT_EQ(array_1.get_rows(), 2);
}

TEST(tests_operations, transpose_1) {
  S21Matrix array_1 = S21Matrix(2, 3);
  S21Matrix array_2 = array_1.Transpose();
  for (int i = 0; i != array_2.get_rows(); ++i) {
    for (int j = 0; j != array_2.get_cols(); ++j) {
      EXPECT_EQ(0, array_2(i, j));
    }
  }
  EXPECT_EQ(array_2.get_rows(), 3);
  EXPECT_EQ(array_2.get_cols(), 2);
}

TEST(tests_operations, transpose_2) {
  S21Matrix array_1(2, 3);
  int count = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
      count++;
    }

  double reference_array[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  S21Matrix array_2 = array_1.Transpose();
  for (int i = 0; i != array_2.get_rows(); ++i) {
    for (int j = 0; j != array_2.get_cols(); ++j) {
      EXPECT_EQ(reference_array[i][j], array_2(i, j));
    }
  }
}

TEST(tests_operations, transpose_3) {
  S21Matrix array_1(3, 2);
  array_1(0, 0) = 5.0;
  array_1(0, 1) = 4.0;
  array_1(1, 0) = 5.0;
  array_1(1, 1) = 4.0;
  array_1(2, 0) = 5.0;
  array_1(2, 1) = 4.0;

  double reference_array[2][3] = {{5, 5, 5}, {4, 4, 4}};
  S21Matrix array_2 = array_1.Transpose();
  for (int i = 0; i != array_2.get_rows(); ++i) {
    for (int j = 0; j != array_2.get_cols(); ++j) {
      EXPECT_EQ(reference_array[i][j], array_2(i, j));
    }
  }
}

TEST(tests_operations, determinant_1) {
  S21Matrix array_1 = S21Matrix(1, 1);
  EXPECT_EQ(array_1.Determinant(), 0);
}

TEST(tests_operations, determinant_2) {
  S21Matrix array_1 = S21Matrix(1, 2);
  EXPECT_THROW(array_1.Determinant(), std::invalid_argument);
}

TEST(tests_operations, determinant_3) {
  S21Matrix array_1 = S21Matrix(2, 2);
  EXPECT_EQ(array_1.Determinant(), 0);
}

TEST(tests_operations, determinant_4) {
  S21Matrix array_1(3, 3);
  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
      count++;
    }

  EXPECT_EQ(array_1.Determinant(), 0);
}

TEST(tests_operations, calccomplements_1) {
  S21Matrix array_1(3, 3);
  int count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      array_1(i, j) = count;
    }
    count++;
  }

  S21Matrix calcs = array_1.CalcComplements();
  for (int i = 0; i != 3; ++i) {
    for (int j = 0; j != 3; ++j) {
      EXPECT_EQ(0, calcs(i, j));
    }
  }
}

TEST(tests_operations, calccomplements_2) {
  S21Matrix array_1 = S21Matrix(3, 4);
  EXPECT_THROW(array_1.CalcComplements(), std::invalid_argument);
}

TEST(tests_operations, calccomplements_3) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1.0;
  array_1(0, 1) = 2.0;
  array_1(1, 0) = 1.0;
  array_1(1, 1) = 1.0;

  S21Matrix calcs_d(2, 2);
  calcs_d(0, 0) = 1.0;
  calcs_d(0, 1) = -1.0;
  calcs_d(1, 0) = -2.0;
  calcs_d(1, 1) = 1.0;

  S21Matrix calcs = array_1.CalcComplements();
  for (int i = 0; i != 2; ++i) {
    for (int j = 0; j != 2; ++j) {
      EXPECT_EQ(calcs_d(i, j), calcs(i, j));
    }
  }
}

TEST(tests_operations, calccomplements_4) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 3.0;
  array_1(0, 1) = 0.0;
  array_1(1, 0) = 0.0;
  array_1(1, 1) = 2.0;

  double calcs_d[2][2] = {{2, 0}, {0, 3}};
  S21Matrix calcs = array_1.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

TEST(tests_operations, inverse_matrix_1) {
  S21Matrix squareMatrix(2, 2);
  squareMatrix(0, 0) = 4.0;
  squareMatrix(0, 1) = 3.0;
  squareMatrix(1, 0) = 3.0;
  squareMatrix(1, 1) = 2.0;

  S21Matrix inverse = squareMatrix.InverseMatrix();
  EXPECT_EQ(inverse(0, 0), -2.0);
  EXPECT_EQ(inverse(0, 1), 3.0);
  EXPECT_EQ(inverse(1, 0), 3.0);
  EXPECT_EQ(inverse(1, 1), -4.0);
}

TEST(tests_operations, inverse_matrix_2) {
  S21Matrix nonSquareMatrix(2, 3);
  EXPECT_THROW(nonSquareMatrix.InverseMatrix(), std::invalid_argument);
}

TEST(tests_operations, inverse_matrix_3) {
  S21Matrix nonSquareMatrix(3, 1);
  EXPECT_THROW(nonSquareMatrix.InverseMatrix(), std::invalid_argument);
}

TEST(tests_operations, inverse_matrix_4) {
  S21Matrix singularMatrix(2, 2);
  singularMatrix(0, 0) = 1.0;
  singularMatrix(0, 1) = 2.0;
  singularMatrix(1, 0) = 2.0;
  singularMatrix(1, 1) = 4.0;
  EXPECT_THROW(singularMatrix.InverseMatrix(), std::invalid_argument);
  double det = singularMatrix.Determinant();
  EXPECT_DOUBLE_EQ(det, 0.0);
}
