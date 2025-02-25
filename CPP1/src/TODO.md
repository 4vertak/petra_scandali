# s21_matrix+

Реализация библиотеки s21_matrix_oop.h

## Реализация функции библиотеки s21_matrix_oop.h

- [x] Программа должна быть разработана на языке C++ стандарта C++17 с использованием компилятора gcc.
- [x] Код программы должен находиться в папке src.
- [x] При написании кода необходимо придерживаться Google Style.
- [x] Реализуй матрицу в виде класса `S21Matrix`.
- [x] Храни только приватные поля `matrix_`, `rows_` и `cols_`.
- [x] Реализуй доступ к приватным полям `rows_` и `cols_` через accessor и mutator. При увеличении размера матрица дополняется нулевыми элементами, при уменьшении лишнее просто отбрасывается.
- [x] Оформи решение как статическую библиотеку (с заголовочным файлом s21_matrix_oop.h).
- [x] Реализуй операции, описанные [ниже](#операции-над-матрицами).
- [x] Перегрузи операторы в соответствии с таблицей в разделе [ниже](#операции-над-матрицами).
- [x] Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest.
- [x] Предусмотри Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_matrix_oop.a).

### Операции над матрицами

- [x] `bool EqMatrix(const S21Matrix& other)` Проверяет матрицы на равенство между собой.
- [x] `void SumMatrix(const S21Matrix& other)` Прибавляет вторую матрицу к текущей различная размерность матриц.
- [x] `void SubMatrix(const S21Matrix& other)` Вычитает из текущей матрицы другую различная размерность матриц.
- [x] `void MulNumber(const double num)` Умножает текущую матрицу на число.
- [x] `void MulMatrix(const S21Matrix& other)` Умножает текущую матрицу на вторую. число столбцов первой матрицы не равно числу строк второй матрицы.
- [x] `S21Matrix Transpose()` Создает новую транспонированную матрицу из текущей и возвращает ее.
- [x] `S21Matrix CalcComplements()` Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее. Матрица не является квадратной.
- [x] `double Determinant()` Вычисляет и возвращает определитель текущей матрицы. Матрица не является квадратной.
- [x] `S21Matrix InverseMatrix()` Вычисляет и возвращает обратную матрицу. Определитель матрицы равен 0.

### Реализация конструкторов и деструктора

- [x] `S21Matrix()` Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью.  
- [x] `S21Matrix(int rows, int cols)` Параметризированный конструктор с количеством строк и столбцов.
- [x] `S21Matrix(const S21Matrix& other)` Конструктор копирования.
- [x] `S21Matrix(S21Matrix&& other)` Конструктор переноса.
- [x] `~S21Matrix()` Деструктор.

### Перегрузка операторов, частично соответствующие операциям выше

- [x] `+` Сложение двух матриц. Различная размерность матриц.
- [x] `-` Вычитание одной матрицы из другой. Различная размерность матриц.
- [x] `*` Умножение матриц и умножение матрицы на число. Число столбцов первой матрицы не равно числу строк второй матрицы.
- [x] `==` Проверка на равенство матриц (`EqMatrix`).
- [x] `=` Присвоение матрице значений другой матрицы.
- [x] `+=` Присвоение сложения (`SumMatrix`). Различная размерность матриц.
- [x] `-=` Присвоение разности (`SubMatrix`). Различная размерность матриц.
- [x] `*=` Присвоение умножения (`MulMatrix`/`MulNumber`).  Число столбцов первой матрицы не равно числу строк второй матрицы.
- [x] `(int i, int j)` Индексация по элементам матрицы (строка, колонка). Индекс за пределами матрицы.
