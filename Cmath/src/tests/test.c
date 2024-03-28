#include "./test.h"

int main(void) {
  int number_failed = 0;
  Suite *test[] = {
      test_abs(),       test_fabs(),    test_fmod(), test_atan(), test_ceil(),
      test_pow(),       test_floor(),   test_cos(),  test_exp(),  test_floor(),
      test_factorial(), test_pow_int(), test_acos(), test_asin(), test_log(),
      test_sqrt(),      test_sin(),     test_tan(),  NULL};
  SRunner *sr;
  int i = 0;
  while (test[i] != NULL) {
    sr = srunner_create(test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    i++;
    // (number_failed != 0)
    //     ? printf("\033[31;1m=========FAILED: %d =========\033[0;0m\n",
    //              number_failed)
    //     :
    printf("\033[32;1m=========FAILED: %d =========\033[0;0m\n", number_failed);
  }

  // if (number_failed == 0) {
  //   return EXIT_SUCCESS;
  // } else {
  //   return EXIT_FAILURE;
  // }

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

// int main(void) {
//   int number_failed;
//   Suite *s;
//   SRunner *sr;

//   s = money_suite();
//   sr = srunner_create(s);

//   srunner_run_all(sr, CK_NORMAL);
//   number_failed = srunner_ntests_failed(sr);
//   srunner_free(sr);
//   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
// }