#include "./backend.h"

State_t *currentState(void) {
  static State_t state = START;
  return &state;
}
/*--------------логика ИГА -----------------------*/

UserAction_t getSignal(int user_input) {
  UserAction_t action = NOSIG;
  if (user_input == 'g') {
    action = Generate;
  } else if (user_input == 's') {
    action = Load;
  } else if (user_input == 'p') {
    action = Pathfinding;
  } else if (user_input == ESCAPE) {
    action = Terminate;
  }

  return action;
}

void userInput(UserAction_t action, State_t *state) {
  switch (action) {
    case Generate:
      if (*state == START || *state == WAITING ||
          *state == LOAD_MAZE_FROM_FILE || *state == FIND_PATHAWAY) {
        *state = GENERATE_MAZE;
      }
      break;
    case Load:
      if (*state == START || *state == WAITING ||
          *state == LOAD_MAZE_FROM_FILE || *state == FIND_PATHAWAY ||
          *state == GENERATE_MAZE) {
        *state = LOAD_MAZE_FROM_FILE;
      }
      break;
    case Pathfinding:
      if (*state == WAITING || *state == LOAD_MAZE_FROM_FILE ||
          *state == GENERATE_MAZE) {
        *state = FIND_PATHAWAY;
      }
      break;
    case Terminate:
      if (*state == START) {
        *state = EXIT;
      } else if (*state == WAITING || *state == LOAD_MAZE_FROM_FILE ||
                 *state == FIND_PATHAWAY || *state == GENERATE_MAZE) {
        *state = START;
      }
      break;
    default:
      break;
  }
}

// void onGenerateMaze(Cli_t *size, Position *start, Position *end) {
//   print_generate_maze(size, start, end);
// }

// void onLoadingMaze(Cli_t *size, Position *start, Position *end) {
//   print_load_maze(size, start, end);
// }

// void onFindPathway(Cli_t *size, Position *start, Position *end,
//                    int pathLength) {
//   print_pathway(size, start, end, &pathLength);
// }

void updateCurrentState(State_t *state) {
  switch (*state) {
    case GENERATE_MAZE:
      // onGenerateMaze(size, start, end);
      *state = WAITING;
      break;
    case LOAD_MAZE_FROM_FILE:
      // onLoadingMaze(size, start, end);
      *state = WAITING;
      break;
    case FIND_PATHAWAY:
      // onFindPathway(size, start, end, pathLength);
      *state = WAITING;
      break;
    default:
      break;
  }
}

/*----------Создание объекта Maze_t------------------*/

/*-----------Дефолтный конструктор для иницализации пустой
 * матрицы----------------*/

// typedef struct {
//   int rows;
//   int cols;
//   int **v_walls;
//   int **h_walls;
//   int *sideLine;
//   int counter;
// } Maze_t;

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
    if (maze->sideLine) free(maze->sideLine);
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

Maze_t *currentMaze(void) {
  static Maze_t maze = {0, 0, NULL, NULL, NULL, 0};
  return &maze;
}

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

// продумать выозвращаемые занчения typdefenum isValid?

int resize_maze_t(Maze_t *maze, int new_rows, int new_cols) {
  int return_value = 0;
  if (!maze || new_rows <= 0 || new_cols <= 0 || new_rows > 50 ||
      new_cols > 50) {
    printf("Размер матрицы должен быть в диапазоне 1-50\n");
  } else {
    int *new_sideLine = malloc(new_cols * sizeof(int));
    int **new_v_walls = allocate_2d_array(new_rows, new_cols);
    int **new_h_walls = allocate_2d_array(new_rows, new_cols);

    if (!new_sideLine || !new_v_walls || !new_h_walls) {
      // printf("Не удалось выделить память\n");
      free(new_sideLine);
      free_walls(new_v_walls, new_rows);
      free_walls(new_h_walls, new_rows);
    } else {
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

      // Инициализация стен
      for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
          maze->v_walls[i][j] = 0;
          maze->h_walls[i][j] = 0;
        }
      }
      return_value = 1;
    }
  }
  return return_value;
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
  }
  return isLoad;
}

/*------------текущее состояния размера
 * лабирнта----------------------------------*/

bool *currentStateSize(void) {
  static bool state = false;
  return &state;
}

/*------------текущее состояния загрузки
 * лабирнта----------------------------------*/

bool *currentStateLoad(void) {
  static bool state = false;
  return &state;
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

/*-----------------------Навигатор---------------------------*/

Pathway_t *currentWay(void) {
  static Pathway_t way = {NULL, 0, 0};
  return &way;
}

Position *currentPath(void) {
  static Position path = {0, 0};
  return &path;
}

/*---------ADD 27.11.24----------------*/

/*-----------------Валидация позиции старта и финиша------------------*/

bool isValidPosition(Position *path) {
  Maze_t *maze = currentMaze();
  bool ret = true;
  if (path->x < 0 || path->x >= maze->rows || path->y < 0 ||
      path->y >= maze->cols) {
    ret = false;
  }
  return ret;
}

point_valid areStartEndValid(Position *start, Position *end) {
  point_valid ret = VALID;
  if (!isValidPosition(start)) {
    // printf("Start point is invalid.\n");
    ret = INVALID_START;
  } else if (!isValidPosition(end)) {
    // printf("End point is invalid.\n");
    ret = INVALID_END;
  }

  return ret;
}

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

  //   // Проверьте, что начальная и конечная позиции находятся в пределах
  //   массива if (begin.y < 0 || begin.y >= way->rows || begin.x < 0 ||
  //       begin.x >= way->cols || end.y < 0 || end.y >= way->rows || end.x < 0
  //       || end.x >= way->cols) {
  //     printf("Ошибка: Начальная или конечная позиция вне границ карты.\n");
  //     return;
  //   }

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
  destroyMap(way);
}