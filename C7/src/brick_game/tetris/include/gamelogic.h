#ifndef SRC_BRICKGAME_TETRIS_BACKEND_H_
#define SRC_BRICKGAME_TETRIS_BACKEND_H_

#include <stdio.h>
#include <stdlib.h>

#include "../../sqlite/sqlite3.h"
#include "./defines.h"
#include "./objects.h"
#include "./shapes.h"

GameInfo_t *gameInfo();
void initGameInfo();
void setHighScore(GameInfo_t *gameInfo, char *db_name);

int checkPosition(Shape_t *shape);
void updateField();
int removeFullRows(GameInfo_t *info);
void updateScore(GameInfo_t *info, int count_lines);
void writeHighScoreToDB(int high_score, char *db_name);
void calculateProjection(Shape_t *shape_projection);

#endif  // SRC_BRICKGAME_TETRIS_BACKEND_H_
