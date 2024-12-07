#ifndef SRC_MAIN_H
#define SRC_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./backend/backend.h"
#include "./gui/console_based_ui.h"

#define GET_USER_INPUT getch()

void game_loop();

#endif  // SRC_MAIN_H