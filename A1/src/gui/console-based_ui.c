
#include "./console_based_ui.h"

void printGame(State_t *state, int pathLength, Cli_t *size, Position *start,
               Position *end) {
  // int height_cli, width_cli;
  // getmaxyx(stdscr, height_cli, width_cli);

  // start_color();
  // INIT_COLOR_PAIR;

  if (*state == START) {
    printStartBanner(size->term_height, size->term_width);
  } else if (*state == GENERATE_MAZE) {
    print_generate_maze(size, start, end);
  } else if (*state == LOAD_MAZE_FROM_FILE) {
    print_load_maze(size, start, end);
  } else if (*state == FIND_PATHAWAY) {
    print_pathway(size, start, end, &pathLength);
  }
}

// TO-DO: разделить фронт от ИГА

Cli_t *currentCliSize(void) {
  static Cli_t size = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  return &size;
}

void printStartBanner(int height_cli, int width_cli) {
  int win_height = height_cli;
  int win_width = width_cli;
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

// void printGenerateMazeBanner(int height_cli, int width_cli) {
//   Maze_t *maze = currentMaze();

//   int cell_height = 1;
//   int cell_width = 2;
//   int start_y = 0;
//   int start_x = 0;
//   int win_height = height_cli;
//   int win_width = width_cli;
//   int x, y;

//   WINDOW *generate = newwin(win_height, win_width, start_y, start_x);
//   werase(generate);

//   // отрисовка границ "поля"
//   // mvhline(start_y, start_x, '_', win_width);
//   // mvvline(start_y + 1, start_x, '|', win_height);

//   // отрисовка лабиринта - стенки справа и снизу
//   for (int i = 0; i < maze->rows; ++i) {
//     for (int j = 0; j < maze->cols; ++j) {
//       y = start_y + i * cell_height;
//       x = start_x + j * cell_width;

//       if (maze->h_walls[i][j]) {
//         wattron(generate, COLOR_PAIR(1));
//         mvwhline(generate, y + cell_height, x + 1, '_', cell_width);
//         wattroff(generate, COLOR_PAIR(1));
//       }

//       if (maze->v_walls[i][j]) {
//         for (int k = 1; k <= cell_height; ++k) {
//           wattron(generate, COLOR_PAIR(1));
//           mvwaddch(generate, y + k, x + cell_width, '|');
//           wattroff(generate, COLOR_PAIR(1));
//         }
//       }
//     }
//   }
//   wrefresh(generate);
//   delwin(generate);
// }
// void printLoadMaze(int height_cli, int width_cli) {
//   Maze_t *maze = currentMaze();
//   int cell_height = 1;
//   int cell_width = 2;
//   int start_y = 0;
//   int start_x = 0;
//   int max_height = height_cli;
//   int max_width = width_cli;
//   int x, y;

//   // отрисовка границ "поля"
//   mvhline(start_y, start_x, '_', max_width);
//   mvvline(start_y + 1, start_x, '|', max_height);

//   // отрисовка лабиринта - стенки справа и снизу
//   for (int i = 0; i < maze->rows; ++i) {
//     for (int j = 0; j < maze->cols; ++j) {
//       y = start_y + i * cell_height;
//       x = start_x + j * cell_width;

//       if (maze->h_walls[i][j]) {
//         mvhline(y + cell_height, x + 1, '_', cell_width);
//       }

//       if (maze->v_walls[i][j]) {
//         for (int k = 1; k <= cell_height; ++k) {
//           mvprintw(y + k, x + cell_width, "|");
//         }
//       }
//     }
//   }
// }
// void printPathBanner(int height_cli, int width_cli, Position *path,
//                      int pathLength) {
//   Maze_t *maze = currentMaze();
//   int cell_height = 1;
//   int cell_width = 2;
//   int start_y = 0;
//   int start_x = 0;
//   int max_height = height_cli;
//   int max_width = width_cli;
//   int x, y;

//   mvhline(start_y, start_x, '_', max_width);
//   mvvline(start_y + 1, start_x, '|', max_height);

//   // Отрисовка стены и лабиринта
//   for (int i = 0; i < maze->rows; ++i) {
//     for (int j = 0; j < maze->cols; ++j) {
//       y = start_y + i * cell_height;
//       x = start_x + j * cell_width;

//       if (maze->h_walls[i][j]) {
//         mvhline(y + cell_height, x + 1, '_', cell_width);
//       }

//       if (maze->v_walls[i][j]) {
//         for (int k = 1; k <= cell_height; ++k) {
//           mvprintw(y + k, x + cell_width, "|");
//         }
//       }
//     }
//   }

//   // Отрисовка пути
//   for (int i = 0; i < pathLength; ++i) {
//     y = start_y + path[i].y * cell_height;
//     x = start_x + path[i].x * cell_width;
//     mvprintw(y + 1, x + 1, "o");
//   }

//   refresh();
// }

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

/*-------------GUI------------------*/

void init_cli_param(Cli_t *size) {
  getmaxyx(stdscr, size->term_height, size->term_width);
  size->maze_win_height = size->term_height - 2;
  size->maze_win_width = (size->term_width * 2 / 3) - 1;
  size->menu_start_x = size->term_width * 2 / 3 + 2;
  size->input_start_y = size->menu_start_y + 1;
  size->input_start_x = size->menu_start_x;
}

void print_menu(int start_y, int start_x, Position *s, Position *e) {
  Maze_t *maze = currentMaze();
  mvprintw(start_y, start_x, "[s] - load maze from file");
  mvprintw(start_y + 1, start_x, "[g] - generate maze");
  mvprintw(start_y + 2, start_x, "[ESC] - quit");
  mvprintw(start_y + 3, start_x, "[p] - show path");
  mvprintw(start_y + 5, start_x, "Mazes size:");
  mvprintw(start_y + 6, start_x + 11, "rows: %d", maze->rows);
  mvprintw(start_y + 7, start_x + 11, "cols: %d", maze->cols);
  mvprintw(start_y + 9, start_x, "Start positiion: %d %d", s->x, s->y);
  mvprintw(start_y + 10, start_x, "End positiion: %d %d", e->x, e->y);
}

void get_filename(int start_y, int start_x, char *filename) {
  mvprintw(start_y + 11, start_x, "Enter the filename: ");
  refresh();
  echo();
  mvgetstr(start_y + 12, start_x, filename);
  noecho();
  clear();
}

void get_start_end_points(int start_y, int start_x, Position *start,
                          Position *end, int menu_x) {
  char input[100];
  mvprintw(start_y + 11, start_x, "%s", "Input start positiion:");
  refresh();
  echo();
  mvgetstr(start_y + 12, start_x, input);
  sscanf(input, "%3d %3d", &start->x, &start->y);
  input[0] = '\0';
  mvprintw(start_y + 13, start_x, "%s", "Input end positiion:");
  mvgetstr(start_y + 14, start_x, input);
  sscanf(input, "%3d %3d", &end->x, &end->y);
  clear();
  print_menu(0, menu_x, start, end);
  noecho();
}

bool get_dimension(int start_y, int start_x) {
  Maze_t *maze = currentMaze();
  bool result = true;
  int rows = 0;
  int cols = 0;
  echo();
  mvprintw(start_y + 11, start_x, "Enter maze rows (1-50): ");
  refresh();
  scanw("%d", &rows);
  mvprintw(start_y + 12, start_x, "Enter maze cols (1-50): ");
  refresh();
  scanw("%d", &cols);
  noecho();
  clear();
  if (rows < 1 || rows > 50 || cols < 1 || cols > 50) {
    rows = 0;
    cols = 0;
    result = false;
  } else {
    resize_maze_t(maze, rows, cols);
  }
  return result;
}

void print_banner_maze(int start_y, int start_x, int max_height,
                       int max_width) {
  Maze_t *maze = currentMaze();
  int cell_height = max_height / maze->rows;
  int cell_width = max_width / maze->cols;
  int x, y;

  // отрисовка границ "поля"
  mvhline(start_y, start_x, '_', max_width);
  mvvline(start_y + 1, start_x, '|', max_height);

  // отрисовка лабиринта по формату данных - стенки справа и снизу
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

void print_path(int start_y, int start_x, int max_height, int max_width,
                Position *path, int pathLength) {
  Maze_t *maze = currentMaze();
  int cell_height = max_height / maze->rows;
  int cell_width = max_width / maze->cols;
  int x, y;

  if (path) {  // Отрисовка пути
    for (int i = 0; i < pathLength; ++i) {
      y = start_y + path[i].y * cell_height;
      x = start_x + path[i].x * cell_width;
      mvprintw(y + 1, x + 1, "o");
    }
  }
}

void print_load_error() { mvprintw(0, 0, "Could not load file"); }

void print_point_eror(point_valid v, int x, int y) {
  if (v == INVALID_START) mvprintw(y, x, "Invalid start");
  if (v == INVALID_END) mvprintw(y, x, "Invalid end");
}

char *currentFileName(void) {
  static char filename[256] = "";
  return filename;
}

void print_load_maze(Cli_t *size, Position *start, Position *end) {
  Maze_t *maze = currentMaze();
  bool *stateLoad = currentStateLoad();
  char *filename = currentFileName();

  get_filename(size->input_start_y, size->input_start_x, filename);
  *stateLoad = load_maze_t(filename, maze);

  if (*stateLoad) {
    print_banner_maze(size->maze_start_y, size->maze_start_x,
                      size->maze_win_height, size->maze_win_width);
  } else {
    print_load_error();
  }
  print_menu(size->menu_start_y, size->menu_start_x, start, end);
}

void print_pathway(Cli_t *size, Position *start, Position *end,
                   int *pathLength) {
  Maze_t *maze = currentMaze();
  Position *path = currentPath();
  get_start_end_points(size->input_start_y, size->input_start_x, start, end,
                       size->menu_start_x);
  point_valid v = areStartEndValid(start, end);
  if (v != VALID) {
    print_point_eror(v, size->menu_start_x, size->input_start_y + 1);
  } else {
    Pathway_t *way = currentWay();

    initializePathway_t(way, maze);

    // Нахождение пути
    findWay(way, *start, *end, &path, pathLength, maze);
    print_banner_maze(size->maze_start_y, size->maze_start_x,
                      size->maze_win_height, size->maze_win_width);
    print_path(size->maze_start_y, size->maze_start_x, size->maze_win_height,
               size->maze_win_width, path, *pathLength);
    free(path);
  }
}

void print_wrong_dimension_error() {
  mvprintw(0, 0, "Incorrected dimension entered");
}

void print_generate_maze(Cli_t *size, Position *start, Position *end) {
  Maze_t *maze = currentMaze();
  bool *stateSize = currentStateSize();
  *stateSize = get_dimension(size->input_start_y, size->input_start_x);
  clear();
  print_menu(size->menu_start_y, size->menu_start_x, start, end);

  if (*stateSize) {
    generateMaze_t(maze);
    print_banner_maze(size->maze_start_y, size->maze_start_x,
                      size->maze_win_height, size->maze_win_width);
  } else {
    print_wrong_dimension_error();
  }
}