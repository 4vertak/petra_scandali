
#include "./test.h"

START_TEST(memchr_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = 6;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello, world!";
  int ch = 'e';
  s21_size_t len = 2;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = 2;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "Hello\n, world!";
  int ch = '\n';
  s21_size_t len = 6;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "Hello@world!";
  int ch = '@';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "Hello@world!";
  int ch = '\0';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "16022024";
  int ch = '6';
  s21_size_t len = 1;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_10) {
  char str[] = "16022024";
  int ch = '6';
  s21_size_t len = 2;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_11) {
  char str[] = "16022024";
  int ch = 54;
  ck_assert_ptr_ne(memchr(str, ch, 1), s21_memchr(str, ch, 2));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_MEMCHR=========\033[0m");

  tc = tcase_create("memchr_tc");
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);
  tcase_add_test(tc, memchr_11);

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