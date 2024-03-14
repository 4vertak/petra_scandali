#include "./test.h"

int main(void) {
  int number_failed = 0;
  Suite *test[] = {
      test_memchr(),   test_memcmp(),   test_memcpy(),  test_memmove(),
      test_strlen(),   test_memset(),   test_strncmp(), test_strchr(),
      test_strrchr(),  test_strncpy(),  test_strncat(), test_strpbrk(),
      test_strerror(), test_strcspn(),  test_strstr(),  test_strtok(),
      test_to_lower(), test_to_upper(), test_insert(),  test_trim(),
      test_sprintf(),  s21_NULL};
  SRunner *sr;
  int i = 0;
  while (test[i] != s21_NULL) {
    sr = srunner_create(test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    i++;

    printf("\033[32;1m==========| FAILED: %d |=========\033[0;0m\n",
           number_failed);  //  number_failed равна 0 то цвет зеленый
  }

  return (number_failed == 0) ? 0 : 1;
}
