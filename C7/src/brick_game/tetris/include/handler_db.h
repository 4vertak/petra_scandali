#ifndef SRC_BRICKGAME_TETRIS_DATABASE_H_
#define SRC_BRICKGAME_TETRIS_DATABASE_H_

#include <sqlite3.h>
#include <string.h>

#include "../include/gamelogic.h"
#include "../include/shapes.h"

void saveGame(char *db_name);

int loadGame(char *db_name);

void insertInfo(sqlite3 *db);

char *serializeArray(int **array, int rows, int cols);

int **deserializeArray(const char *buffer, int rows, int cols);

char *s21_strdup(const char *s);

#endif  // SRC_BRICKGAME_TETRIS_DATABASE_H_