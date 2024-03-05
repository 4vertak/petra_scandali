
#include "./test.h"

START_TEST(test_memmove_1) {
  char dest[100] = "abcdef";
  char dest2[100] = "abcdef";
  ck_assert_msg(
      memcmp(s21_memmove(dest, "ba", 2), memmove(dest2, "ba", 2), 99) == 0,
      "FAILURE!");
  ck_assert_msg(memcmp(s21_memmove(dest, dest + 2, 2),
                       memmove(dest2, dest2 + 2, 2), 99) == 0,
                "FAILURE!");
  ck_assert_msg(
      memcmp(s21_memmove(dest, "", 0), memmove(dest2, "", 0), 99) == 0,
      "FAILURE! Test ");
}
END_TEST
Suite *test_memmove(void) {
  Suite *s = suite_create("\n\033[37;1m=========S21_MEMMOVE=========\033[0m");
  TCase *tc = tcase_create("memmove_tc");
  tcase_add_test(tc, test_memmove_1);

  suite_add_tcase(s, tc);
  return s;
}

// Suite * Money_suite (void)
//  {
//      Suite *s;
//      TCase *tc_core;
//      TCase *tc_limits;

//      s = suite_create("Деньги");

//      /* Основной тестовый пример */
//      tc_core = tcase_create("Core");

// + tcase_add_checked_fixture(tc_core, setup, демонтаж);
//      tcase_add_test (tc_core, test_money_create);
//      suite_add_tcase(s, tc_core);

//      /* Тестовый пример ограничений */
//      tc_limits = tcase_create("Limits");

//      tcase_add_test(tc_limits, test_money_create_neg);
//      tcase_add_test(tc_limits, test_money_create_zero);
//      suite_add_tcase(s, tc_limits);

//      вернуть с;
//  }