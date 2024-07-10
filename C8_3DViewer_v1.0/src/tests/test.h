#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>

#include "../c_mod/affine_func.h"
#include "../c_mod/loader.h"

// загрузчик:
Suite *test_loader(void);
Suite *affine_transformations(void);

#endif  // SRC_TESTS_TEST_H_
