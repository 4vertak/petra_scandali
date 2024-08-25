#ifndef SRC_BRICKGAME_TETRIS_OBJECT_H_
#define SRC_BRICKGAME_TETRIS_OBJECT_H_

#include <sys/time.h>

typedef enum {
  START,
  SPAWN,
  MOVING,
  MOVE,
  ATTACHING,
  GAME_OVER,
  PAUSE,
  SAVE,
  LOADING,
  OPTIONS,
  EXIT_STATE
} GameState_t;

typedef enum {
  Start,
  Pause,
  SaveLoad,
  Options,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action,
  NOSIG
} UserAction_t;

typedef enum { I, O, J, L, S, Z, T } ShapeId_t;

typedef struct {
  int **array;
  int length;
  int row;
  int col;
  ShapeId_t id;
} Shape_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

#endif  // SRC_BRICKGAME_TETRIS_OBJECT_H_