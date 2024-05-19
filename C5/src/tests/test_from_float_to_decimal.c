#include "./test.h"

START_TEST(test_from_float_to_decimal_1) {
  float a = MIN_DEC - 1;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
}
END_TEST

START_TEST(test_from_float_to_decimal_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 0.0;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  snprintf(str1, sizeof(str1), "%.28lf", a);
  snprintf(str2, sizeof(str1), "%.28lf", b);
  ck_assert_str_eq(str1, str2);
  // ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_from_float_to_decimal_3) {
  float a = MAX_DEC;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
}
END_TEST

START_TEST(test_from_float_to_decimal_4) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  char str3[100] = {'\0'};
  char str4[100] = {'\0'};
  s21_decimal val = {0};

  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl1);
  snprintf(str2, sizeof(str1), "%.28lf", fl1_res);
  ck_assert_str_eq(str1, str2);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl2);
  snprintf(str2, sizeof(str1), "%.28lf", fl2_res);
  ck_assert_str_eq(str3, str4);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(test_from_float_to_decimal_5) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  char str3[100] = {'\0'};
  char str4[100] = {'\0'};
  s21_decimal val = {0};
  float fl1 = -128.023;
  float fl2 = 12345.37643764;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl1);
  snprintf(str2, sizeof(str1), "%.28lf", fl1_res);
  ck_assert_str_eq(str1, str2);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl2);
  snprintf(str2, sizeof(str1), "%.28lf", fl2_res);
  ck_assert_str_eq(str3, str4);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(test_from_float_to_decimal_6) {
  s21_decimal val;
  float num = -2147483648;
  s21_from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(test_from_float_to_decimal_7) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  char str3[100] = {'\0'};
  char str4[100] = {'\0'};
  s21_decimal val = {0};
  float fl1 = 22.14836E+03;
  float fl2 = -2.1474836E+09;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl1);
  snprintf(str2, sizeof(str1), "%.28lf", fl1_res);
  ck_assert_str_eq(str1, str2);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl2);
  snprintf(str2, sizeof(str1), "%.28lf", fl2_res);
  ck_assert_str_eq(str3, str4);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(test_from_float_to_decimal_8) {
  s21_decimal val = {0};
  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_9) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  char str3[100] = {'\0'};
  char str4[100] = {'\0'};
  s21_decimal val = {0};
  float fl1 = -333.2222;
  float fl2 = -2.1474836E+20;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl1);
  snprintf(str2, sizeof(str1), "%.28lf", fl1_res);
  ck_assert_str_eq(str1, str2);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  snprintf(str1, sizeof(str1), "%.28lf", fl2);
  snprintf(str2, sizeof(str1), "%.28lf", fl2_res);
  ck_assert_str_eq(str3, str4);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(test_from_float_to_decimal_10) {
  s21_decimal val = {0};
  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_11) {
  s21_decimal val = {0};
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_12) {
  s21_decimal val = {0};
  float a = 1e-30;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_13) {
  s21_decimal val = {{0, 0, 0, 0}};
  float res = 0.;
  float tmp = 1234.56789;
  s21_from_float_to_decimal(tmp, &val);
  s21_from_decimal_to_float(val, &res);
  printf("tmp = %f\nres = %f\n", tmp, res);
  ck_assert_uint_eq(res, tmp);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_FLOAT_TO_DECIMAL |=========\033[0m");
  TCase *tc = tcase_create("tc_from_float_to_decimal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_float_to_decimal_1);
  tcase_add_test(tc, test_from_float_to_decimal_2);
  tcase_add_test(tc, test_from_float_to_decimal_3);
  tcase_add_test(tc, test_from_float_to_decimal_4);
  tcase_add_test(tc, test_from_float_to_decimal_5);
  tcase_add_test(tc, test_from_float_to_decimal_6);
  tcase_add_test(tc, test_from_float_to_decimal_7);
  tcase_add_test(tc, test_from_float_to_decimal_8);
  tcase_add_test(tc, test_from_float_to_decimal_9);
  tcase_add_test(tc, test_from_float_to_decimal_10);
  tcase_add_test(tc, test_from_float_to_decimal_11);
  tcase_add_test(tc, test_from_float_to_decimal_12);
  tcase_add_test(tc, test_from_float_to_decimal_13);

  return s;
}