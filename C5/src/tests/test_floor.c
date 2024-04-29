#include "./test.h"

START_TEST(test_floor_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

// START_TEST(test_floor_1) {
//   s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal res = {0};
//   s21_floor(val, &res);
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   ck_assert_float_eq(-2, fres);
// }
// END_TEST

// START_TEST(test_floor_2) {
//   s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal res = {0};
//   // setScale(&val, 5);
//   s21_floor(val, &res);
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   ck_assert_float_eq(-1, fres);
// }
// END_TEST

// START_TEST(test_floor_3) {
//   s21_decimal val = {{2, 0, 0, 0}};
//   s21_decimal res = {0};
//   // setScale(&val, 5);
//   s21_floor(val, &res);
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   ck_assert_float_eq(0, fres);
// }
// END_TEST

Suite *test_floor(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_FLOOR |=========\033[0m");
  TCase *tc = tcase_create("tc_floor");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_floor_0);
  // tcase_add_test(tc, test_floor_1);
  // tcase_add_test(tc, test_floor_2);
  // tcase_add_test(tc, test_floor_3);
  return s;
}