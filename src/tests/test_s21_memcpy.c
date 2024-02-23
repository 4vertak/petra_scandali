
#include "./test.h"

START_TEST(memcpy_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "Hello";
  s21_size_t len = 5;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "H";
  s21_size_t len = 0;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_3) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "\0";
  s21_size_t len = strlen(str3);
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "\0";
  s21_size_t len = 1;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_5) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "He";
  s21_size_t len = 3;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_6) {
  char str1[15] = "";
  char str2[15] = "";
  char str3[] = "12345678901234";
  // memcpy(str1, str3, len) == "123456789012341234567890123412345678901234";
  // s21_memcpy(str2, str3, len) == "1234567890123412345678901234";
  s21_size_t len = strlen(str3);
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_7) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "Hello@world!";
  s21_size_t len = strlen(str3);
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_8) {
  char str1[13] = "";
  char str2[13] = "";
  char str3[] = "Hello@world!";
  s21_size_t len = strlen(str3);
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_9) {
  char str1[] = "23\022024";
  char str2[] = "23\022024";
  char str3[] = "Hello!";
  s21_size_t len = 6;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_10) {
  char str1[] = "23022024";
  char str2[] = "23022024";
  char str3[] = "Hel";
  s21_size_t len = 3;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

START_TEST(memcpy_11) {
  char str1[] = "Hello,  world!";
  char str2[] = "Hello,  world!";
  char str3[] = "23 \0 02 \0 2024";
  s21_size_t len = 15;
  ck_assert_str_eq(memcpy(str1, str3, len), s21_memcpy(str2, str3, len));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\n\033[37;1m=========S21_MEMCPY=========\033[0m");
  TCase *tc = tcase_create("memcpy_tc");
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);
  tcase_add_test(tc, memcpy_10);
  tcase_add_test(tc, memcpy_11);

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