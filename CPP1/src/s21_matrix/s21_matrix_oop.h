#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <algorithm>  // std::copy | std::min
#include <cmath>      // std::abs
#include <stdexcept>  // invalid_argument | out_of_range
#include <utility>    // std::move | std::swap

class S21Matrix {
 private:
  // attributes
  int _rows, _cols;  // rows and columns attributes
  double *matrix_;   // pointer to the memory where the matrix will be allocated
  void check_index(int row, int col) const;
  S21Matrix get_minor(const int row, const int col) const;

 public:
  /**
   * @brief Реализация конструкторов и деструктора
   */
  S21Matrix() noexcept;                    // default constructor
  explicit S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const S21Matrix &other);       // copy constructor
  S21Matrix(S21Matrix &&other) noexcept;   // move constructor
  ~S21Matrix() noexcept;                   // destructor

  /**
   * @brief Перегрузка операторов, частично соответствующие операциям выше
   */

  S21Matrix &operator=(const S21Matrix &other);  // assignment operator overload
  S21Matrix &operator=(S21Matrix &&other) noexcept;

  double &operator()(int row, int col) &;  // index operator overload
  double &operator()(int row, int col) && = delete;
  const double &operator()(int row, int col) const &;
  const double &operator()(int row, int col) const && = delete;
  bool operator==(const S21Matrix &other) const;
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix operator*(double number) const noexcept;
  friend S21Matrix operator*(double number, const S21Matrix &matrix) noexcept;
  S21Matrix &operator*=(double number);
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix &operator*=(const S21Matrix &other);

  /**
   * @brief Операции над матрицами
   */

  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double number) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  /**
   * @brief accessors и mutators
   */

  int get_cols() const noexcept;
  int get_rows() const noexcept;
  void set_rows(int new_rows);
  void set_cols(int new_cols);
};

#endif  // SRC_S21_MATRIX_OOP_H_