#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>

#include "../c_mod/affine_func.h"
#include "../c_mod/loader.h"

#define RED "\033[0;31m"
#define ORANGE "\033[1;33m"
#define GREEN "\033[0;32m"

// загрузчик:
Suite *test_loader(void);
Suite *affine_transformations(void);

#endif  // SRC_TESTS_TEST_H_
