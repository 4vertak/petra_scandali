#ifndef SRC_BRICKGAME_TETRIS_FSM_H_
#define SRC_BRICKGAME_TETRIS_FSM_H_

#include <stdbool.h>

#include "./gamelogic.h"
#include "./handler_db.h"

GameState_t *currentState(void);
void userInput(UserAction_t action, bool hold);
void handleStartAction(GameInfo_t *info, GameState_t *state);
void handlePauseAction(GameState_t *state, GameInfo_t *info);
void handleSaveLoadAction(GameState_t *state, GameInfo_t *info);
void handleOptionsAction(GameInfo_t *info, GameState_t *state);
void handleTerminateAction(GameInfo_t *info, GameState_t *state);
void handleUpAction(GameInfo_t *info, GameState_t *state);
void moveLeft(GameState_t *state, Shape_t *current, Shape_t *temp);
void moveRight(GameState_t *state, Shape_t *current, Shape_t *temp);
void moveDown(GameState_t *state, Shape_t *current, Shape_t *temp);
void moveAction(GameState_t *state, Shape_t *current, Shape_t *temp);

GameInfo_t updateCurrentState();
void onSpawnState(Shape_t *current, GameState_t *state);
void onMovingState(Shape_t *temp, GameState_t *state);
void onAttachingState(GameInfo_t *info, GameState_t *state);
void onLoadingState(GameState_t *state);
void onSaveState();
int timeToUpdate();

#endif  // SRC_BRICKGAME_TETRIS_FSM_H_