#ifndef SRC_GUI_CLI_H_
#define SRC_GUI_CLI_H_

#include <ncurses.h>

#include "./../../brick_game/tetris/include/gamelogic.h"

#define ROWS_FIELD 20
#define COLS_FIELD 10

#define GET_USER_INPUT getch()

#define SPACE_KEY 32
#define ESCAPE 27
#define ENTER_KEY 10
#define PAUSE_KEY 112
#define SAVE_LOADING_KEY 115

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

void printGame(GameState_t state, GameInfo_t info);
void printStartBanner(int height_cli, int width_cli);
void printNextShapeBanner(GameState_t state, GameInfo_t info, int height_cli,
                          int width_cli);
void printPlayerInfoBanner(GameInfo_t info, int height_cli, int width_cli);

void printField(GameState_t state, GameInfo_t info, int height_cli,
                int width_cli);
void printGameOverBanner(int height_cli, int width_cli);
void printOptionsBanner(int height_cli, int width_cli);
void printLoadingBanner(int height_cli, int width_cli);

#endif  // SRC_GUI_CLI_H_