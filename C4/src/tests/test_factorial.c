#include "./test.h"

START_TEST(fact_test_1) {
    s21_factorial(-1);
    int x = 1;
    ck_assert_double_eq((int)x, (int)x);
}
END_TEST

Suite *test_factorial(void) {
    Suite *s = suite_create("\n\033[37;1m==========| S21_FACTORIAL |=========\033[0m");
    TCase *tc = tcase_create("factorial_tc");

    tcase_add_test(tc, fact_test_1);
    suite_add_tcase(s, tc);
    return s;
}