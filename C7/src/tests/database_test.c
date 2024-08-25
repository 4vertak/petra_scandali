#include "./main_test.h"

int **createArray(int rows, int cols) {
  int **array = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    array[i] = malloc(cols * sizeof(int));
  }
  return array;
}

void freeArray(int **array, int rows) {
  for (int i = 0; i < rows; i++) {
    free(array[i]);
  }
  free(array);
}

START_TEST(test_serialize_array) {
  // Тест 1: Нормальный случай
  int rows1 = 2, cols1 = 3;
  int **array1 = createArray(rows1, cols1);
  array1[0][0] = 1;
  array1[0][1] = 2;
  array1[0][2] = 3;
  array1[1][0] = 4;
  array1[1][1] = 5;
  array1[1][2] = 6;

  char *result1 = serializeArray(array1, rows1, cols1);
  ck_assert_str_eq(result1, "1,2,3,4,5,6");
  free(result1);
  freeArray(array1, rows1);

  // Тест 2: Один элемент
  int rows3 = 1, cols3 = 1;
  int **array3 = createArray(rows3, cols3);
  array3[0][0] = 42;

  char *result3 = serializeArray(array3, rows3, cols3);
  ck_assert_str_eq(result3, "42");
  free(result3);
  freeArray(array3, rows3);

  // Тест 3: Смешанные значения
  int rows4 = 2, cols4 = 2;
  int **array4 = createArray(rows4, cols4);
  array4[0][0] = -1;
  array4[0][1] = 0;
  array4[1][0] = 3;
  array4[1][1] = 7;

  char *result4 = serializeArray(array4, rows4, cols4);
  ck_assert_str_eq(result4, "-1,0,3,7");
  free(result4);
  freeArray(array4, rows4);
}
END_TEST

START_TEST(test_deserialize_array) {
  // Тест 1: Нормальный случай
  const char *buffer1 = "1,2,3,4,5,6";
  int rows1 = 2, cols1 = 3;
  int **result1 = deserializeArray(buffer1, rows1, cols1);

  ck_assert_int_eq(result1[0][0], 1);
  ck_assert_int_eq(result1[0][1], 2);
  ck_assert_int_eq(result1[0][2], 3);
  ck_assert_int_eq(result1[1][0], 4);
  ck_assert_int_eq(result1[1][1], 5);
  ck_assert_int_eq(result1[1][2], 6);
  freeArray(result1, rows1);

  // Тест 2: Неверные размеры (0 строк или 0 колонн)
  int **result3 = deserializeArray(buffer1, 0, 3);
  ck_assert_ptr_eq(result3, NULL);

  result3 = deserializeArray(buffer1, 3, 0);
  ck_assert_ptr_eq(result3, NULL);

  // Тест 3: Отрицательные числа
  const char *buffer5 = "-1,-2,-3,-4,-5,-6";
  int rows5 = 2, cols5 = 3;
  int **result5 = deserializeArray(buffer5, rows5, cols5);
  ck_assert_int_eq(result5[0][0], -1);
  ck_assert_int_eq(result5[0][1], -2);
  ck_assert_int_eq(result5[0][2], -3);
  ck_assert_int_eq(result5[1][0], -4);
  ck_assert_int_eq(result5[1][1], -5);
  ck_assert_int_eq(result5[1][2], -6);
  freeArray(result5, rows5);
}
END_TEST

START_TEST(test_s21_strdup) {
  // Тест 1: Нормальный случай
  const char *original = "Hello, World!";
  char *duplicate = s21_strdup(original);
  ck_assert_str_eq(duplicate, original);
  free(duplicate);

  // Тест 2: Пустая строка
  const char *empty = "";
  char *duplicate_empty = s21_strdup(empty);
  ck_assert_str_eq(duplicate_empty, empty);
  free(duplicate_empty);

  // Тест 3: Проверка, что память была выделена
  const char *str = "Test";
  char *dup_str = s21_strdup(str);
  ck_assert_ptr_ne(dup_str, NULL);
  ck_assert_str_eq(dup_str, str);
  free(dup_str);
}
END_TEST

START_TEST(test_insert_info) {
  Shape_t *shape = currentShape();
  shape->array = getShape(I, 4);
  shape->length = 4;
  shape->col = 0;
  shape->row = 0;
  initGameInfo();

  GameInfo_t *info = gameInfo();
  info->next = getShape(I, 4);
  info->score = 123;
  info->high_score = 456;

  int *history = historyShape();
  history[0] = I;
  history[1] = I;
  history[2] = I;

  char *db_name = "./tests/db_test.db";
  remove(db_name);

  saveGame(db_name);
  ck_assert_int_eq(info->score, 123);
  ck_assert_int_eq(info->high_score, 456);
  freeShape(shape);
  freeMatrix(info->next, getLength(history[MAX_HISTORY - 1]));
  freeMatrix(info->field, ROWS);
}
END_TEST

START_TEST(test_loadgame) {
  Shape_t *shape = currentShape();
  shape->length = 4;
  shape->col = 0;
  shape->row = 0;
  initGameInfo();

  GameInfo_t *info = gameInfo();

  int *history = historyShape();
  history[0] = I;
  history[1] = I;
  history[2] = I;

  char *db_name = "./tests/db_test.db";

  loadGame(db_name);
  ck_assert_int_eq(info->score, 123);
  ck_assert_int_eq(info->high_score, 456);

  remove(db_name);
  freeShape(shape);
  freeMatrix(info->next, getLength(history[MAX_HISTORY - 1]));
  freeMatrix(info->field, ROWS);
}
END_TEST

Suite *test_database(void) {
  Suite *s = suite_create("\n\033[37;1m==========| TEST_DB |=========\033[0m");
  TCase *tc = tcase_create("tc_shapes");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_serialize_array);
  tcase_add_test(tc, test_deserialize_array);
  tcase_add_test(tc, test_s21_strdup);
  tcase_add_test(tc, test_insert_info);
  tcase_add_test(tc, test_loadgame);

  return s;
}