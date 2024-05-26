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
  // printf("tmp = %f\nres = %f\n", tmp, res);
  ck_assert_uint_eq(res, tmp);
}
END_TEST

// add test

START_TEST(test_from_float_to_decimal_17) {
  float num = -27348;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000000000000110101011010100);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_from_float_to_decimal_18) {
  float num = 823923;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 823923);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_19) {
  float num = -129312304;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 129312304);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147483648);
}
END_TEST

START_TEST(test_from_float_to_decimal_22) {
  float num = 912479.2;

  int res = s21_from_float_to_decimal(num, NULL);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_23) {
  float num = -123234.000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000000000011110000101100010);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_from_float_to_decimal_24) {
  float num = 1e-29;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_25) {
  float num = -23748280;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 23748280);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147483648);
}
END_TEST

START_TEST(test_from_float_to_decimal_26) {
  float num = 802000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 802000);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_27) {
  float num = 1.333112552412212431124;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000110010110110101010110110);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b00000000000001110000000000000000);
}
END_TEST

START_TEST(test_from_float_to_decimal_28) {
  float num = 0.5632482;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 5632482);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 458752);
}
END_TEST

START_TEST(test_from_float_to_decimal_29) {
  float num = 0.5632482;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 5632482);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 458752);
}
END_TEST

START_TEST(test_from_float_to_decimal_30) {
  float num = -0.6527385;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 6527385);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147024896);
}
END_TEST

START_TEST(test_from_float_to_decimal_31) {
  float num = -12397620;
  s21_decimal res_bits = {{0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000101111010010110000110100);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_from_float_to_decimal_32) {
  float num = 12397620;
  s21_decimal res_bits = {{0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000101111010010110000110100);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(test_from_float_to_decimal_33) {
  s21_decimal dst = {0}, origin = {0};
  float src = 36401984.2348234;
  int dst_output = 0;
  int result_output = 0;

  origin.bits[0] = 0b00000010001010110111001101000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_34) {
  // NULL тест
  s21_decimal dst = {0}, origin = {0};
  float src = 1234.5;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_35) {
  s21_decimal dst = {0}, origin = {0};
  float src = 36401984.2348234;
  int dst_output = 0;
  int result_output = 0;

  origin.bits[0] = 0b00000010001010110111001101000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_36) {
  s21_decimal dst = {0}, origin = {0};
  float src = 999999995;
  // 9999999|95.0
  // 10000000|00.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00111011100110101100101000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_37) {
  s21_decimal dst = {0}, origin = {0};
  float src = 0.00000000000000000000000000001f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_38) {
  s21_decimal dst = {0}, origin = {0};
  float src = 192836;
  // 192835.9|6
  // 192836.0|0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000101111000101000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_39) {
  s21_decimal dst = {0}, origin = {0};
  float src = -192836;
  // 3552346|23461234.12353236
  // 3552346|00000000.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000101111000101000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_40) {
  s21_decimal dst = {0}, origin = {0};
  float src = 999999995;
  // 9999999|95.0
  // 10000000|00.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00111011100110101100101000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_from_float_to_decimal_41) {
  s21_decimal dst = {0}, origin = {0};
  float src = 0.00000000000000000000000000001f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
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
  // tcase_add_test(tc, test_from_float_to_decimal_14);
  // tcase_add_test(tc, test_from_float_to_decimal_15);
  // tcase_add_test(tc, test_from_float_to_decimal_16);
  tcase_add_test(tc, test_from_float_to_decimal_17);
  tcase_add_test(tc, test_from_float_to_decimal_18);
  tcase_add_test(tc, test_from_float_to_decimal_19);
  // tcase_add_test(tc, test_from_float_to_decimal_20);
  // tcase_add_test(tc, test_from_float_to_decimal_21);
  tcase_add_test(tc, test_from_float_to_decimal_22);
  tcase_add_test(tc, test_from_float_to_decimal_23);
  tcase_add_test(tc, test_from_float_to_decimal_24);
  tcase_add_test(tc, test_from_float_to_decimal_25);
  tcase_add_test(tc, test_from_float_to_decimal_26);
  tcase_add_test(tc, test_from_float_to_decimal_27);
  tcase_add_test(tc, test_from_float_to_decimal_28);
  tcase_add_test(tc, test_from_float_to_decimal_29);
  tcase_add_test(tc, test_from_float_to_decimal_30);
  tcase_add_test(tc, test_from_float_to_decimal_31);
  tcase_add_test(tc, test_from_float_to_decimal_32);
  tcase_add_test(tc, test_from_float_to_decimal_33);
  tcase_add_test(tc, test_from_float_to_decimal_34);
  tcase_add_test(tc, test_from_float_to_decimal_35);
  tcase_add_test(tc, test_from_float_to_decimal_36);
  tcase_add_test(tc, test_from_float_to_decimal_37);
  tcase_add_test(tc, test_from_float_to_decimal_38);
  tcase_add_test(tc, test_from_float_to_decimal_39);
  tcase_add_test(tc, test_from_float_to_decimal_40);
  tcase_add_test(tc, test_from_float_to_decimal_41);

  return s;
}