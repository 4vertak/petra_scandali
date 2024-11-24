#include "./console_based_ui.h"

void printGame(State_t *state, Position *path, int pathLength) {
  int height_cli, width_cli;
  getmaxyx(stdscr, height_cli, width_cli);

  start_color();
  INIT_COLOR_PAIR;

  if (*state == START) {
    printStartBanner(height_cli, width_cli);
  }
  if (*state == GENERATE_MAZE || *state == FREE_STATE) {
    printGenerateMazeBanner(height_cli, width_cli);
    // print_maze_t();
  }
  if (*state == LOAD_MAZE_FROM_FILE) {
    printLoadMaze(height_cli, width_cli);
  } else if (*state == FIND_PATHAWAY) {
    // printPathBanner(height_cli, width_cli, path, pathLength);
    print_maze_t_path(path, pathLength);
  }
}

// void get_filename(int start_y, int start_x, char *filename) {
//   mvprintw(start_y + 5, start_x, "Enter the filename: ");
//   refresh();
//   echo();
//   mvgetstr(start_y + 6, start_x, filename);
//   noecho();
//   clear();
// }

// void get_start_end_points(int start_y, int start_x, Point *start, Point *end,
//                           int menu_x) {
//   char input[100];
//   mvprintw(start_y + 5, start_x, "%s", "Input start point:");
//   refresh();
//   echo();
//   mvgetstr(start_y + 6, start_x, input);
//   sscanf(input, "%3d %3d", &start->x, &start->y);
//   input[0] = '\0';
//   mvprintw(start_y + 7, start_x, "%s", "Input end point:");
//   mvgetstr(start_y + 8, start_x, input);
//   sscanf(input, "%3d %3d", &end->x, &end->y);
//   clear();
//   print_menu(0, menu_x, start, end);
//   noecho();
// }

// bool get_dimension(int start_y, int start_x, int *rows, int *cols) {
//   bool isGot = 1;
//   echo();
//   mvprintw(start_y + 5, start_x, "Enter maze rows (1-50): ");
//   refresh();
//   scanw("%d", rows);
//   mvprintw(start_y + 6, start_x, "Enter maze cols (1-50): ");
//   refresh();
//   scanw("%d", cols);
//   noecho();

//   if (*rows < 1 || *rows > 50 || *cols < 1 || *cols > 50) {
//     *rows = 0;
//     *cols = 0;
//     isGot = 0;
//   }
//   return isGot;
// }

void printStartBanner(int height_cli, int width_cli) {
  int win_height = height_cli / 2;
  int win_width = width_cli / 2;
  int start_y = 0;
  int start_x = 0;

  WINDOW *start = newwin(win_height, win_width, start_y, start_x);
  werase(start);

  int array[4][25] = {
      {0, 0, 7, 0, 0, 0, 7, 0, 0, 3, 0, 0, 6, 6, 0, 0, 0, 2, 0, 0, 0},
      {0, 0, 7, 7, 0, 7, 7, 0, 3, 0, 3, 0, 0, 6, 0, 0, 0, 2, 2, 0, 0},
      {0, 0, 7, 0, 7, 0, 7, 0, 3, 3, 3, 0, 0, 6, 6, 0, 0, 2, 0, 0, 0},
      {0, 0, 7, 0, 0, 0, 7, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 25; j++) {
      int n = array[i][j];
      if (array[i][j] != 0) {
        wattron(start, COLOR_PAIR(n));
        mvwaddch(start, i + 1, j * 2 + 1, ' ');
        mvwaddch(start, i + 1, j * 2 + 2, ' ');
        wattroff(start, COLOR_PAIR(n));
      } else {
        wattron(start, COLOR_PAIR(8));
        mvwaddch(start, i + 1, j * 2 + 1, ' ');
        mvwaddch(start, i + 1, j * 2 + 2, ' ');
        wattroff(start, COLOR_PAIR(8));
      }
    }
  }
  wattron(start, COLOR_PAIR(10));
  mvwprintw(start, 8, 15, "Press [ENTER] to generate");
  wattroff(start, COLOR_PAIR(10));

  mvwprintw(start, 10, 11, "Press [s] to load from file");
  mvwprintw(start, 12, 16, "Press [SPACE] to view pathway");

  wattron(start, COLOR_PAIR(10));
  mvwprintw(start, 14, 16, "Press [ESC] to exit");
  wattroff(start, COLOR_PAIR(10));
  wrefresh(start);
  delwin(start);
}

void printGenerateMazeBanner(int height_cli, int width_cli) {
  Maze_t *maze = currentMaze();

  int cell_height = height_cli / (maze->rows);
  int cell_width = width_cli / (maze->cols * 2);
  int start_y = 0;
  int start_x = 0;
  int win_height = cell_height * maze->rows + 1;
  int win_width = cell_width * maze->cols + 1;
  int x, y;

  WINDOW *generate = newwin(win_height, win_width, start_y, start_x);
  werase(generate);
  // box(generate, 0, 0);

  // отрисовка границ "поля"
  wattron(generate, COLOR_PAIR(10));
  mvwhline(generate, start_y, start_x, '_', win_width);
  mvwvline(generate, start_y, start_x, '|', win_height);
  wattroff(generate, COLOR_PAIR(10));

  // отрисовка лабиринта - стенки справа и снизу
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      y = start_y + i * cell_height;
      x = start_x + j * cell_width;

      if (maze->h_walls[i][j]) {
        wattron(generate, COLOR_PAIR(10));
        mvwhline(generate, y + cell_height, x + 1, '_', cell_width);
        wattroff(generate, COLOR_PAIR(10));
      }

      if (maze->v_walls[i][j]) {
        for (int k = 1; k <= cell_height; ++k) {
          wattron(generate, COLOR_PAIR(10));
          mvwaddch(generate, y + k, x + cell_width, '|');
          wattroff(generate, COLOR_PAIR(10));
        }
      }
    }
  }
  wrefresh(generate);
  delwin(generate);
}

void printLoadMaze(int height_cli, int width_cli) {
  Maze_t *maze = currentMaze();
  int cell_height = 1;
  int cell_width = 2;
  int start_y = 0;
  int start_x = 0;
  int max_height = height_cli;
  int max_width = width_cli;
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
void printPathBanner(int height_cli, int width_cli, Position *path,
                     int pathLength) {
  Maze_t *maze = currentMaze();

  int cell_height = 1;
  int cell_width = 2;
  int start_y = 0;
  int start_x = 0;
  int win_height = height_cli;
  int win_width = width_cli;
  int x, y;

  WINDOW *pathway = newwin(win_height, win_width, start_y, start_x);
  werase(pathway);

  // отрисовка границ "поля"
  // mvhline(start_y, start_x, '_', win_width);
  // mvvline(start_y + 1, start_x, '|', win_height);

  // отрисовка лабиринта - стенки справа и снизу
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      y = start_y + i * cell_height;
      x = start_x + j * cell_width;

      if (maze->h_walls[i][j]) {
        wattron(pathway, COLOR_PAIR(2));
        mvwhline(pathway, y + cell_height, x + 1, '_', cell_width);
        wattroff(pathway, COLOR_PAIR(2));
      }

      if (maze->v_walls[i][j]) {
        for (int k = 1; k <= cell_height; ++k) {
          wattron(pathway, COLOR_PAIR(2));
          mvwaddch(pathway, y + k, x + cell_width, '|');
          wattroff(pathway, COLOR_PAIR(1));
        }
      }
    }
  }

  // Отрисовка пути
  for (int i = 0; i < pathLength; ++i) {
    wattron(pathway, COLOR_PAIR(1));
    y = start_y + path[i].y * cell_height;
    x = start_x + path[i].x * cell_width;
    mvprintw(y + 1, x + 1, "o");
    wattroff(pathway, COLOR_PAIR(1));
  }
  wrefresh(pathway);
  delwin(pathway);
}

void print_maze_t() {
  Maze_t *maze = currentMaze();
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

void print_maze_t_path(const Position *path, int pathLength) {
  Maze_t *maze = currentMaze();
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