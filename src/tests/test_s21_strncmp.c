
#include "./test.h"

START_TEST(strncmp_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  s21_size_t n = 14;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  s21_size_t n = 2;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "Hello@world!";
  char str2[] = "Hello, world!";
  s21_size_t n = 4;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "Hello@world!";
  char str2[] = "Hello@world!";
  s21_size_t n = 13;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "Hello\n, world!";
  char str2[] = "Hello\n, world!";
  s21_size_t n = 15;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] =
      "These are the functions that will make our lives easier! You know, "
      "deciphering Enigma by brute force…I'd rather marry Joan than we do "
      "that. Therefore, it seems that we need to keep analysing texts, looking "
      "for patterns and coincidences. And so, we\\’ll have to come up with "
      "various algorithms related to the processing of that very text and "
      "describe them. That is why we need a number of functions to help us "
      "with that. I'm working on them now.";
  char str2[] =
      "These are the functions that will make our lives easier! You know, "
      "deciphering Enigma by brute force…I'd rather marry Joan than we do "
      "that. Therefore, it seems that we need to keep analysing texts, looking "
      "for patterns and coincidences. And so, we\\’ll have to come up with "
      "various algorithms related to the processing of that very text and "
      "describe them. That is why we need a number of functions to help us "
      "with that. I'm working on them now.";
  s21_size_t n = 200;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char str1[] =
      "These are the functions that will make our lives easier! You know, "
      "deciphering Enigma by brute force…I'd rather marry Joan than we do "
      "that. Therefore, it seems that we need to keep analysing texts, looking "
      "for patterns and coincidences. And so, we\\’ll have to come up with "
      "various algorithms related to the processing of that very text and "
      "describe them. That is why we need a number of functions to help us "
      "with that. I'm working on them now.";
  char str2[] =
      "These are the functions that will make our lives easier! You know, "
      "deciphering Enigma by brute force…I'd rather marry Joan than we do "
      "that. Therefore, it seems that we need to keep analysing texts, looking "
      "for patterns and coincidences. And so, we\\’ll have to come up with "
      "various algorithms related to the processing of that very text and "
      "describe them. That is why we need a number of functions to help us "
      "with that. I'm working on them now.";
  s21_size_t n = 448;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  char str1[] = "2002world!";
  char str2[] = "2002world!";
  s21_size_t n = 11;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  char str1[] = "2002 world";
  char str2[] = "2002 ";
  s21_size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_10) {
  char str1[] = "2002 world";
  char str2[] = "2002 world";
  s21_size_t n = 8;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_11) {
  char str1[] = "20022024!";
  char str2[] = "20022024!";
  s21_size_t n = 10;
  ck_assert_int_eq(strncmp(str1, str2, 1), s21_strncmp(str1, str2, 2));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_STRNCMP=========\033[0m");
  tc = tcase_create("strncmp_tc");
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  tcase_add_test(tc, strncmp_11);

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