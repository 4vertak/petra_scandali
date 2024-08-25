#include "./frontend.h"

void printStartBanner(int height_cli, int width_cli) {
  int win_height = 22;
  int win_width = 52;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;

  WINDOW *start = newwin(win_height, win_width, start_y, start_x);
  werase(start);

  int array[4][25] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 7, 7, 7, 0, 7, 0, 0, 7, 7, 7,
                       0, 3, 3, 0, 1, 0, 0, 6, 6, 0, 0, 0},
                      {0, 0, 0, 0, 7, 0, 0, 7, 7, 0, 0, 7, 0,
                       0, 3, 0, 0, 1, 0, 6, 6, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
                       0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}};

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
  mvwprintw(start, 8, 15, "Press [ENTER] to start");
  wattroff(start, COLOR_PAIR(10));

  mvwprintw(start, 10, 11, "Press [s] to load a saved game");
  mvwprintw(start, 12, 16, "Press [o] to options");

  wattron(start, COLOR_PAIR(10));
  mvwprintw(start, 14, 16, "Press [ESC] to exit");
  wattroff(start, COLOR_PAIR(10));
  wrefresh(start);
  delwin(start);
}

void printOptionsBanner(int height_cli, int width_cli) {
  int win_height = 22;
  int win_width = 52;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;

  WINDOW *options = newwin(win_height, win_width, start_y, start_x);
  werase(options);

  int array[6][26] = {{0, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7,
                       0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 7},
                      {7, 6, 7, 0, 7, 6, 7, 0, 6, 7, 6, 0, 6,
                       0, 7, 6, 7, 0, 7, 7, 0, 7, 0, 0, 7, 6},
                      {7, 0, 7, 0, 7, 0, 7, 0, 0, 7, 0, 0, 0,
                       0, 7, 0, 7, 0, 7, 6, 7, 7, 0, 0, 7, 0},
                      {7, 0, 7, 0, 7, 7, 6, 0, 0, 7, 0, 0, 7,
                       0, 7, 0, 7, 0, 7, 0, 6, 7, 0, 0, 7, 0},
                      {6, 7, 6, 0, 7, 6, 0, 0, 0, 7, 0, 0, 7,
                       0, 6, 7, 6, 0, 7, 0, 0, 7, 0, 7, 7, 0},
                      {0, 6, 0, 0, 6, 0, 0, 0, 0, 6, 0, 0, 6,
                       0, 0, 6, 0, 0, 6, 0, 0, 6, 0, 6, 6, 0}};

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 26; j++) {
      int n = array[i][j];
      if (array[i][j] != 0) {
        wattron(options, COLOR_PAIR(n));
        mvwaddch(options, i + 1, j * 2 + 1, ' ');
        mvwaddch(options, i + 1, j * 2 + 2, ' ');
        wattroff(options, COLOR_PAIR(n));
      } else {
        wattron(options, COLOR_PAIR(8));
        mvwaddch(options, i + 1, j * 2 + 1, ' ');
        mvwaddch(options, i + 1, j * 2 + 2, ' ');
        wattroff(options, COLOR_PAIR(8));
      }
    }
  }

  mvwprintw(options, 10, 8, "'[<]' - move left '[>]' - move right");
  mvwprintw(options, 12, 18, "[SPACE] - rotate");
  mvwprintw(options, 14, 11, "[p] - pause [^] - speed up");
  mvwprintw(options, 16, 18, "[s] - save game");

  wattron(options, COLOR_PAIR(10));
  mvwprintw(options, 19, 15, "Press [ESC] to return");
  wattroff(options, COLOR_PAIR(10));
  wrefresh(options);
  delwin(options);
}

void printLoadingBanner(int height_cli, int width_cli) {
  int win_height = 22;
  int win_width = 52;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;

  WINDOW *loading = newwin(win_height, win_width, start_y, start_x);
  werase(loading);

  int array[7][26] = {{3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3, 3,
                       0, 0, 3, 0, 3, 0, 0, 3, 0, 0, 3, 3, 3},
                      {3, 0, 0, 3, 4, 3, 0, 3, 4, 3, 0, 3, 4,
                       3, 0, 4, 0, 3, 3, 0, 3, 0, 3, 4, 4, 4},
                      {3, 0, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0,
                       3, 0, 0, 0, 3, 4, 3, 3, 0, 3, 0, 0, 0},
                      {3, 0, 0, 3, 0, 3, 0, 3, 3, 3, 0, 3, 0,
                       3, 0, 3, 0, 3, 0, 4, 3, 0, 3, 0, 3, 3},
                      {3, 0, 0, 3, 0, 3, 0, 3, 4, 3, 0, 3, 0,
                       3, 0, 3, 0, 3, 0, 4, 3, 0, 3, 0, 4, 3},
                      {3, 3, 0, 4, 3, 4, 0, 3, 0, 3, 0, 3, 3,
                       4, 0, 3, 0, 3, 0, 0, 3, 0, 4, 3, 3, 4},
                      {4, 4, 0, 0, 4, 0, 0, 4, 0, 4, 0, 4, 4,
                       0, 0, 4, 0, 4, 0, 0, 4, 0, 0, 4, 4, 0}};

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 26; j++) {
      int n = array[i][j];
      if (array[i][j] != 0) {
        wattron(loading, COLOR_PAIR(n));
        mvwaddch(loading, i + 1, j * 2 + 1, ' ');
        mvwaddch(loading, i + 1, j * 2 + 2, ' ');
        wattroff(loading, COLOR_PAIR(n));
      } else {
        wattron(loading, COLOR_PAIR(8));
        mvwaddch(loading, i + 1, j * 2 + 1, ' ');
        mvwaddch(loading, i + 1, j * 2 + 2, ' ');
        wattroff(loading, COLOR_PAIR(8));
      }
    }
  }

  mvwprintw(loading, 10, 15, "Press [ENTER] to start");
  wattron(loading, COLOR_PAIR(10));
  mvwprintw(loading, 12, 15, "Press [ESC] to return");
  wattroff(loading, COLOR_PAIR(10));
  wrefresh(loading);
  delwin(loading);
}

void printField(GameState_t state, GameInfo_t info, int height_cli,
                int width_cli) {
  int win_height = 22;
  int win_width = 22;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - 52) / 2;
  WINDOW *field = newwin(win_height, win_width, start_y, start_x);

  Shape_t *current = currentShape();
  Shape_t shape_projection = copyShape(*current);

  calculateProjection(&shape_projection);
  int Buffer[ROWS_FIELD][COLS_FIELD] = {0};

  if (state != START) {
    for (int i = 0; i < current->length; i++) {
      for (int j = 0; j < current->length; j++) {
        if (shape_projection.array[i][j]) {
          shape_projection.array[i][j] = 9;
          Buffer[shape_projection.row + i][shape_projection.col + j] =
              shape_projection.array[i][j];
        }
        if (current->array[i][j]) {
          Buffer[current->row + i][current->col + j] = current->array[i][j];
        }
      }
    }
  }
  freeShape(&shape_projection);
  werase(field);

  box(field, 0, 0);
  int **coordinates = info.field;
  if (coordinates) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++) {
        if (coordinates[i][j] + Buffer[i][j] && state != START) {
          int n = coordinates[i][j] + Buffer[i][j];
          if (coordinates[i][j] + Buffer[i][j] != 0 &&
              coordinates[i][j] + Buffer[i][j] != 9) {
            wattron(field, COLOR_PAIR(n));
            mvwaddch(field, i + 1, j * 2 + 1, ' ');
            mvwaddch(field, i + 1, j * 2 + 2, ' ');
            wattroff(field, COLOR_PAIR(n));
          } else if (coordinates[i][j] + Buffer[i][j] == 9) {
            wattron(field, COLOR_PAIR(n));
            mvwaddch(field, i + 1, j * 2 + 1, '[');
            mvwaddch(field, i + 1, j * 2 + 2, ']');
            wattroff(field, COLOR_PAIR(n));
          } else if (coordinates[i][j]) {
            wattron(field, COLOR_PAIR(8));
            mvwaddch(field, i + 1, j * 2 + 1, ' ');
            mvwaddch(field, i + 1, j * 2 + 2, ' ');
            wattroff(field, COLOR_PAIR(8));
          }
        }
      }
    }
  }
  wrefresh(field);
  delwin(field);
}

void printPlayerInfoBanner(GameInfo_t info, int height_cli, int width_cli) {
  int win_height = 22;
  int win_width = 52;
  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;

  WINDOW *player_info = newwin(11, 18, start_y, start_x + 22);
  werase(player_info);
  box(player_info, 0, 0);

  mvwprintw(player_info, 1, 6, "SCORE:");

  static int temp = 0;
  static int flag = FALSE;
  if (((info.score - temp) < 1500 && (info.score - temp) > 0) ||
      flag == FALSE) {
    mvwprintw(player_info, 2, 6, "%.5d", info.score);
    flag = FALSE;
  }
  if (info.score / 1500 > temp / 1500 || (flag == TRUE && info.score == temp)) {
    wattron(player_info, COLOR_PAIR(10) | A_BOLD | A_BLINK);
    mvwprintw(player_info, 2, 5, "TETRIS!");
    wattroff(player_info, COLOR_PAIR(10) | A_BOLD | A_BLINK);
    flag = TRUE;
  }

  temp = info.score;
  mvwprintw(player_info, 4, 3, "HIGH SCORE:");
  mvwprintw(player_info, 5, 6, "%.5d", info.high_score);
  mvwprintw(player_info, 7, 4, "LEVEL: %.2d", info.level);
  mvwprintw(player_info, 9, 4, "SPEED: %.2d", info.speed);

  wrefresh(player_info);
  delwin(player_info);
}

void printNextShapeBanner(GameState_t state, GameInfo_t info, int height_cli,
                          int width_cli) {
  int win_height = 22;
  int win_width = 52;

  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;

  WINDOW *next_shape = newwin(11, 18, start_y + 11, start_x + 22);
  WINDOW *empty_bg = newwin(22, 22, start_y, start_x + 22 + 18);
  werase(next_shape);
  werase(empty_bg);
  box(next_shape, 0, 0);
  if (state == PAUSE) {
    mvwprintw(next_shape, 1, 6, "PAUSE");
    mvwprintw(next_shape, 3, 2, "Press:");
    mvwprintw(next_shape, 5, 6, "ENTER");
    mvwprintw(next_shape, 6, 3, "to continue");
    mvwprintw(next_shape, 8, 7, "ESC");
    mvwprintw(next_shape, 9, 5, "to exit");
  } else if (state == SAVE) {
    mvwprintw(next_shape, 1, 6, "SAVE");
    mvwprintw(next_shape, 3, 2, "Press:");
    mvwprintw(next_shape, 5, 6, "ENTER");
    mvwprintw(next_shape, 6, 3, "to continue");
    mvwprintw(next_shape, 8, 7, "ESC");
    mvwprintw(next_shape, 9, 5, "to exit");
  } else {
    mvwprintw(next_shape, 1, 6, "NEXT:");
    int **next = info.next;
    if (next) {
      int *history = historyShape();
      int len = getLength(history[MAX_HISTORY - 1]);
      for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
          if (next[i][j]) {
            int n = next[i][j];
            wattron(next_shape, COLOR_PAIR(n));
            mvwaddch(next_shape, i + 3, j * 2 + 5, ' ');
            mvwaddch(next_shape, i + 3, j * 2 + 6, ' ');
            wattroff(next_shape, COLOR_PAIR(n));
          }
        }
      }
    }
  }
  wrefresh(next_shape);
  wrefresh(empty_bg);
  delwin(next_shape);
  delwin(empty_bg);
}

void printGame(GameState_t state, GameInfo_t info) {
  int height_cli, width_cli;
  getmaxyx(stdscr, height_cli, width_cli);

  start_color();
  INIT_COLOR_PAIR;

  if (state == START) {
    printStartBanner(height_cli, width_cli);
  } else if (state == LOADING) {
    printLoadingBanner(height_cli, width_cli);

  } else if (state == MOVING || state == MOVE || state == ATTACHING ||
             state == PAUSE || state == SAVE) {
    printField(state, info, height_cli, width_cli);
    printPlayerInfoBanner(info, height_cli, width_cli);
    printNextShapeBanner(state, info, height_cli, width_cli);
  } else if (state == GAME_OVER) {
    printGameOverBanner(height_cli, width_cli);
  } else if (state == OPTIONS) {
    printOptionsBanner(height_cli, width_cli);
  }
}

void printGameOverBanner(int height_cli, int width_cli) {
  int win_height = 22;
  int win_width = 52;

  int start_y = (height_cli - win_height) / 2;
  int start_x = (width_cli - win_width) / 2;
  WINDOW *game_over = newwin(win_height, win_width, start_y, start_x);
  werase(game_over);

  int array[20][21] = {
      {0, 4, 4, 4, 0, 0, 4, 4, 0, 0, 4, 0, 0, 0, 4, 0, 0, 4, 4, 4, 4},
      {4, 3, 3, 3, 0, 4, 3, 3, 4, 0, 4, 4, 0, 4, 4, 0, 4, 3, 3, 3, 3},
      {4, 0, 0, 0, 0, 4, 0, 0, 4, 0, 4, 3, 4, 3, 4, 0, 4, 0, 0, 0, 0},
      {4, 0, 4, 4, 0, 4, 4, 4, 4, 0, 4, 0, 3, 0, 4, 0, 4, 4, 4, 4, 0},
      {4, 0, 3, 4, 0, 4, 3, 3, 4, 0, 4, 0, 0, 0, 4, 0, 4, 3, 3, 3, 0},
      {4, 0, 0, 4, 0, 4, 0, 0, 4, 0, 4, 0, 0, 0, 4, 0, 4, 0, 0, 0, 0},
      {3, 4, 4, 3, 0, 4, 0, 0, 4, 0, 4, 0, 0, 0, 4, 0, 3, 4, 4, 4, 4},
      {0, 3, 3, 0, 0, 3, 0, 0, 3, 0, 3, 0, 0, 0, 3, 0, 0, 3, 3, 3, 3},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 4, 4, 0, 0, 4, 0, 0, 4, 0, 0, 4, 4, 4, 0, 4, 4, 4, 4, 0},
      {0, 4, 3, 3, 4, 0, 4, 0, 0, 4, 0, 4, 3, 3, 3, 0, 4, 3, 3, 3, 4},
      {0, 4, 0, 0, 4, 0, 4, 0, 0, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 4},
      {0, 4, 0, 0, 4, 0, 4, 0, 0, 4, 0, 4, 4, 4, 0, 0, 4, 4, 4, 4, 3},
      {0, 4, 0, 0, 4, 0, 4, 0, 0, 4, 0, 4, 3, 3, 0, 0, 4, 3, 4, 3, 0},
      {0, 4, 0, 0, 4, 0, 4, 0, 0, 4, 0, 4, 0, 0, 0, 0, 4, 0, 3, 4, 0},
      {0, 3, 4, 4, 3, 0, 3, 4, 4, 3, 0, 3, 4, 4, 4, 0, 4, 0, 0, 3, 4},
      {0, 0, 3, 3, 0, 0, 0, 3, 3, 0, 0, 0, 3, 3, 3, 0, 3, 0, 0, 0, 3}};

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      int n = array[i][j];
      if (array[i][j] != 0) {
        wattron(game_over, COLOR_PAIR(n));
        mvwaddch(game_over, i + 1, j * 2 + 1, ' ');
        mvwaddch(game_over, i + 1, j * 2 + 2, ' ');
        wattroff(game_over, COLOR_PAIR(n));
      } else {
        wattron(game_over, COLOR_PAIR(8));
        mvwaddch(game_over, i + 1, j * 2 + 1, ' ');
        mvwaddch(game_over, i + 1, j * 2 + 2, ' ');
        wattroff(game_over, COLOR_PAIR(8));
      }
    }
  }
  mvwprintw(game_over, 9, 7, "Press [ENTER] to start new game");
  mvwprintw(game_over, 11, 13, "Press [ESC] to exit");
  wrefresh(game_over);
  delwin(game_over);
}
