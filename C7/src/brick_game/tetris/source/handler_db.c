#include "../include/handler_db.h"

void saveGame(char *db_name) {
  sqlite3 *db;
  char *err_msg = NULL;

  int exit = sqlite3_open(db_name, &db);
  if (exit != SQLITE_OK) {
    sqlite3_close(db);
    return;
  }

  const char *create_table_sql =
      "CREATE TABLE IF NOT EXISTS SaveGameInfo(id INTEGER PRIMARY KEY, score "
      "INTEGER, high_score INTEGER, level INTEGER, speed INTEGER, pause "
      "INTEGER, field TEXT, next TEXT, shape_id INTEGER, length INTEGER, "
      "shape_row INTEGER, shape_col INTEGER, shape_array TEXT, history_array "
      "TEXT);";

  exit = sqlite3_exec(db, create_table_sql, 0, 0, &err_msg);
  if (exit != SQLITE_OK) {
    sqlite3_free(err_msg);
    sqlite3_close(db);
    return;
  }

  insertInfo(db);
  sqlite3_close(db);
}

void insertInfo(sqlite3 *db) {
  GameInfo_t *info = gameInfo();
  Shape_t *shape = currentShape();
  int *history = historyShape();
  char *err_msg = NULL;
  int exit;

  char *serialized_field = serializeArray(info->field, ROWS, 10);

  char *serialized_next =
      serializeArray(info->next, getLength(history[2]), getLength(history[2]));

  char *serialized_shape =
      serializeArray(shape->array, shape->length, shape->length);

  int **history_info = initMatrix(1, 3);

  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 3; j++) {
      history_info[i][j] = history[j];
    }
  }

  char *serialized_history = serializeArray(history_info, 1, 3);
  freeMatrix(history_info, 1);

  char sql[1024];
  exit = snprintf(
      sql, sizeof(sql),
      "INSERT OR REPLACE INTO SaveGameInfo(id, score, high_score, level, "
      "speed, pause, field, next, shape_id, length, shape_row, shape_col, "
      "shape_array, history_array) VALUES(1, %d, %d, %d, %d, %d, '%s', '%s', "
      "%d, %d, %d, %d, '%s', '%s');",
      info->score, info->high_score, info->level, info->speed, info->pause,
      serialized_field, serialized_next, shape->id, shape->length, shape->row,
      shape->col, serialized_shape, serialized_history);

  if (exit < 0 || exit >= (int)sizeof(sql)) {
    free(serialized_field);
    free(serialized_next);
    free(serialized_shape);
    free(serialized_history);
    return;
  }

  exit = sqlite3_exec(db, sql, 0, 0, &err_msg);
  if (exit != SQLITE_OK) {
    sqlite3_free(err_msg);
  }

  free(serialized_field);
  free(serialized_next);
  free(serialized_shape);
  free(serialized_history);
}

char *serializeArray(int **array, int rows, int cols) {
  char *buffer = (char *)malloc(1024 * sizeof(char));
  if (buffer == NULL) {
    return NULL;
  }
  buffer[0] = '\0';

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      char temp[12];
      snprintf(temp, sizeof(temp), "%d", array[i][j]);
      strcat(buffer, temp);
      if (j < cols - 1) {
        strcat(buffer, ",");
      }
    }
    if (i < rows - 1) {
      strcat(buffer, ",");
    }
  }
  return buffer;
}

int loadGame(char *db_name) {
  GameInfo_t *info = gameInfo();
  Shape_t *current = currentShape();
  int *history = historyShape();

  sqlite3 *db;

  int exit = sqlite3_open(db_name, &db);
  if (exit != SQLITE_OK) {
    sqlite3_close(db);
    return FALSE;
  }

  const char *sql =
      "SELECT score, high_score, level, speed, pause, field, next, shape_id, "
      "length, shape_row, shape_col, shape_array, history_array FROM "
      "SaveGameInfo LIMIT 1";

  sqlite3_stmt *stmt;
  exit = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if (exit != SQLITE_OK) {
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return FALSE;
  }

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    info->score = sqlite3_column_int(stmt, 0);
    int tmp_high_score = sqlite3_column_int(stmt, 1);
    if (info->high_score < tmp_high_score) info->high_score = tmp_high_score;
    info->level = sqlite3_column_int(stmt, 2);
    info->speed = sqlite3_column_int(stmt, 3);
    info->pause = sqlite3_column_int(stmt, 4);

    const char *field = (const char *)sqlite3_column_text(stmt, 5);
    if (field) {
      if (info->field) {
        freeMatrix(info->field, ROWS);
      }
      info->field = deserializeArray(field, ROWS, 10);
    }

    const char *serialized_history =
        (const char *)sqlite3_column_text(stmt, 11);
    if (serialized_history) {
      int **array_history = deserializeArray(serialized_history, 1, 3);
      for (int i = 0; i < 3; i++) {
        history[i] = array_history[0][i];
      }
      freeMatrix(array_history, 1);
    }

    const char *next = (const char *)sqlite3_column_text(stmt, 6);
    if (next) {
      if (info->next) {
        freeMatrix(info->next, getLength(history[2]));
      }
      info->next =
          deserializeArray(next, getLength(history[2]), getLength(history[2]));
    }
    if (current->array) {
      freeMatrix(current->array, current->length);
    }
    current->id = sqlite3_column_int(stmt, 7);
    current->length = sqlite3_column_int(stmt, 8);
    current->row = sqlite3_column_int(stmt, 9);
    current->col = sqlite3_column_int(stmt, 10);

    current->array = getShape(current->id, getLength(current->id));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return TRUE;
}

int **deserializeArray(const char *buffer, int rows, int cols) {
  if (rows * cols == 0) {
    return NULL;
  }

  int **array = (int **)malloc(rows * sizeof(int *));
  if (array == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    array[i] = (int *)malloc(cols * sizeof(int));
    if (array[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(array[j]);
      }
      free(array);
      return NULL;
    }
  }

  char *lineBuffer = s21_strdup(buffer);
  if (lineBuffer == NULL) {
    for (int i = 0; i < rows; i++) {
      free(array[i]);
    }
    free(array);
    return NULL;
  }

  char *token = strtok(lineBuffer, ",");
  int rowIdx = 0;
  int colIdx = 0;

  while (token != NULL) {
    array[rowIdx][colIdx] = atoi(token);
    colIdx++;

    if (colIdx >= cols) {
      colIdx = 0;
      rowIdx++;
      if (rowIdx >= rows) {
        break;
      }
    }

    token = strtok(NULL, ",");
  }

  free(lineBuffer);
  return array;
}

char *s21_strdup(const char *s) {
  size_t len = strlen(s) + 1;  // +1 для нулевого терминатора
  char *copy = malloc(len);
  if (copy) {
    memcpy(copy, s, len);  // Копируем строку
  }
  return copy;
}