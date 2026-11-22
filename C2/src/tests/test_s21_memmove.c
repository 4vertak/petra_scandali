#include "./test.h"

START_TEST(memmove_1) {
  char str[] = "ABCDEFGHKL";
  char expected[sizeof(str)];
  memcpy(expected, str, sizeof(str));
  memmove(expected + 2, expected + 4, 5);
  ck_assert_ptr_eq(s21_memmove(str + 2, str + 4, 5), str + 2);
  ck_assert_mem_eq(str, expected, sizeof(str));
}
END_TEST

START_TEST(memmove_2) {
  char str[] = "ABCDEFGHKL";
  char expected[sizeof(str)];
  memcpy(expected, str, sizeof(str));
  memmove(expected + 5, expected + 1, 0);
  ck_assert_ptr_eq(s21_memmove(str + 5, str + 1, 0), str + 5);
  ck_assert_mem_eq(str, expected, sizeof(str));
}
END_TEST

START_TEST(memmove_3) {
  char str[] = "ABCDEFGHKL";
  char expected[sizeof(str)];
  memcpy(expected, str, sizeof(str));
  memmove(expected + 1, expected, 4);
  ck_assert_ptr_eq(s21_memmove(str + 1, str, 4), str + 1);
  ck_assert_mem_eq(str, expected, sizeof(str));
}
END_TEST

Suite *test_memmove(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m==========| S21MEMMOV |=========\033[0m");

  tc = tcase_create("memmove");
  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);

  suite_add_tcase(s, tc);
  return s;
}