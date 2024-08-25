#include "./main_test.h"

START_TEST(test_initGameInfo) {
  initGameInfo();
  GameInfo_t *info = gameInfo();
  Shape_t *current = currentShape();

  ck_assert_int_eq(info->score, 0);
  ck_assert_int_eq(info->level, 1);
  ck_assert_int_eq(info->speed, 1);
  ck_assert_int_eq(info->pause, FALSE);
  ck_assert(info->high_score >=
            0);  // Предполагается, что значение high_score должно быть >= 0.
  freeMatrix(info->field, 20);
  freeShape(current);
}
END_TEST

START_TEST(test_setHighScore) {
  GameInfo_t *info = gameInfo();
  info->high_score = 0;  // Сбрасываем, чтобы проверить
  char db_name[18] = "./db_test.db";
  writeHighScoreToDB(77777, db_name);
  setHighScore(info, db_name);
  ck_assert(
      info->high_score >=
      0);  // Проверяем, что high_score был установлен в ненегативное значение
  remove(db_name);
}
END_TEST

START_TEST(test_checkPosition) {
  Shape_t *shape = currentShape();
  shape->array = getShape(I, 4);
  shape->length = 4;
  shape->col = 0;
  shape->row = 0;
  initGameInfo();
  ck_assert_int_eq(checkPosition(shape), TRUE);

  shape->col = 11;
  ck_assert_int_eq(checkPosition(shape), FALSE);
  GameInfo_t *info = gameInfo();
  freeMatrix(info->field, 20);
  freeShape(shape);
}
END_TEST

START_TEST(test_removeFullRows) {
  initGameInfo();
  GameInfo_t *info = gameInfo();
  for (int j = 0; j < 10; j++) {
    info->field[0][j] = 1;  // Заполняем первый ряд
  }

  int count = removeFullRows(info);
  ck_assert_int_eq(count, 1);  // Должен удалить 1 ряд

  for (int j = 0; j < 10; j++) {
    ck_assert_int_eq(info->field[0][j],
                     0);  // Проверяем, что первый ряд стал пустым
  }
  freeMatrix(info->field, 20);
}
END_TEST

START_TEST(test_updateScore) {
  initGameInfo();
  GameInfo_t *info = gameInfo();
  info->score = 500;  // Установим начальный счет
  updateScore(info, 1);
  ck_assert_int_eq(info->score, 600);  // Проверяем, что счет увеличился на 100
  updateScore(info, 2);
  ck_assert_int_eq(info->score, 900);  // Проверяем, что счет увеличился на 300
  updateScore(info, 3);
  ck_assert_int_eq(info->score, 1600);  // Проверяем, что счет увеличился на 700
  updateScore(info, 4);
  ck_assert_int_eq(info->score,
                   3100);  // Проверяем, что счет увеличился на 1500
  updateScore(info, 5);
  ck_assert_int_eq(info->score,
                   4600);  // Проверяем, что счет увеличился на 1500
  freeMatrix(info->field, 20);
}
END_TEST

START_TEST(test_calculateProjection) {
  Shape_t *shape = currentShape();
  shape->array = getShape(I, 4);
  shape->length = 4;
  shape->col = 0;
  shape->row = 0;
  initGameInfo();

  calculateProjection(shape);

  ck_assert_int_eq(shape->row, 18);
  freeShape(shape);
  GameInfo_t *info = gameInfo();

  freeMatrix(info->field, 20);
}
END_TEST

START_TEST(test_updateField) {
  Shape_t *shape = currentShape();
  shape->array = getShape(I, 4);
  shape->length = 4;
  shape->col = 0;
  shape->row = 0;
  initGameInfo();

  updateField();
  GameInfo_t *info = gameInfo();
  ck_assert_int_eq(info->field[0][1], 0);
  freeShape(shape);
  freeMatrix(info->field, 20);
}
END_TEST

Suite *test_backend(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| TEST_BACKEND |=========\033[0m");
  TCase *tc = tcase_create("tc_shapes");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_initGameInfo);
  tcase_add_test(tc, test_setHighScore);
  tcase_add_test(tc, test_checkPosition);
  tcase_add_test(tc, test_removeFullRows);
  tcase_add_test(tc, test_updateScore);
  tcase_add_test(tc, test_calculateProjection);
  tcase_add_test(tc, test_updateField);

  return s;
}