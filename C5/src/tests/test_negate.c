#include "./test.h"

START_TEST(test_negate_1) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_negate_2) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src = {0};
  s21_from_float_to_decimal(a, &src);
  s21_decimal res = {0};
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  snprintf(str1, sizeof(str1), "%.28lf", -10.1234e5);
  snprintf(str2, sizeof(str2), "%.28lf", res_a);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_negate(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_NEGATE |=========\033[0m");
  TCase *tc = tcase_create("tc_negate");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);
  //   tcase_add_test(tc, test_negate_3);
  //   tcase_add_test(tc, test_negate_4);
  //   tcase_add_test(tc, test_negate_5);
  //   tcase_add_test(tc, test_negate_6);
  //   tcase_add_test(tc, test_negate_7);
  //   tcase_add_test(tc, test_negate_8);
  //   tcase_add_test(tc, test_negate_9);
  //   tcase_add_test(tc, test_negate_10);
  //   tcase_add_test(tc, test_negate_11);
  //   tcase_add_test(tc, test_negate_12);
  //   tcase_add_test(tc, test_negate_13);
  //   tcase_add_test(tc, test_negate_14);
  //   tcase_add_test(tc, test_negate_15);
  //   tcase_add_test(tc, test_negate_16);
  //   tcase_add_test(tc, test_negate_17);
  //   tcase_add_test(tc, test_negate_18);
  //   tcase_add_test(tc, test_negate_19);
  //   tcase_add_test(tc, test_negate_20);
  //   tcase_add_test(tc, test_negate_21);
  //   tcase_add_test(tc, test_negate_22);
  //   tcase_add_test(tc, test_negate_23);
  //   tcase_add_test(tc, test_negate_24);
  //   tcase_add_test(tc, test_negate_25);
  //   tcase_add_test(tc, test_negate_26);
  //   tcase_add_test(tc, test_negate_27);
  //   tcase_add_test(tc, test_negate_28);
  //   tcase_add_test(tc, test_negate_29);
  //   tcase_add_test(tc, test_negate_30);
  //   tcase_add_test(tc, test_negate_31);
  //   tcase_add_test(tc, test_negate_32);
  //   tcase_add_test(tc, test_negate_33);
  //   tcase_add_test(tc, test_negate_34);
  //   tcase_add_test(tc, test_negate_35);
  //   tcase_add_test(tc, test_negate_36);
  //   tcase_add_test(tc, test_negate_37);
  //   tcase_add_test(tc, test_negate_38);
  //   tcase_add_test(tc, test_negate_39);
  //   tcase_add_test(tc, test_negate_40);
  //   tcase_add_test(tc, test_negate_41);
  //   tcase_add_test(tc, test_negate_42);
  //   tcase_add_test(tc, test_negate_43);
  //   tcase_add_test(tc, test_negate_44);
  //   tcase_add_test(tc, test_negate_45);
  //   tcase_add_test(tc, test_negate_46);
  //   tcase_add_test(tc, test_negate_47);
  //   tcase_add_test(tc, test_negate_48);
  //   tcase_add_test(tc, test_negate_49);
  //   tcase_add_test(tc, test_negate_50);
  //   tcase_add_test(tc, test_negate_51);
  //   tcase_add_test(tc, test_negate_52);
  //   tcase_add_test(tc, test_negate_53);
  //   tcase_add_test(tc, test_negate_54);
  //   tcase_add_test(tc, test_negate_55);
  //   tcase_add_test(tc, test_negate_56);
  //   tcase_add_test(tc, test_negate_57);
  //   tcase_add_test(tc, test_negate_58);
  //   tcase_add_test(tc, test_negate_59);
  //   tcase_add_test(tc, test_negate_60);
  //   tcase_add_test(tc, test_negate_61);
  //   tcase_add_test(tc, test_negate_62);
  //   tcase_add_test(tc, test_negate_63);
  //   tcase_add_test(tc, test_negate_64);
  //   tcase_add_test(tc, test_negate_65);
  //   tcase_add_test(tc, test_negate_66);
  //   tcase_add_test(tc, test_negate_67);
  //   tcase_add_test(tc, test_negate_68);
  //   tcase_add_test(tc, test_negate_69);
  //   tcase_add_test(tc, test_negate_70);
  //   tcase_add_test(tc, test_negate_71);
  //   tcase_add_test(tc, test_negate_72);
  //   tcase_add_test(tc, test_negate_73);
  //   tcase_add_test(tc, test_negate_74);
  //   tcase_add_test(tc, test_negate_75);
  //   tcase_add_test(tc, test_negate_76);
  //   tcase_add_test(tc, test_negate_77);
  //   tcase_add_test(tc, test_negate_78);
  //   tcase_add_test(tc, test_negate_79);
  //   tcase_add_test(tc, test_negate_80);
  //   tcase_add_test(tc, test_negate_81);
  //   tcase_add_test(tc, test_negate_82);
  //   tcase_add_test(tc, test_negate_83);
  //   tcase_add_test(tc, test_negate_84);
  //   tcase_add_test(tc, test_negate_85);
  //   tcase_add_test(tc, test_negate_86);
  //   tcase_add_test(tc, test_negate_87);
  //   tcase_add_test(tc, test_negate_88);
  //   tcase_add_test(tc, test_negate_89);
  //   tcase_add_test(tc, test_negate_90);
  //   tcase_add_test(tc, test_negate_91);
  //   tcase_add_test(tc, test_negate_92);
  //   tcase_add_test(tc, test_negate_93);
  //   tcase_add_test(tc, test_negate_94);
  //   tcase_add_test(tc, test_negate_95);
  //   tcase_add_test(tc, test_negate_96);
  //   tcase_add_test(tc, test_negate_97);
  //   tcase_add_test(tc, test_negate_98);
  //   tcase_add_test(tc, test_negate_99);

  return s;
}