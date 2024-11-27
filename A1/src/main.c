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

  Maze_t *maze = currentMaze();
  State_t *state = currentState();

  UserAction_t action = NOSIG;

  while (!break_flag) {
    if (*state == EXIT) break_flag = true;

    userInput(action, state);

    if (*state == START || *state == GENERATE_MAZE ||
        *state == LOAD_MAZE_FROM_FILE || *state == FIND_PATHAWAY ||
        *state == WAITING) {
      handleUserInput(&action);
    }
    printGame(state, pathLength, &start, &end);
    updateCurrentState(state);
  }

  if (maze) {
    if (maze->sideLine) free(maze->sideLine);
    free_walls(maze->v_walls, maze->rows);
    free_walls(maze->h_walls, maze->rows);
  }
}

int main() {
  srand(time(NULL));
  WIN_INIT(10);
  game_loop();
  endwin();
  return 0;
}