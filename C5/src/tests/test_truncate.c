#include "./test.h"

START_TEST(test_truncate_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_truncate_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_truncate_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

// START_TEST(test_truncate_3) {
//   s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal res = {0};
// setScale(&val, 5);
//   ck_assert_int_eq(0, s21_truncate(val, &res));
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   float need = -0.0;
//   ck_assert_float_eq(need, fres);
// }
// END_TEST

// START_TEST(test_truncate_4) {
//   s21_decimal val = {{128, 0, 0, 0}};
//   s21_decimal res = {0};
//   setScale(&val, 1);
//   ck_assert_int_eq(0, s21_truncate(val, &res));
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   float need = 12;
//   ck_assert_float_eq(need, fres);
// }
// END_TEST

Suite *test_truncate(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_TRUNCATE |=========\033[0m");
  TCase *tc = tcase_create("tc_truncate");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_truncate_0);
  tcase_add_test(tc, test_truncate_1);
  tcase_add_test(tc, test_truncate_2);
  // tcase_add_test(tc, test_truncate_3);
  // tcase_add_test(tc, test_truncate_4);
  return s;
}