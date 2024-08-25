#include "./main_test.h"

START_TEST(test_getShape_I) {
  int length = 4;
  int **shape = getShape(I, length);
  for (int j = 0; j < length; j++) {
    ck_assert_int_eq(shape[1][j], 1);  // color_shape = 0 + 1
  }
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_getShape_O) {
  int length = 2;
  int **shape = getShape(O, length);
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      ck_assert_int_eq(shape[i][j], 2);  // color_shape = 1 + 1
    }
  }
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_getShape_J) {
  int length = 4;
  int **shape = getShape(J, length);
  ck_assert_int_eq(shape[0][1], 3);  // color_shape = 2 + 1
  ck_assert_int_eq(shape[1][1], 3);
  ck_assert_int_eq(shape[2][0], 3);
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_getShape_L) {
  int length = 4;
  int **shape = getShape(L, length);
  ck_assert_int_eq(shape[0][1], 4);  // color_shape = 3 + 1
  ck_assert_int_eq(shape[1][1], 4);
  ck_assert_int_eq(shape[2][2], 4);
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_getShape_S) {
  int length = 4;
  int **shape = getShape(S, length);
  ck_assert_int_eq(shape[0][1], 5);  // color_shape = 4 + 1
  ck_assert_int_eq(shape[1][0], 5);
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_getShape_Z) {
  int length = 4;
  int **shape = getShape(Z, length);
  ck_assert_int_eq(shape[0][0], 6);  // color_shape = 5 + 1
  ck_assert_int_eq(shape[1][1], 6);
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_getShape_T) {
  int length = 4;
  int **shape = getShape(T, length);
  for (int j = 0; j < length; j++) {
    ck_assert_int_eq(shape[0][j], 7);  // color_shape = 6 + 1
  }
  ck_assert_int_eq(shape[1][1], 7);
  freeMatrix(shape, length);
}
END_TEST

START_TEST(test_freeShape) {
  Shape_t shape;
  shape.length = 3;
  shape.array = initMatrix(shape.length, shape.length);
  ck_assert_ptr_ne(shape.array, NULL);

  for (int i = 0; i < shape.length; i++) {
    for (int j = 0; j < shape.length; j++) {
      shape.array[i][j] = 1;
    }
  }

  freeShape(&shape);
}
END_TEST

START_TEST(test_setCurrentShape) {
  int **next_shape = initMatrix(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      next_shape[i][j] = 1;
    }
  }
  Shape_t shape = setCurrentShape(next_shape);
  ck_assert_int_eq((shape.length > 0) ? 1 : 0, 1);
  freeMatrix(next_shape, 3);
  freeShape(&shape);
}
END_TEST

START_TEST(test_copyShape) {
  Shape_t original_shape;
  original_shape.length = 3;
  original_shape.array =
      initMatrix(original_shape.length, original_shape.length);

  for (int i = 0; i < original_shape.length; i++) {
    for (int j = 0; j < original_shape.length; j++) {
      original_shape.array[i][j] = (i + 1) * (j + 1);
    }
  }

  Shape_t copied_shape = copyShape(original_shape);

  for (int i = 0; i < original_shape.length; i++) {
    for (int j = 0; j < original_shape.length; j++) {
      ck_assert_int_eq(copied_shape.array[i][j], original_shape.array[i][j]);
    }
  }

  freeShape(&original_shape);
  freeShape(&copied_shape);
}
END_TEST

START_TEST(test_rotateShape_90) {
  Shape_t shape;
  shape.length = 3;
  shape.array = initMatrix(shape.length, shape.length);

  shape.array[0][0] = 1;
  shape.array[0][1] = 2;
  shape.array[0][2] = 3;
  shape.array[1][0] = 4;
  shape.array[1][1] = 5;
  shape.array[1][2] = 6;
  shape.array[2][0] = 7;
  shape.array[2][1] = 8;
  shape.array[2][2] = 9;

  int expected[3][3] = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

  rotateShape(&shape);

  for (int i = 0; i < shape.length; i++) {
    for (int j = 0; j < shape.length; j++) {
      ck_assert_int_eq(shape.array[i][j], expected[i][j]);
    }
  }

  freeShape(&shape);
}
END_TEST

START_TEST(test_rotateShape_2x2) {
  Shape_t shape;
  shape.length = 2;
  shape.array = initMatrix(shape.length, shape.length);

  shape.array[0][0] = 1;
  shape.array[0][1] = 2;
  shape.array[1][0] = 3;
  shape.array[1][1] = 4;

  int expected[2][2] = {{3, 1}, {4, 2}};

  rotateShape(&shape);

  for (int i = 0; i < shape.length; i++) {
    for (int j = 0; j < shape.length; j++) {
      ck_assert_int_eq(shape.array[i][j], expected[i][j]);
    }
  }

  freeShape(&shape);
}
END_TEST

START_TEST(test_setNewRandomShape) {
  GameInfo_t *info = gameInfo();
  Shape_t *current = currentShape();
  int *history = historyShape();

  setNewRandomShape();
  ck_assert_int_eq((current->length > 0) ? 1 : 0, 1);

  info->level = 2;
  ck_assert_int_eq(info->level, 2);
  setNewRandomShape();
  ck_assert_int_eq((current->length > 0) ? 1 : 0, 1);
  info->level = 4;
  ck_assert_int_eq(info->level, 4);
  setNewRandomShape();
  ck_assert_int_eq((current->length > 0) ? 1 : 0, 1);
  info->level = 7;
  ck_assert_int_eq(info->level, 7);
  setNewRandomShape();
  ck_assert_int_eq((current->length > 0) ? 1 : 0, 1);

  freeShape(current);
  freeMatrix(info->next, getLength(history[MAX_HISTORY - 1]));
}
END_TEST

Suite *test_shapes(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| TEST_SHAPES |=========\033[0m");
  TCase *tc = tcase_create("tc_shapes");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_getShape_I);
  tcase_add_test(tc, test_getShape_O);
  tcase_add_test(tc, test_getShape_J);
  tcase_add_test(tc, test_getShape_L);
  tcase_add_test(tc, test_getShape_S);
  tcase_add_test(tc, test_getShape_Z);
  tcase_add_test(tc, test_getShape_T);
  tcase_add_test(tc, test_freeShape);
  tcase_add_test(tc, test_setCurrentShape);
  tcase_add_test(tc, test_copyShape);
  tcase_add_test(tc, test_rotateShape_90);
  tcase_add_test(tc, test_rotateShape_2x2);
  tcase_add_test(tc, test_setNewRandomShape);

  return s;
}