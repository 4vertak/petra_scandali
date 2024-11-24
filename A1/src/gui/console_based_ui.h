#ifndef SRC_GUI_CONSOLE_BASED_UI_H
#define SRC_GUI_CONSOLE_BASED_UI_H

#include <locale.h>
#include <ncurses.h>

#include "../backend/maze.h"

#define ROWS_FIELD 20
#define COLS_FIELD 10

#define GET_USER_INPUT getch()

#define ESCAPE 27
#define ENTER_KEY 10
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

typedef enum {
  START,
  GENERATE_MAZE,
  SAVE_MAZE_IN_FILE,
  LOAD_MAZE_FROM_FILE,
  FIND_PATHAWAY,
  EXIT_STATE
} State_t;

typedef enum { Start, SaveLoad, Action, Terminate, NOSIG } UserAction_t;

/*-----------------FSM Logic----------------------------*/

UserAction_t getSignal(int user_input);
void gameLoop();
bool handleUserInput(UserAction_t *action, bool *hold);

void userInput(UserAction_t action, State_t state);

void updateCurrentState(State_t *state, Maze_t *maze, Pathway_t *way,
                        Position start, Position end, Position *path,
                        int pathLength);

void onGenerateMaze(Maze_t *maze);

void onLoadingMaze(Maze_t *maze);

void onFindPathway(Maze_t *maze, Pathway_t *way, Position start, Position end,
                   Position *path, int pathLength);

/*-----------------CBUI----------------------------*/
void printGame(State_t state, Maze_t *maze, Position *path, int pathLength);

/*---------------Принт Дебаг---------------------*/

void print_maze_t(const Maze_t *maze);

void print_maze_t_path(const Maze_t *maze, const Position *path,
                       int pathLength);

#endif  // SRC_GUI_CONSOLE_BASED_UI_H