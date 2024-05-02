#include "./test.h"

int main(void) {
  int number_failed = 0;
  Suite *test[] = {test_from_decimal_to_float(), test_from_decimal_to_int(),
                   test_from_int_to_decimal(), test_from_float_to_decimal(),
                   NULL};
  SRunner *sr;
  int i = 0;
  while (test[i] != NULL) {
    sr = srunner_create(test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    i++;
    (number_failed != 0)
        ? printf("\033[31;1m=========FAILED: %d =========\033[0;0m\n",
                 number_failed)
        : printf("\033[32;1m=========FAILED: %d =========\033[0;0m\n",
                 number_failed);
  }

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}