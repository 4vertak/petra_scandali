#include "./test.h"

START_TEST(test_fabs_1) {
  int i = 0;
  if (s21_fabs(1.0L) == fabs(1.0L)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_2) {
  int i = 0;
  if (s21_fabs(-1.0L) == fabs(-1.0L)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_3) {
  int i = 0;
  if (s21_fabs(0L) == fabs(0L)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_4) {
  int i = 0;
  if (s21_fabs(-0.0) == fabs(-0.0)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_5) {
  int i = 0;
  if (s21_fabs(0.0) == fabs(0.0)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_6) {
  int i = 0;
  if (s21_fabs(0) == fabs(0)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_7) {
  int i = 0;
  if (s21_fabs(3.1415926535) == fabs(3.1415926535)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_8) {
  int i = 0;
  if (s21_fabs(-3.1415926535) == fabs(-3.1415926535)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_9) {
  int i = 0;
  if (s21_fabs(314) == fabs(314)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_10) {
  int i = 0;
  if (s21_fabs(-1234.4567890123) == fabs(-1234.4567890123)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_11) {
  int i = 0;
  if (s21_fabs(-314) == fabs(-314)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_12) {
  int i = 0;
  if (s21_fabs(1.0E-7) == fabs(1.0E-7)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_13) {
  int i = 0;
  if (s21_fabs(-1.0E-7) == fabs(-1.0E-7)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_14) {
  int i = 0;
  if (s21_fabs(-0.5) == fabs(-0.5)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_15) {
  int i = 0;
  if (s21_fabs(1.5) == fabs(1.5)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_16) {
  int i = 0;
  if (s21_fabs(-1.5) == fabs(-1.5)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_17) {
  int i = 0;
  if (s21_fabs(1234.567891) == fabs(1234.567891)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_18) {
  int i = 0;
  if (s21_fabs(-1234.567891) == fabs(-1234.567891)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_19) {
  int i = 0;
  if (s21_fabs(1L) == fabs(1L)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_20) {
  int i = 0;
  if (s21_fabs(-0.1) == fabs(-0.1)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_21) {
  int i = 0;
  if (s21_fabs(1.57079632679489661923) == fabs(1.57079632679489661923)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

START_TEST(test_fabs_22) {
  int i = 0;
  if (s21_fabs(-1.57079632679489661923) == fabs(-1.57079632679489661923)) i = 1;
  ck_assert_int_eq(i, 1);
}
END_TEST

Suite *test_fabs(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21FABS |=========\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, test_fabs_1);
  tcase_add_test(tc, test_fabs_2);
  tcase_add_test(tc, test_fabs_3);
  tcase_add_test(tc, test_fabs_4);
  tcase_add_test(tc, test_fabs_5);
  tcase_add_test(tc, test_fabs_6);
  tcase_add_test(tc, test_fabs_7);
  tcase_add_test(tc, test_fabs_8);
  tcase_add_test(tc, test_fabs_9);
  tcase_add_test(tc, test_fabs_10);
  tcase_add_test(tc, test_fabs_11);
  tcase_add_test(tc, test_fabs_12);
  tcase_add_test(tc, test_fabs_13);
  tcase_add_test(tc, test_fabs_14);
  tcase_add_test(tc, test_fabs_15);
  tcase_add_test(tc, test_fabs_16);
  tcase_add_test(tc, test_fabs_17);
  tcase_add_test(tc, test_fabs_18);
  tcase_add_test(tc, test_fabs_19);
  tcase_add_test(tc, test_fabs_20);
  tcase_add_test(tc, test_fabs_21);
  tcase_add_test(tc, test_fabs_22);
  suite_add_tcase(s, tc);
  return s;
}