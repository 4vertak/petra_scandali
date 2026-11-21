#include "./main.h"

void game_loop() {
  bool break_flag = false;

  Position start = {0, 0};
  Position end = {0, 0};
  int pathLength = 0;

  Maze_t *maze = currentMaze();
  State_t *state = currentState();
  Cave_t *cave = currentCave();

  UserAction_t action = NOSIG;
  srand(time(NULL));
  while (!break_flag) {
    if (*state == EXIT) break_flag = true;

    userInput(action, state);

    if (*state != EXIT) {
      handleUserInput(&action);
    }

    updateCurrentState(state);
    printGame(state, pathLength, &start, &end);
  }

  if (maze) {
    if (maze->sideLine) free(maze->sideLine);
    free2dArray(maze->v_walls, maze->rows);
    free2dArray(maze->h_walls, maze->rows);
  }
  if (cave) {
    freeCave(cave);
  }
  endwin();
}

#ifndef DEBAG
int main() {
  WIN_INIT(10);
  srand(time(NULL));
  game_loop();
  return 0;
}
#endif

#ifdef DEBAG

int main() {
  Maze_t *maze = createMaze(10, 10);
  // loadMaze("MazeTest.txt", maze);
  generateMaze_t(maze);
  Pathway_t way;
  initializePathway_t(&way, maze);

  Position start = {0, 0};
  Position end = {9, 9};

  Position *path = NULL;
  int pathLength = 0;
  for (int i = 0; i < way.rows; ++i) {
    for (int j = 0; j < way.cols; ++j) {
      printf("%2d ", way.map[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  findWay(&way, start, end, &path, &pathLength, maze);

  for (int i = 0; i < way.rows; ++i) {
    for (int j = 0; j < way.cols; ++j) {
      printf("%2d ", way.map[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Путь длиной %d\n", pathLength);

  for (int i = 0; i < pathLength; ++i) {
    printf("path[%d].y = %2d path[%d].x = %2d\n", i, path[i].y, i, path[i].x);
  }
  float ***Q = createQTable(maze);
  q_learning(maze, &start, &end, Q);
  int **patharray = allocateArray(maze->rows, maze->cols);
  int len = 0;
  //   loadQTable("QTable.txt", Q, maze);

  findWayinQTable(&start, &end, patharray, &len, maze, Q);
  printQTable(maze, Q);

  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      printf("%2d ", patharray[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  saveQTable("QTable.txt", Q, maze);
  saveMaze("MazeTest.txt", maze);
  free2dArray(patharray, maze->rows);
  free(path);
  freeingPathMapMemory(&way);
  freeMaze(maze);

  return 0;
}
#endif