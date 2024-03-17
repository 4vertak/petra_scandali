#include "./test.h"

int main(void) {
  int number_failed = 0;
  Suite *test[] = {test_memchr(),
                   test_memcmp(),
                   test_memcpy(),
                   test_memmove(),
                   test_strlen(),
                   test_memset(),
                   test_strncmp(),
                   test_strchr(),
                   test_strrchr(),
                   test_strncpy(),
                   test_strncat(),
                   test_strpbrk(),
                   test_strerror(),
                   test_strcspn(),
                   test_strstr(),
                   test_strtok(),
                   test_to_lower(),
                   test_to_upper(),
                   test_insert(),
                   test_trim(),
                   test_sscanf(),
                   test_sprintf(),
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
    // (number_failed != 0)
    //     ? printf("\033[31;1m=========FAILED: %d =========\033[0;0m\n",
    //              number_failed)
    //     :
    printf("\033[32;1m=========FAILED: %d =========\033[0;0m\n", number_failed);
  }

  if (number_failed == 0) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }

  // return (number_failed == 0) ? 0 : 1;
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