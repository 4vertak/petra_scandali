
#include "./test.h"

START_TEST(strncat_1) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_2) {
  char str1[9] = "ab\nc";
  char str2[9] = "ab\nc";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_3) {
  char str1[9] = "ab\0c";
  char str2[9] = "ab\0c";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_4) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "de\0f";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_5) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "de\nf";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_6) {
  char str1[9] = "ab\0c";
  char str2[9] = "ab\0c";
  char str3[] = "def";
  int n = 4;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_7) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "de\0f";
  int n = 4;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_8) {
  char str1[9] = "";
  char str2[9] = "";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_9) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_10) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "def";
  int n = 3;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_11) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "def";
  int n = 3;
  ck_assert_str_eq(strncat(str1, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\n\033[37;1m=========S21_STRNCAT=========\033[0m");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);
  tcase_add_test(tc, strncat_11);

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