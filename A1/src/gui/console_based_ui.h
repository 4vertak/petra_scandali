#ifndef SRC_GUI_CONSOLE_BASED_UI_H
#define SRC_GUI_CONSOLE_BASED_UI_H

#include <locale.h>
#include <ncurses.h>
#include <string.h>

#include "../backend/backend.h"

#define ROWS_FIELD 100
#define COLS_FIELD 100

#define GET_USER_INPUT getch()

#define COLOR_ORANGE 214
#define COLOR_VIOLET 129
#define COLOR_PINK 215
#define COLOR_GREY 246

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
    init_pair(1, COLOR_RED, COLOR_RED);       \
    init_color(COLOR_PINK, 930, 80, 796);     \
    init_pair(2, COLOR_PINK, COLOR_PINK);     \
    init_color(COLOR_ORANGE, 1000, 550, 0);   \
    init_pair(3, COLOR_ORANGE, COLOR_ORANGE); \
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW); \
    init_pair(5, COLOR_GREEN, COLOR_GREEN);   \
    init_color(COLOR_VIOLET, 580, 0, 830);    \
    init_pair(6, COLOR_VIOLET, COLOR_VIOLET); \
    init_pair(7, COLOR_BLUE, COLOR_BLUE);     \
    init_pair(8, COLOR_WHITE, COLOR_BLACK);   \
    init_color(COLOR_GREY, 502, 502, 502);    \
    init_pair(9, COLOR_GREY, COLOR_BLACK);    \
    init_pair(10, COLOR_ORANGE, COLOR_BLACK); \
    init_pair(11, COLOR_YELLOW, COLOR_BLACK); \
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

Cli_t *currentCliSize(void);
void init_cli_param(Cli_t *size);
void print_menu(int start_y, int start_x, Position *start, Position *end);
void get_filename(int start_y, int start_x, char *filename);
void get_start_end_points(int start_y, int start_x, Position *start,
                          Position *end, int menu_x);
void get_dimension(Cli_t *size);
void print_banner_maze(int start_y, int start_x, int max_height, int max_width,
                       Position *start, Position *end, int pathLength);
void print_path(int start_y, int start_x, int max_height, int max_width,
                Position *path, int pathLength);
void print_load_error();
char *currentFileName(void);
void print_load_maze(Cli_t *size, Position *start, Position *end);
void print_pathway(Cli_t *size, Position *start, Position *end,
                   int *pathLength);
void print_wrong_dimension_error();
void printGame(State_t *state, int pathLength, Position *start, Position *end);
void printStartBanner(int height_cli, int width_cli);

#endif  // SRC_GUI_CONSOLE_BASED_UI_H