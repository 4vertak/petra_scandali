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

// add test90

START_TEST(test_div_17) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

// ПРОВЕРИТЬ НА КОРРЕКТНОСТЬ
// START_TEST(test_div_18) {
//   s21_decimal value_2 = {0};
//   s21_decimal value_1 = {0};
//   s21_decimal result = {0};
//   int x = 2, y = 3;
//   s21_from_int_to_decimal(x, &value_1);
//   s21_from_int_to_decimal(y, &value_2);
//   int return_value = s21_div(value_1, value_2, &result);
//   float result_float = 0;
//   s21_from_decimal_to_float(result, &result_float);
//   ck_assert_int_eq(fabs((result_float - 0.66666)) < 1e-4, 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

START_TEST(test_div_19) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_div_20) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(test_div_21) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  int a = 1246, b = 2;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int rez = 0, origin_rez = a / b;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  s21_from_decimal_to_int(result, &rez);
  ck_assert_int_eq(rez, origin_rez);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_div_22) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  int a = 1246, b = 4;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int rez = 0, origin_rez = a / b;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  s21_from_decimal_to_int(result, &rez);
  ck_assert_int_eq(rez, origin_rez);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_div_23) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  float a = 5224, b = 20;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float rez = 0, origin_rez = a / b;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  s21_from_decimal_to_float(result, &rez);
  ck_assert_int_eq(rez, origin_rez);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_div_24) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  float a = 5224, b = 235;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float rez = 0, origin_rez = a / b;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  s21_from_decimal_to_float(result, &rez);
  ck_assert_int_eq(rez, origin_rez);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_div_25) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  float a = 65224, b = 23512;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float rez = 0, origin_rez = a / b;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  s21_from_decimal_to_float(result, &rez);
  ck_assert_int_eq(rez, origin_rez);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_div_26) {
  s21_decimal src1, src2, result;
  int a = 32768;
  int b = 2;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 16384;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  s21_from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(test_div_27) {
  s21_decimal src1, src2, result, origin;
  // 0
  // 0.015
  // 0
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_div_28) {
  s21_decimal src1, src2, result;
  // 3
  // 2
  // result = NULL;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check_origin, check);
}
END_TEST

START_TEST(test_div_29) {
  s21_decimal src1, src2, result;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int check = s21_div(src1, src2, &result);
  int check_origin = 3;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(test_div_30) {
//   s21_decimal src1, src2, result, origin;
//   // 1
//   // 3
//   // 0.3(3) ????
//   src1.bits[0] = 0b00000000000000000000000000000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000011;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   origin.bits[0] = 0b00000101010101010101010101010101;
//   origin.bits[1] = 0b00010100101101110000000011001011;
//   origin.bits[2] = 0b00001010110001010100010011001010;
//   origin.bits[3] = 0b00000000000111000000000000000000;
//   int check = s21_div(src1, src2, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(check, check_origin);
//   ck_assert_int_eq(result.bits[3], origin.bits[3]);
//   ck_assert_int_eq(result.bits[2], origin.bits[2]);
//   ck_assert_int_eq(result.bits[1], origin.bits[1]);
//   ck_assert_int_eq(result.bits[0], origin.bits[0]);
// }
// END_TEST

START_TEST(test_div_31) {
  s21_decimal src1, src2, result = {0};
  float a = -115.2;
  float b = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  int check = s21_div(src1, src2, &result);
  int check_origin = 3;
  ck_assert_int_eq(check_origin, check);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

// START_TEST(test_div_32) {
//   s21_decimal src1, src2, result = {{0}};
//   src1.bits[0] = 0b11111111111111111111111111111111;
//   src1.bits[1] = 0b11111111111111111111111111111111;
//   src1.bits[2] = 0b11111111111111111111111111111111;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000001;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000111000000000000000000;
//   int check = s21_div(src1, src2, &result);
//   int check_origin = 1;
//   ck_assert_int_eq(check, check_origin);
//   ck_assert_int_eq(result.bits[3], 0);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[1], 0);
//   ck_assert_int_eq(result.bits[0], 0);
// }
// END_TEST

START_TEST(test_div_33) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(test_div_34) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
  ck_assert_int_eq(return_value, 3);
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
  tcase_add_test(tc, test_div_17);
  // tcase_add_test(tc, test_div_18); // битс 3 проверить значения
  tcase_add_test(tc, test_div_19);
  tcase_add_test(tc, test_div_20);
  tcase_add_test(tc, test_div_21);
  tcase_add_test(tc, test_div_22);
  tcase_add_test(tc, test_div_23);
  tcase_add_test(tc, test_div_24);
  tcase_add_test(tc, test_div_25);
  tcase_add_test(tc, test_div_26);
  tcase_add_test(tc, test_div_27);
  tcase_add_test(tc, test_div_28);
  tcase_add_test(tc, test_div_29);
  // tcase_add_test(tc, test_div_30); // обрезка а нето переполнение
  tcase_add_test(tc, test_div_31);
  // tcase_add_test(tc, test_div_32); // ПЕРЕПОЛНЕНИЕ ???
  tcase_add_test(tc, test_div_33);
  tcase_add_test(tc, test_div_34);

  return s;
}