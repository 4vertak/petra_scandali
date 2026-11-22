#include "test.h"

START_TEST(token_sequence) {
  const char *inputs[] = {"Hello, world!",
                          ",hi;;there!",
                          ",;!,",
                          " ",
                          "",
                          "Hello, World, BYE, MOON!",
                          "no-delimiters",
                          "a,b;c d",
                          "whole string"};
  const char *first[] = {", ", ",;!", ",;!", " ", "", ",! ", ".,", ",", ""};
  const char *rest[] = {", ", ",;!", "", "", "", ",! ", " ", "; ", ""};
  char expected[64], actual[64];
  strcpy(expected, inputs[_i]);
  strcpy(actual, inputs[_i]);
  char *ref = strtok(expected, first[_i]);
  char *got = s21_strtok(actual, first[_i]);
  while (ref) {
    ck_assert_ptr_nonnull(got);
    ck_assert_int_eq(ref - expected, got - actual);
    ck_assert_str_eq(ref, got);
    ref = strtok(NULL, rest[_i]);
    got = s21_strtok(NULL, rest[_i]);
  }
  ck_assert_ptr_null(got);
  ck_assert_ptr_null(s21_strtok(NULL, rest[_i]));
}
END_TEST

START_TEST(restart_tokenization) {
  char old[] = "one two", fresh[] = "new:end";
  ck_assert_str_eq(s21_strtok(old, " "), "one");
  ck_assert_str_eq(s21_strtok(fresh, ":"), "new");
  ck_assert_str_eq(s21_strtok(NULL, ""), "end");
  ck_assert_ptr_null(s21_strtok(NULL, ""));
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("strtok");
  TCase *tc = tcase_create("tokens");
  tcase_add_loop_test(tc, token_sequence, 0, 9);
  tcase_add_test(tc, restart_tokenization);
  suite_add_tcase(s, tc);
  return s;
}
