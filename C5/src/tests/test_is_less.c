#include "./test.h"

START_TEST(test_is_less_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_bit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_bit(&val1, 127, 1);
  set_bit(&val2, 127, 0);
  set_bit(&val1, 83, 1);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_bit(&val1, 127, 1);
  set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(test_is_less_7) {
  float a = -25.158531;
  float b = -39.425785;

  s21_decimal _a = {0};
  s21_decimal _b = {0};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less(_a, _b), a < b);
}
END_TEST

START_TEST(test_is_less_8) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_is_less_9) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_10) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_11) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_12) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_13) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_14) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_15) {
  float num1 = -34534534.232446543232446543;
  float num2 = -3.232323233232323233;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_16) {
  s21_decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2
  ck_assert_int_eq(s21_is_less(dec5, dec6), 0);
  ck_assert_int_eq(s21_is_less(dec6, dec5), 1);

  s21_decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(s21_is_less(dec7, dec8), 1);
  ck_assert_int_eq(s21_is_less(dec8, dec7), 0);

  s21_decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(s21_is_less(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_less(dec2, dec1), 1);

  s21_decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(s21_is_less(dec3, dec4), 1);
  ck_assert_int_eq(s21_is_less(dec4, dec3), 0);

  s21_decimal dec9 = {{12345, 0, 0, 0}};
  s21_decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(dec9, dec10), 0);
  ck_assert_int_eq(s21_is_less(dec10, dec9), 0);

  s21_decimal dec11 = {{0, 0, 0, 0}};
  s21_decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(dec11, dec12), 0);
  ck_assert_int_eq(s21_is_less(dec12, dec11), 0);
}
END_TEST

Suite *test_is_less(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_IS_LESS |=========\033[0m");
  TCase *tc = tcase_create("tc_is_less");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_is_less_0);
  tcase_add_test(tc, test_is_less_1);
  tcase_add_test(tc, test_is_less_2);
  tcase_add_test(tc, test_is_less_3);
  tcase_add_test(tc, test_is_less_4);
  tcase_add_test(tc, test_is_less_5);
  tcase_add_test(tc, test_is_less_6);
  tcase_add_test(tc, test_is_less_7);
  tcase_add_test(tc, test_is_less_8);
  tcase_add_test(tc, test_is_less_9);
  tcase_add_test(tc, test_is_less_10);
  tcase_add_test(tc, test_is_less_11);
  tcase_add_test(tc, test_is_less_12);
  tcase_add_test(tc, test_is_less_13);
  tcase_add_test(tc, test_is_less_14);
  tcase_add_test(tc, test_is_less_15);
  tcase_add_test(tc, test_is_less_16);

  return s;
}