#include <limits.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50
#define kEmpty 0
// #define PRINT_DEBAG

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  int **map;  // Основная карта
  int rows;   // Количество строк
  int cols;   // Количество колонок
} Pathway_t;

typedef struct {
  int rows;
  int cols;
  int **v_walls;
  int **h_walls;
  int *sideLine;
  int counter;
} Maze_t;

/*-----------------------Навигатор---------------------------*/

// Функция выделения памяти для карты
void allocateMap(Pathway_t *way) {
  way->map = (int **)malloc(way->rows * sizeof(int *));
  for (int i = 0; i < way->rows; i++) {
    way->map[i] = (int *)malloc(way->cols * sizeof(int));
    for (int j = 0; j < way->cols; j++) {
      way->map[i][j] = -1;
    }
  }
}

// Функция инициализации структуры Pathway_t
void initializePathway_t(Pathway_t *way, Maze_t *maze) {
  way->rows = maze->rows;
  way->cols = maze->cols;
  allocateMap(way);  // Выделяем память для карты
}

// Функция освобождения памяти карты
void destroyMap(Pathway_t *way) {
  if (way->map) {
    for (int i = 0; i < way->rows; i++) {
      free(way->map[i]);
    }
    free(way->map);
    way->map = NULL;
  }
}

// Функция для изменения ячейки
int changeTheCell(int value, int cell) {
  if (cell == -1) {
    cell = value;  // Если ячейка еще не инициализирована, присваиваем значение
  } else {
    cell = (cell < value)
               ? cell
               : value;  // Сравниваем и присваиваем минимальное значение
  }
  return cell;
}

// Функция для нахождения возможных шагов
int takePossibleSteps(Pathway_t *way, int step, Maze_t *maze) {
  int result = 0;
  for (int i = 0; i < way->rows; i++) {
    for (int j = 0; j < way->cols; j++) {
      if (way->map[i][j] == step) {
        result++;
        // Проверка на перемещение вниз
        if (i < way->rows - 1 && !maze->h_walls[i][j]) {
          way->map[i + 1][j] = changeTheCell(step + 1, way->map[i + 1][j]);
        }
        // Проверка на перемещение вверх
        if (i > 0 && !maze->h_walls[i - 1][j]) {
          way->map[i - 1][j] = changeTheCell(step + 1, way->map[i - 1][j]);
        }
        // Проверка на перемещение вправо
        if (j < way->cols - 1 && !maze->v_walls[i][j]) {
          way->map[i][j + 1] = changeTheCell(step + 1, way->map[i][j + 1]);
        }
        // Проверка на перемещение влево
        if (j > 0 && !maze->v_walls[i][j - 1]) {
          way->map[i][j - 1] = changeTheCell(step + 1, way->map[i][j - 1]);
        }
      }
    }
  }
  return result;
}

// Функция для нахождения пути
void findWay(Pathway_t *way, Position begin, Position end, Position **path,
             int *pathLength, Maze_t *maze) {
  *pathLength = 0;  // Инициализация длины пути
  int y = end.y;
  int x = end.x;

  // Проверьте, что начальная и конечная позиции находятся в пределах массива
  if (begin.y < 0 || begin.y >= way->rows || begin.x < 0 ||
      begin.x >= way->cols || end.y < 0 || end.y >= way->rows || end.x < 0 ||
      end.x >= way->cols) {
    printf("Ошибка: Начальная или конечная позиция вне границ карты.\n");
    return;
  }

  int count = 1;
  int step = 0;

  way->map[begin.y][begin.x] = 0;  // Установка начальной позиции

  // Процесс нахождения шагов, пока есть шаги и местоположение не достигнуто
  while (count > 0 && way->map[y][x] == -1) {
    count = takePossibleSteps(way, step++, maze);
  }

  if (way->map[y][x] != -1) {
    step = way->map[y][x];
    *path = (Position *)malloc(sizeof(Position) * (step + 1));

    // Начальная позиция
    (*path)[(*pathLength)].x = x;
    (*path)[(*pathLength)++].y = y;

    // Обратный переход к начальной позиции
    while (y != begin.y || x != begin.x) {
      if (y < way->rows - 1 && !maze->h_walls[y][x] &&
          way->map[y + 1][x] == step - 1)
        y++;
      else if (y > 0 && !maze->h_walls[y - 1][x] &&
               way->map[y - 1][x] == step - 1)
        y--;
      else if (x < way->cols - 1 && !maze->v_walls[y][x] &&
               way->map[y][x + 1] == step - 1)
        x++;
      else if (x > 0 && !maze->v_walls[y][x - 1] &&
               way->map[y][x - 1] == step - 1)
        x--;

      (*path)[(*pathLength)].x =
          x;  // Используем скобки для доступа к элементу массива
      (*path)[(*pathLength)++].y =
          y;  // Используем скобки для доступа к элементу массива
      step--;
    }
  }
}

/*-----------Выделение и освобождеие памяти---------------*/

void free_walls(int **walls, int rows) {
  if (walls) {
    for (int i = 0; i < rows; i++) {
      free(walls[i]);
    }
    free(walls);
  }
}

void free_maze_t(Maze_t *maze) {
  if (maze) {
    free(maze->sideLine);
    free_walls(maze->v_walls, maze->rows);
    free_walls(maze->h_walls, maze->rows);
    free(maze);
  }
}

int **allocate_2d_array(int rows, int cols) {
  int **array = malloc(rows * sizeof(int *));
  if (array) {
    for (int i = 0; i < rows; i++) {
      array[i] = malloc(cols * sizeof(int));
      if (!array[i]) {
        free_walls(array, i);
        return NULL;
      }
    }
  }
  return array;
}

/*----------Создание объекта Maze_t------------------*/

Maze_t *create_maze_t(int rows, int cols) {
  if (rows <= 0 || cols <= 0 || rows > 50 || cols > 50) {
    printf("Размер матрицы должен быть в диапазоне 1-50\n");
    return NULL;
  }

  Maze_t *maze = malloc(sizeof(Maze_t));
  if (!maze) {
    printf("Не удалось выделить память\n");
    return NULL;
  }

  maze->rows = rows;
  maze->cols = cols;
  maze->counter = 1;

  maze->sideLine = malloc(cols * sizeof(int));
  maze->v_walls = allocate_2d_array(rows, cols);
  maze->h_walls = allocate_2d_array(rows, cols);

  if (!maze->sideLine || !maze->v_walls || !maze->h_walls) {
    printf("Не удалось выделить память\n");
    free_maze_t(maze);
    return NULL;
  }

  // Инициализация стен
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      maze->v_walls[i][j] = 0;
      maze->h_walls[i][j] = 0;
    }
  }

  return maze;
}

int resize_maze_t(Maze_t *maze, int new_rows, int new_cols) {
  if (!maze || new_rows <= 0 || new_cols <= 0 || new_rows > 50 ||
      new_cols > 50) {
    printf("Размер матрицы должен быть в диапазоне 1-50\n");
    return -1;
  }

  int *new_sideLine = malloc(new_cols * sizeof(int));
  int **new_v_walls = allocate_2d_array(new_rows, new_cols);
  int **new_h_walls = allocate_2d_array(new_rows, new_cols);

  if (!new_sideLine || !new_v_walls || !new_h_walls) {
    printf("Не удалось выделить память\n");
    free(new_sideLine);
    free_walls(new_v_walls, new_rows);
    free_walls(new_h_walls, new_rows);
    return -1;
  }

  // Освобождение старых стен
  free(maze->sideLine);
  free_walls(maze->v_walls, maze->rows);
  free_walls(maze->h_walls, maze->rows);

  // Обновление указателей и размеров
  maze->sideLine = new_sideLine;
  maze->v_walls = new_v_walls;
  maze->h_walls = new_h_walls;
  maze->rows = new_rows;
  maze->cols = new_cols;
  maze->counter = 1;

  return 0;
}

/*---------Загрузка файла лабиринт------------*/

bool load_maze_t(const char *filename, Maze_t *maze) {
  bool isLoad = false;
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    int new_row;
    int new_col;
    fscanf(file, "%d %d", &new_row, &new_col);
    if (new_row != maze->rows || new_col != maze->cols) {
      resize_maze_t(maze, new_row, new_col);
    }
    for (int i = 0; i < maze->rows; ++i) {
      for (int j = 0; j < maze->cols; ++j) {
        fscanf(file, "%d", &maze->v_walls[i][j]);
      }
    }
    for (int i = 0; i < maze->rows; ++i) {
      for (int j = 0; j < maze->cols; ++j) {
        fscanf(file, "%d", &maze->h_walls[i][j]);
      }
    }
    fclose(file);
    isLoad = true;
  } else {
    printf("File not found\n");
  }
  return isLoad;
}

/*--------Генерации лабиринта-----------*/

/* Заполним вектор пустым значением */
void fillEmptyValue(Maze_t *maze) {
  for (int i = 0; i < maze->cols; i++) {
    maze->sideLine[i] = kEmpty;
  }
}

void assignUniqueSet(Maze_t *maze) {
  for (int i = 0; i < maze->cols; i++) {
    if (maze->sideLine[i] == kEmpty) {
      maze->sideLine[i] = maze->counter;
      maze->counter++;
    }
  }
}

bool randomBool() { return rand() % 2 == 0; }

/* Объединение ячеек в одно множество */

void mergeSet(Maze_t *maze, int index, int element) {
  int mutableSet = maze->sideLine[index + 1];
  for (int j = 0; j < maze->cols; j++) {
    /* Проверка ячеек на одно множество */
    if (maze->sideLine[j] == mutableSet) {
      /* Объединение ячейки в множество */
      maze->sideLine[j] = element;
    }
  }
}

/* Добавление правой вертикальной стенки */
void addingVerticalWalls(Maze_t *maze, int row) {
  for (int i = 0; i < maze->cols - 1; i++) {
    /* Ставим стенку или нет */
    bool choice = randomBool();

    /* Проверка условия для предотовращения зацикливания */
    if (choice == true || maze->sideLine[i] == maze->sideLine[i + 1]) {
      maze->v_walls[row][i] = true;
    } else {
      /* Объединение ячеек в одно множество */
      mergeSet(maze, i, maze->sideLine[i]);
    }
  }
  /* Добавление правой стенки в последней ячейки */
  maze->v_walls[row][maze->cols - 1] = true;  // Добавляем правую стену
}

/* Подсчет ячеек, которые содержаться в уникальном множестве */
int calculateUniqueSet(Maze_t *maze, int element) {
  int countUniqueSet = 0;
  for (int i = 0; i < maze->cols; i++) {
    if (maze->sideLine[i] == element) {
      countUniqueSet++;
    }
  }
  return countUniqueSet;
}

/* Добавление нижней горизонтальной стенки */
void addingHorizontalWalls(Maze_t *maze, int row) {
  for (int i = 0; i < maze->cols; i++) {
    /* Ставим стенку или нет */
    bool choice = randomBool();
    /* Проверка, что множество имеет более одной ячейки (это предовратит
     * замкнутые области  */
    if (calculateUniqueSet(maze, maze->sideLine[i]) > 1 && choice == true) {
      /* Ставим горизонтальную стенку */
      maze->h_walls[row][i] = true;
    }
  }
}

/* Подсчет горизонтальных стен у ячеек уникального множества */

int calculateHorizontalWalls(Maze_t *maze, int element, int row) {
  int countHorizontalWalls = 0;
  for (int i = 0; i < maze->cols; i++) {
    if (maze->sideLine[i] == element && maze->h_walls[row][i] == false) {
      countHorizontalWalls++;
    }
  }
  return countHorizontalWalls;
}
/* Проверка условие 4.1 и 4.2 */
void checkedHorizontalWalls(Maze_t *maze, int row) {
  for (int i = 0; i < maze->cols; i++) {
    if (calculateHorizontalWalls(maze, maze->sideLine[i], row) == 0) {
      maze->h_walls[row][i] =
          false;  // Убедитесь, что нет стены, если изолировано
    }
  }
}

void preparatingNewLine(Maze_t *maze, int row) {
  for (int i = 0; i < maze->cols; i++) {
    if (maze->h_walls[row][i] == true) {
      /* Присваиваем ячейки пустое множество */
      maze->sideLine[i] = kEmpty;  // Создайте дополнительный проход
    }
  }
}

/* Проверка условий на добавление последней строки */
void checkedEndLine(Maze_t *maze) {
  for (int i = 0; i < maze->cols - 1; i++) {
    /* Проверка условия пункта 5.2.1
        1. Если текущая ячейка и ячейка справа члены разных множеств, то:
        1.1 Удалите правую границу
        1.2 Объедините множества текущей ячейки и ячейки справа
        1.3 Выведите завершающую строку*/

    if (maze->sideLine[i] != maze->sideLine[i + 1]) {
      /* Убираем вертикальную стенку */
      maze->v_walls[maze->rows - 1][i] = false;
      /* Объединяем множества */
      mergeSet(maze, i, maze->sideLine[i]);
    }
    /* Добавляем горизонтальные стенки */
    maze->h_walls[maze->rows - 1][i] = true;
  }
  /* Добавляем горизонтальную стенку в последней ячейке */
  maze->h_walls[maze->rows - 1][maze->cols - 1] = true;
}

/* Добавление последней строки */
void addingEndLine(Maze_t *maze) {
  assignUniqueSet(maze);
  addingVerticalWalls(maze, maze->rows - 1);
  checkedEndLine(maze);
}

/* Метод генерации лабиринта */
void generateMaze_t(Maze_t *maze) {
  /* Шаг 1 */
  fillEmptyValue(maze);

#ifdef PRINT_DEBAG
  printf("Step 1: fillEmptyValue\n");
  for (int i = 0; i < maze->cols; i++) {
    printf("%d ", maze->sideLine[i]);
  }

  printf("\n");
#endif

  for (int j = 0; j < maze->rows - 1; j++) {
    /* Шаг 2 */
    assignUniqueSet(maze);

#ifdef PRINT_DEBAG
    printf("Step 2: assignUniqueSet\n");
    for (int i = 0; i < maze->cols; i++) {
      printf("%d ", maze->sideLine[i]);
    }
    printf("\n");
#endif

    /* Шаг 3 */
    addingVerticalWalls(maze, j);

#ifdef PRINT_DEBAG
    printf("Step 3: addingVerticalWalls\n");
    for (int i = 0; i < maze->cols; i++) {
      printf("%d ", maze->v_walls[j][i]);
    }
    printf("\n");
#endif

    /* Шаг 4 */
    addingHorizontalWalls(maze, j);

#ifdef PRINT_DEBAG
    printf("Step 4.1: addingHorizontalWalls\n");
    for (int i = 0; i < maze->cols; i++) {
      printf("%d ", maze->h_walls[j][i]);
    }
    printf("\n");
#endif

    checkedHorizontalWalls(maze, j);

#ifdef PRINT_DEBAG
    printf("Step 4.2: checkedHorizontalWalls\n");
    for (int i = 0; i < maze->cols; i++) {
      printf("%d ", maze->h_walls[j][i]);
    }
    printf("\n");
#endif
    /* Шаг 5.1*/
    preparatingNewLine(maze, j);

#ifdef PRINT_DEBAG
    printf("Step 5: preparatingNewLine\n");
    for (int i = 0; i < maze->cols; i++) {
      printf("%d ", maze->sideLine[i]);
    }
    printf("\n");
#endif
  }

  /* Шаг 5.2 */
  addingEndLine(maze);
}

/*---------------Принт Дебаг---------------------*/

void print_test(Maze_t *maze) {
  printf("\n");
  printf("----Print Maze_t %d x %d----\n", maze->rows, maze->cols);
  printf("\n");

  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      printf("%d ", maze->v_walls[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      printf("%d ", maze->h_walls[i][j]);
    }
    printf("\n");
  }
}

void print_maze_t(const Maze_t *maze) {
  int cell_height = 1;
  int cell_width = 2;
  int start_y = 0;
  int start_x = 0;
  int max_height = LINES - 1;  // Резервируем одну строку для управления
  int max_width = COLS - 1;
  int x, y;

  // отрисовка границ "поля"
  mvhline(start_y, start_x, '_', max_width);
  mvvline(start_y + 1, start_x, '|', max_height);

  // отрисовка лабиринта - стенки справа и снизу
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      y = start_y + i * cell_height;
      x = start_x + j * cell_width;

      if (maze->h_walls[i][j]) {
        mvhline(y + cell_height, x + 1, '_', cell_width);
      }

      if (maze->v_walls[i][j]) {
        for (int k = 1; k <= cell_height; ++k) {
          mvprintw(y + k, x + cell_width, "|");
        }
      }
    }
  }
}

void print_maze_t_path(const Maze_t *maze, const Position *path,
                       int pathLength) {
  int cell_height = 1;
  int cell_width = 2;
  int start_y = 0;
  int start_x = 0;
  int max_height = LINES - 1;
  int max_width = COLS - 1;
  int x, y;

  mvhline(start_y, start_x, '_', max_width);
  mvvline(start_y + 1, start_x, '|', max_height);

  // Отрисовка стены и лабиринта
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      y = start_y + i * cell_height;
      x = start_x + j * cell_width;

      if (maze->h_walls[i][j]) {
        mvhline(y + cell_height, x + 1, '_', cell_width);
      }

      if (maze->v_walls[i][j]) {
        for (int k = 1; k <= cell_height; ++k) {
          mvprintw(y + k, x + cell_width, "|");
        }
      }
    }
  }

  // Отрисовка пути
  for (int i = 0; i < pathLength; ++i) {
    y = start_y + path[i].y * cell_height;
    x = start_x + path[i].x * cell_width;
    mvprintw(y + 1, x + 1, "o");
  }

  refresh();
}

int main() {
#ifndef PRINT_DEBAG
  initscr();  // Начать режим ncurses
  cbreak();   // Отключить буферизацию ввода
#endif
  Maze_t *maze = create_maze_t(20, 20);

  srand(time(NULL));

  generateMaze_t(maze);

  Pathway_t way;
  initializePathway_t(&way, maze);

  Position start = {0, 0};
  Position end = {19, 11};

  Position *path = NULL;
  int pathLength = 0;

  // Нахождение пути
  findWay(&way, start, end, &path, &pathLength, maze);

#ifndef PRINT_DEBAG
  print_maze_t(maze);
  getch();
  clear();
  print_maze_t_path(maze, path, pathLength);
  getch();
  clear();
#endif

#ifdef PRINT_DEBAG
  print_test(maze);

#endif

  resize_maze_t(maze, 10, 10);
  generateMaze_t(maze);

#ifndef PRINT_DEBAG

  print_maze_t(maze);

  getch();
  clear();

#endif

#ifdef PRINT_DEBAG
  print_test(maze);

#endif

  load_maze_t("test.txt", maze);

#ifndef PRINT_DEBAG

  print_maze_t(maze);

  getch();
  clear();
  endwin();
#endif

#ifdef PRINT_DEBAG
  print_test(maze);

#endif
  free(path);
  destroyMap(&way);
  free_maze_t(maze);

  return 0;
}
