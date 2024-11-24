#include "./maze.h"

State_t *currentState(void) {
  static State_t state = START;
  return &state;
}

UserAction_t getSignal(int user_input) {
  UserAction_t action = NOSIG;
  if (user_input == ENTER_KEY) {
    action = Start;
  } else if (user_input == ESCAPE) {
    action = Terminate;
  } else if (user_input == SAVE_LOADING_KEY) {
    action = SaveLoad;
  } else if (user_input == SPACE_KEY) {
    action = Action;
  }

  return action;
}

void userInput(UserAction_t action, State_t *state) {
  switch (action) {
    case Start:
      if (*state == START) {
        *state = GENERATE_MAZE;
      }
      break;
    case SaveLoad:
      if (*state == FREE_STATE) {
        *state = SAVE_MAZE_IN_FILE;
      }
      if (*state == START) {
        *state = LOAD_MAZE_FROM_FILE;
      }
      break;
    case Action:
      if (*state == FREE_STATE) {
        *state = FIND_PATHAWAY;
      }
      break;
    case Terminate:
      if (*state == START || *state == GENERATE_MAZE ||
          *state == LOAD_MAZE_FROM_FILE || *state == FREE_STATE) {
        *state = EXIT_STATE;
      }
      break;
    default:
      break;
  }
}

void updateCurrentState(State_t *state, Position *path, int pathLength) {
  switch (*state) {
    case START:
      break;
    case GENERATE_MAZE:
      onGenerateMaze();
      *state = FREE_STATE;
      break;
    case LOAD_MAZE_FROM_FILE:
      onLoadingMaze();
      *state = FREE_STATE;
      break;
    // case SAVE_MAZE_IN_FILE:
    //   onSaveState();
    //   break;
    case FIND_PATHAWAY:
      onFindPathway(path, pathLength);
      *state = FREE_STATE;
      break;
    default:
      break;
  }
}

void onGenerateMaze() {
  Maze_t *maze = currentMaze();
  int rows = 20, cols = 20;
  create_maze(rows, cols);
  // resize_maze(maze, rows, cols);

  srand(time(NULL));
  generateMaze_t(maze);
}

void onLoadingMaze() {
  Maze_t *maze = currentMaze();
  // char file_name[512];
  // printf("Введите имя файла':\n");
  // scanf("%s", file_name);
  load_maze("test.txt", maze);
}

void onFindPathway(Position *path, int pathLength) {
  Maze_t *maze = currentMaze();
  Pathway_t way;

  initializePathway(&way, maze);
  Position start = {0, 0};
  Position end = {19, 19};
  findWay(&way, start, end, &path, &pathLength, maze);
}
