
#include "../include/fsm.h"

struct timeval before_now, now;

GameState_t *currentState(void) {
  static GameState_t state = START;
  return &state;
}

void userInput(UserAction_t action, bool hold) {
  GameInfo_t *info = gameInfo();
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  if (!info || !state || !current) {
    return;
  }
  Shape_t temp = copyShape(*current);
  if (hold) {
    switch (action) {
      case Start:
        handleStartAction(info, state);
        break;
      case Pause:
        handlePauseAction(state, info);
        break;
      case SaveLoad:
        handleSaveLoadAction(state, info);
        break;
      case Options:
        handleOptionsAction(info, state);
        break;
      case Terminate:
        handleTerminateAction(info, state);
        break;
      case Up:
        handleUpAction(info, state);
        freeShape(&temp);
        break;
      case Left:
        moveLeft(state, current, &temp);
        freeShape(&temp);
        break;
      case Right:
        moveRight(state, current, &temp);
        freeShape(&temp);
        break;
      case Down:
        moveDown(state, current, &temp);
        freeShape(&temp);
        break;
      case Action:
        moveAction(state, current, &temp);
        freeShape(&temp);
        break;
      default:
        break;
    }

  } else {
    if (*state == MOVE) {
      current->row++;
    }
  }
}

void handleStartAction(GameInfo_t *info, GameState_t *state) {
  if (*state == START) {
    *state = SPAWN;
  } else if (*state == PAUSE) {
    int temp = info->pause;
    info->pause = FALSE;
    *state = temp;
  } else if (*state == SAVE) {
    int temp = info->pause;
    info->pause = FALSE;
    *state = temp;
  } else if (*state == LOADING) {
    int temp = info->pause;
    info->pause = FALSE;
    *state = temp;
  } else if (*state == GAME_OVER) {
    *state = START;
  }
}

void handlePauseAction(GameState_t *state, GameInfo_t *info) {
  if (*state == MOVING || *state == MOVE) {
    info->pause = *state;
    *state = PAUSE;
  }
}

void handleSaveLoadAction(GameState_t *state, GameInfo_t *info) {
  if (*state == MOVING || *state == MOVE) {
    info->pause = *state;
    *state = SAVE;
  }
  if (*state == START) {
    *state = LOADING;
  }
}
void handleOptionsAction(GameInfo_t *info, GameState_t *state) {
  if (*state == START || *state == MOVING || *state == MOVE) {
    info->pause = *state;
    *state = OPTIONS;
  }
}

void handleTerminateAction(GameInfo_t *info, GameState_t *state) {
  if (*state == PAUSE) {
    info->pause = FALSE;
    *state = EXIT_STATE;
  } else if (*state == OPTIONS) {
    int temp = info->pause;
    info->pause = FALSE;
    *state = temp;
  } else if (*state == LOADING) {
    *state = START;
  } else {
    *state = EXIT_STATE;
  }
}

void handleUpAction(GameInfo_t *info, GameState_t *state) {
  if (*state == MOVING || *state == MOVE) {
    if (info->speed < 10) info->speed++;
  }
}

void moveLeft(GameState_t *state, Shape_t *current, Shape_t *temp) {
  if (*state == MOVING) {
    temp->col--;
    if (checkPosition(temp)) current->col--;
  }
}

void moveRight(GameState_t *state, Shape_t *current, Shape_t *temp) {
  if (*state == MOVING) {
    temp->col++;
    if (checkPosition(temp)) current->col++;
  }
}

void moveDown(GameState_t *state, Shape_t *current, Shape_t *temp) {
  if (*state == MOVING) {
    temp->row++;
    if (checkPosition(temp)) {
      current->row++;
    } else {
      *state = ATTACHING;
    }
  }
}

void moveAction(GameState_t *state, Shape_t *current, Shape_t *temp) {
  if (*state == MOVING) {
    rotateShape(temp);
    if (checkPosition(temp)) rotateShape(current);
  }
}

GameInfo_t updateCurrentState() {
  GameInfo_t *info = gameInfo();
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  Shape_t temp = copyShape(*current);
  switch (*state) {
    case START:
      initGameInfo();
      break;
    case SPAWN:
      onSpawnState(current, state);
      break;
    case MOVING:
      onMovingState(&temp, state);
      break;
    case MOVE:
      *state = MOVING;
      break;
    case ATTACHING:
      onAttachingState(info, state);
      break;
    case SAVE:
      onSaveState();
      break;
    case LOADING:
      onLoadingState(state);
      break;
    case GAME_OVER:

      break;
    default:
      break;
  }
  freeShape(&temp);
  return *info;
}

void onSpawnState(Shape_t *current, GameState_t *state) {
  setNewRandomShape();
  if (!checkPosition(current)) {
    *state = GAME_OVER;
  } else {
    *state = MOVING;
  }
}

void onMovingState(Shape_t *temp, GameState_t *state) {
  gettimeofday(&now, NULL);
  if (timeToUpdate()) {
    temp->row++;
    if (checkPosition(temp)) {
      *state = MOVE;
    } else {
      *state = ATTACHING;
    }
    gettimeofday(&before_now, NULL);
  }
}

void onAttachingState(GameInfo_t *info, GameState_t *state) {
  Shape_t temp = setCurrentShape(info->next);
  if (!checkPosition(&temp)) {
    *state = GAME_OVER;
  } else {
    updateField();
    int count_lines = removeFullRows(info);
    updateScore(info, count_lines);
    *state = SPAWN;
  }
}

void onLoadingState(GameState_t *state) {
  char db_name[18] = "./db/data_base.db";
  int flag_check_save = loadGame(db_name);
  if (flag_check_save == FALSE) *state = START;
}

void onSaveState() {
  char db_name[18] = "./db/data_base.db";
  saveGame(db_name);
}

int timeToUpdate() {
  GameInfo_t *info = gameInfo();

  suseconds_t timer = 400000;
  return ((suseconds_t)(now.tv_sec * 1000000 + now.tv_usec) -
          ((suseconds_t)before_now.tv_sec * 1000000 + before_now.tv_usec)) >
         timer - ((info->speed > 1) ? (DEGREES * info->speed) : 0);
}