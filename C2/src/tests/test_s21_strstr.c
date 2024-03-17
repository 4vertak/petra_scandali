
#include "./test.h"

START_TEST(strstr_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  char str1[] = "Hello, world!";
  char str2[] = "";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  char str1[] = "";
  char str2[] = "Hello, world!";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  char str1[] = "Bye, Moon, Moon!";
  char str2[] = "Moon";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  char str1[] = "Bye, Moon!";
  char str2[] = "World";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_6) {
  char str1[] = "Bye, Moon!";
  char str2[] = "Bye";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_7) {
  char str1[] = "qwerty";
  char str2[] = "qwertyq";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_8) {
  char str1[] = "qwerty";
  char str2[] = "qwerty";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_9) {
  char str1[] = "asd";
  char str2[] = "dsa";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_10) {
  char str1[] = "asd";
  char str2[] = "S";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21STRSTR |=========\033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);

  suite_add_tcase(s, tc);
  return s;
}