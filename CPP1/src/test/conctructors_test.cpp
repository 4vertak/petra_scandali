#include "./main_test.h"

TEST(s21_constructors_tests, constructor_0) {
  S21Matrix array;
  EXPECT_EQ(array.get_cols(), 0);
  EXPECT_EQ(array.get_rows(), 0);
}

TEST(s21_constructors_tests, constructor_1) {
  S21Matrix array(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(array(i, j), 0.0);
    }
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array(i, j) = 1.0;

  EXPECT_EQ(array.get_cols(), 3);
  EXPECT_EQ(array.get_rows(), 3);
}

TEST(s21_constructors_tests, constructor_2) {
  S21Matrix array = S21Matrix(3, 3);
  EXPECT_EQ(array.get_cols(), 3);
  EXPECT_EQ(array.get_rows(), 3);
}

// test corect copy value matrix

TEST(tests_constructors, constructor_3) {
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

  S21Matrix array_copy(array);

  EXPECT_EQ(array_copy.get_rows(), array.get_rows());
  EXPECT_EQ(array_copy.get_cols(), array.get_cols());

  for (int i = 0; i < array.get_rows(); ++i) {
    for (int j = 0; j < array.get_cols(); ++j) {
      EXPECT_DOUBLE_EQ(array_copy(i, j), array(i, j));
    }
  }
}
// test incorect row&col matrix
TEST(tests_constructors, constructor_4) {
  EXPECT_THROW(S21Matrix array(-3, -3), std::out_of_range);
}

// copy empty matrix

TEST(tests_constructors, constructor_5) {
  S21Matrix array;
  S21Matrix array_copy(array);
  EXPECT_EQ(array_copy.get_rows(), array.get_rows());
  EXPECT_EQ(array_copy.get_cols(), array.get_cols());
}
// cope if size matrix = 0
TEST(tests_constructors, constructor_6) {
  S21Matrix array(0, 0);
  S21Matrix array_copy(array);
  EXPECT_EQ(array_copy.get_rows(), array.get_rows());
  EXPECT_EQ(array_copy.get_cols(), array.get_cols());
}

TEST(tests_constructors, constructor_7) {
  S21Matrix array(1, 1);
  array(0, 0) = 42.0;
  S21Matrix array_copy(array);
  EXPECT_EQ(array_copy.get_rows(), array.get_rows());
  EXPECT_EQ(array_copy.get_cols(), array.get_cols());
  EXPECT_DOUBLE_EQ(array_copy(0, 0), array(0, 0));
}

TEST(tests_constructors, constructor_8) {
  S21Matrix array(1, 1);
  array(0, 0) = 42.0;
  S21Matrix array_2(std::move(array));
  EXPECT_EQ(array.get_rows(), 0);
  EXPECT_EQ(array.get_cols(), 0);
}
