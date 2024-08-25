#include "../include/gamelogic.h"

GameInfo_t *gameInfo() {
  static GameInfo_t info = {NULL, NULL, 0, 0, 0, 1, FALSE};
  return &info;
}

void initGameInfo() {
  GameInfo_t *info = gameInfo();
  info->field = initMatrix(ROWS, 10);
  info->next = NULL;
  info->score = 0;
  char db_name[18] = "./db/data_base.db";
  setHighScore(info, db_name);
  info->level = 1;
  info->speed = 1;
  info->pause = FALSE;
}

// void setHighScore(GameInfo_t *gameInfo) {
//   FILE *HighScore = fopen("./highscore.txt", "r+");
//   if (HighScore) {
//     char str_score[15];
//     if (fgets(str_score, 15, HighScore)) {
//       gameInfo->high_score = atoi(str_score);
//     } else {
//       gameInfo->high_score = 0;
//     }
//     fclose(HighScore);
//   } else {
//     gameInfo->high_score = 0;
//   }
// }

void setHighScore(GameInfo_t *gameInfo, char *db_name) {
  sqlite3 *db = NULL;
  int exit;

  exit = sqlite3_open(db_name, &db);
  if (exit != SQLITE_OK) {
    gameInfo->high_score = 0;
    sqlite3_close(db);
    return;
  }

  const char *select_sql = "SELECT score FROM highscores WHERE id = 1;";
  sqlite3_stmt *stmt;

  exit = sqlite3_prepare_v2(db, select_sql, -1, &stmt, 0);
  if (exit == SQLITE_OK) {
    if (sqlite3_step(stmt) == SQLITE_ROW) {
      gameInfo->high_score = sqlite3_column_int(stmt, 0);
    } else {
      gameInfo->high_score = 0;
    }
  } else {
    gameInfo->high_score = 0;
  }
  sqlite3_finalize(stmt);
  sqlite3_close(db);
}

int checkPosition(Shape_t *shape) {
  if (!shape || !shape->array || !shape->length) {
    return FALSE;
  }

  GameInfo_t *info = gameInfo();

  for (int i = 0; i < shape->length; i++) {
    for (int j = 0; j < shape->length; j++) {
      if (shape->array[i][j]) {
        if (shape->col + j < 0 || shape->col + j >= 10 ||
            shape->row + i >= ROWS ||
            (info->field[shape->row + i][shape->col + j])) {
          return FALSE;
        }
      }
    }
  }
  return TRUE;
}

void updateField() {
  GameInfo_t *info = gameInfo();
  Shape_t *current = currentShape();
  for (int i = 0; i < current->length; i++) {
    for (int j = 0; j < current->length; j++) {
      if (current->array[i][j]) {
        info->field[current->row + i][current->col + j] = current->array[i][j];
      }
    }
  }
}

int removeFullRows(GameInfo_t *info) {
  int count_lines = 0;
  for (int i = 0; i < ROWS; i++) {
    int sum = 10;
    for (int j = 0; j < 10; j++) {
      if (info->field[i][j]) sum -= 1;
    }
    if (sum == 0) {
      (count_lines)++;
      for (int k = i; k > 0; k--) {
        for (int l = 0; l < 10; l++) {
          info->field[k][l] = info->field[k - 1][l];
        }
      }
      for (int l = 0; l < 10; l++) {
        info->field[0][l] = 0;
      }
    }
  }
  return count_lines;
}

void updateScore(GameInfo_t *info, int count_lines) {
  if (count_lines) {
    if (count_lines == 1) {
      info->score += 100;
    } else if (count_lines == 2) {
      info->score += 300;
    } else if (count_lines == 3) {
      info->score += 700;
    } else if (count_lines >= 4) {
      info->score += 1500;
    }
    if (info->score > info->high_score) {
      info->high_score = info->score;
      char db_name[18] = "./db/data_base.db";
      writeHighScoreToDB(info->high_score, db_name);
    }
    int tmp = info->level;
    if (info->score / 600 > 10) {
      info->level = 10;
    } else {
      info->level = info->score / 600 + 1;
    }
    if (tmp < info->level) {
      info->speed += (info->level - tmp);
    }
  }
}

void writeHighScoreToDB(int high_score, char *db_name) {
  sqlite3 *db;
  char *err_message = 0;
  int exit;
  sqlite3_open(db_name, &db);

  const char *create_table_sql =
      "CREATE TABLE IF NOT EXISTS highscores ("
      "id INTEGER PRIMARY KEY, "
      "score INTEGER);";
  sqlite3_exec(db, create_table_sql, 0, 0, &err_message);

  char sql[100];
  sprintf(sql, "INSERT OR REPLACE INTO highscores (id, score) VALUES (1, %d);",
          high_score);
  exit = sqlite3_exec(db, sql, 0, 0, &err_message);
  if (exit != SQLITE_OK) sqlite3_free(err_message);
  sqlite3_close(db);
}

void calculateProjection(Shape_t *shape_projection) {
  Shape_t temp = copyShape(*shape_projection);
  temp.row += 1;
  while (checkPosition(&temp)) {
    temp.row++;
  }
  shape_projection->row = temp.row - 1;
  for (int i = 0; i < shape_projection->length; i++) {
    for (int j = 0; j < temp.length; j++) {
      if (shape_projection->array[i][j] != 0) shape_projection->array[i][j] = 8;
    }
  }
  freeShape(&temp);
}

// void writeHighScoreToFile(int high_score) {
//   FILE *highScoreFile = fopen("./highscore.txt", "w");
//   if (highScoreFile) {
//     fprintf(highScoreFile, "%d", high_score);
//     fclose(highScoreFile);
//   }
// }
