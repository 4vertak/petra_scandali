#ifndef SRC_MAIN_H
#define SRC_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./backend/maze.h"
#include "./gui/console_based_ui.h"
#include "./tests/test.h"

#define GET_USER_INPUT getch()

UserAction_t getSignal(int user_input);
void gameLoop();
bool handleUserInput(UserAction_t *action, bool *hold);

#endif  // SRC_MAIN_H