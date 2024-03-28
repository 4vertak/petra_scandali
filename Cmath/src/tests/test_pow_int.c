#include "./test.h"

START_TEST(pow_int_test_1) {
    ck_assert_int_eq(s21_pow_int(2, -1), pow(2, -1));
}
END_TEST;

Suite *test_pow_int(void) {
    Suite *s = suite_create("\n\033[37;1m==========| S21_POW_INT |=========\033[0m");
    TCase *tc = tcase_create("pow_int_tc");

    tcase_add_test(tc, pow_int_test_1);
    suite_add_tcase(s, tc);
    return s;
}

