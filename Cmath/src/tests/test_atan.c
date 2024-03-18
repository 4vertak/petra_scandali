#include "./test.h"

START_TEST(test_atan_1) {
  long double num = 1.000000;
  for (long double i = 0.000001; i < 1000; i *= 2) {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    double x = s21_atan(num);
    double y = atan(num);
    snprintf(str1, sizeof(str1), "%.6lf", x);
    snprintf(str2, sizeof(str1), "%.6lf", y);
    ck_assert_str_eq(str1, str2);
    printf("i=%Lf\n", i);
    printf("num=%Lf\n", num);
    printf("x:%f\n y:%f\n", x, y);
    printf("%s\n", str1);
    printf("%s\n\n", str2);
    num -= i;
  }
}
END_TEST

Suite *test_atan(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ATAN |=========\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, test_atan_1);
  suite_add_tcase(s, tc);
  return s;
}