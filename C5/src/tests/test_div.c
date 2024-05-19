#include "./test.h"

START_TEST(test_div_1) {
  int num1 = 100;
  int num2 = 50;
  int res_origin = 2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_div_2) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -16384;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_div_3) {
  int num1 = 2;
  int num2 = 2;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_div_4) {
  int num1 = 0;
  int num2 = 5;
  int res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_div_5) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_6) {
  float num1 = -9403.0e2;
  float num2 = -2020.29;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_7) {
  float num1 = -9403.0e2;
  float num2 = 2020.29;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_8) {
  float num1 = -9403.0e2;
  float num2 = 2.28e17;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_9) {
  float num1 = -0.9;
  float num2 = 30.323;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

// START_TEST(test_div_10) {
//   char str1[100] = {'\0'};
//   char str2[100] = {'\0'};
//   s21_decimal dec1 = {{100, 0, 0, 0}};
//   s21_decimal dec2 = {{99999, 0, 0, 0}};

//   float res_s21 = 0;
//   float res = 100.0 / 99999.0;

//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   s21_from_decimal_to_float(res1, &res_s21);
//   snprintf(str1, sizeof(str1), "%.28lf", res);
//   snprintf(str2, sizeof(str1), "%.28lf", res_s21);
//   ck_assert_str_eq(str1, str2);
//   // ck_assert_float_eq_tol(res_s21, res, 6);
// }
// END_TEST

// START_TEST(test_div_11) {
//   char str1[100] = {'\0'};
//   char str2[100] = {'\0'};
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = 100;
//   float tmp2 = 999.99;
//   float res_s21 = 0.0;
//   float res = 0.100001;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_float_to_decimal(tmp2, &dec2);
//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   s21_from_decimal_to_float(res1, &res_s21);
//   snprintf(str1, sizeof(str1), "%.28lf", res);
//   snprintf(str2, sizeof(str1), "%.28lf", res_s21);
//   ck_assert_str_eq(str1, str2);
//   // ck_assert_float_eq_tol(res_s21, res, 6);
// }
// END_TEST

// START_TEST(test_div_12) {
//   char str1[100] = {'\0'};
//   char str2[100] = {'\0'};
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = -100;
//   int tmp2 = -99999;
//   float res_s21 = 0;
//   float res = 0.00100001;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   s21_from_decimal_to_float(res1, &res_s21);
//   snprintf(str1, sizeof(str1), "%.28lf", res);
//   snprintf(str2, sizeof(str1), "%.28lf", res_s21);
//   ck_assert_str_eq(str1, str2);
//   // ck_assert_float_eq_tol(res_s21, res, 6);
// }
// END_TEST

START_TEST(test_div_13) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
  s21_decimal dec2 = {{2.00e2, 0, 0, 0}};

  int res_s21 = 0;
  int res = 50;

  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  snprintf(str1, sizeof(str1), "%d", res);
  snprintf(str2, sizeof(str1), "%d", res_s21);
  ck_assert_str_eq(str1, str2);
  // ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_14) {
  s21_decimal dec1 = {{1110, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};

  s21_decimal res1;
  int res = s21_div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_div_15) {
  float num1 = -0.9e3;
  float num2 = 30.32;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_16) {
  float num1 = -0.9;
  float num2 = 0.000076;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_DIV |=========\033[0m");
  TCase *tc = tcase_create("tc_test_div");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_2);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_4);
  tcase_add_test(tc, test_div_5);
  tcase_add_test(tc, test_div_6);
  tcase_add_test(tc, test_div_7);
  tcase_add_test(tc, test_div_8);
  tcase_add_test(tc, test_div_9);
  //   tcase_add_test(tc, test_div_10);
  //   tcase_add_test(tc, test_div_11);
  //   tcase_add_test(tc, test_div_12);
  tcase_add_test(tc, test_div_13);
  tcase_add_test(tc, test_div_14);
  tcase_add_test(tc, test_div_15);
  tcase_add_test(tc, test_div_16);

  return s;
}