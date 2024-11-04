#include "./s21_matrix_oop.h"

/**
 * @brief Реализация конструкторов и деструктора
 */
/**
 * @brief S21Matrix()
 * Базовый конструктор, инициализирующий матрицу некоторой заранее заданной
 * размерностью.
 */
S21Matrix::S21Matrix() noexcept : _rows(0), _cols(0), matrix_(nullptr) {}

/**
 * @brief S21Matrix(int rows, int cols)
 * Параметризированный конструктор с количеством строк и столбцов.
 * @param rows
 * @param cols
 */
S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
  if (_rows < 0 || _cols < 0) {
    throw std::out_of_range("Incorrect matrix size");
  }
  matrix_ = new double[_rows * _cols]{};
}

/**
 * @brief S21Matrix(const S21Matrix& other)
 * Конструктор копирования.
 * @param other
 */
S21Matrix::S21Matrix(const S21Matrix &other)
    : _rows(other._rows),
      _cols(other._cols),
      matrix_(new double[_rows * _cols]) {
  std::copy(other.matrix_, other.matrix_ + _rows * _cols, matrix_);
}

/**
 * @brief S21Matrix(S21Matrix&& other)
 * Конструктор переноса.
 * @param other
 */
S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : _rows(other._rows), _cols(other._cols), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other._rows = 0;
  other._cols = 0;
}

/**
 * @brief ~S21Matrix()
 * Деструктор.
 */
S21Matrix::~S21Matrix() noexcept {
  delete[] matrix_;
  _rows = 0;
  _cols = 0;
  matrix_ = nullptr;
}

/**
 * @brief Accessors и mutators
 */
/**
 * @brief Accessors get_rows
 * @return int
 */
int S21Matrix::get_rows() const noexcept { return _rows; }

/**
 * @brief Accessors get_cols
 * @return int
 */
int S21Matrix::get_cols() const noexcept { return _cols; }

/**
 * @brief Mutators set_rows
 * принимаeт новые значения и устанавливаeт его в соответствующее приватное поле
 * (`_rows`). Также проверяет входные параметры на корректность перед
 * изменением.
 * @param rows
 */
void S21Matrix::set_rows(int rows) {
  if (rows < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }

  if (rows != _rows) {
    S21Matrix tmp{rows, _cols};
    int min = std::min(_rows, rows);
    for (int i = 0; i < min; ++i) {
      for (int j = 0; j < _cols; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

/**
 * @brief Mutators set_rows
 * принимаeт новые значения и устанавливаeт его в соответствующее приватное поле
 * (`_cols`). Также проверяет входные параметры на корректность перед
 * изменением.
 * @param cols
 */
void S21Matrix::set_cols(int cols) {
  if (cols < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }

  if (cols != _cols) {
    S21Matrix tmp{_rows, cols};
    int min = std::min(_cols, cols);
    for (int i = 0; i < _rows; ++i) {
      for (int j = 0; j < min; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

/**
 * @brief Операции над матрицами
 */
/**
 * @brief S21Matrix::EqMatrix(const S21Matrix &other) const
 * Проверяет матрицы на равенство между собой.
 * @param other
 * @return true
 * @return false
 */
bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (_rows != other._rows || _cols != other._cols) {
    return false;
  }

  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      if (std::abs(other(i, j) - (*this)(i, j)) > 1e-7) {
        return false;
      }
    }
  }
  return true;
}

/**
 * @brief S21Matrix::SumMatrix(const S21Matrix &other)
 * Прибавляет вторую матрицу к текущей различная размерность матриц.
 * @param other
 */
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (_rows != other.get_rows() || _cols != other.get_cols()) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      (*this)(i, j) += other(i, j);
    }
  }
}

/**
 * @brief S21Matrix::SubMatrix(const S21Matrix &other)
 *  Вычитает из текущей матрицы другую различная размерность матриц.
 * @param other
 */
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (_rows != other.get_rows() || _cols != other.get_cols()) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

/**
 * @brief S21Matrix::MulNumber(const double number)
 * Умножает текущую матрицу на число.
 * @param number
 */
void S21Matrix::MulNumber(const double number) noexcept {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      (*this)(i, j) *= number;
    }
  }
}

/**
 * @brief void MulMatrix(const S21Matrix& other)
 * Умножает текущую матрицу на вторую. Если число столбцов первой матрицы не
 * равно числу строк второй матрицы.
 * @param other
 */
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (_cols != other.get_rows()) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  S21Matrix result{_rows, other.get_cols()};
  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      for (int k = 0; k < _cols; ++k) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  *this = std::move(result);
}

/**
 * @brief S21Matrix Transpose()
 * Создает новую транспонированную матрицу из текущей и возвращает ее
 * @return S21Matrix
 */
S21Matrix S21Matrix::Transpose() const {
  S21Matrix result{_cols, _rows};
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      result(j, i) = (*this)(i, j);
    }
  }
  return result;
}

/**
 * @brief S21Matrix CalcComplements()
 *  Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее.
 * Матрица не является квадратной.
 * @return S21Matrix
 */
S21Matrix S21Matrix::CalcComplements() const {
  if (_rows != _cols) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  S21Matrix result{_rows, _cols};
  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      S21Matrix minor_matrix = get_minor(i, j);

      result(i, j) = minor_matrix.Determinant();

      if ((i + j) % 2 != 0) {
        result(i, j) = -result(i, j);
      }
    }
  }
  return result;
}

/**
 * @brief double Determinant()
 * Вычисляет и возвращает определитель текущей матрицы. Матрица не является
 * квадратной.
 * @return double. Возвращаем произведение диагональных элементов
 */
double S21Matrix::Determinant() const {
  if (_rows != _cols) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  double result = 1.0;
  S21Matrix tmp(*this);
  int size = _rows;
  for (int i = 0; i < size; ++i) {
    // Поиск строки с максимальным элементом в текущем столбце
    int max_row_index = i;
    for (int j = i + 1; j < size; ++j) {
      if (std::abs(tmp(j, i)) > std::abs(tmp(max_row_index, i))) {
        max_row_index = j;
      }
    }
    // Проверка на нулевой элемент
    if (std::abs(tmp(max_row_index, i)) < 1e-7) {
      return 0.0;  // Определитель равен нулю
    }
    // Поменять строки местами
    if (i != max_row_index) {
      for (int k = 0; k < size; ++k) {
        std::swap(tmp(i, k), tmp(max_row_index, k));
      }
      result = -result;
    }
    // Умножаем на диагональный элемент
    result *= tmp(i, i);
    // Приведение матрицы к треугольному виду
    for (int j = i + 1; j < size; ++j) {
      double koef = tmp(j, i) / tmp(i, i);
      for (int k = i; k < size; ++k) {
        tmp(j, k) -= tmp(i, k) * koef;
      }
    }
  }
  return result;
}

/**
 * @brief S21Matrix InverseMatrix()
 * Вычисляет и возвращает обратную матрицу. Определитель матрицы равен 0.
 * @return S21Matrix
 */
S21Matrix S21Matrix::InverseMatrix() const {
  if (_rows != _cols) {
    throw std::invalid_argument("Incorrect matrix size");
  }

  double det = Determinant();

  if (std::abs(det) < 1e-7) {
    throw std::invalid_argument("Determinant != 0");
  }

  return Transpose().CalcComplements() * (1.0 / det);
}

/**
 * @brief Перегрузка операторов, частично соответствующие операциям выше
 */

/**
 * @brief  Перегрузка оператора =
 * Присвоение матрице значений другой матрицы.
 * @param other
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    delete[] this->matrix_;
    this->_rows = 0;
    this->_cols = 0;
    this->matrix_ = nullptr;

    this->_rows = other._rows;
    this->_cols = other._cols;
    this->matrix_ = new double[_rows * _cols];
    std::copy(other.matrix_, other.matrix_ + (this->_rows * this->_cols),
              this->matrix_);
  }
  return *this;
}

/**
 * @brief Перегрузка оператора = для конструктора перемещения
 * @param other
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    delete[] matrix_;
    _rows = 0;
    _cols = 0;
    matrix_ = nullptr;

    std::swap(_rows, other._rows);
    std::swap(_cols, other._cols);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

/**
 * @brief  Перегрузка оператора () возвращающая ссылку на элемент
 * Индексация по элементам матрицы (строка, колонка). Индекс за пределами
 * матрицы.
 * @param row
 * @param col
 * @return double&
 */
double &S21Matrix::operator()(int row, int col) & {
  check_index(row, col);
  return matrix_[row * _cols + col];
}

/**
 * @brief Перегрузка оператора () возвращающая const ссылку на элемент ))
 * Индексация по элементам матрицы (строка, колонка). Индекс за пределами
 * матрицы.
 * @param row
 * @param col
 * @return const double&
 */
const double &S21Matrix::operator()(int row, int col) const & {
  check_index(row, col);
  return matrix_[row * _cols + col];
}

/**
 * @brief Перегрузка оператора ==
 * Проверка на равенство матриц (`EqMatrix`).
 * @param other
 * @return true
 * @return false
 */
bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

/**
 * @brief Перегрузка оператора +
 * Сложение двух матриц. Различная размерность матриц.
 * @param other
 * @return S21Matrix
 */
S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.SumMatrix(other);
  return tmp;
}

/**
 * @brief Перегрузка оператора +=
 * Присвоение сложения (`SumMatrix`). Различная размерность матриц.
 * @param other
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

/**
 * @brief Перегрузка оператора -
 * Вычитание одной матрицы из другой. Различная размерность матриц.
 * @param other
 * @return S21Matrix
 */
S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.SubMatrix(other);
  return tmp;
}

/**
 * @brief Перегрузка оператора -=
 * Присвоение разности (`SubMatrix`). Различная размерность матриц.
 * @param other
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

/**
 * @brief Перегрузка оператора *
 * Умножение матрицы на число.
 * @param number
 * @return S21Matrix
 */
S21Matrix S21Matrix::operator*(double number) const noexcept {
  S21Matrix tmp{*this};
  tmp.MulNumber(number);
  return tmp;
}

/**
 * @brief Перегрузка оператора *
 * умножение матрицы на число.
 * @param number
 * @param matrix
 * @return S21Matrix
 */
S21Matrix operator*(double number, const S21Matrix &other) noexcept {
  S21Matrix tmp = other * number;
  return tmp;
}

/**
 * @brief Перегрузка оператора *=
 * Присвоение умножения (`MulNumber`).
 * @param number
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator*=(double number) {
  MulNumber(number);
  return *this;
}

/**
 * @brief Перегрузка оператора *
 * Умножение матриц. Число столбцов первой матрицы не равно числу строк второй
 * матрицы.
 * @param other
 * @return S21Matrix
 */
S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.MulMatrix(other);
  return tmp;
}

/**
 * @brief Перегрузка оператора *=
 * Присвоение умножения (`MulMatrix`).  Число столбцов первой
 * матрицы не равно числу строк второй матрицы.
 * @param other
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

/**
 * @brief Вспомогательный метод приватный для получения минора матрицы
 * @param row
 * @param col
 * @return S21Matrix
 */
S21Matrix S21Matrix::get_minor(const int row, const int col) const {
  check_index(row, col);

  S21Matrix result{_rows - 1, _cols - 1};
  for (int i = 0; i < _rows; ++i) {
    if (i == row) continue;  // Пропускаем строку, которую нужно исключить
    for (int j = 0; j < _cols; ++j) {
      if (j == col) continue;  // Пропускаем столбец, который нужно исключить
      // Высчитываем итоговые индексы, с учётом пропущенного
      result(i - (i > row ? 1 : 0), j - (j > col ? 1 : 0)) = (*this)(i, j);
    }
  }
  return result;
}

/**
 * @brief Вспомогательный приватный метод для проверки корректности индексов
 * матрицы
 * @param row
 * @param col
 */
void S21Matrix::check_index(int row, int col) const {
  if (row >= _rows || col >= _cols || row < 0 || col < 0) {
    throw std::out_of_range("Index out of range for matrix access: " +
                            std::to_string(row) + ", " + std::to_string(col));
  }
}
