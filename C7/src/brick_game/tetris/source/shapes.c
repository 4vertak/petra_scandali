#include "../include/shapes.h"
int *historyShape() {
  static int history[MAX_HISTORY] = {0};
  return history;
}

Shape_t *currentShape() {
  static Shape_t shape = {NULL, 0, 0, 0, I};
  return &shape;
}

int **getShape(ShapeId_t id, int length) {
  int **new_shape = initMatrix(length, length);
  int color_shape = id + 1;
  switch (id) {
    case I:
      for (int j = 0; j < length; j++) new_shape[1][j] = color_shape;
      break;
    case O:
      for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++) new_shape[i][j] = color_shape;
      break;
    case J:
      for (int j = 0; j < length; j++) new_shape[j][1] = color_shape;
      new_shape[2][0] = color_shape;
      break;
    case L:
      for (int j = 0; j < length; j++) new_shape[j][1] = color_shape;
      new_shape[2][2] = color_shape;
      break;
    case S:
      for (int j = 0; j < length - 1; j++) {
        new_shape[0][j + 1] = color_shape;
        new_shape[1][j] = color_shape;
      }
      break;
    case Z:
      for (int j = 0; j < length - 1; j++) {
        new_shape[0][j] = color_shape;
        new_shape[1][j + 1] = color_shape;
      }
      break;
    case T:
      for (int j = 0; j < length; j++) new_shape[0][j] = color_shape;
      new_shape[1][1] = color_shape;
      break;
  }
  return new_shape;
}

int **initMatrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    return NULL;
  }

  int **array = (int **)calloc(rows, sizeof(int *));
  if (array == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    array[i] = (int *)calloc(cols, sizeof(int));
    if (array[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(array[j]);
      }
      free(array);
      return NULL;
    }
  }
  return array;
}

void freeMatrix(int **array, int rows) {
  if (array) {
    for (int i = 0; i < rows; i++) {
      if (array[i] != NULL) {
        free(array[i]);
        array[i] = NULL;
      }
    }
    free(array);
    // array = NULL;
  }
}

int **getNewRandomShape(int level) {
  int *history = historyShape();
  int candidate_shapes[COUNT_SHAPES];
  int candidate_count = 0;

  // Заполняем массив candidate_shapes индексами от 0 до COUNT_SHAPES - 1
  for (int i = 0; i < COUNT_SHAPES; i++) {
    candidate_shapes[i] = i;
  }

  // Проверяем на уникальность по истории
  for (int i = 0; i < COUNT_SHAPES; i++) {
    if (level < 2) {
      if (candidate_shapes[i] != history[2] &&
          candidate_shapes[i] != history[1] &&
          candidate_shapes[i] != history[0]) {
        candidate_shapes[candidate_count++] = candidate_shapes[i];
      }
    } else if (level < 3) {
      if (candidate_shapes[i] != history[2] &&
          candidate_shapes[i] != history[1]) {
        candidate_shapes[candidate_count++] = candidate_shapes[i];
      }
    } else if (level < 5) {
      if (candidate_shapes[i] != history[2]) {
        candidate_shapes[candidate_count++] = candidate_shapes[i];
      }
    } else {
      candidate_shapes[candidate_count++] = candidate_shapes[i];
    }
  }

  int id = candidate_shapes[rand() % candidate_count];

  for (int i = 0; i < MAX_HISTORY - 1; i++) {
    history[i] = history[i + 1];
  }
  history[MAX_HISTORY - 1] = id;

  int length = getLength(id);
  int **array = getShape(id, length);

  return array;
}

int getLength(ShapeId_t id) {
  int N = 3;
  if (id == I) {
    N = 4;
  } else if (id == O) {
    N = 2;
  }
  return N;
}

void setNewRandomShape() {
  GameInfo_t *info = gameInfo();
  Shape_t *current = currentShape();

  if (current != NULL) {
    freeShape(current);
  }

  *current = setCurrentShape();

  if (info->next != NULL) {
    freeMatrix(info->next, getLength(historyShape()[MAX_HISTORY - 1]));
    info->next = NULL;
  }

  info->next = getNewRandomShape(info->level);
}

void freeShape(Shape_t *shape) {
  if (shape) {
    if (shape->array) {
      freeMatrix(shape->array, shape->length);
      shape->array = NULL;
    }
    shape->length = 0;
    shape->row = 0;
    shape->col = 0;
    shape->id = I;
  }
}

Shape_t setCurrentShape() {
  int *history = historyShape();
  Shape_t new_shape = {NULL, 0, 0, 0, 0};
  new_shape.id = history[MAX_HISTORY - 1];
  new_shape.length = getLength(new_shape.id);
  if (new_shape.length > 0)
    new_shape.array = getShape(new_shape.id, new_shape.length);
  new_shape.col = 10 / 2 - ((new_shape.length == 4) ? 3 : new_shape.length) / 2;
  new_shape.row = 0;

  return new_shape;
}

Shape_t copyShape(Shape_t shape) {
  Shape_t new_shape;
  new_shape.length = shape.length;
  new_shape.row = shape.row;
  new_shape.col = shape.col;
  new_shape.id = shape.id;

  new_shape.array = initMatrix(new_shape.length, new_shape.length);
  for (int i = 0; i < new_shape.length; i++) {
    for (int j = 0; j < new_shape.length; j++) {
      new_shape.array[i][j] = shape.array[i][j];
    }
  }
  return new_shape;
}

void rotateShape(Shape_t *shape) {
  for (int i = 0; i < shape->length; i++) {
    for (int j = i + 1; j < shape->length; j++) {
      shape->array[i][j] ^= shape->array[j][i];
      shape->array[j][i] ^= shape->array[i][j];
      shape->array[i][j] ^= shape->array[j][i];
    }
  }
  for (int i = 0; i < shape->length; i++) {
    for (int j = 0; j < shape->length / 2; j++) {
      shape->array[i][j] ^= shape->array[i][shape->length - 1 - j];
      shape->array[i][shape->length - 1 - j] ^= shape->array[i][j];
      shape->array[i][j] ^= shape->array[i][shape->length - 1 - j];
    }
  }
}
