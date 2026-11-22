#include "test.h"

int main(void) {
  Suite *suites[] = {
      test_memchr(),   test_memcmp(),   test_memcpy(),      test_memmove(),
      test_strlen(),   test_memset(),   test_strncmp(),     test_strchr(),
      test_strrchr(),  test_strncpy(),  test_strncat(),     test_strpbrk(),
      test_strerror(), test_strcspn(),  test_strstr(),      test_strtok(),
      test_to_lower(), test_to_upper(), test_insert(),      test_trim(),
      test_sscanf(),   test_sprintf(),  test_regressions(),
  };
  SRunner *runner = srunner_create(suites[0]);
  for (size_t i = 1; i < sizeof(suites) / sizeof(*suites); ++i)
    srunner_add_suite(runner, suites[i]);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
