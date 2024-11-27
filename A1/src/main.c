#include "./main.h"

void handleUserInput(UserAction_t *action) {
  int signal = GET_USER_INPUT;
  if (signal != ERR) {
    *action = getSignal(signal);
  }
}

void game_loop() {
  bool break_flag = false;

  Position start = {0, 0};
  Position end = {0, 0};
  int pathLength = 0;
  init_pair(1, COLOR_RED, COLOR_BLACK);

  Maze_t *maze = currentMaze();
  State_t *state = currentState();
  Cli_t *size = currentCliSize();

  UserAction_t action = NOSIG;

  while (!break_flag) {
    init_cli_param(size);

    if (*state == EXIT) break_flag = true;

    userInput(action, state);

    if (*state == START || *state == GENERATE_MAZE ||
        *state == LOAD_MAZE_FROM_FILE || *state == FIND_PATHAWAY ||
        *state == WAITING) {
      handleUserInput(&action);
    }
    printGame(state, pathLength, size, &start, &end);
    updateCurrentState(state);
  }

  free_maze_t(maze);
}

int main() {
  srand(time(NULL));
  WIN_INIT(10);
  game_loop();
  endwin();
  return 0;
}