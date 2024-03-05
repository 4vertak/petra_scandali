#include "./test.h"
#define BUFF_SIZE 512

START_TEST(test_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is int value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_accuracy_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_left_align_minus) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-5li";
//   int val = 69;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_explicit_signs_plus) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%+12d";
//   int val = 69;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_filling_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%05i";
//   int val = 69;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_addarg_width_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%0*d";
//   int val = 69;
//   ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                    sprintf(str2, format, 5, val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_addarg_accuracy_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%0.*i";
//   int val = 69;
//   ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                    sprintf(str2, format, 5, val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_flags_ints) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char format[] = "%0.*i %d %4.*i %013d %d";
//   int val = 69;
//   ck_assert_int_eq(
//       s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
//       sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_long_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%+5.31li";
//   long int val = 698518581899;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_short_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-16.9hi";
//   short int val = 6958;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_another_long_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%0.*ld";
//   long val = 8581385185;
//   ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                    sprintf(str2, format, 5, val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_zero_accuracy_zero_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%.0d";
//   int val = 0;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_space_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "% d";
//   int val = 0;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_unsigned) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%u";
//   unsigned int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_unsigned_width) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%15u";
//   unsigned int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_unsigned_left_align_minus) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-16u";
//   unsigned int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_unsigned_accuracy) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%.51u";
//   unsigned int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_unsigned_many_flags) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "% 5.51u";
//   unsigned int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_unsigned_short) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%hu";
//   unsigned short int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_unsigned_long) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%lu";
//   unsigned long int val = 949149114140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_many) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%lu, %u, %hu, %.5u, %5.u";
//   unsigned long int val = 949149114140;
//   ck_assert_int_eq(
//       s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//       sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
//               (unsigned)14414, (unsigned)9681));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_octal_width) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%15o";
//   int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_octal_flags) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-16o";
//   int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_octal_accuracy) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%.51o";
//   int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_octal_many_flags) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-5.51o";
//   int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_octal_zero) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%o";
//   ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_octal_short) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%hd";
//   short int val = 14140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_octal_long) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%lo";
//   long int val = 949149114140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_unsigned_zero) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%u";
//   ck_assert_int_eq(s21_sprintf(str1, format, 0),
//                    sprintf(str2, format, (unsigned)0));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%c";
//   char val = 'X';
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_char_accuracy) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%.5c";
//   char val = 'c';
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_char_left_align_minus) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "% -5c";
//   char val = 'c';
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(one_width) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%15c";
//   char val = 'c';
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_char_many) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
//   char val = 'c';
//   ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
//                    sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_char_many_flags) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-5.3c";
//   char val = 'c';
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_string) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%s";
//   char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_string_accurancy) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%.15s";
//   char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_string_width) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%15s";
//   char *val = "69 IS MY FAVORITE NUMBER";
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_string_many_flags) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%-15.9s";
//   char *val = "69 IS MY FAVORITE NUMBER";
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_string_many_args) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%s%s%s%s";
//   char *val =
//       "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
//   char *s1 = "";
//   char *s2 = "87418347813748913749871389480913";
//   char *s3 = "HAHAABOBASUCKER";
//   ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
//                    sprintf(str2, format, val, s1, s2, s3));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_string_width_huge) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char *val = "kjafdiuhfjahfjdahf";
//   char *format = "%120s";
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_empty_format_and_parameters) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c",
//   '\t'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S',
//   's'),
//                    sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_string) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
//                    sprintf(str2, "%s", "Drop Sega PLS"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_string) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(
//       s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
//       sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_dec) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_dec) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
//                    sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
//                    sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_unsigned_dec) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
//                    sprintf(str2, "%u", (unsigned)100));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_unsigned_dec) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
//                    sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
//                            (unsigned)666, (unsigned)100));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_char_with_alignment_left) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c",
//   '\t'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_char_with_alignment_right) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
//                    sprintf(str2, "%-8c", '\t'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_char_with_alignment) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   ck_assert_int_eq(
//       s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
//       sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf1) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%10ld";

//   ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf3) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%8.3c";

//   ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format,
//   'a'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf4) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%+5.5d aboba";

//   int val = 10000;
//   int a = s21_sprintf(str1, format, val);
//   int b = sprintf(str2, format, val);
//   ck_assert_int_eq(a, b);

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf7) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%7.4s";

//   ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
//                    sprintf(str2, format, "aboba floppa"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf8) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%6.6u";

//   ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
//                    sprintf(str2, format, 12341151));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf9) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%li%ld%lu";

//   ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
//                    sprintf(str2, format, 666666666666, 777, 111));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf10) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%hi%hd%hu";

//   ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
//                    sprintf(str2, format, 666, -777, 111));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf15) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

//   ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333,
//   -166513.1232),
//                    sprintf(str2, format, 1, 222, 33333333333,
//                    -166513.1232));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf16) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "% c";

//   ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format,
//   'a'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf17) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "% s";

//   ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
//                    sprintf(str2, format, "aboba likes floppa"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf18) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "% s% c";

//   ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
//                    sprintf(str2, format, "", 'f'));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf19) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%210s";

//   ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
//                    sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf20) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%-115s";

//   ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
//                    sprintf(str2, format, "Nick her"));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf28) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   int n1;
//   int n2;
//   int a = s21_sprintf(str1, "%d%n", 123, &n1);
//   int b = sprintf(str2, "%d%n", 123, &n2);

//   ck_assert_int_eq(a, b);
//   ck_assert_int_eq(n1, n2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf30) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%-.1d";

//   ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format,
//   111));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf43) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%.5o";

//   ck_assert_int_eq(s21_sprintf(str1, format, 12345),
//                    sprintf(str2, format, 12345));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(wide_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %lc";
//   unsigned long w = L'汉';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(width_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %5c";
//   char w = 'c';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(minus_wide_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %-5lc";
//   unsigned long w = L'森';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string1) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %5.12ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %120ls ABOBA";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string3) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %-43ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string4) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %43ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_char2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %43lc";
//   unsigned long w = L'森';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_int_eq(a, b);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

Suite *test_sprintf(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_SPRINTF=========\033[0m");
  tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, test_int);
  tcase_add_test(tc, test_accuracy_int);
  tcase_add_test(tc, test_width_int);
  // tcase_add_test(tc, test_left_align_minus);
  // tcase_add_test(tc, test_explicit_signs_plus);
  // tcase_add_test(tc, test_filling_int);
  // tcase_add_test(tc, test_addarg_width_int);
  // tcase_add_test(tc, test_addarg_accuracy_int);
  // tcase_add_test(tc, test_many_flags_ints);
  // tcase_add_test(tc, test_long_int);
  // tcase_add_test(tc, test_short_int);
  // tcase_add_test(tc, test_another_long_int);
  // tcase_add_test(tc, test_zero_accuracy_zero_int);
  // tcase_add_test(tc, test_space_int);
  // tcase_add_test(tc, test_unsigned);
  // tcase_add_test(tc, test_unsigned_width);
  // tcase_add_test(tc, test_unsigned_left_align_minus);
  // tcase_add_test(tc, test_unsigned_accuracy);
  // tcase_add_test(tc, test_unsigned_many_flags);
  // tcase_add_test(tc, test_unsigned_short);
  // tcase_add_test(tc, test_unsigned_long);
  // tcase_add_test(tc, unsigned_many);
  // tcase_add_test(tc, test_octal_width);
  // tcase_add_test(tc, test_octal_flags);
  // tcase_add_test(tc, test_octal_accuracy);
  // tcase_add_test(tc, test_octal_many_flags);
  // tcase_add_test(tc, test_octal_short);
  // tcase_add_test(tc, test_octal_long);
  // tcase_add_test(tc, test_unsigned_zero);
  // tcase_add_test(tc, test_char);
  // tcase_add_test(tc, test_char_left_align_minus);
  // tcase_add_test(tc, test_octal_zero);
  // tcase_add_test(tc, one_width);
  // tcase_add_test(tc, test_char_accuracy);
  // tcase_add_test(tc, test_char_many);
  // tcase_add_test(tc, test_char_many_flags);
  // tcase_add_test(tc, test_string);
  // tcase_add_test(tc, test_string_accurancy);
  // tcase_add_test(tc, test_string_width);
  // tcase_add_test(tc, test_string_many_flags);
  // tcase_add_test(tc, test_string_many_args);
  // tcase_add_test(tc, test_string_width_huge);
  // tcase_add_test(tc, test_empty_format_and_parameters);
  // tcase_add_test(tc, test_one_char);
  // tcase_add_test(tc, one_width);
  // tcase_add_test(tc, test_many_char);
  // tcase_add_test(tc, test_one_string);
  // tcase_add_test(tc, test_many_string);
  // tcase_add_test(tc, test_one_dec);
  // tcase_add_test(tc, test_many_dec);
  // tcase_add_test(tc, test_one_int);
  // tcase_add_test(tc, test_many_int);
  // tcase_add_test(tc, test_one_unsigned_dec);
  // tcase_add_test(tc, test_many_unsigned_dec);
  // tcase_add_test(tc, test_one_char_with_alignment_left);
  // tcase_add_test(tc, test_one_char_with_alignment_right);
  // tcase_add_test(tc, test_many_char_with_alignment);
  // tcase_add_test(tc, test_sprintf1);
  // tcase_add_test(tc, test_sprintf3);
  // tcase_add_test(tc, test_sprintf4);
  // tcase_add_test(tc, test_sprintf7);
  // tcase_add_test(tc, test_sprintf8);
  // tcase_add_test(tc, test_sprintf9);
  // tcase_add_test(tc, test_sprintf10);
  // tcase_add_test(tc, test_sprintf15);
  // tcase_add_test(tc, test_sprintf16);
  // tcase_add_test(tc, test_sprintf17);
  // tcase_add_test(tc, test_sprintf18);
  // tcase_add_test(tc, test_sprintf19);
  // tcase_add_test(tc, test_sprintf20);
  // tcase_add_test(tc, test_sprintf28);
  // tcase_add_test(tc, test_sprintf30);
  // tcase_add_test(tc, test_sprintf43);
  // tcase_add_test(tc, wide_char);
  // tcase_add_test(tc, width_char);
  // tcase_add_test(tc, wide_string);
  // tcase_add_test(tc, wide_string1);
  // tcase_add_test(tc, wide_string2);
  // tcase_add_test(tc, wide_string3);
  // tcase_add_test(tc, wide_string4);
  // tcase_add_test(tc, wide_char2);
  suite_add_tcase(s, tc);
  return s;
}

// Suite * Money_suite (void)
//  {
//      Suite *s;
//      TCase *tc_core;
//      TCase *tc_limits;

//      s = suite_create("Деньги");

//      /* Основной тестовый пример */
//      tc_core = tcase_create("Core");

// + tcase_add_checked_fixture(tc_core, setup, демонтаж);
//      tcase_add_test (tc_core, test_money_create);
//      suite_add_tcase(s, tc_core);

//      /* Тестовый пример ограничений */
//      tc_limits = tcase_create("Limits");

//      tcase_add_test(tc_limits, test_money_create_neg);
//      tcase_add_test(tc_limits, test_money_create_zero);
//      suite_add_tcase(s, tc_limits);

//      вернуть с;
//  }
