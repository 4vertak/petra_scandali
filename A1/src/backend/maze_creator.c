#include "./maze.h"

/*----------Создание объекта Maze_t------------------*/

/*-----------Дефолтный конструктор для иницализации пустой
 * матрицы----------------*/

Maze_t *create_empty_maze() {
  Maze_t *maze = malloc(sizeof(Maze_t));
  maze->rows = 0;
  maze->cols = 0;
  maze->counter = 1;
  maze->sideLine = NULL;
  maze->v_walls = NULL;
  maze->h_walls = NULL;

  return maze;
}

Maze_t *create_maze(int rows, int cols) {
  if (rows < 0 || cols < 0 || rows > 50 || cols > 50) {
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
    free_maze(maze);
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

int resize_maze(Maze_t *maze, int new_rows, int new_cols) {
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

bool load_maze(const char *filename, Maze_t *maze) {
  bool isLoad = false;
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    int new_row;
    int new_col;
    fscanf(file, "%d %d", &new_row, &new_col);
    if (new_row != maze->rows || new_col != maze->cols) {
      resize_maze(maze, new_row, new_col);
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

/*-----------Выделение и освобождеие памяти---------------*/

void free_walls(int **walls, int rows) {
  if (walls) {
    for (int i = 0; i < rows; i++) {
      free(walls[i]);
    }
    free(walls);
  }
}

void free_maze(Maze_t *maze) {
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