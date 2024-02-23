
#include "./test.h"

START_TEST(memset_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = 6;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_2) {
  char str[] = "Hello, world!";
  int ch = 'e';
  s21_size_t len = 2;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_3) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_4) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = 2;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_6) {
  char str[] = "Hello\n, world!";
  int ch = '\n';
  s21_size_t len = 6;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_7) {
  char str[] = "Hello@world!";
  int ch = '@';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_8) {
  char str[] = "Hello@world!";
  int ch = '\0';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_9) {
  char str[] = "16022024";
  int ch = '6';
  s21_size_t len = 1;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_10) {
  char str[] = "16022024";
  int ch = '6';
  s21_size_t len = 2;
  ck_assert_ptr_eq(memset(str, ch, len), s21_memset(str, ch, len));
}
END_TEST

START_TEST(memset_11) {
  char str[] = "16022024";
  int ch = 54;
  ck_assert_ptr_eq(memset(str, ch, 1), s21_memset(str, ch, 2));
}
END_TEST

Suite *test_memset(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_MEMSET=========\033[0m");

  tc = tcase_create("memset_tc");
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);
  tcase_add_test(tc, memset_7);
  tcase_add_test(tc, memset_8);
  tcase_add_test(tc, memset_9);
  tcase_add_test(tc, memset_10);
  tcase_add_test(tc, memset_11);

  suite_add_tcase(s, tc);
  return s;
}