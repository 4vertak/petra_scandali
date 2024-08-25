#ifndef SRC_BRICKGAME_TETRIS_SHAPES_H_
#define SRC_BRICKGAME_TETRIS_SHAPES_H_

#include <time.h>

#include "./defines.h"
#include "./gamelogic.h"
#include "./objects.h"

Shape_t *currentShape();
int *historyShape();
int **getShape(ShapeId_t id, int length);
int **initMatrix(int rows, int cols);

void freeMatrix(int **array, int rows);

int **getNewRandomShape(int level);

int getLength(ShapeId_t id);

void setNewRandomShape();
Shape_t setCurrentShape();
Shape_t copyShape(Shape_t shape);

void freeShape(Shape_t *shape);

void rotateShape(Shape_t *shape);

#endif  // SRC_BRICKGAME_TETRIS_SHAPES_H_