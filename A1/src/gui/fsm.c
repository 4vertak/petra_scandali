#include "./console_based_ui.h"

UserAction_t getSignal(int user_input) {
  UserAction_t action = NOSIG;
  if (user_input == ENTER_KEY)
    action = Start;
  else if (user_input == ESCAPE)
    action = Terminate;
  else if (user_input == SAVE_LOADING_KEY)
    action = SaveLoad;
  else if (user_input == ESCAPE)
    action = Action;

  return action;
}

void gameLoop() {
  Maze_t *maze = create_empty_maze();
  Pathway_t way;

  initializePathway_t(&way, maze);

  Position start = {0, 0};
  Position end = {0, 0};
  Position *path = NULL;
  int pathLength = 0;

  State_t *state = START;

  bool break_flag = TRUE;

  bool hold = FALSE;

  UserAction_t action = NOSIG;

  srand(time(NULL));
  while (break_flag) {
    if (*state == EXIT_STATE) break_flag = FALSE;

    userInput(action, *state);

    if (*state == START || *state == GENERATE_MAZE ||
        *state == LOAD_MAZE_FROM_FILE || *state == SAVE_MAZE_IN_FILE ||
        *state == FIND_PATHAWAY) {
      handleUserInput(&action, &hold);
    }

    updateCurrentState(state, maze, &way, start, end, path, pathLength);
    printGame(*state, maze, path, pathLength);
  }

  free(path);
  destroyMap(&way);
  free_maze(maze);
  endwin();
}

void userInput(UserAction_t action, State_t state) {
  switch (action) {
    case Start:
      if (state == START) {
        state = GENERATE_MAZE;
      }
      break;
    case SaveLoad:
      if (state == GENERATE_MAZE) {
        state = SAVE_MAZE_IN_FILE;
      }
      if (state == START) {
        state = LOAD_MAZE_FROM_FILE;
      }
      break;
    case Terminate:
      state = EXIT_STATE;
      break;
    default:
      break;
  }
}

bool handleUserInput(UserAction_t *action, bool *hold) {
  int signal = GET_USER_INPUT;
  if (signal != ERR) {
    *hold = true;
    *action = getSignal(signal);
  } else {
    *hold = false;
  }
  return *hold;
}

void updateCurrentState(State_t *state, Maze_t *maze, Pathway_t *way,
                        Position start, Position end, Position *path,
                        int pathLength) {
  switch (*state) {
    case START:
      break;
    case GENERATE_MAZE:
      onGenerateMaze(maze);
      break;
    case LOAD_MAZE_FROM_FILE:
      onLoadingMaze(maze);
      break;
    // case SAVE_MAZE_IN_FILE:
    //   onSaveState();
    //   break;
    case FIND_PATHAWAY:
      onFindPathway(maze, way, start, end, path, pathLength);
      break;
    default:
      break;
  }
}

void onGenerateMaze(Maze_t *maze) {
  int rows, cols;
  printf(
      "Введите размеры лабиринта, в формате 'число строк' 'число столбцов':\n");
  scanf("%d %d", &rows, &cols);
  resize_maze(maze, rows, cols);
  srand(time(NULL));
  generateMaze_t(maze);
}

void onLoadingMaze(Maze_t *maze) {
  char file_name[512];
  printf("Введите имя файла':\n");
  scanf("%s", file_name);
  load_maze("test.txt", maze);
}

void onFindPathway(Maze_t *maze, Pathway_t *way, Position start, Position end,
                   Position *path, int pathLength) {
  printf("Введите координаты старта 'x' 'y':\n");
  scanf("%d %d", &start.x, &start.y);
  printf("Введите координаты выхода 'x' 'y':\n");
  scanf("%d %d", &end.x, &end.y);

  // Нахождение пути
  findWay(way, start, end, &path, &pathLength, maze);
}

void printGame(State_t *state, Maze_t *maze, Position *path, int pathLength) {}
