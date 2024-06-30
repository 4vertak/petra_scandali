#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>

#include "../backend/affine_transformations.h"
#include "../backend/loader.h"

// загрузчик:
Suite *test_loader(void);
Suite *affine_transformations(void);

#endif  // SRC_TESTS_TEST_H_
