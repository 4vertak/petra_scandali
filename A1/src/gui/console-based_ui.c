
#include "./console_based_ui.h"

void console_based_gui() {
  setlocale(LC_ALL, "");
  WIN_INIT(10);
  srand(time(NULL));
  gameLoop();
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