#include "./main_test.h"

TEST(test_mutators, set_rows_1) {
  S21Matrix array(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array(i, j) = 1.0;

  array.set_rows(5);
  EXPECT_EQ(array.get_rows(), 5);
}
// Invalid input length error
TEST(test_mutators, set_rows_2) {
  S21Matrix array(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array(i, j) = 1.0;
  EXPECT_THROW(array.set_rows(-1), std::invalid_argument);
}

TEST(test_mutators, set_cols_1) {
  S21Matrix array(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array(i, j) = 1.0;
  array.set_cols(5);
  EXPECT_EQ(array.get_cols(), 5);
}
// Invalid input length error
TEST(test_mutators, set_cols_2) {
  S21Matrix array(3, 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) array(i, j) = 1.0;
  EXPECT_THROW(array.set_cols(-1), std::invalid_argument);
}
