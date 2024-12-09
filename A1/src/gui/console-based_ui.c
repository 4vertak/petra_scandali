#include "./console_based_ui.h"

void handleUserInput(UserAction_t *action) {
  int signal = GET_USER_INPUT;
  if (signal != ERR) {
    *action = getSignal(signal);
  } else
    *action = NOSIG;
}

void printGame(State_t *state, int pathLength, Position *start, Position *end) {
  Cli_t *size = currentCliSize();
  init_cli_param(size);
  bool *stateFind = pathfindingState();
  bool *stateSave = mazeSaveState();
  bool *stateLoad = mazeLoadingState();
  Maze_t *maze = currentMaze();
  Cave_t *cave = currentCave();
  unsigned int delay = 0;
  int step_count = 0;
  char *filename = currentFileName();
  bool exit_state = false;
  UserAction_t action = NOSIG;
  start_color();

  INIT_COLOR_PAIR;
  switch (*state) {
    case START:
      *stateFind = false;
      printStartBanner(size->term_height, size->term_width);
      break;
    case SELECT_GENERATE:
      *stateFind = false;
      printSelectBanner(size->term_height, size->term_width);
      break;
    case SELECT_LOAD:
      *stateFind = false;
      printSelectBanner(size->term_height, size->term_width);
      break;
    case GENERATE_MAZE:
      *stateFind = false;
      clear();
      print_mazes_menu(size->menu_start_y, size->menu_start_x, start, end);
      getParamMaze(size);
      break;
    case GENERATE_CAVE:
      *stateFind = false;
      clear();

      print_caves_automod_menu(size->menu_start_y, size->menu_start_x, cave,
                               delay);
      getParamCave(size);
      break;
    case SELECT_DISPLAY_WAY:
      *stateFind = false;
      print_caves_automod_menu(size->menu_start_y, size->menu_start_x, cave,
                               delay);
      printSelectDisplayCaveBanner(size->term_height, size->term_width);
      break;
    case LOAD_MAZE_FROM_FILE:
      *stateFind = false;
      clear();
      print_mazes_menu(size->menu_start_y, size->menu_start_x, start, end);
      get_filename(size->input_start_y, size->input_start_x, filename);
      *stateLoad = loadMaze(filename, maze);
      if (!*stateLoad)
        mvprintw(size->menu_start_y + 12, size->input_start_x,
                 "Could not load file");
      break;
    case LOAD_CAVE_FROM_FILE:
      *stateFind = false;
      clear();
      print_caves_menu(size->menu_start_y, size->menu_start_x, cave);
      get_filename(size->input_start_y, size->input_start_x, filename);
      *stateLoad = readFile(cave, filename);
      if (!*stateLoad)
        mvprintw(size->menu_start_y + 12, size->input_start_x,
                 "Could not load file");
      break;
    case SAVE_MAZE_IN_FILE:
      *stateFind = false;
      clear();
      print_mazes_menu(size->menu_start_y, size->menu_start_x, start, end);
      get_filename(size->input_start_y, size->input_start_x, filename);
      *stateSave = saveMaze(filename, maze);
      if (!*stateSave)
        mvprintw(size->menu_start_y + 12, size->input_start_x,
                 "Could not save file");
      break;
    case FIND_PATHAWAY:
      *stateFind = false;
      print_mazes_menu(size->menu_start_y, size->menu_start_x, start, end);
      get_start_end_points(size->input_start_y, size->input_start_x, start, end,
                           size->menu_start_x);
      if (!checkPosition(start)) {
        mvprintw(size->menu_start_y + 12, size->input_start_x, "Invalid start");
      } else if (!checkPosition(end)) {
        mvprintw(size->menu_start_y + 12, size->input_start_x, "Invalid end");
      } else {
        *stateFind = true;
      }
      break;
    case MAZE_PRINTING:
      print_mazes_menu(size->menu_start_y, size->menu_start_x, start, end);
      printWinMaze(size->maze_start_y, size->maze_start_x,
                   size->maze_win_height, size->maze_win_width, start, end,
                   pathLength);
      break;
    case CAVE_PRINTING:
      print_caves_menu(size->menu_start_y, size->menu_start_x, cave);
      printWinCave(size->maze_start_y, size->maze_start_x,
                   size->maze_win_height, size->maze_win_width);
      break;
    case CAVE_PRINTING_STEP_BY_STEP:

      clear();
      while (!exit_state) {
        print_caves_manualmod_menu(size->menu_start_y, size->menu_start_x, cave,
                                   step_count);
        printWinCave(size->maze_start_y, size->maze_start_x,
                     size->maze_win_height, size->maze_win_width);
        handleUserInput(&action);
        if (action == nextStep) {
          updateMap(cave);
          step_count++;
        } else if (action == Terminate) {
          exit_state = true;
          *state = CAVE_PRINTING;
        }
      }
      clear();
      break;
    case CAVE_PRINTING_AUTO:
      clear();
      delay = 1000000;
      nodelay(stdscr, TRUE);
      while (!exit_state) {
        print_caves_automod_menu(size->menu_start_y, size->menu_start_x, cave,
                                 delay);
        printWinCave(size->maze_start_y, size->maze_start_x,
                     size->maze_win_height, size->maze_win_width);
        updateMap(cave);
        handleUserInput(&action);
        if (action == speedUp) {
          delay += 100000;
        } else if (action == speedDown) {
          delay -= 100000;
        } else if (action == Terminate) {
          exit_state = true;
          *state = CAVE_PRINTING;
        }
        usleep(delay);
      }
      clear();
      break;
    default:
      break;
  }
}

void print_mazes_menu(int start_y, int start_x, Position *start,
                      Position *end) {
  Maze_t *maze = currentMaze();
  mvprintw(start_y + 1, start_x, "[l] - load maze from file");
  mvprintw(start_y + 2, start_x, "[g] - generate maze");
  mvprintw(start_y + 3, start_x, "[s] - save maze");
  mvprintw(start_y + 4, start_x, "[f] - show path");
  mvprintw(start_y + 5, start_x, "[ESC] - quit");
  mvprintw(start_y + 7, start_x, "Mazes size:");
  mvprintw(start_y + 8, start_x + 11, "rows: %d", maze->rows);
  mvprintw(start_y + 9, start_x + 11, "cols: %d", maze->cols);
  mvprintw(start_y + 10, start_x, "Start positiion: %d %d", start->x, start->y);
  mvprintw(start_y + 11, start_x, "End positiion: %d %d", end->x, end->y);
}

void print_caves_menu(int start_y, int start_x, Cave_t *cave) {
  mvprintw(start_y + 1, start_x, "[l] - load from file");
  mvprintw(start_y + 2, start_x, "[g] - generate");
  mvprintw(start_y + 3, start_x, "[s] - save");
  mvprintw(start_y + 5, start_x, "[ESC] - quit");
  mvprintw(start_y + 7, start_x, "Caves size:");
  mvprintw(start_y + 8, start_x + 11, "rows: %d", cave->rows);
  mvprintw(start_y + 9, start_x + 11, "cols: %d", cave->cols);
  mvprintw(start_y + 10, start_x, "Birth limit: %d", cave->birthLimit);
  mvprintw(start_y + 11, start_x, "Born limit: %d", cave->bornLimit);
}

void print_caves_automod_menu(int start_y, int start_x, Cave_t *cave,
                              unsigned int delay) {
  mvprintw(start_y + 1, start_x, "[ESC]  - stop & exit");
  mvprintw(start_y + 2, start_x, "[UP] - delay Up");
  mvprintw(start_y + 3, start_x, "[DOWN] - delay Down");
  mvprintw(start_y + 5, start_x, "Caves size:");
  mvprintw(start_y + 6, start_x + 11, "rows: %d", cave->rows);
  mvprintw(start_y + 7, start_x + 11, "cols: %d", cave->cols);
  mvprintw(start_y + 8, start_x, "Birth limit: %d", cave->birthLimit);
  mvprintw(start_y + 9, start_x, "Born limit: %d", cave->bornLimit);
  mvprintw(start_y + 11, start_x, "Seconds delay: %.2f",
           (float)delay / 1000000);
}

void print_caves_manualmod_menu(int start_y, int start_x, Cave_t *cave,
                                int step_count) {
  mvprintw(start_y + 1, start_x, "[n] - next step");
  mvprintw(start_y + 3, start_x, "[ESC] - stop & exit");
  mvprintw(start_y + 5, start_x, "Caves size:");
  mvprintw(start_y + 6, start_x + 11, "rows: %d", cave->rows);
  mvprintw(start_y + 7, start_x + 11, "cols: %d", cave->cols);
  mvprintw(start_y + 8, start_x, "Birth limit: %d", cave->birthLimit);
  mvprintw(start_y + 9, start_x, "Born limit: %d", cave->bornLimit);
  mvprintw(start_y + 11, start_x, "Step: %d", step_count);
}

Cli_t *currentCliSize(void) {
  static Cli_t size = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  return &size;
}

void printSelectBanner(int height_cli, int width_cli) {
  int win_height = 7;
  int win_width = 25;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;
  color_enum color = DEFAULT_COLOR;

  WINDOW *winToSelect = newwin(win_height, win_width, start_y, start_x);
  werase(winToSelect);
  box(winToSelect, 0, 0);
  color = ORANGEFONT;

  wattron(winToSelect, COLOR_PAIR(color));
  mvwprintw(winToSelect, 1, 4, "Press to select:");
  mvwprintw(winToSelect, 3, 7, "[m] - maze");
  mvwprintw(winToSelect, 5, 7, "[c] - cave");
  wattroff(winToSelect, COLOR_PAIR(color));

  wrefresh(winToSelect);
  delwin(winToSelect);
}

void printSelectDisplayCaveBanner(int height_cli, int width_cli) {
  int win_height = 7;
  int win_width = 25;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2 - 4;
  color_enum color = DEFAULT_COLOR;

  WINDOW *winToSelect = newwin(win_height, win_width, start_y, start_x);
  werase(winToSelect);
  box(winToSelect, 0, 0);
  color = ORANGEFONT;

  wattron(winToSelect, COLOR_PAIR(color));
  mvwprintw(winToSelect, 1, 4, "Press to select:");
  mvwprintw(winToSelect, 3, 4, "[s] step by step");
  mvwprintw(winToSelect, 5, 7, "[a] - auto");
  wattroff(winToSelect, COLOR_PAIR(color));

  wrefresh(winToSelect);
  delwin(winToSelect);
}

void printStartBanner(int height_cli, int width_cli) {
  int win_height = 22;
  int win_width = 55;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;
  color_enum color = DEFAULT_COLOR;

  WINDOW *start = newwin(win_height, win_width, start_y, start_x);
  werase(start);

  int array[7][49] = {
      {47, 92, 92, 0,  0,  0,  0,  0,  0,  0,  47, 92, 92, 0,  0,  0,  0,
       0,  0,  47, 92, 0,  0,  0,  0,  0,  0,  0,  47, 92, 92, 92, 92, 92,
       92, 92, 0,  47, 92, 92, 47, 92, 92, 92, 92, 92, 92, 92, 92},
      {47, 92, 0,  47, 92, 92, 0,  0,  0,  47, 92, 92, 92, 0, 0, 0, 0,
       0,  47, 92, 0,  92, 92, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,
       0,  47, 92, 92, 0,  0,  47, 92, 92, 0,  0,  0,  0,  0, 0},
      {47, 92, 92, 0, 47, 92, 92, 0,  47, 0, 47, 92, 92, 0, 0, 0, 0,
       47, 92, 0,  0, 47, 92, 92, 0,  0,  0, 0,  0,  0,  0, 0, 0, 0,
       47, 92, 92, 0, 0,  0,  47, 92, 92, 0, 0,  0,  0,  0, 0},
      {47, 92, 92, 0, 0, 47, 92, 92, 0,  0,  47, 92, 92, 0, 0, 0,  47,
       92, 92, 0,  0, 0, 47, 92, 92, 0,  0,  0,  0,  0,  0, 0, 47, 92,
       92, 0,  0,  0, 0, 0,  47, 92, 92, 92, 92, 92, 92, 0, 0},
      {47, 92, 92, 0,  0,  0, 47, 92, 0,  0, 47, 92, 92, 0, 0,  47, 92,
       92, 92, 92, 92, 92, 0, 47, 92, 92, 0, 0,  0,  0,  0, 47, 92, 92,
       0,  0,  0,  0,  0,  0, 47, 92, 92, 0, 0,  0,  0,  0, 0},
      {47, 92, 92, 0, 0, 0, 0,  0,  0,  0,  47, 92, 92, 0,  47, 92, 92,
       0,  0,  0,  0, 0, 0, 0,  47, 92, 92, 0,  0,  47, 92, 92, 0,  0,
       0,  0,  0,  0, 0, 0, 47, 92, 92, 0,  0,  0,  0,  0,  0},
      {47, 92, 92, 0,  0,  0,  0,  0,  0,  0,  47, 92, 92, 47, 92, 92, 0,
       0,  0,  0,  0,  0,  0,  0,  0,  47, 92, 92, 47, 92, 92, 92, 92, 92,
       92, 92, 92, 92, 92, 92, 47, 92, 92, 92, 92, 92, 92, 92, 92}

  };

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 49; j++) {
      if (array[i][j] == 92) {
        color = ORANGE;
        wattron(start, COLOR_PAIR(color));
        mvwaddch(start, i + 1, j + 1, ' ');
        wattroff(start, COLOR_PAIR(color));
      }
      if (array[i][j] == 47) {
        color = RED;
        wattron(start, COLOR_PAIR(color));
        mvwaddch(start, i + 1, j + 1, ' ');
        wattroff(start, COLOR_PAIR(color));
      }
    }
  }
  color = DEFAULT_COLOR;
  color = ORANGEFONT;

  wattron(start, COLOR_PAIR(color));
  mvwprintw(start, 10, 15, "Press [g] to generate");
  mvwprintw(start, 12, 11, "Press [l] to load from file");
  mvwprintw(start, 14, 16, "Press [ESC] to exit");
  wattroff(start, COLOR_PAIR(color));

  color = GREY;

  wattron(start, COLOR_PAIR(color));
  mvwprintw(start, 21, 5, "Size CLI: height_CLI = %d width_CLI = %d",
            height_cli, width_cli);
  wattroff(start, COLOR_PAIR(color));

  wrefresh(start);
  delwin(start);
}

void init_cli_param(Cli_t *size) {
  getmaxyx(stdscr, size->term_height, size->term_width);
  size->maze_win_height = size->term_height - 2;
  size->maze_win_width = size->term_width - 29;
  size->menu_start_x = size->term_width - 26;
  size->input_start_y = size->menu_start_y + 10;
  size->input_start_x = size->menu_start_x;
}

void get_filename(int start_y, int start_x, char *filename) {
  nodelay(stdscr, false);
  mvprintw(start_y + 4, start_x, "Enter the filename: ");
  refresh();
  echo();
  mvgetstr(start_y + 5, start_x, filename);
  noecho();
  clear();
  nodelay(stdscr, true);
}

void get_position(int start_y, int start_x, Position *point,
                  const char *string) {
  nodelay(stdscr, false);
  char input[100];
  mvprintw(start_y + ((strcmp(string, "start") == 0) ? 4 : 6), start_x,
           "%s %s %s", "Input", string, "positiion:");
  refresh();
  echo();
  mvgetstr(start_y + ((strcmp(string, "start") == 0) ? 5 : 7), start_x, input);
  sscanf(input, "%3d %3d", &point->y, &point->x);
  noecho();
  nodelay(stdscr, true);
}

void get_start_end_points(int start_y, int start_x, Position *start,
                          Position *end, int menu_x) {
  bool *show_pathfinding_map = showPathfindingMapState();
  UserAction_t action = NOSIG;
  char *namepoints = "start";
  get_position(start_y, start_x, start, namepoints);
  namepoints = "end";
  get_position(start_y, start_x, end, namepoints);
  print_mazes_menu(0, menu_x, start, end);
  nodelay(stdscr, false);
  handleUserInput(&action);
  if (action == ShowPathfindingMap)
    *show_pathfinding_map = true;
  else
    *show_pathfinding_map = false;
  nodelay(stdscr, true);
}

void getParamMaze(Cli_t *size) {
  nodelay(stdscr, false);
  bool *stateSize = sizeInputState();
  Maze_t *maze = currentMaze();
  *stateSize = true;
  int rows = 0;
  int cols = 0;
  echo();
  mvprintw(size->input_start_y + 4, size->input_start_x,
           "Enter maze rows (1-50): ");
  refresh();
  scanw("%d", &rows);
  mvprintw(size->input_start_y + 6, size->input_start_x,
           "Enter maze cols (1-50): ");
  refresh();
  scanw("%d", &cols);
  noecho();

  if (rows < 1 || rows > 50 || cols < 1 || cols > 50) {
    rows = 0;
    cols = 0;
    *stateSize = false;
    mvprintw(size->input_start_y + 7, size->input_start_x,
             "Incorrected dimension entered");
  } else {
    resizeMaze(maze, rows, cols);

    generateMaze_t(maze);
    clear();
  }
  nodelay(stdscr, true);
}

void getParamCave(Cli_t *size) {
  nodelay(stdscr, false);
  bool *stateSize = sizeInputState();
  Cave_t *cave = currentCave();
  *stateSize = true;
  int rows = 0;
  int cols = 0;
  int birthLimit = 0;
  int bornLimit = 0;
  int chance = 0;
  echo();
  mvprintw(size->input_start_y + 4, size->input_start_x,
           "Enter cave rows (1-50): ");
  refresh();
  scanw("%d", &rows);
  mvprintw(size->input_start_y + 6, size->input_start_x,
           "Enter cave cols (1-50): ");
  refresh();
  scanw("%d", &cols);
  mvprintw(size->input_start_y + 8, size->input_start_x,
           "Enter birthLimit (1-8): ");
  refresh();
  scanw("%d", &birthLimit);
  mvprintw(size->input_start_y + 10, size->input_start_x,
           "Enter bornLimit (1-8): ");
  refresh();
  scanw("%d", &bornLimit);
  mvprintw(size->input_start_y + 12, size->input_start_x,
           "Enter chance (1-100): ");
  refresh();
  scanw("%d", &chance);

  noecho();

  if (rows < 1 || rows > 50) {
    rows = 0;
    cols = 0;
    *stateSize = false;
    mvprintw(size->input_start_y + 5, size->input_start_x,
             "Incorrected dimension entered");
  } else if (cols < 1 || cols > 50) {
    cols = 0;
    *stateSize = false;
    mvprintw(size->input_start_y + 7, size->input_start_x,
             "Incorrected dimension entered");
  } else if (birthLimit < 1 || birthLimit > 8) {
    birthLimit = 0;
    *stateSize = false;
    mvprintw(size->input_start_y + 9, size->input_start_x,
             "Incorrected birthLimit entered");
  } else if (bornLimit < 1 || bornLimit > 8) {
    bornLimit = 0;
    *stateSize = false;
    mvprintw(size->input_start_y + 11, size->input_start_x,
             "Incorrected bornLimit entered");
  } else if (chance < 1 || chance > 100) {
    chance = 0;
    *stateSize = false;
    mvprintw(size->input_start_y + 13, size->input_start_x,
             "Incorrected chance entered");
  } else {
    resizeCave(cave, rows, cols);
    setLimits(cave, birthLimit, bornLimit);
    generateMap(cave, chance);
    clear();
  }
  nodelay(stdscr, true);
}

void printWinMaze(int start_y, int start_x, int max_height, int max_width,
                  Position *start, Position *end, int pathLength) {
  Maze_t *maze = currentMaze();
  int cell_height = max_height / maze->rows;
  int cell_width = max_width / maze->cols;

  int win_height = max_height;
  int win_width = max_width + 2;

  WINDOW *maze_win = newwin(win_height, win_width, start_y, start_x);
  werase(maze_win);
  bannerMaze(maze_win, maze, start_y, start_x, cell_height, cell_width);
  bool *stateFind = pathfindingState();
  if (*stateFind) {
    bannerPath(maze_win, start_y, start_x, cell_height, cell_width, start, end,
               pathLength);
  }
  wrefresh(maze_win);
  delwin(maze_win);
}

void printWinCave(int start_y, int start_x, int max_height, int max_width) {
  Cave_t *cave = currentCave();
  int cell_height = max_height / cave->rows;
  int cell_width = max_width / cave->cols;

  int win_height = max_height;
  int win_width = max_width + 2;

  WINDOW *cave_win = newwin(win_height, win_width, start_y, start_x);
  werase(cave_win);
  bannerCave(cave_win, cave, start_y, start_x, cell_height, cell_width);
  wrefresh(cave_win);
  delwin(cave_win);
}

void bannerMaze(WINDOW *maze_win, Maze_t *maze, int start_y, int start_x,
                int cell_height, int cell_width) {
  color_enum color = DEFAULT_COLOR;
  color = ORANGEFONT;

  wattron(maze_win, COLOR_PAIR(color));
  mvwhline(maze_win, start_y, start_x, '_', maze->cols * cell_width);
  mvwvline(maze_win, start_y + 1, start_x, '|', maze->rows * cell_height);
  wattroff(maze_win, COLOR_PAIR(color));

  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      int y = start_y + i * cell_height;
      int x = start_x + j * cell_width;

      if (maze->h_walls[i][j]) {
        wattron(maze_win, COLOR_PAIR(color));
        mvwhline(maze_win, y + cell_height, x + 1, '_', cell_width);
        wattroff(maze_win, COLOR_PAIR(color));
      }

      if (maze->v_walls[i][j]) {
        for (int k = 1; k <= cell_height; ++k) {
          wattron(maze_win, COLOR_PAIR(color));
          mvwaddch(maze_win, y + k, x + cell_width, '|');
          wattroff(maze_win, COLOR_PAIR(color));
        }
      }
    }
  }
}

void bannerCave(WINDOW *cave_win, Cave_t *cave, int start_y, int start_x,
                int cell_height, int cell_width) {
  color_enum color = DEFAULT_COLOR;

  for (int i = 0; i < cave->rows; ++i) {
    for (int j = 0; j < cave->cols; ++j) {
      int y = start_y + i * cell_height;
      int x = start_x + j * cell_width;

      if (cave->map[i][j]) {
        color = ORANGE;
        for (int k = 0; k < cell_height; ++k) {
          for (int m = 0; m < cell_width; ++m) {
            wattron(cave_win, COLOR_PAIR(color));
            mvwaddch(cave_win, y + k, x + m, ' ');
            wattroff(cave_win, COLOR_PAIR(color));
          }
        }
      } else {
        color = ORANGEFONT;
        for (int k = 0; k < cell_height; ++k) {
          for (int m = 0; m < cell_width; ++m) {
            wattron(cave_win, COLOR_PAIR(color));
            mvwaddch(cave_win, y + k, x + m, ' ');
            wattroff(cave_win, COLOR_PAIR(color));
          }
        }
      }
    }
  }
}

void bannerPath(WINDOW *maze_win, int start_y, int start_x, int cell_height,
                int cell_width, Position *start, Position *end,
                int pathLength) {
  Position *path = wayOut();
  Pathway_t *way = ways();
  Maze_t *maze = currentMaze();

  bool *show_pathfinding_map = showPathfindingMapState();

  initializePathway_t(way, maze);

  findWay(way, *start, *end, &path, &pathLength, maze);
  color_enum color = DEFAULT_COLOR;
  color = GREY;
  if (*show_pathfinding_map) {
    for (int i = 0; i < way->rows; ++i) {
      for (int j = 0; j < way->cols; ++j) {
        int y = start_y + i * cell_height;
        int x = start_x + j * cell_width;
        if (way->map[i][j] != -1) {
          wattron(maze_win, COLOR_PAIR(color));
          mvwaddch(maze_win, y + ((cell_height == 1) ? 1 : cell_height / 2),
                   x + ((cell_width == 1) ? 1 : cell_width / 2), '*');
          wattroff(maze_win, COLOR_PAIR(color));
        }
      }
    }
  }
  color = REDFONT;
  for (int i = 0; i < pathLength; ++i) {
    int y = start_y + path[i].y * cell_height;
    int x = start_x + path[i].x * cell_width;
    wattron(maze_win, COLOR_PAIR(color));
    mvwaddch(maze_win, y + ((cell_height == 1) ? 1 : cell_height / 2),
             x + ((cell_width == 1) ? 1 : cell_width / 2), '*');
    wattroff(maze_win, COLOR_PAIR(color));
  }
  free(path);
}

char *currentFileName(void) {
  static char filename[256] = "";
  return filename;
}

void print_wrong_dimension_error() {
  mvprintw(0, 0, "Incorrected dimension entered");
}