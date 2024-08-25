#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../brick_game/tetris/include/fsm.h"
#include "../brick_game/tetris/include/gamelogic.h"

// #define DEBAG

Suite *test_shapes(void);
Suite *test_fsm(void);
Suite *test_backend(void);
Suite *test_database(void);

#endif  // SRC_TESTS_TEST_H_