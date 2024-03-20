#include "./test.h"

START_TEST(test_acos_1) {
  double num = -1.000001;
  for (long double i = 0.000001; i < 3; i *= 2) {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    double x = s21_acos(num);
    double y = acos(num);
    snprintf(str1, sizeof(str1), "%.6lf", x);
    snprintf(str2, sizeof(str1), "%.6lf", y);
    ck_assert_str_eq(str1, str2);
    num += i;
  }
}
END_TEST

Suite *test_acos(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ACOS |=========\033[0m");
  TCase *tc = tcase_create("acos_tc");

  tcase_add_test(tc, test_acos_1);
  suite_add_tcase(s, tc);
  return s;
}