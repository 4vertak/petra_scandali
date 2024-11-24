#ifndef SRC_GUI_CONSOLE_BASED_UI_H
#define SRC_GUI_CONSOLE_BASED_UI_H

#include <locale.h>
#include <ncurses.h>

#include "../backend/maze.h"

#define ROWS_FIELD 100
#define COLS_FIELD 100

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

/*-----------------CBUI----------------------------*/

void console_based_gui();
void printGame(State_t *state, Position *path, int pathLength);
void printStartBanner(int height_cli, int width_cli);
void printGenerateMazeBanner(int height_cli, int width_cli);
void printLoadMaze(int height_cli, int width_cli);
void printPathBanner(int height_cli, int width_cli, Position *path,
                     int pathLength);
/*---------------Принт Дебаг---------------------*/

void print_maze_t();

void print_maze_t_path(const Position *path, int pathLength);

#endif  // SRC_GUI_CONSOLE_BASED_UI_H