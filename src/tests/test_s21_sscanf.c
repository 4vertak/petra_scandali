#include <check.h>
#include <string.h>

#include "../s21_sscanf.h"
#include "../s21_string.h"

START_TEST(sscanf_test_1) {  // пустая строка или строка,в которой только
                             // пробелы,табы и т.д
  char str_1[LEN] = "";
  char str_2[LEN] = "      ";
  int a1 = 0, a2 = 0;
  char b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d", &a1), _sscanf(str_1, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d", &a1), _sscanf(str_2, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%c", &b1), _sscanf(str_1, "%c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%c", &b1), _sscanf(str_2, "%c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_2) {  // подавление присваивания полностью и конкретного
                             // значения
  char str_1[LEN] = "abc";
  char str_2[LEN] = "1 % 3";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%% %d %d", &a1, &b1),
                   _sscanf(str_1, "%% %d %d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d %% %d", &a1, &b1),
                   _sscanf(str_1, "%d %% %d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%*d%d %d", &a1, &b1),
                   _sscanf(str_1, "%*d%d %d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d%*d %d", &a1, &b1),
                   _sscanf(str_1, "%d%*d %d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d %% %d", &a1, &b1),
                   _sscanf(str_2, "%d %% %d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_c_1) {  // спецификатор c обычные ситуации
  char str_1[LEN] = "ab";
  char str_2[LEN] = "     ab ";
  char str_3[LEN] = "     a   b ";
  char a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%c", &a1), _sscanf(str_1, "%c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%c", &a1), _sscanf(str_2, "%c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "  %c", &a1), _sscanf(str_2, "  %c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c%c", &a1, &b1),
                   _sscanf(str_3, "%c%c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "    %c%c", &a1, &b1),
                   _sscanf(str_3, "    %c%c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c  %c", &a1, &b1),
                   _sscanf(str_3, "%c  %c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c  %c ", &a1, &b1),
                   _sscanf(str_3, "%c  %c ", &a2, &b2));
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
  ck_assert_int_eq(sscanf(str_1, "%lc", &a1), _sscanf(str_1, "%lc", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1c", &b1), _sscanf(str_1, "%1c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2c", &b1), _sscanf(str_1, "%2c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%1c%1c ", &b1, &c1),
                   _sscanf(str_2, "%1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, " %1c%1c ", &b1, &c1),
                   _sscanf(str_2, " %1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %1c%1c ", &b1, &c1),
                   _sscanf(str_3, " %1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%1c%1c ", &b1, &c1),
                   _sscanf(str_3, "%1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %lc%lc ", &a1, &d1),
                   _sscanf(str_3, " %lc%lc ", &a2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %lc%lc ", &a1, &d1),
                   _sscanf(str_3, " %lc%lc ", &a2, &d2));
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
  ck_assert_int_eq(sscanf(str_1, "%d", &a1), _sscanf(str_1, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d", &a1), _sscanf(str_2, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d", &a1), _sscanf(str_3, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d", &a1), _sscanf(str_4, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d%d", &a1, &b1),
                   _sscanf(str_1, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d%d", &a1, &b1),
                   _sscanf(str_2, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d%d", &a1, &b1),
                   _sscanf(str_3, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d%d", &a1, &b1),
                   _sscanf(str_4, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%d%d", &a1, &b1),
                   _sscanf(str_5, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%d%d", &a1, &b1),
                   _sscanf(str_6, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%d%d", &a1, &b1),
                   _sscanf(str_7, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_2) {  // спецификатор d знаки
  char str_1[LEN] = "+123";
  char str_2[LEN] = "-123";
  char str_3[LEN] = "+123 -123";
  char str_4[LEN] = "+123-123";
  char str_5[LEN] = "++123";
  char str_6[LEN] = "------123";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d", &a1), _sscanf(str_1, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2d", &a1), _sscanf(str_1, "%2d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d", &a1), _sscanf(str_2, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%d", &a1), _sscanf(str_5, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%d", &a1), _sscanf(str_6, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d%d", &a1, &b1),
                   _sscanf(str_3, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d%d", &a1, &b1),
                   _sscanf(str_4, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_3) {  // спецификатор d длина+ширина h
  char str_1[LEN] = "123456";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%hd", &a1), _sscanf(str_1, "%hd", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hd", &a1), _sscanf(str_1, "%1hd", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hd%1hd", &a1, &b1),
                   _sscanf(str_1, "%1hd%1hd", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_4) {  // спецификатор d длина+ширина l
  char str_1[LEN] = "123456";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%ld", &a1), _sscanf(str_1, "%ld", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1ld", &a1), _sscanf(str_1, "%1ld", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3ld%3ld", &a1, &b1),
                   _sscanf(str_1, "%3ld%3ld", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_5) {  // спецификатор d ширина
  char str_1[LEN] = "123456";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1d", &a1), _sscanf(str_1, "%1d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2d", &a1), _sscanf(str_1, "%2d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%6d", &a1), _sscanf(str_1, "%6d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%7d", &a1), _sscanf(str_1, "%7d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1d%1d", &a1, &b1),
                   _sscanf(str_1, "%1d%1d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3d%3d", &a1, &b1),
                   _sscanf(str_1, "%3d%3d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_i_1) {  // спецификатор i обычные ситуации
  char str_1[LEN] = "0743";
  char str_2[LEN] = "0x456";
  char str_3[LEN] = "044 0x44";
  char str_4[LEN] = "044 0x4e4";
  char str_5[LEN] = "0e44 0x4e4";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%i", &a1), _sscanf(str_1, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%i", &a1), _sscanf(str_2, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%i%i", &a1, &b1),
                   _sscanf(str_3, "%i%i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%i%i", &a1, &b1),
                   _sscanf(str_4, "%i%i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%i%i", &a1, &b1),
                   _sscanf(str_5, "%i%i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_i_2) {  // спецификатор i знаки
  char str_1[LEN] = "+0123";
  char str_2[LEN] = "-0456";
  char str_3[LEN] = "+0x123";
  char str_4[LEN] = "-0x456";
  char str_5[LEN] = "+0x123 -0456";
  char str_6[LEN] = "-0x456 +0899";
  char str_7[LEN] = "++0x123";
  char str_8[LEN] = "--0899";
  char str_9[LEN] = "+0xFFFF";
  char str_10[LEN] = "-0xA123";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%i", &a1), _sscanf(str_1, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%i", &a1), _sscanf(str_2, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%i", &a1), _sscanf(str_3, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%i", &a1), _sscanf(str_4, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%i", &a1), _sscanf(str_7, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_8, "%i", &a1), _sscanf(str_8, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_9, "%i", &a1), _sscanf(str_9, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_10, "%i", &a1), _sscanf(str_10, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%i%i", &a1, &b1),
                   _sscanf(str_5, "%i%i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%i%i", &a1, &b1),
                   _sscanf(str_6, "%i%i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

// START_TEST(sscanf_test_i_3) {  // спецификатор i ширина
//   char str_1[LEN] = "0123456";
//   char str_2[LEN] = "0x123456";
//   int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1i", &a1), _sscanf(str_1, "%1i", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2i", &a1), _sscanf(str_1, "%2i", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%6i", &a1), _sscanf(str_1, "%6i", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15i", &a1), _sscanf(str_1, "%15i",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%1i", &a1), _sscanf(str_2, "%1i", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%2i", &a1), _sscanf(str_2, "%2i", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%6i", &a1), _sscanf(str_2, "%6i", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%15i", &a1), _sscanf(str_2, "%15i",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1i%1i", &a1, &b1),
//                    _sscanf(str_1, "%1i%1i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2i%2i", &a1, &b1),
//                    _sscanf(str_1, "%2i%2i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%3i%4i", &a1, &b1),
//                    _sscanf(str_1, "%3i%4i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15i%1i", &a1, &b1),
//                    _sscanf(str_1, "%15i%1i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%1i%1i", &a1, &b1),
//                    _sscanf(str_2, "%1i%1i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%2i%2i", &a1, &b1),
//                    _sscanf(str_2, "%2i%2i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%3i%4i", &a1, &b1),
//                    _sscanf(str_2, "%3i%4i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%15i%1i", &a1, &b1),
//                    _sscanf(str_2, "%15i%1i", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

// START_TEST(sscanf_test_i_4) {  // спецификатор i ширина+длина l
//   char str_1[LEN] = "0123456";
//   char str_2[LEN] = "0x123456";
//   long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1li", &a1), _sscanf(str_1, "%1li",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2li", &a1), _sscanf(str_1, "%2li",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%6li", &a1), _sscanf(str_1, "%6li",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15li", &a1),
//                    _sscanf(str_1, "%15li", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%1li", &a1), _sscanf(str_2, "%1li",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%2li", &a1), _sscanf(str_2, "%2li",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%6li", &a1), _sscanf(str_2, "%6li",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%15li", &a1),
//                    _sscanf(str_2, "%15li", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1li%1li", &a1, &b1),
//                    _sscanf(str_1, "%1li%1li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2li%2li", &a1, &b1),
//                    _sscanf(str_1, "%2li%2li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%3li%4li", &a1, &b1),
//                    _sscanf(str_1, "%3li%4li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15li%1li", &a1, &b1),
//                    _sscanf(str_1, "%15li%1li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%1li%1li", &a1, &b1),
//                    _sscanf(str_2, "%1li%1li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%2li%2li", &a1, &b1),
//                    _sscanf(str_2, "%2li%2li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%3li%4li", &a1, &b1),
//                    _sscanf(str_2, "%3li%4li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%15li%1li", &a1, &b1),
//                    _sscanf(str_2, "%15li%1li", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

// START_TEST(sscanf_test_i_5) {  // спецификатор i ширина+длина h
//   char str_1[LEN] = "0123456";
//   char str_2[LEN] = "0x123456";
//   short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1hi", &a1), _sscanf(str_1, "%1hi",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2hi", &a1), _sscanf(str_1, "%2hi",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%6hi", &a1), _sscanf(str_1, "%6hi",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15hi", &a1),
//                    _sscanf(str_1, "%15hi", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%1hi", &a1), _sscanf(str_2, "%1hi",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%2hi", &a1), _sscanf(str_2, "%2hi",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%6hi", &a1), _sscanf(str_2, "%6hi",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%15hi", &a1),
//                    _sscanf(str_2, "%15hi", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1hi%1hi", &a1, &b1),
//                    _sscanf(str_1, "%1hi%1hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2hi%2hi", &a1, &b1),
//                    _sscanf(str_1, "%2hi%2hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%3hi%4hi", &a1, &b1),
//                    _sscanf(str_1, "%3hi%4hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15hi%1hi", &a1, &b1),
//                    _sscanf(str_1, "%15hi%1hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%1hi%1hi", &a1, &b1),
//                    _sscanf(str_2, "%1hi%1hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%2hi%2hi", &a1, &b1),
//                    _sscanf(str_2, "%2hi%2hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%3hi%4hi", &a1, &b1),
//                    _sscanf(str_2, "%3hi%4hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_2, "%15hi%1hi", &a1, &b1),
//                    _sscanf(str_2, "%15hi%1hi", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

START_TEST(sscanf_test_i_6) {  // спецификатор i несколько х и 0
  char str_1[LEN] = "00743";
  char str_2[LEN] = "0xx456";
  char str_3[LEN] = "0044 0x4x4";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%i", &a1), _sscanf(str_1, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%i", &a1), _sscanf(str_2, "%i", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%i%i", &a1, &b1),
                   _sscanf(str_1, "%i%i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2i%3i", &a1, &b1),
                   _sscanf(str_1, "%2i%3i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%2i%3i", &a1, &b1),
                   _sscanf(str_2, "%2i%3i", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  char f1[LEN] = "%i%i%i%i";
  ck_assert_int_eq(sscanf(str_3, f1, &a1, &b1, &c1, &d1),
                   _sscanf(str_3, f1, &a2, &b2, &c2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_1) {  // спецификатор f обычные ситуации без точки
  char str_1[LEN] = "ab";
  char str_2[LEN] = "123";
  char str_3[LEN] = "1b";
  char str_4[LEN] = "b1";
  char str_5[LEN] = "123 123";
  char str_6[LEN] = "123 1b";
  char str_7[LEN] = "1b 123";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f", &a1), _sscanf(str_1, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f", &a1), _sscanf(str_2, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%f", &a1), _sscanf(str_3, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%f", &a1), _sscanf(str_4, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f%f", &a1, &b1),
                   _sscanf(str_1, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f%f", &a1, &b1),
                   _sscanf(str_2, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%f%f", &a1, &b1),
                   _sscanf(str_3, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%f%f", &a1, &b1),
                   _sscanf(str_4, "%d%d", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%f%f", &a1, &b1),
                   _sscanf(str_5, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%f%f", &a1, &b1),
                   _sscanf(str_6, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%f%f", &a1, &b1),
                   _sscanf(str_7, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_2) {  // спецификатор f обычные ситуации с точкой
  char str_1[LEN] = "1.ab";
  char str_2[LEN] = "1.3b";
  char str_3[LEN] = "b.123";
  char str_4[LEN] = "1.23";
  char str_5[LEN] = "12.3";
  char str_6[LEN] = "0.123";
  char str_7[LEN] = "12.3 32.2";
  char str_8[LEN] = "0.123 0.345";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f", &a1), _sscanf(str_1, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f", &a1), _sscanf(str_2, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%f", &a1), _sscanf(str_3, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%f", &a1), _sscanf(str_4, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%f", &a1), _sscanf(str_5, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%f", &a1), _sscanf(str_6, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f%f", &a1, &b1),
                   _sscanf(str_1, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f%f", &a1, &b1),
                   _sscanf(str_2, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%f%f", &a1, &b1),
                   _sscanf(str_7, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_8, "%f%f", &a1, &b1),
                   _sscanf(str_8, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_3) {  // спецификатор f со знаками
  char str_1[LEN] = "+1.23";
  char str_2[LEN] = "-12.3";
  char str_3[LEN] = "+12.3 -32.2";
  char str_4[LEN] = "-0.123 -0.345";
  char str_5[LEN] = "++1.23";
  char str_6[LEN] = "--12.3";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f", &a1), _sscanf(str_1, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f", &a1), _sscanf(str_2, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%f", &a1), _sscanf(str_5, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%f", &a1), _sscanf(str_6, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%f%f", &a1, &b1),
                   _sscanf(str_3, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%f%f", &a1, &b1),
                   _sscanf(str_4, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_4) {  // спецификатор f длина+ширина Lf
  char str_1[LEN] = "1.23";
  char str_2[LEN] = "12.3 32.2";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%Lf", &a1), _sscanf(str_1, "%Lf", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2Lf", &a1), _sscanf(str_1, "%2Lf", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%4Lf", &a1), _sscanf(str_1, "%4Lf", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%Lf%Lf", &a1, &b1),
                   _sscanf(str_2, "%Lf%Lf", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%1Lf%1Lf", &a1, &b1),
                   _sscanf(str_2, "%1Lf%1Lf", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%2Lf%2Lf", &a1, &b1),
                   _sscanf(str_2, "%2Lf%2Lf", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%5Lf%2Lf", &a1, &b1),
                   _sscanf(str_2, "%5Lf%2Lf", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_5) {  // спецификатор f длина+ширина lf
  char str_1[LEN] = "1.23";
  char str_2[LEN] = "12.3 32.2";
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%lf", &a1), _sscanf(str_1, "%lf", &a2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1lf", &a1), _sscanf(str_1, "%1lf", &a2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%4lf", &a1), _sscanf(str_1, "%4lf", &a2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%lf%lf", &a1, &b1),
                   _sscanf(str_2, "%lf%lf", &a2, &b2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  // ck_assert_double_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%1lf%1lf", &a1, &b1),
                   _sscanf(str_2, "%1lf%1lf", &a2, &b2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  // ck_assert_double_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%2lf%2lf", &a1, &b1),
                   _sscanf(str_2, "%2lf%2lf", &a2, &b2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  // ck_assert_double_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%5lf%2lf", &a1, &b1),
                   _sscanf(str_2, "%5lf%2lf", &a2, &b2));
  // ck_assert_double_eq_tol(a1, a2, 10 - 7);
  // ck_assert_double_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_6) {  // спецификатор f несколько точек
  char str_1[LEN] = "1.2..3";
  char str_2[LEN] = "1.2.55.3";
  char str_3[LEN] = "12..3 32.2";
  char str_4[LEN] = "12.3 32.2.1";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f", &a1), _sscanf(str_1, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%4f", &a1), _sscanf(str_1, "%4f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f", &a1), _sscanf(str_2, "%f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%8f", &a1), _sscanf(str_2, "%8f", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f%f", &a1, &b1),
                   _sscanf(str_2, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%f%f", &a1, &b1),
                   _sscanf(str_3, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%3f%4f", &a1, &b1),
                   _sscanf(str_3, "%3f%4f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%5f%5f", &a1, &b1),
                   _sscanf(str_3, "%5f%5f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%f%f", &a1, &b1),
                   _sscanf(str_4, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%5f%5f", &a1, &b1),
                   _sscanf(str_4, "%5f%5f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%10f%10f", &a1, &b1),
                   _sscanf(str_4, "%10f%10f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_f_7) {  // спецификатор f inf, nan
  char str_1[LEN] = "nan";
  char str_2[LEN] = "-nan";
  char str_3[LEN] = "+nan";
  char str_4[LEN] = "inf";
  char str_5[LEN] = "+inf";
  char str_6[LEN] = "-inf";
  char str_7[LEN] = "inf nan";
  char str_8[LEN] = "-inf nan";
  char str_9[LEN] = "inf -nan";
  char str_10[LEN] = "inf 2.3";
  char str_11[LEN] = "2.3 nan";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%f", &a1), _sscanf(str_1, "%f", &a2));
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%f", &a1), _sscanf(str_2, "%f", &a2));
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%f", &a1), _sscanf(str_3, "%f", &a2));
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%f", &a1), _sscanf(str_4, "%f", &a2));
  // ck_assert_float_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%f", &a1), _sscanf(str_5, "%f", &a2));
  // ck_assert_float_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%f", &a1), _sscanf(str_6, "%f", &a2));
  // ck_assert_float_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%f%f", &a1, &b1),
                   _sscanf(str_7, "%f%f", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_8, "%f%f", &a1, &b1),
                   _sscanf(str_8, "%f%f", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_9, "%f%f", &a1, &b1),
                   _sscanf(str_9, "%f%f", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_10, "%f%f", &a1, &b1),
                   _sscanf(str_10, "%f%f", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_11, "%f%f", &a1, &b1),
                   _sscanf(str_11, "%f%f", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_ge_1) {  // спецификатор gGeE обычные ситуации без точки
                                // и экспоненты
  char str_1[LEN] = "ab";
  char str_2[LEN] = "123";
  char str_3[LEN] = "1b";
  char str_4[LEN] = "b1";
  char str_5[LEN] = "123 123";
  char str_6[LEN] = "123 1b";
  char str_7[LEN] = "1b 123";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%g", &a1), _sscanf(str_1, "%g", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%G", &a1), _sscanf(str_2, "%G", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%e", &a1), _sscanf(str_3, "%e", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%E", &a1), _sscanf(str_4, "%E", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%g%g", &a1, &b1),
                   _sscanf(str_5, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%G%G", &a1, &b1),
                   _sscanf(str_6, "%G%G", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%e%e", &a1, &b1),
                   _sscanf(str_7, "%e%e", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%E%E", &a1, &b1),
                   _sscanf(str_7, "%E%E", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_ge_2) {  // спецификатор ge обычные ситуации с точкой и
                                // экспонентой
  char str_1[LEN] = "1.23";
  char str_2[LEN] = "0.123";
  char str_3[LEN] = "1.23e-5";
  char str_4[LEN] = "0.123E5";
  char str_5[LEN] = "12.3 32.2";
  char str_6[LEN] = "12.3e5 32.2E-5";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%g", &a1), _sscanf(str_1, "%g", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%G", &a1), _sscanf(str_2, "%G", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%e", &a1), _sscanf(str_3, "%e", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%E", &a1), _sscanf(str_4, "%E", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%g%g", &a1, &b1),
                   _sscanf(str_5, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%G%G", &a1, &b1),
                   _sscanf(str_5, "%G%G", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%E%E", &a1, &b1),
                   _sscanf(str_6, "%E%E", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%e%e", &a1, &b1),
                   _sscanf(str_6, "%e%e", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_ge_3) {  // спецификатор ge со знаками
  char str_1[LEN] = "+1.23";
  char str_2[LEN] = "-12.3";
  char str_3[LEN] = "+1.23e-5";
  char str_4[LEN] = "-12.3e5";
  char str_5[LEN] = "+12.3 -32.2";
  char str_6[LEN] = "-0.123 -0.345";
  char str_7[LEN] = "+12.3e5 -32.2e-5";
  char str_8[LEN] = "-0.123e-5 -0.345e5";
  char str_9[LEN] = "++1.23";
  char str_10[LEN] = "--12.3";
  char str_11[LEN] = "++1.23e-5";
  char str_12[LEN] = "--12.3e5";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%g", &a1), _sscanf(str_1, "%g", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%G", &a1), _sscanf(str_2, "%G", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%e", &a1), _sscanf(str_3, "%e", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%E", &a1), _sscanf(str_4, "%E", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_9, "%g", &a1), _sscanf(str_9, "%g", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_10, "%G", &a1), _sscanf(str_10, "%G", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_11, "%e", &a1), _sscanf(str_11, "%e", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_12, "%E", &a1), _sscanf(str_12, "%E", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%g%g", &a1, &b1),
                   _sscanf(str_5, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%G%G", &a1, &b1),
                   _sscanf(str_6, "%G%G", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%e%e", &a1, &b1),
                   _sscanf(str_7, "%e%e", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_8, "%E%E", &a1, &b1),
                   _sscanf(str_8, "%E%E", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_ge_4) {  // спецификатор ge длина+ширина
  char str_1[LEN] = "1.23";
  char str_2[LEN] = "1.23e5";
  char str_3[LEN] = "1.23e-5";
  char str_4[LEN] = "12.3 32.2";
  char str_5[LEN] = "12.3e5 32.2e-5";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%Lg", &a1), _sscanf(str_1, "%Lg", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%LG", &a1), _sscanf(str_2, "%LG", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%Le", &a1), _sscanf(str_3, "%Le", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%LE", &a1), _sscanf(str_1, "%LE", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1Lg", &a1), _sscanf(str_1, "%1Lg", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%2LG", &a1), _sscanf(str_2, "%2LG", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%4Le", &a1), _sscanf(str_3, "%4Le", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%10LE", &a1), _sscanf(str_1, "%10LE", &a2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%Lg%Lg", &a1, &b1),
                   _sscanf(str_4, "%Lg%Lg", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%LG%LG", &a1, &b1),
                   _sscanf(str_4, "%LG%LG", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%Le%Le", &a1, &b1),
                   _sscanf(str_5, "%Le%Le", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%LE%LE", &a1, &b1),
                   _sscanf(str_5, "%LE%LE", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%1Lg%1Lg", &a1, &b1),
                   _sscanf(str_4, "%1Lg%1Lg", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%2LG%2LG", &a1, &b1),
                   _sscanf(str_4, "%2LG%2LG", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%4Le%4Le", &a1, &b1),
                   _sscanf(str_5, "%4Le%4Le", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%6LE%6LE", &a1, &b1),
                   _sscanf(str_5, "%6LE%6LE", &a2, &b2));
  // ck_assert_ldouble_eq_tol(a1, a2, 10 - 7);
  // ck_assert_ldouble_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_ge_5) {  // спецификатор ge ситуации с точкой и
                                // экспонентой, которых несколько
  char str_1[LEN] = "1.2.3";
  char str_2[LEN] = "0.12.3";
  char str_3[LEN] = "1.2e3e-5";
  char str_4[LEN] = "0.1E23E5";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%g", &a1), _sscanf(str_1, "%g", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%5g", &a1), _sscanf(str_1, "%5g", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%G", &a1), _sscanf(str_2, "%G", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%5G", &a1), _sscanf(str_2, "%5G", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%e", &a1), _sscanf(str_3, "%e", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%E", &a1), _sscanf(str_4, "%E", &a2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%g%g", &a1, &b1),
                   _sscanf(str_1, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%g%g", &a1, &b1),
                   _sscanf(str_2, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%g%g", &a1, &b1),
                   _sscanf(str_3, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%g%g", &a1, &b1),
                   _sscanf(str_4, "%g%g", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_ge_6) {  // спецификатор ge inf, nan
  char str_1[LEN] = "nan";
  char str_2[LEN] = "-nan";
  char str_3[LEN] = "+nan";
  char str_4[LEN] = "inf";
  char str_5[LEN] = "+inf";
  char str_6[LEN] = "-inf";
  char str_7[LEN] = "inf nan";
  char str_8[LEN] = "-inf nan";
  char str_9[LEN] = "inf -nan";
  char str_10[LEN] = "inf 2.3";
  char str_11[LEN] = "2.3 nan";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%g", &a1), _sscanf(str_1, "%g", &a2));
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%G", &a1), _sscanf(str_2, "%G", &a2));
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%e", &a1), _sscanf(str_3, "%e", &a2));
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%E", &a1), _sscanf(str_4, "%E", &a2));
  // ck_assert_float_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%g", &a1), _sscanf(str_5, "%g", &a2));
  // ck_assert_float_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%G", &a1), _sscanf(str_6, "%G", &a2));
  // ck_assert_float_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%e%e", &a1, &b1),
                   _sscanf(str_7, "%e%e", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_8, "%E%E", &a1, &b1),
                   _sscanf(str_8, "%E%E", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_9, "%g%G", &a1, &b1),
                   _sscanf(str_9, "%g%G", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_10, "%e%E", &a1, &b1),
                   _sscanf(str_10, "%e%E", &a2, &b2));
  // ck_assert_float_eq(a1, a2);
  // ck_assert_float_eq_tol(b1, b2, 10 - 7);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_11, "%g%e", &a1, &b1),
                   _sscanf(str_11, "%g%e", &a2, &b2));
  // ck_assert_float_eq_tol(a1, a2, 10 - 7);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_o_1) {  // спецификатор o обычные ситуации
  char str_1[LEN] = "0743";
  char str_2[LEN] = "0123";
  char str_3[LEN] = "0b123";
  char str_4[LEN] = "0.123";
  char str_5[LEN] = "044 032";
  char str_6[LEN] = "00743";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%o", &a1), _sscanf(str_1, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%o", &a1), _sscanf(str_2, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%o", &a1), _sscanf(str_3, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%o", &a1), _sscanf(str_4, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%o", &a1), _sscanf(str_1, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%o%o", &a1, &b1),
                   _sscanf(str_5, "%o%o", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%o%o", &a1, &b1),
                   _sscanf(str_6, "%o%o", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_o_2) {  // спецификатор o знаки
  char str_1[LEN] = "+0123";
  char str_2[LEN] = "-0456";
  char str_3[LEN] = "+0123 -0456";
  char str_4[LEN] = "-0456 +0899";
  char str_5[LEN] = "++0123";
  char str_6[LEN] = "--0899";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%o", &a1), _sscanf(str_1, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%o", &a1), _sscanf(str_2, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%o", &a1), _sscanf(str_5, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%o", &a1), _sscanf(str_6, "%o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%o%o", &a1, &b1),
                   _sscanf(str_3, "%o%o", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%o%o", &a1, &b1),
                   _sscanf(str_4, "%o%o", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_o_3) {  // спецификатор o длина+ширина l
  char str_1[LEN] = "0123456";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1lo", &a1), _sscanf(str_1, "%1lo", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2lo", &a1), _sscanf(str_1, "%2lo", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%4lo", &a1), _sscanf(str_1, "%4lo", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%10lo", &a1), _sscanf(str_1, "%10lo", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%lo", &a1), _sscanf(str_1, "%lo", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3lo%3lo", &a1, &b1),
                   _sscanf(str_1, "%3lo%3lo", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%lo%lo", &a1, &b1),
                   _sscanf(str_1, "%lo%lo", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_o_4) {  // спецификатор o длина+ширина h
  char str_1[LEN] = "0123456";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1ho", &a1), _sscanf(str_1, "%1ho", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2ho", &a1), _sscanf(str_1, "%2ho", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%4ho", &a1), _sscanf(str_1, "%4ho", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%10ho", &a1), _sscanf(str_1, "%10ho", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%ho", &a1), _sscanf(str_1, "%ho", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%15ho%1ho", &a1, &b1),
                   _sscanf(str_1, "%15ho%1ho", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%ho%ho", &a1, &b1),
                   _sscanf(str_1, "%ho%ho", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_o_5) {  // спецификатор o ширина
  char str_1[LEN] = "0123456";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1o", &a1), _sscanf(str_1, "%1o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2o", &a1), _sscanf(str_1, "%2o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%4o", &a1), _sscanf(str_1, "%4o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%10o", &a1), _sscanf(str_1, "%10o", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3o%3o", &a1, &b1),
                   _sscanf(str_1, "%3o%3o", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%15o%1o", &a1, &b1),
                   _sscanf(str_1, "%15o%1o", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_s_1) {  // спецификатор s обычные ситуации
  char str_1[LEN] = "abcde";
  char str_2[LEN] = "abcde edcba";
  char str_3[LEN] = "abcd/0e";
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  char s5[LEN] = {0};
  char s6[LEN] = {0};
  char s7[LEN] = {0};
  char s8[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%s", s1), _sscanf(str_1, "%s", s2));
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(sscanf(str_3, "%s", s7), _sscanf(str_3, "%s", s8));
  ck_assert_str_eq(s7, s8);
  ck_assert_int_eq(sscanf(str_2, "%s%s", s3, s5),
                   _sscanf(str_2, "%s%s", s4, s6));
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
}
END_TEST

START_TEST(sscanf_test_s_2) {  // спецификатор s ширина
  char str_1[LEN] = "abcde";
  char str_2[LEN] = "abcde edcba";
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  char s5[LEN] = {0};
  char s6[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%1s", s1), _sscanf(str_1, "%1s", s2));
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(sscanf(str_2, "%1s%1s", s3, s5),
                   _sscanf(str_2, "%1s%1s", s4, s6));
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
}
END_TEST

START_TEST(sscanf_test_s_3) {  // спецификатор s ширина
  char str_1[LEN] = "abcde";
  char str_2[LEN] = "abcde edcba";
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  char s5[LEN] = {0};
  char s6[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%10s", s1), _sscanf(str_1, "%10s", s2));
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(sscanf(str_2, "%10s%1s", s3, s5),
                   _sscanf(str_2, "%10s%1s", s4, s6));
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
}
END_TEST

START_TEST(sscanf_test_s_4) {  // спецификатор s длина
  char str_1[LEN] = "abcde";
  char str_2[LEN] = "abcde edcba";
  wchar_t s1[LEN] = {0};
  wchar_t s2[LEN] = {0};
  wchar_t s3[LEN] = {0};
  wchar_t s4[LEN] = {0};
  wchar_t s5[LEN] = {0};
  wchar_t s6[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%ls", s1), _sscanf(str_1, "%ls", s2));
  // ck_assert_mem_eq(s1, s2, LEN);
  ck_assert_int_eq(sscanf(str_2, "%ls%ls", s3, s5),
                   _sscanf(str_2, "%ls%ls", s4, s6));
  // ck_assert_mem_eq(s3, s4, LEN);
  // ck_assert_mem_eq(s5, s6, LEN);
}
END_TEST

START_TEST(sscanf_test_s_5) {  // спецификатор s ширина+длина
  char str_1[LEN] = "abcde";
  char str_2[LEN] = "abcde edcba";
  wchar_t s1[LEN] = {0};
  wchar_t s2[LEN] = {0};
  wchar_t s3[LEN] = {0};
  wchar_t s4[LEN] = {0};
  wchar_t s5[LEN] = {0};
  wchar_t s6[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%1ls", s1), _sscanf(str_1, "%1ls", s2));
  // ck_assert_mem_eq(s1, s2, LEN);
  ck_assert_int_eq(sscanf(str_2, "%1ls%1ls", s3, s5),
                   _sscanf(str_2, "%1ls%1ls", s4, s6));
  // ck_assert_mem_eq(s3, s4, LEN);
  // ck_assert_mem_eq(s5, s6, LEN);
}
END_TEST

START_TEST(sscanf_test_u_1) {  // спецификатор u обычные ситуации
  char str_1[LEN] = "ab";
  char str_2[LEN] = "123";
  char str_3[LEN] = "1b";
  char str_4[LEN] = "b1";
  char str_5[LEN] = "123 123";
  char str_6[LEN] = "123 1b";
  char str_7[LEN] = "1b 123";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%u", &a1), _sscanf(str_1, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%u", &a1), _sscanf(str_2, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%u", &a1), _sscanf(str_3, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%u", &a1), _sscanf(str_4, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%u%u", &a1, &b1),
                   _sscanf(str_1, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%u%u", &a1, &b1),
                   _sscanf(str_2, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%u%u", &a1, &b1),
                   _sscanf(str_3, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%u%u", &a1, &b1),
                   _sscanf(str_4, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%u%u", &a1, &b1),
                   _sscanf(str_5, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%u%u", &a1, &b1),
                   _sscanf(str_6, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%u%u", &a1, &b1),
                   _sscanf(str_7, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_u_2) {  // спецификатор u знаки
  char str_1[LEN] = "+123";
  char str_2[LEN] = "-123";
  char str_3[LEN] = "+123 -123";
  char str_4[LEN] = "+123-123";
  char str_5[LEN] = "++123";
  char str_6[LEN] = "------123";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%u", &a1), _sscanf(str_1, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%u", &a1), _sscanf(str_2, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%u", &a1), _sscanf(str_5, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%u", &a1), _sscanf(str_6, "%u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%u%u", &a1, &b1),
                   _sscanf(str_3, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%u%u", &a1, &b1),
                   _sscanf(str_4, "%u%u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_u_3) {  // спецификатор u длина+ширина h
  char str_1[LEN] = "123456";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%hu", &a1), _sscanf(str_1, "%hu", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hu", &a1), _sscanf(str_1, "%1hu", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hu%1hu", &a1, &b1),
                   _sscanf(str_1, "%1hu%1hu", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_u_4) {  // спецификатор u длина+ширина l
  char str_1[LEN] = "123456";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%lu", &a1), _sscanf(str_1, "%lu", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1lu", &a1), _sscanf(str_1, "%1lu", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3lu%3lu", &a1, &b1),
                   _sscanf(str_1, "%3lu%3lu", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_u_5) {  // спецификатор u ширина
  char str_1[LEN] = "123456";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1u", &a1), _sscanf(str_1, "%1u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2u", &a1), _sscanf(str_1, "%2u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%6u", &a1), _sscanf(str_1, "%6u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%7u", &a1), _sscanf(str_1, "%7u", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1u%1u", &a1, &b1),
                   _sscanf(str_1, "%1u%1u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3u%3u", &a1, &b1),
                   _sscanf(str_1, "%3u%3u", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_xX_1) {  // спецификатор xX обычные ситуации
  char str_1[LEN] = "0x456";
  char str_2[LEN] = "0x45aA6";
  char str_3[LEN] = "0x45fff6";
  char str_4[LEN] = "0x45FFF6";
  char str_5[LEN] = "0x444 0x44";
  char str_6[LEN] = "0x44 0x4e4";
  char str_7[LEN] = "0e44 0x44";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%x", &a1), _sscanf(str_1, "%x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%X", &a1), _sscanf(str_2, "%X", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%x", &a1), _sscanf(str_3, "%x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%X", &a1), _sscanf(str_4, "%X", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%x%x", &a1, &b1),
                   _sscanf(str_5, "%x%x", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%X%X", &a1, &b1),
                   _sscanf(str_6, "%X%X", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%x%X", &a1, &b1),
                   _sscanf(str_7, "%x%X", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_xX_2) {  // спецификатор xX знаки
  char str_1[LEN] = "+0x123";
  char str_2[LEN] = "-0x456";
  char str_3[LEN] = "+0x123 -0x456";
  char str_4[LEN] = "++0x123";
  char str_5[LEN] = "--0899";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%x", &a1), _sscanf(str_1, "%x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3x", &a1), _sscanf(str_1, "%3x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%X", &a1), _sscanf(str_2, "%X", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%x", &a1), _sscanf(str_4, "%x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%X", &a1), _sscanf(str_5, "%X", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%x%x", &a1, &b1),
                   _sscanf(str_3, "%x%x", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%X%X", &a1, &b1),
                   _sscanf(str_4, "%X%X", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

// START_TEST(sscanf_test_xX_3) {  // спецификатор xX ширина
//   char str_1[LEN] = "0x123456";
//   unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1x", &a1), _sscanf(str_1, "%1x", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2X", &a1), _sscanf(str_1, "%2X", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%6x", &a1), _sscanf(str_1, "%6x", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15X", &a1), _sscanf(str_1, "%15X",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1x%1x", &a1, &b1),
//                    _sscanf(str_1, "%1x%1x", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2X%2X", &a1, &b1),
//                    _sscanf(str_1, "%2X%2X", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%3x%4X", &a1, &b1),
//                    _sscanf(str_1, "%3x%4X", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15X%1x", &a1, &b1),
//                    _sscanf(str_1, "%15X%1x", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

// START_TEST(sscanf_test_xX_4) {  // спецификатор xX ширина+длина l
//   char str_1[LEN] = "0x123456";
//   unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1lx", &a1), _sscanf(str_1, "%1lx",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2lX", &a1), _sscanf(str_1, "%2lX",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%6lx", &a1), _sscanf(str_1, "%6lx",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15lX", &a1),
//                    _sscanf(str_1, "%15lX", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1lx%1lx", &a1, &b1),
//                    _sscanf(str_1, "%1lx%1lx", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2lX%2lX", &a1, &b1),
//                    _sscanf(str_1, "%2lX%2lX", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%3lX%4lx", &a1, &b1),
//                    _sscanf(str_1, "%3lX%4lx", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15lx%1lX", &a1, &b1),
//                    _sscanf(str_1, "%15lx%1lX", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

// START_TEST(sscanf_test_xX_5) {  // спецификатор xX ширина+длина h
//   char str_1[LEN] = "0x123456";
//   unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1hx", &a1), _sscanf(str_1, "%1hx",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2hX", &a1), _sscanf(str_1, "%2hX",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%6hx", &a1), _sscanf(str_1, "%6hx",
//   &a2)); ck_assert_int_eq(a1, a2); a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15hX", &a1),
//                    _sscanf(str_1, "%15hX", &a2));
//   ck_assert_int_eq(a1, a2);
//   a1 = 0, a2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%1hx%1hx", &a1, &b1),
//                    _sscanf(str_1, "%1hx%1hx", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%2hX%2hX", &a1, &b1),
//                    _sscanf(str_1, "%2hX%2hX", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%3hx%4hX", &a1, &b1),
//                    _sscanf(str_1, "%3hx%4hX", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
//   ck_assert_int_eq(sscanf(str_1, "%15hX%1hx", &a1, &b1),
//                    _sscanf(str_1, "%15hX%1hx", &a2, &b2));
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   a1 = 0, a2 = 0, b1 = 0, b2 = 0;
// }
// END_TEST

START_TEST(sscanf_test_xX_6) {  // спецификатор xX несколько х
  char str_1[LEN] = "0x45x6";
  char str_2[LEN] = "0x450x6";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%x", &a1), _sscanf(str_1, "%x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%x", &a1), _sscanf(str_2, "%x", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%x%X", &a1, &b1),
                   _sscanf(str_1, "%x%X", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%x%X", &a1, &b1),
                   _sscanf(str_2, "%x%X", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_n_1) {  // спецификатор n обычные ситуации
  char str_1[LEN] = "123 456 789 0";
  char f1[LEN] = "%n%d%d%d";
  char f2[LEN] = "%d%n%d%d";
  char f3[LEN] = "%d%d%n%d";
  char f4[LEN] = "%d%d%d%n";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f1, &d1, &a1, &b1, &c1),
                   _sscanf(str_1, f1, &d2, &a2, &b2, &c2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f2, &a1, &d1, &b1, &c1),
                   _sscanf(str_1, f2, &a2, &d2, &b2, &c2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f3, &a1, &b1, &d1, &c1),
                   _sscanf(str_1, f3, &a2, &b2, &d2, &c2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f4, &a1, &b1, &c1, &d1),
                   _sscanf(str_1, f4, &a2, &b2, &c2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
}
END_TEST

START_TEST(sscanf_test_n_2) {  // спецификатор n обычные ситуации
  char str_1[LEN] = "abcde edcba";
  int a1 = 0, a2 = 0;
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%s%n%s", s1, &a1, s3),
                   _sscanf(str_1, "%s%n%s", s2, &a2, s4));
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_n_3) {  // спецификатор n обычные ситуации
  char str_1[LEN] = "abcde edcba";
  int a1 = 0, a2 = 0;
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%s %n %s", s1, &a1, s3),
                   _sscanf(str_1, "%s %n %s", s2, &a2, s4));
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_n_4) {  // спецификатор n обычные ситуации
  char str_1[LEN] = "abcde edcba";
  int a1 = 0, a2 = 0;
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%1s%1s%n", s1, s3, &a1),
                   _sscanf(str_1, "%1s%1s%n", s2, s4, &a2));
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_n_5) {  // спецификатор n необычные ситуации
  char str_1[LEN] = "abcde a edcba";
  int a1 = 0, a2 = 0;
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, "%s a %s%n", s1, s3, &a1),
                   _sscanf(str_1, "%s a %s%n", s2, s4, &a2));
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_n_6) {  // спецификатор n необычные ситуации
  char str_1[LEN] = "abcde a edcba";
  char f1[LEN] = "%s abcd %s %n";
  int a1 = 0, a2 = 0;
  char s1[LEN] = {0};
  char s2[LEN] = {0};
  char s3[LEN] = {0};
  char s4[LEN] = {0};
  ck_assert_int_eq(sscanf(str_1, f1, s1, s3, &a1),
                   _sscanf(str_1, f1, s2, s4, &a2));
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_p_1) {
  char str_1[LEN] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  char f1[LEN] = "%p%p%p%p";
  char f2[LEN] = "%p %p %p %p";
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f1, &a2, &b2, &c2, &d2),
                   _sscanf(str_1, f1, &a1, &b1, &c1, &d1));
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f2, &a2, &b2, &c2, &d2),
                   _sscanf(str_1, f2, &a1, &b1, &c1, &d1));
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *suite =
      suite_create("\n\033[37;1m=========S21_SSCANF=========\033[0m");
  TCase *tcase_core = tcase_create("sscanf_tc");
  tcase_add_test(tcase_core, sscanf_test_1);
  tcase_add_test(tcase_core, sscanf_test_2);
  tcase_add_test(tcase_core, sscanf_test_c_1);
  tcase_add_test(tcase_core, sscanf_test_c_2);
  tcase_add_test(tcase_core, sscanf_test_d_1);
  tcase_add_test(tcase_core, sscanf_test_d_2);
  tcase_add_test(tcase_core, sscanf_test_d_3);
  tcase_add_test(tcase_core, sscanf_test_d_4);
  tcase_add_test(tcase_core, sscanf_test_d_5);
  tcase_add_test(tcase_core, sscanf_test_i_1);
  tcase_add_test(tcase_core, sscanf_test_i_2);
  // tcase_add_test(tcase_core, sscanf_test_i_3);
  // tcase_add_test(tcase_core, sscanf_test_i_4);
  // tcase_add_test(tcase_core, sscanf_test_i_5);
  tcase_add_test(tcase_core, sscanf_test_i_6);
  tcase_add_test(tcase_core, sscanf_test_f_1);
  tcase_add_test(tcase_core, sscanf_test_f_2);
  tcase_add_test(tcase_core, sscanf_test_f_3);
  tcase_add_test(tcase_core, sscanf_test_f_4);
  tcase_add_test(tcase_core, sscanf_test_f_5);
  tcase_add_test(tcase_core, sscanf_test_f_6);
  tcase_add_test(tcase_core, sscanf_test_f_7);
  tcase_add_test(tcase_core, sscanf_test_ge_1);
  tcase_add_test(tcase_core, sscanf_test_ge_2);
  tcase_add_test(tcase_core, sscanf_test_ge_3);
  tcase_add_test(tcase_core, sscanf_test_ge_4);
  tcase_add_test(tcase_core, sscanf_test_ge_5);
  tcase_add_test(tcase_core, sscanf_test_ge_6);
  tcase_add_test(tcase_core, sscanf_test_o_1);
  tcase_add_test(tcase_core, sscanf_test_o_2);
  tcase_add_test(tcase_core, sscanf_test_o_3);
  tcase_add_test(tcase_core, sscanf_test_o_4);
  tcase_add_test(tcase_core, sscanf_test_o_5);
  tcase_add_test(tcase_core, sscanf_test_s_1);
  tcase_add_test(tcase_core, sscanf_test_s_2);
  tcase_add_test(tcase_core, sscanf_test_s_3);
  tcase_add_test(tcase_core, sscanf_test_s_4);
  tcase_add_test(tcase_core, sscanf_test_s_5);
  tcase_add_test(tcase_core, sscanf_test_u_1);
  tcase_add_test(tcase_core, sscanf_test_u_2);
  tcase_add_test(tcase_core, sscanf_test_u_3);
  tcase_add_test(tcase_core, sscanf_test_u_4);
  tcase_add_test(tcase_core, sscanf_test_u_5);
  tcase_add_test(tcase_core, sscanf_test_xX_1);
  tcase_add_test(tcase_core, sscanf_test_xX_2);
  // tcase_add_test(tcase_core, sscanf_test_xX_3);
  // tcase_add_test(tcase_core, sscanf_test_xX_4);
  // tcase_add_test(tcase_core, sscanf_test_xX_5);
  tcase_add_test(tcase_core, sscanf_test_xX_6);
  tcase_add_test(tcase_core, sscanf_test_n_1);
  tcase_add_test(tcase_core, sscanf_test_n_2);
  tcase_add_test(tcase_core, sscanf_test_n_3);
  tcase_add_test(tcase_core, sscanf_test_n_4);
  tcase_add_test(tcase_core, sscanf_test_n_5);
  tcase_add_test(tcase_core, sscanf_test_n_6);
  tcase_add_test(tcase_core, sscanf_test_p_1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}