#include "./s21_matrix.h"

S21Matrix::S21Matrix() noexcept : _rows(0), _cols(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
  if (_rows < 0 || _cols < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  matrix_ = new double[_rows * _cols]{};
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : _rows(other._rows),
      _cols(other._cols),
      matrix_(new double[_rows * _cols]) {
  std::copy(other.matrix_, other.matrix_ + _rows * _cols, matrix_);
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : _rows(other._rows), _cols(other._cols), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other._rows = 0;
  other._cols = 0;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  S21Matrix copy{other};
  *this = std::move(copy);
  return *this;
}

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

S21Matrix::~S21Matrix() noexcept {
  delete[] matrix_;
  _rows = 0;
  _cols = 0;
  matrix_ = nullptr;
}

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

void S21Matrix::MulNumber(const double number) noexcept {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      (*this)(i, j) *= number;
    }
  }
}

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

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result{_cols, _rows};
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      result(j, i) = (*this)(i, j);
    }
  }
  return result;
}

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

double S21Matrix::Determinant() const {
  if (_rows != _cols) {
    throw std::invalid_argument("Incorrect matrix size");
  }

  double result = 1.0;
  S21Matrix tmp{*this};
  int size = _rows;
  for (int i = 0; i < size; ++i) {
    int rotate_value = i;
    for (int j = i + 1; j < size; ++j) {
      if (std::abs(tmp(j, i)) > std::abs(tmp(rotate_value, i))) {
        rotate_value = j;
      }
    }
    if (std::abs(tmp(rotate_value, i)) < 1e-7) {
      return 0.0;
    }

    if (i != rotate_value) {
      for (int k = 0; k < _cols; k++) {
        std::swap(tmp(i, k), tmp(rotate_value, k));
      }
    }
    result *= tmp(i, i);
    if (i != rotate_value) {
      result = -result;
    }
    for (int j = i + 1; j < size; ++j) {
      double koef = tmp(j, i) / tmp(i, i);
      for (int k = i; k < size; ++k) {
        tmp(j, k) -= tmp(i, k) * koef;
      }
    }
  }

  return result;
}

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

int S21Matrix::get_rows() const noexcept { return _rows; }

int S21Matrix::get_cols() const noexcept { return _cols; }

void S21Matrix::set_rows(int new_rows) {
  if (new_rows < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }

  if (new_rows != _rows) {
    S21Matrix tmp{new_rows, _cols};
    int min = std::min(_rows, new_rows);
    for (int i = 0; i < min; ++i) {
      for (int j = 0; j < _cols; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

void S21Matrix::set_cols(int new_cols) {
  if (new_cols < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }

  if (new_cols != _cols) {
    S21Matrix tmp{_rows, new_cols};
    int min = std::min(_cols, new_cols);
    for (int i = 0; i < _rows; ++i) {
      for (int j = 0; j < min; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

double &S21Matrix::operator()(int row, int col) & {
  if (row >= _rows || col >= _cols || row < 0 || col < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  return matrix_[row * _cols + col];
}

const double &S21Matrix::operator()(int row, int col) const & {
  if (row >= _rows || col >= _cols || row < 0 || col < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  return matrix_[row * _cols + col];
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(double number) const noexcept {
  S21Matrix tmp{*this};
  tmp.MulNumber(number);
  return tmp;
}

S21Matrix operator*(double number, const S21Matrix &matrix) noexcept {
  S21Matrix tmp = matrix * number;
  return tmp;
}

S21Matrix &S21Matrix::operator*=(double number) {
  MulNumber(number);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::get_minor(const int row, const int col) const {
  if (row >= _rows || col >= _cols || row < 0 || col < 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }

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
