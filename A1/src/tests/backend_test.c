#include "./main_test.h"

START_TEST(test_create_maze_1) {
  Maze_t *staticMaze = currentMaze();

  ck_assert_int_eq(staticMaze->rows, 0);
  ck_assert_int_eq(staticMaze->cols, 0);
  ck_assert_int_eq((staticMaze->v_walls) ? 1 : 0, 0);
  ck_assert_int_eq((staticMaze->h_walls) ? 1 : 0, 0);
  ck_assert_int_eq((staticMaze->sideLine) ? 1 : 0, 0);
  ck_assert_int_eq(staticMaze->counter, 0);
  if (staticMaze) {
    if (staticMaze->sideLine) free(staticMaze->sideLine);
    freeWalls(staticMaze->v_walls, staticMaze->rows);
    freeWalls(staticMaze->h_walls, staticMaze->rows);
  }
}
END_TEST

START_TEST(test_create_maze_2) {
  int rows = 10;
  int cols = 10;
  Maze_t *maze = createMaze(rows, cols);

  ck_assert_int_eq(maze->rows, 10);
  ck_assert_int_eq(maze->cols, 10);
  ck_assert_int_eq((maze->v_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->h_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->sideLine) ? 1 : 0, 1);
  ck_assert_int_eq(maze->counter, 1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ck_assert_int_eq(maze->v_walls[i][j], 0);
      ck_assert_int_eq(maze->h_walls[i][j], 0);
    }
  }
  freeMaze(maze);
}
END_TEST

START_TEST(test_create_maze_3) {
  int rows = 51;
  int cols = 51;
  Maze_t *maze = createMaze(rows, cols);
  ck_assert_int_eq((maze) ? 1 : 0, 0);

  freeMaze(maze);
}
END_TEST

START_TEST(test_create_maze_4) {
  int rows = 0;
  int cols = 0;
  Maze_t *maze = createMaze(rows, cols);
  ck_assert_int_eq((maze) ? 1 : 0, 0);

  freeMaze(maze);
}
END_TEST

START_TEST(test_resize_maze_1) {
  int rows = 10;
  int cols = 10;
  Maze_t *maze = createMaze(rows, cols);

  ck_assert_int_eq(maze->rows, 10);
  ck_assert_int_eq(maze->cols, 10);
  ck_assert_int_eq((maze->v_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->h_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->sideLine) ? 1 : 0, 1);
  ck_assert_int_eq(maze->counter, 1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ck_assert_int_eq(maze->v_walls[i][j], 0);
      ck_assert_int_eq(maze->h_walls[i][j], 0);
    }
  }
  rows = 20;
  cols = 20;
  resizeMaze(maze, rows, cols);
  ck_assert_int_eq(maze->rows, 20);
  ck_assert_int_eq(maze->cols, 20);
  ck_assert_int_eq((maze->v_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->h_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->sideLine) ? 1 : 0, 1);
  ck_assert_int_eq(maze->counter, 1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ck_assert_int_eq(maze->v_walls[i][j], 0);
      ck_assert_int_eq(maze->h_walls[i][j], 0);
    }
  }

  freeMaze(maze);
}
END_TEST

START_TEST(test_resize_maze_2) {
  int rows = 10;
  int cols = 10;
  Maze_t *maze = createMaze(rows, cols);

  ck_assert_int_eq(maze->rows, 10);
  ck_assert_int_eq(maze->cols, 10);
  ck_assert_int_eq((maze->v_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->h_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->sideLine) ? 1 : 0, 1);
  ck_assert_int_eq(maze->counter, 1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ck_assert_int_eq(maze->v_walls[i][j], 0);
      ck_assert_int_eq(maze->h_walls[i][j], 0);
    }
  }
  rows = 0;
  cols = 0;
  int result = resizeMaze(maze, rows, cols);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(maze->rows, 10);
  ck_assert_int_eq(maze->cols, 10);
  freeMaze(maze);
}
END_TEST

START_TEST(test_resize_maze_3) {
  int rows = 10;
  int cols = 10;
  Maze_t *maze = createMaze(rows, cols);

  ck_assert_int_eq(maze->rows, 10);
  ck_assert_int_eq(maze->cols, 10);
  ck_assert_int_eq((maze->v_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->h_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->sideLine) ? 1 : 0, 1);
  ck_assert_int_eq(maze->counter, 1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ck_assert_int_eq(maze->v_walls[i][j], 0);
      ck_assert_int_eq(maze->h_walls[i][j], 0);
    }
  }
  rows = 51;
  cols = 51;
  int result = resizeMaze(maze, rows, cols);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(maze->rows, 10);
  ck_assert_int_eq(maze->cols, 10);
  freeMaze(maze);
}
END_TEST

START_TEST(test_load_maze_1) {
  Maze_t *maze = createMaze(1, 1);
  const char *filename = "./tests/test_maze.txt";
  bool result = loadMaze(filename, maze);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(maze->rows, 4);
  ck_assert_int_eq(maze->cols, 4);
  ck_assert_int_eq((maze->v_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->h_walls) ? 1 : 0, 1);
  ck_assert_int_eq((maze->sideLine) ? 1 : 0, 1);
  ck_assert_int_eq(maze->counter, 1);

  freeMaze(maze);
}
END_TEST

START_TEST(test_load_maze_2) {
  Maze_t *maze = createMaze(1, 1);
  const char *filename = "./test_maze.txt";
  bool result = loadMaze(filename, maze);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(maze->rows, 1);
  ck_assert_int_eq(maze->cols, 1);
  ck_assert_int_eq(maze->counter, 1);

  freeMaze(maze);
}
END_TEST

START_TEST(test_generate_maze_1) {
  Maze_t *maze = createMaze(20, 20);
  generateMaze_t(maze);

  ck_assert_int_eq(maze->rows, 20);
  ck_assert_int_eq(maze->cols, 20);
  ck_assert_int_ne(maze->counter, 1);

  freeMaze(maze);
}
END_TEST

/*-------НАвигатор-----*/

START_TEST(test_find_pathway_maze_1) {
  Maze_t *maze = createMaze(20, 20);
  generateMaze_t(maze);
  Pathway_t way;
  initializePathway_t(&way, maze);

  Position start = {0, 0};
  Position end = {19, 11};

  Position *path = NULL;
  int pathLength = 0;

  findWay(&way, start, end, &path, &pathLength, maze);

  ck_assert_int_eq(maze->rows, 20);
  ck_assert_int_eq(maze->cols, 20);
  ck_assert_int_ne(pathLength, 0);
  ck_assert_int_eq((path) ? 1 : 0, 1);

  free(path);
  freeingPathMapMemory(&way);
  freeMaze(maze);
}
END_TEST

/*-------FSM-----*/

START_TEST(test_fsm_1) {
  State_t *state = currentState();
  UserAction_t action = NOSIG;
  ck_assert_int_eq(*state, START);
  ck_assert_int_eq(action, NOSIG);
  action = getSignal(103);
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, GENERATE_MAZE);

  updateCurrentState(state);
  ck_assert_int_eq(*state, WAITING);
  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, LOAD_MAZE_FROM_FILE);
  ck_assert_int_eq(action, Load);
  updateCurrentState(state);
  ck_assert_int_eq(*state, WAITING);
  action = getSignal('p');
  userInput(action, state);
  ck_assert_int_eq(*state, FIND_PATHAWAY);
  ck_assert_int_eq(action, Pathfinding);
  updateCurrentState(state);
  ck_assert_int_eq(*state, WAITING);

  action = getSignal(ESCAPE);
  userInput(action, state);
  ck_assert_int_eq(*state, START);
  ck_assert_int_eq(action, Terminate);
  action = getSignal(ESCAPE);
  userInput(action, state);
  ck_assert_int_eq(*state, EXIT);
  ck_assert_int_eq(action, Terminate);

  *state = START;
  action = NOSIG;
  ck_assert_int_eq(*state, START);
  ck_assert_int_eq(action, NOSIG);
  action = getSignal('g');
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, GENERATE_MAZE);

  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, LOAD_MAZE_FROM_FILE);
  ck_assert_int_eq(action, Load);
  updateCurrentState(state);

  action = getSignal('p');
  userInput(action, state);
  ck_assert_int_eq(*state, FIND_PATHAWAY);
  ck_assert_int_eq(action, Pathfinding);

  action = getSignal('g');
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, GENERATE_MAZE);
  action = getSignal('p');
  userInput(action, state);
  ck_assert_int_eq(*state, FIND_PATHAWAY);
  ck_assert_int_eq(action, Pathfinding);

  action = getSignal(ESCAPE);
  userInput(action, state);
  ck_assert_int_eq(*state, START);
  ck_assert_int_eq(action, Terminate);
  action = getSignal(ESCAPE);
  userInput(action, state);
  ck_assert_int_eq(*state, EXIT);
  ck_assert_int_eq(action, Terminate);
}
END_TEST

/*----------помоганторы----------------*/

START_TEST(test_helpers_maze_1) {
  Pathway_t *way = ways();

  ck_assert_int_eq(way->rows, 0);
  ck_assert_int_eq(way->cols, 0);
  ck_assert_int_eq((way->map) ? 1 : 0, 0);

  Position *start = wayOut();
  ck_assert_int_eq(start->x, 0);
  ck_assert_int_eq(start->y, 0);

  Maze_t *staticMaze = currentMaze();
  resizeMaze(staticMaze, 3, 3);
  start->x = 4;
  start->y = 4;

  int result = checkPosition(start);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_helpers_maze_2) {
  Position start = {0, 0};
  Position end = {3, 3};

  Maze_t *staticMaze = currentMaze();
  resizeMaze(staticMaze, 4, 4);

  ck_assert_int_eq(areStartEndValid(&start, &end), 0);
  end.x = 4;
  end.y = 3;
  ck_assert_int_eq(areStartEndValid(&start, &end), 2);

  start.x = 4;
  start.y = 3;
  ck_assert_int_eq(areStartEndValid(&start, &end), 1);
  if (staticMaze) {
    if (staticMaze->sideLine) free(staticMaze->sideLine);
    freeWalls(staticMaze->v_walls, staticMaze->rows);
    freeWalls(staticMaze->h_walls, staticMaze->rows);
  }
}
END_TEST

START_TEST(test_helpers_maze_3) {
  bool *stateSizeMaze = mazeSizeInputState();
  ck_assert_uint_eq(*stateSizeMaze, 0);

  bool *stateLoadMaze = mazeLoadingState();
  ck_assert_uint_eq(*stateLoadMaze, 0);
}
END_TEST

Suite *test_backend(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| TEST_BACKEND |=========\033[0m");
  TCase *tc = tcase_create("tc_shapes");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_create_maze_1);
  tcase_add_test(tc, test_create_maze_2);
  tcase_add_test(tc, test_create_maze_3);
  tcase_add_test(tc, test_create_maze_4);
  tcase_add_test(tc, test_resize_maze_1);
  tcase_add_test(tc, test_resize_maze_2);
  tcase_add_test(tc, test_resize_maze_3);
  tcase_add_test(tc, test_load_maze_1);
  tcase_add_test(tc, test_load_maze_2);
  tcase_add_test(tc, test_generate_maze_1);
  tcase_add_test(tc, test_find_pathway_maze_1);
  tcase_add_test(tc, test_fsm_1);
  tcase_add_test(tc, test_helpers_maze_1);
  tcase_add_test(tc, test_helpers_maze_2);
  tcase_add_test(tc, test_helpers_maze_3);

  return s;
}