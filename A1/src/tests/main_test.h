#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../backend/backend.h"

// #define PRINT_DEBAG

Suite *test_backend(void);

#ifdef PRINT_DEBAG

void print_test(Maze_t *maze);

#endif

#endif  // SRC_TESTS_TEST_H_