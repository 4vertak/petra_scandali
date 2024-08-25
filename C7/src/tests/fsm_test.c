#include "./main_test.h"

void setup(void) {
  GameState_t *state = currentState();
  *state = START;  // Сброс состояния игры
}

START_TEST(test_userInput_start) {
  GameState_t *state = currentState();
  bool hold = true;

  userInput(Start, hold);
  ck_assert_int_eq(*state, SPAWN);

  *state = PAUSE;
  userInput(Start, hold);
  ck_assert_int_ne(*state, PAUSE);

  *state = SAVE;
  userInput(Start, hold);
  ck_assert_int_ne(*state, SAVE);

  *state = LOADING;
  userInput(Start, hold);
  ck_assert_int_ne(*state, SAVE);

  *state = GAME_OVER;
  userInput(Start, hold);
  ck_assert_int_eq(*state, START);
  *state = OPTIONS;
  userInput(Start, hold);
  ck_assert_int_eq(*state, OPTIONS);
}
END_TEST

START_TEST(test_userInput_pause) {
  GameState_t *state = currentState();
  bool hold = true;

  *state = MOVING;
  userInput(Pause, hold);
  ck_assert_int_eq(*state, PAUSE);

  *state = MOVE;
  userInput(Pause, hold);
  ck_assert_int_eq(*state, PAUSE);
  *state = SAVE;
  userInput(Pause, hold);
  ck_assert_int_ne(*state, PAUSE);
}
END_TEST

START_TEST(test_userInput_saveLoad) {
  GameState_t *state = currentState();
  bool hold = true;

  *state = MOVING;
  userInput(SaveLoad, hold);
  ck_assert_int_eq(*state, SAVE);

  *state = MOVE;
  userInput(SaveLoad, hold);
  ck_assert_int_eq(*state, SAVE);

  *state = START;
  userInput(SaveLoad, hold);
  ck_assert_int_eq(*state, LOADING);
}
END_TEST

START_TEST(test_userInput_options) {
  GameState_t *state = currentState();
  bool hold = true;

  *state = MOVING;
  userInput(Options, hold);
  ck_assert_int_eq(*state, OPTIONS);

  *state = MOVE;
  userInput(Options, hold);
  ck_assert_int_eq(*state, OPTIONS);

  *state = START;
  userInput(Options, hold);
  ck_assert_int_eq(*state, OPTIONS);

  *state = ATTACHING;
  userInput(Options, hold);
  ck_assert_int_eq(*state, ATTACHING);
}
END_TEST

START_TEST(test_userInput_terminate) {
  GameState_t *state = currentState();
  bool hold = true;

  *state = START;
  userInput(Terminate, hold);
  ck_assert_int_eq(*state, EXIT_STATE);
  ck_assert_int_ne(*state, GAME_OVER);

  *state = PAUSE;
  userInput(Terminate, hold);
  ck_assert_int_eq(*state, EXIT_STATE);

  *state = OPTIONS;
  userInput(Terminate, hold);
  ck_assert_int_ne(*state, OPTIONS);

  *state = LOADING;
  userInput(Terminate, hold);
  ck_assert_int_eq(*state, START);
}
END_TEST

// Тест для функции handleStartAction (начало игры)
START_TEST(test_userInput_up) {
  GameState_t *state = currentState();
  GameInfo_t *info = gameInfo();
  bool hold = true;

  *state = MOVING;
  userInput(Up, hold);
  ck_assert_int_eq(info->speed, 2);
  ck_assert_int_ne(info->speed, 1);

  *state = MOVE;
  userInput(Up, hold);
  ck_assert_int_eq(info->speed, 3);
  ck_assert_int_ne(info->speed, 2);

  info->speed = 10;
  userInput(Up, hold);
  ck_assert_int_eq(info->speed, 10);
  ck_assert_int_ne(info->speed, 11);

  *state = START;
  info->speed = 0;
  userInput(Up, hold);
  ck_assert_int_eq(info->speed, 0);
  ck_assert_int_ne(info->speed, 1);
}
END_TEST

// Тест для функции moveLeft
START_TEST(test_userInput_left) {
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  bool hold = true;

  *state = MOVING;

  // Выполнение перемещения влево
  userInput(Left, hold);
  ck_assert_int_eq(current->col, 0);
}
END_TEST

START_TEST(test_userInput_right) {
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  bool hold = true;

  *state = MOVING;

  // Выполнение перемещения влево
  userInput(Right, hold);
  ck_assert_int_eq(current->col, 0);
}
END_TEST

START_TEST(test_userInput_down) {
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  bool hold = true;

  *state = MOVING;

  // Выполнение перемещения влево
  userInput(Down, hold);
  ck_assert_int_eq(current->row, 0);
}
END_TEST

START_TEST(test_userInput_action) {
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  bool hold = true;

  *state = MOVING;

  // Выполнение перемещения влево
  userInput(Action, hold);
  ck_assert_int_eq(current->col, 0);
  ck_assert_int_eq(current->row, 0);
}
END_TEST

START_TEST(test_userInput_holdFalse) {
  GameState_t *state = currentState();
  Shape_t *current = currentShape();
  bool hold = false;

  *state = MOVE;

  // Выполнение перемещения влево
  userInput(NOSIG, hold);
  ck_assert_int_eq(current->col, 0);
  ck_assert_int_eq(current->row, 1);

  *state = MOVING;

  // Выполнение перемещения влево
  userInput(NOSIG, hold);
  ck_assert_int_eq(current->col, 0);
  ck_assert_int_eq(current->row, 1);
}
END_TEST

// Тест для функции handleStartAction (игра завершена)
START_TEST(test_updateCurrentState_MOVE) {
  GameState_t *state = currentState();
  *state = MOVE;

  updateCurrentState();
  ck_assert_int_eq(*state, MOVING);

  *state = LOADING;

  updateCurrentState();
  ck_assert_int_eq(*state, START);

  *state = SAVE;

  updateCurrentState();
  ck_assert_int_eq(*state, SAVE);

  *state = MOVING;

  updateCurrentState();
  ck_assert_int_eq(*state, ATTACHING);
}
END_TEST

// Тест для функции handlePauseAction
START_TEST(test_handlePauseAction_MOVING) {
  GameState_t *state = currentState();
  *state = MOVING;
  GameInfo_t info = {0};  // Инициализация GameInfo_t

  handlePauseAction(state, &info);
  ck_assert_int_eq(info.pause,
                   MOVING);  // Проверка, что состояние паузы установлено
  ck_assert_int_eq(*state,
                   PAUSE);  // Проверка, что состояние изменилось на PAUSE
}
END_TEST

Suite *test_fsm(void) {
  Suite *s = suite_create("\n\033[37;1m==========| TEST_FSM |=========\033[0m");
  TCase *tc = tcase_create("tc_fsm");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_userInput_start);
  tcase_add_test(tc, test_userInput_pause);
  tcase_add_test(tc, test_userInput_saveLoad);
  tcase_add_test(tc, test_userInput_options);
  tcase_add_test(tc, test_userInput_terminate);
  tcase_add_test(tc, test_userInput_up);
  tcase_add_test(tc, test_userInput_left);
  tcase_add_test(tc, test_userInput_right);
  tcase_add_test(tc, test_userInput_down);
  tcase_add_test(tc, test_userInput_action);
  tcase_add_test(tc, test_userInput_holdFalse);

  tcase_add_test(tc, test_updateCurrentState_MOVE);
  tcase_add_test(tc, test_handlePauseAction_MOVING);

  return s;
}