#include "./maze.h"

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