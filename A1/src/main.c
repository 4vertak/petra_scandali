#include "./main.h"

bool handleUserInput(UserAction_t *action, bool *hold) {
  int signal = GET_USER_INPUT;
  if (signal != ERR) {
    *hold = true;
    *action = getSignal(signal);
  } else {
    *hold = false;
  }
  return *hold;
}

void gameLoop() {
  Maze_t *maze = currentMaze();
  Position *path = NULL;
  int pathLength = 0;

  State_t *state = currentState();

  bool break_flag = TRUE;

  bool hold = FALSE;

  UserAction_t action = NOSIG;

  srand(time(NULL));
  while (break_flag) {
    if (*state == EXIT_STATE) break_flag = FALSE;

    userInput(action, state);

    if (*state == START || *state == GENERATE_MAZE ||
        *state == LOAD_MAZE_FROM_FILE || *state == SAVE_MAZE_IN_FILE ||
        *state == FIND_PATHAWAY || FREE_STATE) {
      handleUserInput(&action, &hold);
    }

    updateCurrentState(state, path, pathLength);
    printGame(state, path, pathLength);
  }

  free(path);
  free_maze(maze);
  endwin();
}

void console_based_gui() {
  setlocale(LC_ALL, "");
  WIN_INIT(10);
  srand(time(NULL));
  gameLoop();
}

int main() {
  console_based_gui();
  return 0;
}
