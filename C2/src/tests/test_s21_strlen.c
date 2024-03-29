
#include "./test.h"

START_TEST(strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "Hello\n, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  char str[] = "Hello@world!\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  char str[] = "Hello@world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  char str[] = "16022024";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_10) {
  char str[] = "16022024";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_11) {
  char str[] = "16022024";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *test_strlen(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21STRLEN |=========\033[0m");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_7);
  tcase_add_test(tc, strlen_8);
  tcase_add_test(tc, strlen_9);
  tcase_add_test(tc, strlen_10);
  tcase_add_test(tc, strlen_11);

  suite_add_tcase(s, tc);
  return s;
}