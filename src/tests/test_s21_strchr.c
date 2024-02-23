
#include "./test.h"

START_TEST(strchr_1) {
  char *str = "Hello, world!";
  int ch = 'H';
  ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

// START_TEST(strchr_2) {
//   char str[] = "Hello, world!";
//   int ch = 'e';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_3) {
//   char str[] = "Hello, world!";
//   int ch = '1';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_4) {
//   char str[] = "Hello, world!";
//   int ch = 101;
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_5) {
//   char str[] = "Hello, world!";
//   int ch = 'l';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_6) {
//   char str[] = "Hello\n, world!";
//   int ch = '\n';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_7) {
//   char str[] = "Hello@world!";
//   int ch = '@';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_8) {
//   char str[] = "Hello@world!";
//   int ch = '\0';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_9) {
//   char str[] = "16022024";
//   int ch = '6';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_10) {
//   char str[] = "16022024";
//   int ch = '6';
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

// START_TEST(strchr_11) {
//   char str[] = "16022024";
//   int ch = 54;
//   ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
// }
// END_TEST

Suite *test_strchr(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[32;1m=========S21_STRCHR=========\033[0m");

  tc = tcase_create("strchr_tc");
  // tcase_add_test(tc, strchr_1);
  // tcase_add_test(tc, strchr_2);
  // tcase_add_test(tc, strchr_3);
  // tcase_add_test(tc, strchr_4);
  // tcase_add_test(tc, strchr_5);
  // tcase_add_test(tc, strchr_6);
  // tcase_add_test(tc, strchr_7);
  // tcase_add_test(tc, strchr_8);
  // tcase_add_test(tc, strchr_9);
  // tcase_add_test(tc, strchr_10);
  // tcase_add_test(tc, strchr_11);

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