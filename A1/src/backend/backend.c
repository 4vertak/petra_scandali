#include "./backend.h"

/*--------------логика ИГА -----------------------*/
State_t *currentState(void) {
  static State_t state = START;
  return &state;
}

UserAction_t getSignal(int user_input) {
  UserAction_t action = NOSIG;
  if (user_input == 'g') {
    action = Generate;
  } else if (user_input == 'l') {
    action = Load;
  } else if (user_input == 'f') {
    action = Pathfinding;
  } else if (user_input == 's') {
    action = Save;
  } else if (user_input == ESCAPE) {
    action = Terminate;
  }

  return action;
}

void userInput(UserAction_t action, State_t *state) {
  switch (action) {
    case Generate:
      if (*state == START || *state == MAZE_PRINTING ||
          *state == FIND_PATHAWAY) {
        *state = GENERATE_MAZE;
      }
      break;
    case Load:
      if (*state == START || *state == MAZE_PRINTING ||
          *state == FIND_PATHAWAY) {
        *state = LOAD_MAZE_FROM_FILE;
      }
      break;
    case Pathfinding:
      if (*state == MAZE_PRINTING || *state == FIND_PATHAWAY) {
        *state = FIND_PATHAWAY;
      }
      break;
    case Save:
      if (*state == MAZE_PRINTING || *state == FIND_PATHAWAY) {
        *state = SAVE_MAZE_IN_FILE;
      }
      break;
    case Terminate:
      *state = EXIT;

      break;
    default:
      break;
  }
}

void updateCurrentState(State_t *state) {
  bool *stateSize = mazeSizeInputState();
  bool *stateLoad = mazeLoadingState();
  bool *stateSave = mazeSaveState();
  bool *stateFind = pathfindingState();
  switch (*state) {
    case GENERATE_MAZE:
      if (*stateSize) {
        *state = MAZE_PRINTING;
        *stateSize = false;
      }
      break;
    case LOAD_MAZE_FROM_FILE:
      if (*stateLoad) *state = MAZE_PRINTING;
      break;
    case SAVE_MAZE_IN_FILE:
      if (*stateSave) *state = MAZE_PRINTING;
      break;
    case FIND_PATHAWAY:
      if (*stateFind) *state = MAZE_PRINTING;
      break;
    default:
      break;
  }
}

/*-----------Выделение и освобождеие памяти---------------*/

void freeWalls(int **walls, int rows) {
  if (walls) {
    for (int i = 0; i < rows; i++) {
      free(walls[i]);
    }
    free(walls);
  }
}

void freeMaze(Maze_t *maze) {
  if (maze) {
    if (maze->sideLine) free(maze->sideLine);
    freeWalls(maze->v_walls, maze->rows);
    freeWalls(maze->h_walls, maze->rows);
    free(maze);
  }
}

int **allocateArray(int rows, int cols) {
  int **array = malloc(rows * sizeof(int *));
  if (array) {
    for (int i = 0; i < rows; i++) {
      array[i] = malloc(cols * sizeof(int));
      if (!array[i]) {
        freeWalls(array, i);
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

Maze_t *createMaze(int rows, int cols) {
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
  maze->v_walls = allocateArray(rows, cols);
  maze->h_walls = allocateArray(rows, cols);

  if (!maze->sideLine || !maze->v_walls || !maze->h_walls) {
    printf("Не удалось выделить память\n");
    freeMaze(maze);
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

int resizeMaze(Maze_t *maze, int new_rows, int new_cols) {
  int return_value = 0;
  if (!maze || new_rows <= 0 || new_cols <= 0 || new_rows > 50 ||
      new_cols > 50) {
    printf("Размер матрицы должен быть в диапазоне 1-50\n");
  } else {
    int *new_sideLine = malloc(new_cols * sizeof(int));
    int **new_v_walls = allocateArray(new_rows, new_cols);
    int **new_h_walls = allocateArray(new_rows, new_cols);

    if (!new_sideLine || !new_v_walls || !new_h_walls) {
      // printf("Не удалось выделить память\n");
      free(new_sideLine);
      freeWalls(new_v_walls, new_rows);
      freeWalls(new_h_walls, new_rows);
    } else {
      // Освобождение старых стен
      free(maze->sideLine);
      freeWalls(maze->v_walls, maze->rows);
      freeWalls(maze->h_walls, maze->rows);

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

bool loadMaze(const char *filename, Maze_t *maze) {
  bool isLoad = false;
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    int new_row;
    int new_col;
    fscanf(file, "%d %d", &new_row, &new_col);
    if (new_row != maze->rows || new_col != maze->cols) {
      resizeMaze(maze, new_row, new_col);
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

/*---------Сохранение лабиринта в файл------------*/

bool saveMaze(const char *filename, Maze_t *maze) {
  bool isSave = false;
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    // perror("Не удалось открыть файл");
    return isSave;
  }

  fprintf(file, "%d %d\n", maze->rows, maze->cols);

  for (int i = 0; i < maze->rows; i++) {
    for (int j = 0; j < maze->cols; j++) {
      fprintf(file, "%d ", maze->v_walls[i][j]);
    }
    fprintf(file, "\n");
  }
  fprintf(file, "\n");
  for (int i = 0; i < maze->rows; i++) {
    for (int j = 0; j < maze->cols; j++) {
      fprintf(file, "%d ", maze->h_walls[i][j]);
    }
    fprintf(file, "\n");
  }

  fclose(file);
  isSave = true;
  return isSave;
}

/*------------текущее состояния размера
 * лабирнта----------------------------------*/

bool *mazeSizeInputState(void) {
  static bool state = false;
  return &state;
}

/*------------текущее состояния загрузки
 * лабирнта----------------------------------*/

bool *mazeLoadingState(void) {
  static bool state = false;
  return &state;
}

bool *mazeSaveState(void) {
  static bool state = false;
  return &state;
}

bool *pathfindingState(void) {
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
  fillEmptyValue(maze);
  for (int j = 0; j < maze->rows - 1; j++) {
    assignUniqueSet(maze);
    addingVerticalWalls(maze, j);
    addingHorizontalWalls(maze, j);
    checkedHorizontalWalls(maze, j);
    preparatingNewLine(maze, j);
  }
  addingEndLine(maze);
}

/*-----------------------Навигатор---------------------------*/

Pathway_t *ways(void) {
  static Pathway_t way = {NULL, 0, 0};
  return &way;
}

Position *wayOut(void) {
  static Position path = {0, 0};
  return &path;
}

/*---------ADD 27.11.24----------------*/

/*-----------------Валидация позиции старта и финиша------------------*/

bool checkPosition(Position *path) {
  Maze_t *maze = currentMaze();
  bool return_value = true;
  if (path->x < 0 || path->y >= maze->rows || path->y < 0 ||
      path->x >= maze->cols) {
    return_value = false;
  }
  return return_value;
}

// Функция выделения памяти для карты
void allocationOfPathMapMemory(Pathway_t *ways) {
  ways->map = (int **)malloc(ways->rows * sizeof(int *));
  for (int i = 0; i < ways->rows; i++) {
    ways->map[i] = (int *)malloc(ways->cols * sizeof(int));
    for (int j = 0; j < ways->cols; j++) {
      ways->map[i][j] = -1;
    }
  }
}

// Функция инициализации структуры Pathway_t
void initializePathway_t(Pathway_t *ways, Maze_t *maze) {
  ways->rows = maze->rows;
  ways->cols = maze->cols;
  allocationOfPathMapMemory(ways);  // Выделяем память для карты
}

// Функция освобождения памяти карты
void freeingPathMapMemory(Pathway_t *ways) {
  if (ways->map) {
    for (int i = 0; i < ways->rows; i++) {
      free(ways->map[i]);
    }
    free(ways->map);
    ways->map = NULL;
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
int takePossibleSteps(Pathway_t *ways, int step, Maze_t *maze) {
  int result = 0;
  for (int i = 0; i < ways->rows; i++) {
    for (int j = 0; j < ways->cols; j++) {
      if (ways->map[i][j] == step) {
        result++;
        // Проверка на перемещение вниз
        if (i < ways->rows - 1 && !maze->h_walls[i][j]) {
          ways->map[i + 1][j] = changeTheCell(step + 1, ways->map[i + 1][j]);
        }
        // Проверка на перемещение вверх
        if (i > 0 && !maze->h_walls[i - 1][j]) {
          ways->map[i - 1][j] = changeTheCell(step + 1, ways->map[i - 1][j]);
        }
        // Проверка на перемещение вправо
        if (j < ways->cols - 1 && !maze->v_walls[i][j]) {
          ways->map[i][j + 1] = changeTheCell(step + 1, ways->map[i][j + 1]);
        }
        // Проверка на перемещение влево
        if (j > 0 && !maze->v_walls[i][j - 1]) {
          ways->map[i][j - 1] = changeTheCell(step + 1, ways->map[i][j - 1]);
        }
      }
    }
  }
  return result;
}

// Функция для нахождения пути
void findWay(Pathway_t *ways, Position begin, Position end, Position **path,
             int *pathLength, Maze_t *maze) {
  *pathLength = 0;  // Инициализация длины пути
  int y = end.y;
  int x = end.x;
  int count = 1;
  int step = 0;
  //   printf("end.y %d  end.x %d\n", end.y, end.x);

  ways->map[begin.y][begin.x] = 0;  // Установка начальной позиции

  // Процесс нахождения шагов, пока есть шаги и местоположение не достигнуто
  while (count > 0 && ways->map[y][x] == -1) {
    count = takePossibleSteps(ways, step++, maze);
    // printf("Путь длиной %d\n", step);
  }

  if (ways->map[y][x] != -1) {
    step = ways->map[y][x];
    *path = (Position *)malloc(sizeof(Position) * (step + 1));

    // Начальная позиция
    (*path)[(*pathLength)].x = x;
    (*path)[(*pathLength)++].y = y;
    // Обратный переход к начальной позиции
    while (y != begin.y || x != begin.x) {
      if (y < ways->rows - 1 && !maze->h_walls[y][x] &&
          ways->map[y + 1][x] == step - 1)
        y++;
      else if (y > 0 && !maze->h_walls[y - 1][x] &&
               ways->map[y - 1][x] == step - 1)
        y--;
      else if (x < ways->cols - 1 && !maze->v_walls[y][x] &&
               ways->map[y][x + 1] == step - 1)
        x++;
      else if (x > 0 && !maze->v_walls[y][x - 1] &&
               ways->map[y][x - 1] == step - 1)
        x--;

      (*path)[(*pathLength)].x =
          x;  // Используем скобки для доступа к элементу массива
      (*path)[(*pathLength)++].y =
          y;  // Используем скобки для доступа к элементу массива
      step--;
    }
  }
  //   freeingPathMapMemory(ways);
}