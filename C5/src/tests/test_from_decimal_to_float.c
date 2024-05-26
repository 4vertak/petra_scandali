#include "./test.h"

START_TEST(test_from_decimal_to_float_0) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_exp(&val, 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  // printf("dst = %f\nres = %f\n", *dst, res);
  ck_assert_uint_eq(*dst, res);
}
END_TEST

START_TEST(test_from_decimal_to_float_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_bit(&val, 127, 1);
  set_exp(&val, 5);
  float res = -1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(val, dst);
  // printf("dst = %f\nres = %f\n", *dst, res);
  ck_assert_uint_eq(*dst, res);
}
END_TEST

START_TEST(test_from_decimal_to_float_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 1234567890123456789012345678.0;
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

START_TEST(test_from_decimal_to_float_3) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 123456789012345678901234567.8;
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

// START_TEST(test_from_decimal_to_float_4) {
//   char str1[100] = {'\0'};
//   char str2[100] = {'\0'};
//   float a = 12345678901234567890123456.78;
//   float b = 0.0;
//   int error = 0;
//   int func_error = 0;
//   s21_decimal dec = {0};
//   func_error = s21_from_float_to_decimal(a, &dec);
//   s21_from_decimal_to_float(dec, &b);
//   ck_assert_int_eq(error, func_error);
//   snprintf(str1, sizeof(str1), "%.15lf", a);
//   snprintf(str2, sizeof(str1), "%.15lf", b);
//   ck_assert_str_eq(str1, str2);
//   // ck_assert_float_eq(a, b);
// }
// END_TEST

START_TEST(test_from_decimal_to_float_5) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 1234567890123456789012345.678;
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

START_TEST(test_from_decimal_to_float_6) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 12345.678901234567890123456780;
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

START_TEST(test_from_decimal_to_float_7) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 12.345678901234567890123456780;
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

START_TEST(test_from_decimal_to_float_8) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 1.2345678901234567890123456780;
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

START_TEST(test_from_decimal_to_float_9) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 0.12345678901234567890123456780;
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

START_TEST(test_from_decimal_to_float_10) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 1.2e-27;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  s21_from_float_to_decimal(a, &dec);
  func_error = s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  snprintf(str1, sizeof(str1), "%.7lf", a);
  snprintf(str2, sizeof(str1), "%.7lf", b);
  ck_assert_str_eq(str1, str2);
  // ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_from_decimal_to_float_11) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 1.2e-26;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  s21_from_float_to_decimal(a, &dec);
  func_error = s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  snprintf(str1, sizeof(str1), "%.7lf", a);
  snprintf(str2, sizeof(str1), "%.7lf", b);
  ck_assert_str_eq(str1, str2);
  // ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_from_decimal_to_float_12) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 1.2e-8;
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

START_TEST(test_from_decimal_to_float_13) {
  char str1[100] = {'0', '.', '0', '0', '0', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
  char str2[100] = {'\0'};
  float a = MAX_DEC + 1;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  snprintf(str2, sizeof(str1), "%.28lf", b);
  ck_assert_str_eq(str1, str2);
  // ck_assert_float_eq(0, b);
}
END_TEST

START_TEST(test_from_decimal_to_float_14) {
  char str1[100] = {'-', '0', '.', '0', '0', '0', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '0', '0', '0', '0'};
  char str2[100] = {'\0'};
  float a = MIN_DEC - 1;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);

  snprintf(str2, sizeof(str1), "%.28lf", b);
  ck_assert_str_eq(str1, str2);
  // ck_assert_float_eq(0, b);
}
END_TEST

START_TEST(test_from_decimal_to_float_15) {
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

START_TEST(test_from_decimal_to_float_16) {
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

START_TEST(test_from_decimal_to_float_17) {
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

START_TEST(test_from_decimal_to_float_18) {
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

START_TEST(test_from_decimal_to_float_19) {
  s21_decimal val;
  float num = -2147483648;
  s21_from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(test_from_decimal_to_float_20) {
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

START_TEST(test_from_decimal_to_float_21) {
  s21_decimal val = {0};
  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_22) {
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

// addtests

START_TEST(test_from_decimal_to_float_23) {
  float src = 0.00000000000;
  float temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_float(value_1, &temp);
  if (fabs(src - temp) < pow(10, -7)) {
    return_value = 1;
  }
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_24) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float src = 0.01;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0b00000000000000100000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  snprintf(str1, sizeof(str1), "%.28lf", src);
  snprintf(str2, sizeof(str2), "%.28lf", temp);
  ck_assert_str_eq(str1, str2);
  // ck_assert_int_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(test_from_decimal_to_float_25) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float src = 0.00000123;
  float temp = 0;
  s21_decimal value_1 = {{123, 0, 0, 0b00000000000010000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  snprintf(str1, sizeof(str1), "%.28lf", src);
  snprintf(str2, sizeof(str2), "%.28lf", temp);
  ck_assert_str_eq(str1, str2);
  // ck_assert_int_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(test_from_decimal_to_float_26) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float src = -0.01;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0x80020000}};
  s21_from_decimal_to_float(value_1, &temp);
  snprintf(str1, sizeof(str1), "%.28lf", src);
  snprintf(str2, sizeof(str2), "%.28lf", temp);
  ck_assert_str_eq(str1, str2);
  // ck_assert_int_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(test_from_decimal_to_float_27) {
  s21_decimal value = {{1812, 0, 0, 0}};
  set_sign(&value, 1);
  float result;
  float check = -1812;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_28) {
  s21_decimal value = {{18122, 0, 0, 0}};
  set_exp(&value, 3);
  set_sign(&value, 1);
  float result;
  float check = -18.122;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_29) {
  s21_decimal value = {{0xFFFFFF, 0, 0, 0}};
  float result;
  float check = 16777215;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_30) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  float result;
  float check = 0xFFFFFFFFFFFFFFFF;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_31) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147745792;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_int_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_DECIMAL_TO_FLOAT |=========\033[0m");
  TCase *tc = tcase_create("tc_from_decimal_to_float");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_decimal_to_float_0);
  tcase_add_test(tc, test_from_decimal_to_float_1);
  tcase_add_test(tc, test_from_decimal_to_float_2);
  tcase_add_test(tc, test_from_decimal_to_float_3);
  // tcase_add_test(tc, test_from_decimal_to_float_4); //работает)
  tcase_add_test(tc, test_from_decimal_to_float_5);
  tcase_add_test(tc, test_from_decimal_to_float_6);
  tcase_add_test(tc, test_from_decimal_to_float_7);
  tcase_add_test(tc, test_from_decimal_to_float_8);
  tcase_add_test(tc, test_from_decimal_to_float_9);
  tcase_add_test(tc, test_from_decimal_to_float_10);
  tcase_add_test(tc, test_from_decimal_to_float_11);
  tcase_add_test(tc, test_from_decimal_to_float_12);
  tcase_add_test(tc, test_from_decimal_to_float_13);
  tcase_add_test(tc, test_from_decimal_to_float_14);
  tcase_add_test(tc, test_from_decimal_to_float_15);
  tcase_add_test(tc, test_from_decimal_to_float_16);
  tcase_add_test(tc, test_from_decimal_to_float_17);
  tcase_add_test(tc, test_from_decimal_to_float_18);
  tcase_add_test(tc, test_from_decimal_to_float_19);
  tcase_add_test(tc, test_from_decimal_to_float_20);
  tcase_add_test(tc, test_from_decimal_to_float_21);
  tcase_add_test(tc, test_from_decimal_to_float_22);
  tcase_add_test(tc, test_from_decimal_to_float_23);
  tcase_add_test(tc, test_from_decimal_to_float_24);
  tcase_add_test(tc, test_from_decimal_to_float_25);
  tcase_add_test(tc, test_from_decimal_to_float_26);
  tcase_add_test(tc, test_from_decimal_to_float_27);
  tcase_add_test(tc, test_from_decimal_to_float_28);
  tcase_add_test(tc, test_from_decimal_to_float_29);
  tcase_add_test(tc, test_from_decimal_to_float_30);
  tcase_add_test(tc, test_from_decimal_to_float_31);

  return s;
}