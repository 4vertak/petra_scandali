#include "./test.h"

START_TEST(test_asin_1) {
  double num = -1.000001;
  for (long double i = 0.000001; i < 3; i *= 2) {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    double x = s21_asin(num);
    double y = asin(num);
    snprintf(str1, sizeof(str1), "%.6lf", x);
    snprintf(str2, sizeof(str1), "%.6lf", y);
    ck_assert_str_eq(str1, str2);
    printf("i=%Lf\n", i);
    printf("num=%f\n", num);
    printf("x:%f\n y:%f\n", x, y);
    printf("%s\n", str1);
    printf("%s\n\n", str2);
    num += i;
  }
}
END_TEST

Suite *test_asin(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_ASIN |=========\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, test_asin_1);
  suite_add_tcase(s, tc);
  return s;
}