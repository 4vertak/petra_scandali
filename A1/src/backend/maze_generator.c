#include "./maze.h"

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