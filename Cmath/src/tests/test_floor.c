#include "./test.h"

START_TEST(floor_test_1) {
    ck_assert_double_eq(s21_floor(-0.1), floor(-0.1));
}
END_TEST;

START_TEST(floor_test_2) {
    ck_assert_double_eq(s21_floor(0.1), floor(0.1));
}
END_TEST;

START_TEST(floor_test_3) {
    ck_assert_double_eq(s21_floor(-1), floor(-1));
}
END_TEST;

Suite *test_floor(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_FLOOR |=========\033[0m");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, floor_test_1);
  tcase_add_test(tc, floor_test_2);
  tcase_add_test(tc, floor_test_3);
  suite_add_tcase(s, tc);
  return s;
}