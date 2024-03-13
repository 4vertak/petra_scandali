#include "./test.h"

START_TEST(strtok_1) {
  char str[] = "Hello, world!";
  char d[] = ",.;!?-_ ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

START_TEST(strtok_2) {
  char str[] = ",hello;world!";
  char d[] = ",.;!?-_ ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

START_TEST(strtok_3) {
  char str[] = ",;!,";
  char d[] = ",.;!?-_ ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

START_TEST(strtok_4) {
  char str[] = " ";
  char d[] = ",.;!?-_ ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

START_TEST(strtok_5) {
  char str[] = " ";
  char d[] = ",.;!?-_ ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

// START_TEST(strtok_6) {
//   char *str = s21_NULL;
//   char d[] = ",. ";
//   ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
// }
// END_TEST

START_TEST(strtok_7) {
  char str[] = "\0";
  char d[] = ",.;!?-_ ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

START_TEST(strtok_8) {
  char str[] = "Hello, World, BYE, MOON!";
  char delim[] = ",! ";
  char *token = s21_strtok(str, delim);
  while (token != s21_NULL) {
    // printf("%s\n", token);
    token = s21_strtok(s21_NULL, delim);
  }
  char *real_token = strtok(str, delim);
  while (real_token != s21_NULL) {
    // printf("%s'n", real_token);
    real_token = s21_strtok(s21_NULL, delim);
  }
  ck_assert_ptr_eq(token, real_token);
}
END_TEST

START_TEST(strtok_9) {
  char str[] = "ya_prosto_reshil_eto_sdelav_v_func_null";
  char d[] = ",.! ";
  ck_assert_ptr_eq(strtok(str, d), s21_strtok(str, d));
}
END_TEST

START_TEST(strtok_13) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_str_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_str_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_str_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_str_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  }
  ck_assert_str_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_str_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  ck_assert_str_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
}
END_TEST

START_TEST(strtok_17) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(strtok_18) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(s21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(s21_NULL, s3);

  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s4, s5);
  ck_assert_str_eq(s6, s7);
}
END_TEST

START_TEST(strtok_20) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_str_eq(s1, s2);
}
END_TEST

Suite *test_strtok(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_STRTOK=========\033[0m");

  tc = tcase_create("strtok");
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  // tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);
  tcase_add_test(tc, strtok_16);
  tcase_add_test(tc, strtok_17);
  tcase_add_test(tc, strtok_18);
  tcase_add_test(tc, strtok_19);
  tcase_add_test(tc, strtok_20);

  suite_add_tcase(s, tc);
  return s;
}
