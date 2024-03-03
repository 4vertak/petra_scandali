#include "./test.h"

START_TEST(strrchr_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello, world!";
  int ch = 'e';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "Hello, world!";
  int ch = '1';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "Hello, world!";
  int ch = 101;
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "Hello\n, world!";
  int ch = '\n';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char str[] = "Hello@world!";
  int ch = '@';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "Hello@world!";
  int ch = '\0';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_9) {
  char str[] = "16022024";
  int ch = '6';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_10) {
  char str[] = "\0";
  int ch = '6';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_11) {
  char str[] = "16022024";
  int ch = 54;
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_STRRCHR=========\033[0m");

  tc = tcase_create("strrchr_tc");
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);
  tcase_add_test(tc, strrchr_11);

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