#include "./test.h"

START_TEST(test_abs_1) { ck_assert_int_eq(s21_abs((int)1.0L), abs((int)1.0L)); }
END_TEST

START_TEST(test_abs_2) {
  ck_assert_int_eq(s21_abs((int)-1.0L), abs((int)-1.0L));
}
END_TEST

START_TEST(test_abs_3) { ck_assert_int_eq(s21_abs((int)0L), abs((int)0L)); }
END_TEST

START_TEST(test_abs_4) { ck_assert_int_eq(s21_abs((int)-0.0), abs((int)-0.0)); }
END_TEST

START_TEST(test_abs_5) { ck_assert_int_eq(s21_abs((int)0.0), abs((int)0.0)); }
END_TEST

START_TEST(test_abs_6) { ck_assert_int_eq(s21_abs((int)0), abs((int)0)); }
END_TEST

START_TEST(test_abs_7) {
  ck_assert_int_eq(s21_abs((int)31415926535), abs((int)31415926535));
}
END_TEST

START_TEST(test_abs_8) {
  ck_assert_int_eq(s21_abs((int)-31415926535), abs((int)-31415926535));
}
END_TEST

START_TEST(test_abs_9) { ck_assert_int_eq(s21_abs((int)314), abs((int)314)); }
END_TEST

START_TEST(test_abs_10) {
  ck_assert_int_eq(s21_abs((int)-1234.456789), abs((int)-1234.456789));
}
END_TEST

START_TEST(test_abs_11) {
  ck_assert_int_eq(s21_abs((int)-314), abs((int)-314));
}
END_TEST

START_TEST(test_abs_12) {
  ck_assert_int_eq(s21_abs((int)1.0E-7), abs((int)1.0E-7));
}
END_TEST

START_TEST(test_abs_13) {
  ck_assert_int_eq(s21_abs((int)-1.0E-7), abs((int)-1.0E-7));
}
END_TEST

Suite *test_abs(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ABS |=========\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, test_abs_1);
  tcase_add_test(tc, test_abs_2);
  tcase_add_test(tc, test_abs_3);
  tcase_add_test(tc, test_abs_4);
  tcase_add_test(tc, test_abs_5);
  tcase_add_test(tc, test_abs_6);
  tcase_add_test(tc, test_abs_7);
  tcase_add_test(tc, test_abs_8);
  tcase_add_test(tc, test_abs_9);
  tcase_add_test(tc, test_abs_10);
  tcase_add_test(tc, test_abs_11);
  tcase_add_test(tc, test_abs_12);
  tcase_add_test(tc, test_abs_13);
  suite_add_tcase(s, tc);
  return s;
}