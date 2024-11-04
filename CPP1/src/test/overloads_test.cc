#include "./main_test.h"

TEST(tests_overloads, AssignmentOperatorTest) {
  S21Matrix array_copy;  // Создаем пустую матрицу для присваивания

  S21Matrix array(3, 3);
  array(0, 0) = 1.0;
  array(0, 1) = 2.0;
  array(0, 2) = 3.0;
  array(1, 0) = 4.0;
  array(1, 1) = 5.0;
  array(1, 2) = 6.0;
  array(2, 0) = 7.0;
  array(2, 1) = 8.0;
  array(2, 2) = 9.0;

  array_copy = array;  // Присваиваем

  EXPECT_EQ(array_copy.get_rows(), array.get_rows());
  EXPECT_EQ(array_copy.get_cols(), array.get_cols());

  for (int i = 0; i < array.get_rows(); ++i) {
    for (int j = 0; j < array.get_cols(); ++j) {
      EXPECT_DOUBLE_EQ(array_copy(i, j), array(i, j));
    }
  }
}

TEST(tests_operations, operator_mul_number_matrix_1) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1.0;
  array_1(0, 1) = 2.0;
  array_1(1, 0) = 3.0;
  array_1(1, 1) = 4.0;

  double scalar = 3.0;
  S21Matrix resultMatrix = scalar * array_1;

  EXPECT_EQ(resultMatrix(0, 0), 3.0);
  EXPECT_EQ(resultMatrix(0, 1), 6.0);
  EXPECT_EQ(resultMatrix(1, 0), 9.0);
  EXPECT_EQ(resultMatrix(1, 1), 12.0);

  EXPECT_EQ(array_1(0, 0), 1.0);
  EXPECT_EQ(array_1(0, 1), 2.0);
  EXPECT_EQ(array_1(1, 0), 3.0);
  EXPECT_EQ(array_1(1, 1), 4.0);
}

TEST(tests_operations, operator_mul_number_1) {
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
  array_1 *= 10;
  for (int i = 0; i < array_1.get_rows(); ++i) {
    for (int j = 0; j < array_1.get_cols(); ++j) {
      EXPECT_EQ(array_1(i, j), array_2(i, j));
    }
  }
}

TEST(tests_overloads, Addition_test_1) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1;
  array_1(0, 1) = 2;
  array_1(1, 0) = 3;
  array_1(1, 1) = 4;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 5;
  array_2(0, 1) = 6;
  array_2(1, 0) = 7;
  array_2(1, 1) = 8;

  S21Matrix result = array_1 + array_2;

  EXPECT_EQ(result(0, 0), 6);
  EXPECT_EQ(result(0, 1), 8);
  EXPECT_EQ(result(1, 0), 10);
  EXPECT_EQ(result(1, 1), 12);
}

TEST(tests_overloads, Addition_test_2) {
  S21Matrix array_1(2, 2);
  S21Matrix array_2(3, 3);

  ASSERT_THROW(
      { S21Matrix result = array_1 + array_2; }, std::invalid_argument);
}

TEST(tests_overloads, Addition_test_3) {
  S21Matrix array_1(2, 2);
  S21Matrix array_2(2, 2);

  S21Matrix result = array_1 + array_2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 0);
}

TEST(tests_overloads, Addition_test_4) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = -1;
  array_1(0, 1) = -2;
  array_1(1, 0) = -3;
  array_1(1, 1) = -4;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = -1;
  array_2(0, 1) = -1;
  array_2(1, 0) = -1;
  array_2(1, 1) = -1;

  S21Matrix result = array_1 + array_2;

  EXPECT_EQ(result(0, 0), -2);
  EXPECT_EQ(result(0, 1), -3);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -5);
}

TEST(tests_overloads, Addition_test_5) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1000000000;
  array_1(0, 1) = 2000000000;
  array_1(1, 0) = 3000000000;
  array_1(1, 1) = 4000000000;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 5000000000;
  array_2(0, 1) = 6000000000;
  array_2(1, 0) = 7000000000;
  array_2(1, 1) = 8000000000;

  S21Matrix result = array_1 + array_2;

  EXPECT_EQ(result(0, 0), 6000000000);
  EXPECT_EQ(result(0, 1), 8000000000);
  EXPECT_EQ(result(1, 0), 10000000000);
  EXPECT_EQ(result(1, 1), 12000000000);
}

TEST(tests_overloads, Subtraction_test_1) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1;
  array_1(0, 1) = 2;
  array_1(1, 0) = 3;
  array_1(1, 1) = 4;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 5;
  array_2(0, 1) = 6;
  array_2(1, 0) = 7;
  array_2(1, 1) = 8;

  S21Matrix result = array_1 - array_2;

  EXPECT_EQ(result(0, 0), -4);
  EXPECT_EQ(result(0, 1), -4);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -4);
}

TEST(tests_overloads, Subtraction_test_2) {
  S21Matrix array_1(2, 2);
  S21Matrix array_2(3, 3);

  ASSERT_THROW(
      { S21Matrix result = array_1 - array_2; }, std::invalid_argument);
}

TEST(tests_overloads, Subtraction_test_3) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = -1;
  array_1(0, 1) = -2;
  array_1(1, 0) = -3;
  array_1(1, 1) = -4;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = -1;
  array_2(0, 1) = -1;
  array_2(1, 0) = -1;
  array_2(1, 1) = -1;

  S21Matrix result = array_1 - array_2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), -1);
  EXPECT_EQ(result(1, 0), -2);
  EXPECT_EQ(result(1, 1), -3);
}

TEST(tests_overloads, Subtraction_test_4) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1000000000;
  array_1(0, 1) = 2000000000;
  array_1(1, 0) = 3000000000;
  array_1(1, 1) = 4000000000;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 5000000000;
  array_2(0, 1) = 4000000000;
  array_2(1, 0) = 3000000000;
  array_2(1, 1) = 2000000000;

  S21Matrix result = array_1 - array_2;

  EXPECT_EQ(result(0, 0), -4000000000);
  EXPECT_EQ(result(0, 1), -2000000000);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 2000000000);
}

TEST(tests_overloads, MulNumber_test_1) {
  S21Matrix array(2, 2);
  array(0, 0) = 1.0;
  array(0, 1) = 2.0;
  array(1, 0) = 3.0;
  array(1, 1) = 4.0;

  array = array * 2.0;

  ASSERT_EQ(array(0, 0), 2.0);
}

TEST(tests_overloads, MulNumber_test_2) {
  S21Matrix array(2, 2);
  array(0, 0) = 1.0;
  array(0, 1) = 2.0;
  array(1, 0) = 3.0;
  array(1, 1) = 4.0;

  array = array * 2.0;

  ASSERT_EQ(array(0, 1), 4.0);
}

TEST(tests_overloads, MulNumber_test_3) {
  S21Matrix array(2, 2);
  array(0, 0) = 1.0;
  array(0, 1) = 2.0;
  array(1, 0) = 3.0;
  array(1, 1) = 4.0;

  array = array * 2.0;

  ASSERT_EQ(array(1, 0), 6.0);
}

TEST(tests_overloads, MulNumber_test_4) {
  S21Matrix array(2, 2);
  array(0, 0) = 1.0;
  array(0, 1) = 2.0;
  array(1, 0) = 3.0;
  array(1, 1) = 4.0;

  array = array * 2.0;

  ASSERT_EQ(array(1, 1), 8.0);
}

TEST(tests_overloads, MulMatrix_test_1) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1.0;
  array_1(0, 1) = 2.0;
  array_1(1, 0) = 3.0;
  array_1(1, 1) = 4.0;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 2.0;
  array_2(0, 1) = 0.0;
  array_2(1, 0) = 1.0;
  array_2(1, 1) = 2.0;

  S21Matrix result = array_1 * array_2;

  ASSERT_EQ(result(0, 0), 4.0);
}

TEST(tests_overloads, MulMatrix_test_2) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1.0;
  array_1(0, 1) = 2.0;
  array_1(1, 0) = 3.0;
  array_1(1, 1) = 4.0;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 2.0;
  array_2(0, 1) = 0.0;
  array_2(1, 0) = 1.0;
  array_2(1, 1) = 2.0;

  S21Matrix result = array_1 * array_2;

  ASSERT_EQ(result(0, 1), 4.0);
}

TEST(tests_overloads, MulMatrix_test_3) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1.0;
  array_1(0, 1) = 2.0;
  array_1(1, 0) = 3.0;
  array_1(1, 1) = 4.0;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 2.0;
  array_2(0, 1) = 0.0;
  array_2(1, 0) = 1.0;
  array_2(1, 1) = 2.0;

  S21Matrix result = array_1 * array_2;

  ASSERT_EQ(result(1, 0), 10.0);
}

TEST(tests_overloads, MulMatrix_test__4) {
  S21Matrix array_1(2, 3);
  S21Matrix array_2(2, 2);
  ASSERT_THROW(
      { S21Matrix result = array_1 * array_2; }, std::invalid_argument);
}

TEST(tests_overloads, EqualMatrix_test_1) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  EXPECT_TRUE(array == array);
}

TEST(tests_overloads, EqualMatrix_test_2) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1;
  array_1(0, 1) = 2;
  array_1(1, 0) = 3;
  array_1(1, 1) = 4;

  S21Matrix array_2(2, 2);
  array_2(0, 0) = 1;
  array_2(0, 1) = 2;
  array_2(1, 0) = 3;
  array_2(1, 1) = 4;

  EXPECT_TRUE(array_1 == array_2);
}

TEST(tests_overloads, EqualMatrix_test_3) {
  S21Matrix array_1(2, 2);
  array_1(0, 0) = 1;
  array_1(0, 1) = 2;
  array_1(1, 0) = 3;
  array_1(1, 1) = 4;

  S21Matrix array_2(3, 3);
  array_2(0, 0) = 1;
  array_2(0, 1) = 2;
  array_2(0, 2) = 0;
  array_2(1, 0) = 3;
  array_2(1, 1) = 4;
  array_2(1, 2) = 0;
  array_2(2, 0) = 0;
  array_2(2, 1) = 0;
  array_2(2, 2) = 0;

  EXPECT_FALSE(array_1 == array_2);
}

TEST(tests_overloads, EqualMatrix_test_4) {
  S21Matrix array_1(0, 0);
  S21Matrix array_2(0, 0);

  EXPECT_TRUE(array_1 == array_2);
}

TEST(tests_overloads, AddToItself_test_1) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  array += array;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(array(i, j), (i * 2 + j + 1) * 2);
    }
  }
}

TEST(tests_overloads, AddToItself_test_2) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  S21Matrix emptyMatrix(2, 2);

  array += emptyMatrix;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(array(i, j), i * 2 + j + 1);
    }
  }
}

TEST(tests_overloads, AddToItself_test_3) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  S21Matrix emptyMatrix(2, 2);

  emptyMatrix += array;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(emptyMatrix(i, j), i * 2 + j + 1);
    }
  }
}

TEST(tests_overloads, SubToItself_test_1) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  S21Matrix emptyMatrix(2, 2);

  array -= emptyMatrix;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(array(i, j), i * 2 + j + 1);
    }
  }
}

TEST(tests_overloads, SubToItself_test_2) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  S21Matrix emptyMatrix(2, 2);

  emptyMatrix -= array;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(emptyMatrix(i, j), -(i * 2 + j + 1));
    }
  }
}

TEST(tests_overloads, MulToItself_test_1) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  S21Matrix Result(2, 2);
  Result(0, 0) = 7;
  Result(0, 1) = 10;
  Result(1, 0) = 15;
  Result(1, 1) = 22;

  array *= array;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(array(i, j), Result(i, j));
    }
  }
}

TEST(tests_overloads, MulToItself_test_2) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;

  S21Matrix emptyMatrix(2, 2);

  array *= emptyMatrix;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(array(i, j), 0);
    }
  }
}

TEST(tests_overloads, OverBracket_test_1) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;
  EXPECT_EQ(array(0, 0), 1);
}

TEST(tests_overloads, tests_overloads_throw) {
  S21Matrix array(2, 2);
  EXPECT_THROW(array(0, 3), std::invalid_argument);
}

TEST(tests_overloads, OverBracket_test_2) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;
  EXPECT_EQ(array(0, 1), 2);
}

TEST(tests_overloads, OverBracket_test_3) {
  S21Matrix array(2, 2);
  array(0, 0) = 1;
  array(0, 1) = 2;
  array(1, 0) = 3;
  array(1, 1) = 4;
  EXPECT_EQ(array(1, 0), 3);
}