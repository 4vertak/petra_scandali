#include "./test.h"

START_TEST(test_fmod_0) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1.0, -3);
  double y = fmod(1.0, -3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_1) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1.0 / 0.0, 3);
  double y = fmod(1.0 / 0.0, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_2) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1.0, 3);
  double y = fmod(-1.0, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_3) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.0, 3);
  double y = fmod(0.0, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_4) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-0.0, 3);
  double y = fmod(-0.0, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_5) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0, 3);
  double y = fmod(0, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_6) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0L, 3);
  double y = fmod(0L, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_7) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1, 3);
  double y = fmod(1, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_8) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1, 3);
  double y = fmod(-1, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_9) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(314, 3);
  double y = fmod(314, 3);
  snprintf(str1, sizeof(str1), "%16.6lf", x);
  snprintf(str2, sizeof(str1), "%16.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_10) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-314, 3);
  double y = fmod(-314, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_11) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(314159, 3);
  double y = fmod(314159, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_12) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-314159.2, 3);
  double y = fmod(-314159.2, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_13) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.7, 3);
  double y = fmod(0.7, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_14) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-0.7, 3);
  double y = fmod(-0.7, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_15) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1.5, 3);
  double y = fmod(1.5, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_16) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1.5, 3);
  double y = fmod(-1.5, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_17) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1570.796326, 3);
  double y = fmod(1570.796326, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_18) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1570.796326, 3);
  double y = fmod(-1570.796326, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_19) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(3, 3);
  double y = fmod(3, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_20) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-3, 3);
  double y = fmod(-3, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_21) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.3425443513423432432432, 3);
  double y = fmod(0.3425443513423432432432, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_22) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-0.3425443513423432432432, 3);
  double y = fmod(-0.3425443513423432432432, 3);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_23) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1, 2.5);
  double y = fmod(1, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_24) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1.0, 2.5);
  double y = fmod(-1.0, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_25) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.0, 2.5);
  double y = fmod(0.0, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_26) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-0.0, 2.5);
  double y = fmod(-0.0, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_27) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0, 2.5);
  double y = fmod(0, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_28) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0L, 2.5);
  double y = fmod(0L, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_29) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1, 2.5);
  double y = fmod(1, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_30) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1, 2.5);
  double y = fmod(-1, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_31) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1, 2.5);
  double y = fmod(1, 2.5);
  snprintf(str1, sizeof(str1), "%16.6lf", x);
  snprintf(str2, sizeof(str1), "%16.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_32) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1, 2.5);
  double y = fmod(1, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_33) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(314159, 2.5);
  double y = fmod(314159, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_34) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-0.0000001, 2.5);
  double y = fmod(-0.0000001, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_35) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.3, 2.5);
  double y = fmod(0.3, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_36) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.1, 2.5);
  double y = fmod(0.1, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_37) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-3.1, 2.5);
  double y = fmod(-3.1, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_38) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(0.5, 2.5);
  double y = fmod(0.5, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_39) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(3.14159265358979323846, 2.5);
  double y = fmod(3.14159265358979323846, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_40) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1570.796326, 2.5);
  double y = fmod(-1570.796326, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_41) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(1.0E-7, 2.5);
  double y = fmod(1.0E-7, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_fmod_42) {
  char str1[69] = {'\0'};
  char str2[69] = {'\0'};
  double x = s21_fmod(-1.0E-7, 2.5);
  double y = fmod(-1.0E-7, 2.5);
  snprintf(str1, sizeof(str1), "%.6lf", x);
  snprintf(str2, sizeof(str1), "%.6lf", y);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_fmod(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21FMOD |=========\033[0m");
  TCase *tc = tcase_create("fmod_tc");

  tcase_add_test(tc, test_fmod_0);
  tcase_add_test(tc, test_fmod_1);
  tcase_add_test(tc, test_fmod_2);
  tcase_add_test(tc, test_fmod_3);
  tcase_add_test(tc, test_fmod_4);
  tcase_add_test(tc, test_fmod_5);
  tcase_add_test(tc, test_fmod_6);
  tcase_add_test(tc, test_fmod_7);
  tcase_add_test(tc, test_fmod_8);
  tcase_add_test(tc, test_fmod_9);
  tcase_add_test(tc, test_fmod_10);
  tcase_add_test(tc, test_fmod_11);
  tcase_add_test(tc, test_fmod_12);
  tcase_add_test(tc, test_fmod_13);
  tcase_add_test(tc, test_fmod_14);
  tcase_add_test(tc, test_fmod_15);
  tcase_add_test(tc, test_fmod_16);
  tcase_add_test(tc, test_fmod_17);
  tcase_add_test(tc, test_fmod_18);
  tcase_add_test(tc, test_fmod_19);
  tcase_add_test(tc, test_fmod_20);
  tcase_add_test(tc, test_fmod_21);
  tcase_add_test(tc, test_fmod_22);
  tcase_add_test(tc, test_fmod_23);
  tcase_add_test(tc, test_fmod_24);
  tcase_add_test(tc, test_fmod_25);
  tcase_add_test(tc, test_fmod_26);
  tcase_add_test(tc, test_fmod_27);
  tcase_add_test(tc, test_fmod_28);
  tcase_add_test(tc, test_fmod_29);
  tcase_add_test(tc, test_fmod_30);
  tcase_add_test(tc, test_fmod_31);
  tcase_add_test(tc, test_fmod_32);
  tcase_add_test(tc, test_fmod_33);
  tcase_add_test(tc, test_fmod_34);
  tcase_add_test(tc, test_fmod_35);
  tcase_add_test(tc, test_fmod_36);
  tcase_add_test(tc, test_fmod_37);
  tcase_add_test(tc, test_fmod_38);
  tcase_add_test(tc, test_fmod_39);
  tcase_add_test(tc, test_fmod_40);
  tcase_add_test(tc, test_fmod_41);
  tcase_add_test(tc, test_fmod_42);
  suite_add_tcase(s, tc);
  return s;
}