#include "./tetris.h"

int main() {
  setlocale(LC_ALL, "");
  WIN_INIT(10);
  srand(time(NULL));
  gameLoop();
  return 0;
}

UserAction_t getSignal(int user_input) {
  UserAction_t action = NOSIG;
  if (user_input == KEY_UP)
    action = Up;
  else if (user_input == KEY_DOWN)
    action = Down;
  else if (user_input == KEY_LEFT)
    action = Left;
  else if (user_input == KEY_RIGHT)
    action = Right;
  else if (user_input == SPACE_KEY)
    action = Action;
  else if (user_input == ENTER_KEY)
    action = Start;
  else if (user_input == PAUSE_KEY)
    action = Pause;
  else if (user_input == ESCAPE)
    action = Terminate;
  else if (user_input == SAVE_LOADING_KEY) {
    action = SaveLoad;
  } else if (user_input == 'o') {
    action = Options;
  }

  return action;
}

void gameLoop() {
  GameInfo_t *info = gameInfo();
  Shape_t *current = currentShape();
  GameState_t *state = currentState();
  int *history = historyShape();

  bool break_flag = TRUE;
  UserAction_t action = NOSIG;
  bool hold = FALSE;
  srand(time(NULL));
  while (break_flag) {
    if (*state == EXIT_STATE) break_flag = FALSE;

    userInput(action, hold);

    if (*state == START || *state == OPTIONS || *state == LOADING ||
        *state == MOVING || *state == SPAWN || *state == PAUSE ||
        *state == SAVE || *state == GAME_OVER) {
      handleUserInput(&action, &hold);
    }

    updateCurrentState();
    printGame(*state, *info);
  }

  freeShape(current);
  freeMatrix(info->next, getLength(history[MAX_HISTORY - 1]));
  freeMatrix(info->field, ROWS);
  endwin();
}

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
