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
   * @brief accessors и mutators
   */

  int get_cols() const noexcept;
  int get_rows() const noexcept;
  void set_rows(int new_rows);
  void set_cols(int new_cols);

  /**
   * @brief Операции над матрицами
   */

  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double number);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  /**
   * @brief Перегрузка операторов, частично соответствующие операциям выше
   */

  S21Matrix &operator=(const S21Matrix &other);  // assignment operator overload
  S21Matrix &operator=(S21Matrix &&other) noexcept;

  /**
   * @brief В данной реализации перегрузки оператор вызова `()` ограничиваем
  изменения элементов матрицы в зависимости от категории значения (lvalue или
  rvalue), что позволяет безопасно использовать константные значения.
  *Кратко:
   * lvalue - это значения имеющие адрес в памяти, т.е. им можно присваивать
  значения
   * rvalue - это временные значения, которые не имеют адреса в памяти или
  изначально не предназначены для изменения (например, результаты выражения)
  * более подробно: https://en.cppreference.com/w/cpp/language/value_category
   */

  double &operator()(int row, int col)
      &;  // Позволяет изменять элемент по заданным индексам `row` и `col`, если
          // объект находится в "lvalue" состоянии (можно менять).
  double &operator()(int row, int col) && =
      delete;  // Запрет на изменение элемента, если объект находится в "rvalue"
               // состоянии (временный объект).
  const double &operator()(int row, int col)
      const &;  // Позволяет получить   доступ к элементу как в "lvalue" режиме
                // без возможности изменения (возврат по константной ссылке).
  const double &operator()(int row, int col) const && =
      delete;  // Запрет на  доступ к элементу из временного объекта при помощи
               // константного доступа.
  bool operator==(const S21Matrix &other) const;
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix operator*(double number) const;

  /**
   * @brief релизовал как friend function чтобы  фбло легче
   * реализовать и повторно использовать перегрузку оператор *  )))
   */
  friend S21Matrix operator*(double number, const S21Matrix &matrix) noexcept;
  S21Matrix &operator*=(double number);
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix &operator*=(const S21Matrix &other);
};

#endif  // SRC_S21_MATRIX_OOP_H_
