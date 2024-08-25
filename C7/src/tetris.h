#ifndef SRC_BRICKGAME_TETRIS_H_
#define SRC_BRICKGAME_TETRIS_H_

#include <locale.h>

#include "./brick_game/tetris/include/fsm.h"
#include "./brick_game/tetris/include/gamelogic.h"
#include "./gui/cli/frontend.h"

UserAction_t getSignal(int user_input);
void gameLoop();

bool handleUserInput(UserAction_t *action, bool *hold);

#endif  // SRC_BRICKGAME_TETRIS_H_