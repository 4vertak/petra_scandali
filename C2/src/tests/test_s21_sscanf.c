#include <check.h>
#include <string.h>

#include "./test.h"

#define LEN 4096

START_TEST(sscanf_test_c_1) {  // спецификатор c обычные ситуации
  char str_1[LEN] = "ab";
  char str_2[LEN] = "     ab ";
  char str_3[LEN] = "     a   b ";
  char a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%c", &a1), s21_sscanf(str_1, "%c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%c", &a1), s21_sscanf(str_2, "%c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "  %c", &a1), s21_sscanf(str_2, "  %c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c%c", &a1, &b1),
                   s21_sscanf(str_3, "%c%c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "    %c%c", &a1, &b1),
                   s21_sscanf(str_3, "    %c%c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c  %c", &a1, &b1),
                   s21_sscanf(str_3, "%c  %c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c  %c ", &a1, &b1),
                   s21_sscanf(str_3, "%c  %c ", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_c_2) {  // спецификатор c +длина+ширина
  char str_1[LEN] = "ab";
  char str_2[LEN] = "     ab ";
  char str_3[LEN] = "     a   b ";
  wchar_t a1 = 0, a2 = 0, d1 = 0, d2 = 0;
  char b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%lc", &a1), s21_sscanf(str_1, "%lc", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1c", &b1), s21_sscanf(str_1, "%1c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2c", &b1), s21_sscanf(str_1, "%2c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%1c%1c ", &b1, &c1),
                   s21_sscanf(str_2, "%1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, " %1c%1c ", &b1, &c1),
                   s21_sscanf(str_2, " %1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %1c%1c ", &b1, &c1),
                   s21_sscanf(str_3, " %1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%1c%1c ", &b1, &c1),
                   s21_sscanf(str_3, "%1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %lc%lc ", &a1, &d1),
                   s21_sscanf(str_3, " %lc%lc ", &a2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %lc%lc ", &a1, &d1),
                   s21_sscanf(str_3, " %lc%lc ", &a2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, d1 = 0, d2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_1) {  // спецификатор d обычные ситуации
  char str_1[LEN] = "ab";
  char str_2[LEN] = "123";
  char str_3[LEN] = "1b";
  char str_4[LEN] = "b1";
  char str_5[LEN] = "123 123";
  char str_6[LEN] = "123 1b";
  char str_7[LEN] = "1b 123";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  // ck_assert_int_eq(sscanf(str_1, "%d", &a1), s21_sscanf(str_1, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d", &a1), s21_sscanf(str_2, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d", &a1), s21_sscanf(str_3, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d", &a1), s21_sscanf(str_4, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d%d", &a1, &b1),
                   s21_sscanf(str_1, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d%d", &a1, &b1),
                   s21_sscanf(str_2, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d%d", &a1, &b1),
                   s21_sscanf(str_3, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d%d", &a1, &b1),
                   s21_sscanf(str_4, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%d%d", &a1, &b1),
                   s21_sscanf(str_5, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%d%d", &a1, &b1),
                   s21_sscanf(str_6, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%d%d", &a1, &b1),
                   s21_sscanf(str_7, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

// START_TEST(sscanf_test_d_2) {  // спецификатор d знаки
//   char str_1[LEN] = "+123";
//   char str_2[LEN] = "-123";
//   char str_3[LEN] = "+123 -123";
//   char str_4[LEN] = "+123-123";
//   char str_5[LEN] = "++123";
//   char str_6[LEN] = "------123";
//   int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   // ck_assert_int_eq(sscanf(str_1, "%d", &a1), s21_sscanf(str_1, "%d",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   // ck_assert_int_eq(sscanf(str_1, "%2d", &a1), s21_sscanf(str_1, "%2d",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%d", &a1), s21_sscanf(str_2, "%d", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_5, "%d", &a1), s21_sscanf(str_5, "%d", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_6, "%d", &a1), s21_sscanf(str_6, "%d", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_3, "%d%d", &a1, &b1),
//                    s21_sscanf(str_3, "%d%d", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_4, "%d%d", &a1, &b1),
//                    s21_sscanf(str_4, "%d%d", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

START_TEST(sscanf_test_d_3) {  // спецификатор d длина+ширина h
  char str_1[LEN] = "123456";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%hd", &a1), s21_sscanf(str_1, "%hd", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hd", &a1), s21_sscanf(str_1, "%1hd", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hd%1hd", &a1, &b1),
                   s21_sscanf(str_1, "%1hd%1hd", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_4) {  // спецификатор d длина+ширина l
  char str_1[LEN] = "123456";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%ld", &a1), s21_sscanf(str_1, "%ld", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1ld", &a1), s21_sscanf(str_1, "%1ld", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3ld%3ld", &a1, &b1),
                   s21_sscanf(str_1, "%3ld%3ld", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_5) {  // спецификатор d ширина
  char str_1[LEN] = "123456";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1d", &a1), s21_sscanf(str_1, "%1d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2d", &a1), s21_sscanf(str_1, "%2d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%6d", &a1), s21_sscanf(str_1, "%6d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%7d", &a1), s21_sscanf(str_1, "%7d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1d%1d", &a1, &b1),
                   s21_sscanf(str_1, "%1d%1d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3d%3d", &a1, &b1),
                   s21_sscanf(str_1, "%3d%3d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

Suite *test_sscanf(void) {
  Suite *suite =
      suite_create("\n\033[37;1m=========S21S21_SSCANF=========\033[0m");
  TCase *tcase_core = tcase_create("sscanf_tc");
  tcase_add_test(tcase_core, sscanf_test_c_1);
  tcase_add_test(tcase_core, sscanf_test_c_2);
  tcase_add_test(tcase_core, sscanf_test_d_1);
  // tcase_add_test(tcase_core, sscanf_test_d_2);
  tcase_add_test(tcase_core, sscanf_test_d_3);
  tcase_add_test(tcase_core, sscanf_test_d_4);
  tcase_add_test(tcase_core, sscanf_test_d_5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}