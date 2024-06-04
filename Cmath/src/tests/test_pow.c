#include "./test.h"

// START_TEST(pow_test_0) {
//     ck_assert_double_eq(s21_pow(0, 0), pow(0, 0));
//     ck_assert_double_eq(s21_pow(1, 0), pow(1, 0));
//     ck_assert_double_eq(s21_pow(0, 1), pow(0, 1));
//     ck_assert_double_eq(s21_pow(1, 1), pow(1, 1));
//     ck_assert_double_eq(s21_pow(1, -1), pow(1, -1));
//     ck_assert_double_eq(s21_pow(-1, 1), pow(-1, 1));
//     ck_assert_double_eq(s21_pow(-1, -1), pow(-1, -1));
// }
// END_TEST;

START_TEST(pow_test_1) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, S21_INF_NEG),
                      pow(S21_INF_NEG, S21_INF_NEG));
  ck_assert_double_eq(s21_pow(S21_INF_NEG, S21_INF_POS),
                      pow(S21_INF_NEG, S21_INF_POS));
  ck_assert_double_eq(s21_pow(S21_INF_NEG, 1), pow(S21_INF_NEG, 1));
  ck_assert_double_nan(s21_pow(-20, 0.4));
  ck_assert_double_nan(pow(-20, 0.4));
}
END_TEST

START_TEST(pow_test_2) {
  // ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(pow(NAN, NAN));
  ck_assert_double_eq(s21_exp(S21_INF_NEG), exp(S21_INF_NEG));
}
END_TEST

/*START_TEST(pow_test_3) {
  ck_assert_double_eq(s21_pow(1, S21_NAN), pow(1, S21_NAN));
  ck_assert_double_nan(s21_pow(1, NAN));
  ck_assert_double_nan(pow(1, NAN));
}
END_TEST

START_TEST(pow_test_4) {
  ck_assert_double_eq(s21_pow(2.0, 1.1), pow(2.0, 1.1));
}
END_TEST

START_TEST(pow_test_5) {
  ck_assert_double_eq(s21_pow(2.0, -1.0), pow(2.0, -1.0));
  ck_assert_double_eq(s21_pow(2.0, 0), pow(2.0, 0));
  ck_assert_double_eq(s21_pow(2.0, 1), pow(2.0, 1.0));
  ck_assert_double_eq(s21_pow(2.0, 2.0), pow(2.0, 2.0));
  ck_assert_double_eq(s21_pow(2.0, 3.0), pow(2.0, 3.0));
  ck_assert_double_eq(s21_pow(2.0, 4.0), pow(2.0, 4.0));
}
END_TEST*/

Suite *test_pow(void) {
  Suite *s = suite_create("\n\033[37;1m==========| S21_POW |=========\033[0m");
  TCase *tc = tcase_create("pow_tc");

  // tcase_add_test(tc, pow_test_0);
  tcase_add_test(tc, pow_test_1);
  tcase_add_test(tc, pow_test_2);
  /*tcase_add_test(tc, pow_test_3);
  tcase_add_test(tc, pow_test_4);
  tcase_add_test(tc, pow_test_5);*/
  suite_add_tcase(s, tc);
  return s;
}