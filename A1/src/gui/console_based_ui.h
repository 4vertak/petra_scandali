#ifndef SRC_GUI_CONSOLE_BASED_UI_H
#define SRC_GUI_CONSOLE_BASED_UI_H

#include <locale.h>
#include <ncurses.h>
#include <string.h>
#define __USE_MISC
#include <unistd.h>

#include "../backend/backend.h"

#define ROWS_FIELD 100
#define COLS_FIELD 100

#define GET_USER_INPUT getch()

#define COLOR_ORANGE 214
#define COLOR_GREY 246

typedef enum {
  DEFAULT_COLOR,
  RED,
  ORANGE,
  GREY,
  ORANGEFONT,
  REDFONT,
} color_enum;

#define WIN_INIT(time)    \
  {                       \
    initscr();            \
    noecho();             \
    curs_set(0);          \
    keypad(stdscr, TRUE); \
    timeout(time);        \
  }

#define INIT_COLOR_PAIR                       \
  {                                           \
    init_pair(0, COLOR_WHITE, COLOR_BLACK);   \
    init_pair(1, COLOR_RED, COLOR_RED);       \
    init_color(COLOR_ORANGE, 1000, 550, 0);   \
    init_pair(2, COLOR_ORANGE, COLOR_ORANGE); \
    init_color(COLOR_GREY, 502, 502, 502);    \
    init_pair(3, COLOR_GREY, COLOR_BLACK);    \
    init_pair(4, COLOR_ORANGE, COLOR_BLACK);  \
    init_pair(5, COLOR_RED, COLOR_BLACK);     \
  }

typedef struct {
  int term_height;
  int term_width;
  int maze_start_y;
  int maze_start_x;
  int menu_start_x;
  int menu_start_y;
  int input_start_x;
  int input_start_y;
  int maze_win_height;
  int maze_win_width;
} Cli_t;

/*-----------------CBUI----------------------------*/

void handleUserInput(UserAction_t *action);

Cli_t *currentCliSize(void);
void init_cli_param(Cli_t *size);
void print_mazes_menu(int start_y, int start_x, Position *start, Position *end);
void print_caves_menu(int start_y, int start_x, Cave_t *cave);
void get_filename(int start_y, int start_x, char *filename);
void get_start_end_points(int start_y, int start_x, Position *start,
                          Position *end, int menu_x);
void getParamMaze(Cli_t *size);
void getParamCave(Cli_t *size);
void printWinMaze(int start_y, int start_x, int max_height, int max_width,
                  Position *start, Position *end, int pathLength);
void printWinCave(int start_y, int start_x, int max_height, int max_width);

void bannerMaze(WINDOW *maze_win, Maze_t *maze, int start_y, int start_x,
                int cell_height, int cell_width);
void bannerCave(WINDOW *cave_win, Cave_t *cave, int start_y, int start_x,
                int cell_height, int cell_width);
void bannerPath(WINDOW *maze_win, int start_y, int start_x, int cell_height,
                int cell_width, Position *start, Position *end, int pathLength);
void print_load_error();
char *currentFileName(void);
void print_load_maze(Cli_t *size, Position *start, Position *end);
void print_pathway(Cli_t *size, Position *start, Position *end,
                   int *pathLength);
void print_wrong_dimension_error();
void printGame(State_t *state, int pathLength, Position *start, Position *end);
void printStartBanner(int height_cli, int width_cli);
void printSelectBanner(int height_cli, int width_cli);
void printSelectDisplayCaveBanner(int height_cli, int width_cli);
void print_caves_automod_menu(int start_y, int start_x, Cave_t *cave,
                              unsigned int delay);
void print_caves_manualmod_menu(int start_y, int start_x, Cave_t *cave,
                                int step_count);

#endif  // SRC_GUI_CONSOLE_BASED_UI_H