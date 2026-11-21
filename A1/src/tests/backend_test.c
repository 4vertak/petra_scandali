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
    free2dArray(staticMaze->v_walls, staticMaze->rows);
    free2dArray(staticMaze->h_walls, staticMaze->rows);
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
  bool result_save = saveMaze(filename, maze);
  ck_assert_int_eq(result_save, 1);

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
  action = getSignal('g');
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, SELECT_GENERATE);

  *state = FIND_PATHAWAY;
  action = NOSIG;
  action = getSignal('g');
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, SELECT_GENERATE);

  *state = CAVE_PRINTING_STEP_BY_STEP;
  action = NOSIG;
  action = getSignal('g');
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, SELECT_GENERATE);

  *state = CAVE_PRINTING;
  action = NOSIG;
  action = getSignal('g');
  userInput(action, state);
  ck_assert_int_eq(action, Generate);
  ck_assert_int_eq(*state, SELECT_GENERATE);

  /*----------selectMaze------------------*/

  *state = SELECT_GENERATE;
  action = NOSIG;
  action = getSignal('m');
  userInput(action, state);
  ck_assert_int_eq(action, selectMaze);
  ck_assert_int_eq(*state, GENERATE_MAZE);

  *state = SELECT_LOAD;
  action = NOSIG;
  action = getSignal('m');
  userInput(action, state);
  ck_assert_int_eq(action, selectMaze);
  ck_assert_int_eq(*state, LOAD_MAZE_FROM_FILE);

  /*----------selectCave------------------*/

  *state = SELECT_GENERATE;
  action = NOSIG;
  action = getSignal('c');
  userInput(action, state);
  ck_assert_int_eq(action, selectCave);
  ck_assert_int_eq(*state, GENERATE_CAVE);

  *state = SELECT_LOAD;
  action = NOSIG;
  action = getSignal('c');
  userInput(action, state);
  ck_assert_int_eq(action, selectCave);
  ck_assert_int_eq(*state, LOAD_CAVE_FROM_FILE);

  /*-------------load-----------*/

  *state = START;
  action = getSignal('l');

  userInput(action, state);
  ck_assert_int_eq(*state, SELECT_LOAD);
  ck_assert_int_eq(action, Load);

  *state = FIND_PATHAWAY;
  action = NOSIG;
  action = getSignal('l');
  userInput(action, state);
  ck_assert_int_eq(*state, SELECT_LOAD);
  ck_assert_int_eq(action, Load);

  *state = CAVE_PRINTING_STEP_BY_STEP;
  action = NOSIG;
  action = getSignal('l');
  userInput(action, state);
  ck_assert_int_eq(*state, SELECT_LOAD);
  ck_assert_int_eq(action, Load);

  *state = CAVE_PRINTING;
  action = NOSIG;
  action = getSignal('l');
  userInput(action, state);
  ck_assert_int_eq(*state, SELECT_LOAD);
  ck_assert_int_eq(action, Load);

  /*-------------Pathfinding-----------*/

  *state = MAZE_PRINTING;
  action = getSignal('f');

  userInput(action, state);
  ck_assert_int_eq(*state, FIND_PATHAWAY);
  ck_assert_int_eq(action, Pathfinding);

  *state = FIND_PATHAWAY;
  action = getSignal('f');

  userInput(action, state);
  ck_assert_int_eq(*state, FIND_PATHAWAY);
  ck_assert_int_eq(action, Pathfinding);

  /*-------------QLearning-----------*/

  *state = MAZE_PRINTING;
  action = getSignal('q');

  userInput(action, state);
  ck_assert_int_eq(*state, QL_TRAIN);
  ck_assert_int_eq(action, QLearning);

  *state = FIND_PATHAWAY;
  action = getSignal('q');

  userInput(action, state);
  ck_assert_int_eq(*state, QL_TRAIN);
  ck_assert_int_eq(action, QLearning);

  /*-------------ShowPathfindingMap-----------*/

  *state = SELECT_DISPLAY_WAY;
  action = getSignal('a');

  userInput(action, state);
  ck_assert_int_eq(*state, CAVE_PRINTING_AUTO);
  ck_assert_int_eq(action, ShowPathfindingMap);

  /*-------------Save-----------*/

  *state = FIND_PATHAWAY;
  action = NOSIG;
  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, SAVE_MAZE_IN_FILE);
  ck_assert_int_eq(action, Save);

  *state = CAVE_PRINTING_STEP_BY_STEP;
  action = NOSIG;
  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, SAVE_MAZE_IN_FILE);
  ck_assert_int_eq(action, Save);

  *state = CAVE_PRINTING_AUTO;
  action = NOSIG;
  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, SAVE_MAZE_IN_FILE);
  ck_assert_int_eq(action, Save);

  *state = CAVE_PRINTING;
  action = NOSIG;
  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, SAVE_MAZE_IN_FILE);
  ck_assert_int_eq(action, Save);

  *state = SELECT_DISPLAY_WAY;
  action = NOSIG;
  action = getSignal('s');
  userInput(action, state);
  ck_assert_int_eq(*state, CAVE_PRINTING_STEP_BY_STEP);
  ck_assert_int_eq(action, Save);

  /*-------------Terminate-----------*/
  action = getSignal(ESCAPE);
  userInput(action, state);
  ck_assert_int_eq(*state, EXIT);
  ck_assert_int_eq(action, Terminate);
  action = getSignal(NOSIG);
  userInput(action, state);
  ck_assert_int_eq(*state, EXIT);
  ck_assert_int_eq(action, NOSIG);

  /*-------------updateCurrentState-----------*/
  bool *stateSize = sizeInputState();
  bool *stateLoad = mazeLoadingState();
  bool *stateSave = mazeSaveState();
  bool *stateFind = pathfindingState();

  *state = START;

  updateCurrentState(state);
  ck_assert_int_eq(*state, START);

  *state = GENERATE_MAZE;
  *stateSize = false;
  updateCurrentState(state);
  ck_assert_int_eq(*state, GENERATE_MAZE);
  *stateSize = true;
  updateCurrentState(state);
  ck_assert_int_eq(*state, MAZE_PRINTING);
  ck_assert_int_eq(*stateSize, false);

  *state = GENERATE_CAVE;
  *stateSize = false;
  updateCurrentState(state);
  ck_assert_int_eq(*state, GENERATE_CAVE);
  *stateSize = true;
  updateCurrentState(state);
  ck_assert_int_eq(*state, SELECT_DISPLAY_WAY);
  ck_assert_int_eq(*stateSize, false);

  *state = LOAD_MAZE_FROM_FILE;
  *stateLoad = false;
  updateCurrentState(state);
  ck_assert_int_eq(*state, LOAD_MAZE_FROM_FILE);
  *stateLoad = true;
  updateCurrentState(state);
  ck_assert_int_eq(*state, MAZE_PRINTING);
  ck_assert_int_eq(*stateLoad, false);

  *state = LOAD_CAVE_FROM_FILE;
  *stateLoad = false;
  updateCurrentState(state);
  ck_assert_int_eq(*state, LOAD_CAVE_FROM_FILE);
  *stateLoad = true;
  updateCurrentState(state);
  ck_assert_int_eq(*state, CAVE_PRINTING);
  ck_assert_int_eq(*stateLoad, false);

  *state = SAVE_MAZE_IN_FILE;
  *stateSave = false;
  updateCurrentState(state);
  ck_assert_int_eq(*state, SAVE_MAZE_IN_FILE);
  *stateSave = true;
  updateCurrentState(state);
  ck_assert_int_eq(*state, MAZE_PRINTING);
  ck_assert_int_eq(*stateSave, false);

  *state = FIND_PATHAWAY;
  *stateFind = true;
  updateCurrentState(state);
  ck_assert_int_eq(*state, MAZE_PRINTING);

  *state = FIND_PATHAWAY;
  *stateFind = false;
  updateCurrentState(state);
  ck_assert_int_eq(*state, FIND_PATHAWAY);
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
  Maze_t *staticMaze = currentMaze();
  resizeMaze(staticMaze, 4, 4);

  if (staticMaze) {
    if (staticMaze->sideLine) free(staticMaze->sideLine);
    free2dArray(staticMaze->v_walls, staticMaze->rows);
    free2dArray(staticMaze->h_walls, staticMaze->rows);
  }
}
END_TEST

START_TEST(test_helpers_maze_3) {
  bool *stateSizeMaze = sizeInputState();
  ck_assert_uint_eq(*stateSizeMaze, 0);

  bool *stateLoadMaze = mazeLoadingState();
  ck_assert_uint_eq(*stateLoadMaze, 0);

  bool *result = showPathfindingMapState();
  ck_assert_uint_eq(*result, 0);
}
END_TEST

/*--------------Cave--------------------------*/

START_TEST(test_cave_1) {
  Cave_t *cave = currentCave();
  char *filename = "./tests/test_cave.txt";
  bool result = readFile(cave, filename);
  ck_assert_int_eq(cave->rows, 4);
  ck_assert_int_eq(cave->cols, 4);
  ck_assert_int_eq(result, 1);

  int rows = 10;
  int cols = 10;
  int birthLimit = 1;
  int bornLimit = 6;
  int chance = 45;
  resizeCave(cave, rows, cols);
  setLimits(cave, birthLimit, bornLimit);
  generateMap(cave, chance);
  for (int i = 0; i < 10; i++) {
    updateMap(cave);
    ck_assert_int_eq(cave->rows, rows);
    ck_assert_int_eq(cave->cols, cols);
    ck_assert_int_eq(cave->birthLimit, birthLimit);
    ck_assert_int_eq(cave->bornLimit, bornLimit);
  }
  if (cave) {
    freeCave(cave);
  }
}
END_TEST

/*--------------Q-Learning--------------------------*/

START_TEST(test_ml_ql_1) {
  Maze_t *maze = createMaze(4, 4);
  generateMaze_t(maze);
  Position start = {0, 0};
  Position end = {3, 3};
  float ***Q = createQTable(maze);
  q_learning(maze, &start, &end, Q);
  int **patharray = allocateArray(maze->rows, maze->cols);
  int len = 0;
  findWayinQTable(&start, &end, patharray, &len, maze, Q);
  printQTable(maze, Q);
  bool result = saveQTable("QTable.txt", Q, maze);
  ck_assert_int_eq(result, true);
  result = loadQTable("QTable.txt", Q, maze);
  ck_assert_int_eq(result, true);
  free2dArray(patharray, maze->rows);
  freeQTable(Q, maze->rows, maze->cols);
  freeMaze(maze);
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
  tcase_add_test(tc, test_cave_1);
  tcase_add_test(tc, test_ml_ql_1);

  return s;
}