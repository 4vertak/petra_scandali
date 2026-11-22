#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif
#include <check.h>
#include <errno.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

#include "./test.h"

#define LEN 4096

START_TEST(sscanf_test_c_1) {  // спецификатор c обычные ситуации
  char str_1[LEN] = "ab";
  char str_2[LEN] = "     ab ";
  char str_3[LEN] = "     a   b ";
  char a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%c", &a1), s21_sscanf(str_1, "%c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%c", &a1), s21_sscanf(str_2, "%c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "  %c", &a1), s21_sscanf(str_2, "  %c", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c%c", &a1, &b1),
                   s21_sscanf(str_3, "%c%c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "    %c%c", &a1, &b1),
                   s21_sscanf(str_3, "    %c%c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c  %c", &a1, &b1),
                   s21_sscanf(str_3, "%c  %c", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%c  %c ", &a1, &b1),
                   s21_sscanf(str_3, "%c  %c ", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_c_2) {  // спецификатор c +длина+ширина
  char str_1[LEN] = "ab";
  char str_2[LEN] = "     ab ";
  char str_3[LEN] = "     a   b ";
  wchar_t a1 = 0, a2 = 0, d1 = 0, d2 = 0;
  char b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%lc", &a1), s21_sscanf(str_1, "%lc", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1c", &b1), s21_sscanf(str_1, "%1c", &b2));
  ck_assert_int_eq(b1, b2);
  b1 = 0, b2 = 0;
  char expected[2], actual[2];
  ck_assert_int_eq(sscanf(str_1, "%2c", expected),
                   s21_sscanf(str_1, "%2c", actual));
  ck_assert_mem_eq(expected, actual, sizeof(actual));
  b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%1c%1c ", &b1, &c1),
                   s21_sscanf(str_2, "%1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, " %1c%1c ", &b1, &c1),
                   s21_sscanf(str_2, " %1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %1c%1c ", &b1, &c1),
                   s21_sscanf(str_3, " %1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%1c%1c ", &b1, &c1),
                   s21_sscanf(str_3, "%1c%1c ", &b2, &c2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);
  c1 = 0, c2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %lc%lc ", &a1, &d1),
                   s21_sscanf(str_3, " %lc%lc ", &a2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_3, " %lc%lc ", &a1, &d1),
                   s21_sscanf(str_3, " %lc%lc ", &a2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, d1 = 0, d2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_1) {  // спецификатор d обычные ситуации
  char str_1[LEN] = "ab";
  char str_2[LEN] = "123";
  char str_3[LEN] = "1b";
  char str_4[LEN] = "b1";
  char str_5[LEN] = "123 123";
  char str_6[LEN] = "123 1b";
  char str_7[LEN] = "1b 123";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d", &a1), s21_sscanf(str_1, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d", &a1), s21_sscanf(str_2, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d", &a1), s21_sscanf(str_3, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d", &a1), s21_sscanf(str_4, "%d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%d%d", &a1, &b1),
                   s21_sscanf(str_1, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_2, "%d%d", &a1, &b1),
                   s21_sscanf(str_2, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_3, "%d%d", &a1, &b1),
                   s21_sscanf(str_3, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_4, "%d%d", &a1, &b1),
                   s21_sscanf(str_4, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_5, "%d%d", &a1, &b1),
                   s21_sscanf(str_5, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_6, "%d%d", &a1, &b1),
                   s21_sscanf(str_6, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_7, "%d%d", &a1, &b1),
                   s21_sscanf(str_7, "%d%d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_2) {
  const char *inputs[] = {"+123",  "-123",      "+123 -123", "+123-123",
                          "++123", "------123", "+"};
  for (size_t i = 0; i < sizeof(inputs) / sizeof(*inputs); ++i) {
    int a = 42, b = 42, ref_a = 42, ref_b = 42;
    ck_assert_int_eq(s21_sscanf(inputs[i], "%d%d", &a, &b),
                     sscanf(inputs[i], "%d%d", &ref_a, &ref_b));
    ck_assert_int_eq(a, ref_a);
    ck_assert_int_eq(b, ref_b);
  }
}
END_TEST

START_TEST(sscanf_test_d_3) {  // спецификатор d длина+ширина h
  char str_1[LEN] = "12345";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%hd", &a1), s21_sscanf(str_1, "%hd", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hd", &a1), s21_sscanf(str_1, "%1hd", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1hd%1hd", &a1, &b1),
                   s21_sscanf(str_1, "%1hd%1hd", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_4) {  // спецификатор d длина+ширина l
  char str_1[LEN] = "123456";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%ld", &a1), s21_sscanf(str_1, "%ld", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1ld", &a1), s21_sscanf(str_1, "%1ld", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3ld%3ld", &a1, &b1),
                   s21_sscanf(str_1, "%3ld%3ld", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(sscanf_test_d_5) {  // спецификатор d ширина
  char str_1[LEN] = "123456";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1d", &a1), s21_sscanf(str_1, "%1d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%2d", &a1), s21_sscanf(str_1, "%2d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%6d", &a1), s21_sscanf(str_1, "%6d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%7d", &a1), s21_sscanf(str_1, "%7d", &a2));
  ck_assert_int_eq(a1, a2);
  a1 = 0, a2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%1d%1d", &a1, &b1),
                   s21_sscanf(str_1, "%1d%1d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  ck_assert_int_eq(sscanf(str_1, "%3d%3d", &a1, &b1),
                   s21_sscanf(str_1, "%3d%3d", &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
}
END_TEST

START_TEST(allocated_text_fields) {
  const char *input = " A  word:]-!tail";
  char raw[2], word[5], set[4], tail[8];
  int expected_count, count;
  ck_assert_int_eq(sscanf(input, "%2c %4s:%3[]-]!%7s%n", raw, word, set, tail,
                          &expected_count),
                   4);
  char *got_raw = NULL, *got_word = NULL, *got_set = NULL, *got_tail = NULL;
  ck_assert_int_eq(s21_sscanf(input, "%2mc %4ms:%m[]-]!%ms%n", &got_raw,
                              &got_word, &got_set, &got_tail, &count),
                   4);
  ck_assert_mem_eq(got_raw, raw, sizeof(raw));
  ck_assert_str_eq(got_word, word);
  ck_assert_str_eq(got_set, set);
  ck_assert_str_eq(got_tail, tail);
  ck_assert_int_eq(count, expected_count);
  free(got_raw);
  free(got_word);
  free(got_set);
  free(got_tail);
}
END_TEST

START_TEST(allocated_wide_fields) {
  const char *input = " A  cat:abc!";
  wchar_t raw[2], word[4], set[4];
  int expected_count, count;
  ck_assert_int_eq(
      sscanf(input, "%2lc %3ls:%3l[a-c]%n", raw, word, set, &expected_count),
      3);
  wchar_t *got_raw = NULL, *got_word = NULL, *got_set = NULL;
  ck_assert_int_eq(s21_sscanf(input, "%2mlc %3mls:%ml[a-c]%n", &got_raw,
                              &got_word, &got_set, &count),
                   3);
  ck_assert(wmemcmp(got_raw, raw, 2) == 0);
  ck_assert(wcscmp(got_word, word) == 0);
  ck_assert(wcscmp(got_set, set) == 0);
  ck_assert_int_eq(count, expected_count);
  free(got_raw);
  free(got_word);
  free(got_set);
}
END_TEST

START_TEST(wide_aliases_and_byte_counts) {
  wchar_t raw[3] = {L'x', L'x', L'!'}, word[4];
  int count;
  ck_assert_int_eq(s21_sscanf(" A cat", "%2C%3S%n", raw, word, &count), 2);
  ck_assert(wmemcmp(raw, L" A!", 3) == 0 && wcscmp(word, L"cat") == 0);
  ck_assert_int_eq(count, 6);

  if (setlocale(LC_CTYPE, "C.UTF-8") || setlocale(LC_CTYPE, "en_US.UTF-8") ||
      setlocale(LC_CTYPE, "UTF-8")) {
    const char *input = "\u00e9\u20ac \u0416\u0417\u03b1\u03b2!";
    wchar_t *pair = NULL, *letters = NULL, *greek = NULL;
    ck_assert_int_eq(s21_sscanf(input, "%2mC %2mS%ml[^!]%n", &pair, &letters,
                                &greek, &count),
                     3);
    ck_assert(wmemcmp(pair, L"\u00e9\u20ac", 2) == 0);
    ck_assert(wcscmp(letters, L"\u0416\u0417") == 0);
    ck_assert(wcscmp(greek, L"\u03b1\u03b2") == 0);
    ck_assert_uint_eq((size_t)count, strlen(input) - 1);
    free(pair);
    free(letters);
    free(greek);
  }
  setlocale(LC_CTYPE, "C");
}
END_TEST

START_TEST(wide_field_boundaries) {
  wchar_t word[8], *allocated = word;
  int count;
  ck_assert_int_eq(s21_sscanf("abc\xff", "%l[a-c]%n", word, &count), 1);
  ck_assert(wcscmp(word, L"abc") == 0);
  ck_assert_int_eq(count, 3);
  if (setlocale(LC_CTYPE, "C.UTF-8") || setlocale(LC_CTYPE, "en_US.UTF-8") ||
      setlocale(LC_CTYPE, "UTF-8")) {
    const char *input = "\u2003x\u2003 word";
    wchar_t ref[8];
    int ref_count;
    ck_assert_int_eq(sscanf(input, "%ls%n", ref, &ref_count), 1);
    ck_assert_int_eq(s21_sscanf(input, "%S%n", word, &count), 1);
    ck_assert(wcscmp(word, ref) == 0);
    ck_assert_int_eq(count, ref_count);

    // A scanset can end between the bytes of a wide character.
    errno = 0;
    int result = s21_sscanf("\u00ea", "%ml[\u00e9]", &allocated);
    int error = errno;
    ck_assert_int_eq(result, EOF);
    ck_assert_int_eq(error, EILSEQ);
    ck_assert_ptr_eq(allocated, word);
  }
  setlocale(LC_CTYPE, "C");
}
END_TEST

START_TEST(numbered_arguments) {
  const char *input = "ignore 013 7f % 0x1.8p+1 hi";
  int number, ref_number;
  unsigned char byte, ref_byte;
  short count, ref_count;
  double fraction, ref_fraction;
  char *word = NULL, ref_word[3];
  ck_assert_int_eq(sscanf(input, "%*s %3i %hhx %% %la %2s%hn", &ref_number,
                          &ref_byte, &ref_fraction, ref_word, &ref_count),
                   4);
  ck_assert_int_eq(s21_sscanf(input, "%*ms %4$3i %2$hhx %% %5$la %3$2ms%1$hn",
                              &count, &byte, &word, &number, &fraction),
                   4);
  ck_assert_int_eq(number, ref_number);
  ck_assert_uint_eq(byte, ref_byte);
  ck_assert(fraction == ref_fraction);
  ck_assert_str_eq(word, ref_word);
  ck_assert_int_eq(count, ref_count);
  free(word);
}
END_TEST

START_TEST(numbered_gaps_and_reuse) {
  double skipped = 2.5;
  int count = -1, value = -1;
  ck_assert_int_eq(
      s21_sscanf("17 23", "%3$d %3$d%1$n", &count, &skipped, &value), 2);
  ck_assert_int_eq(value, 23);
  ck_assert_int_eq(count, 5);
  ck_assert(skipped == 2.5);
#if NL_ARGMAX >= 12
  char raw[3] = "??";
  ck_assert_int_eq(
      s21_sscanf("xyz123   ok", "%*3mc%*m[0-9] %12$2c%1$n", &count, &skipped,
                 &skipped, &skipped, &skipped, &skipped, &skipped, &skipped,
                 &skipped, &skipped, &skipped, raw),
      1);
  ck_assert_int_eq(count, 11);
  ck_assert_str_eq(raw, "ok");
#endif
}
END_TEST

START_TEST(unassigned_allocations) {
  char saved[] = "saved", *word = saved, *first = NULL;
  wchar_t wide_saved[] = L"saved", *wide = wide_saved;
  ck_assert_int_eq(s21_sscanf("", "%ms", &word), EOF);
  ck_assert_int_eq(s21_sscanf("%", "%%%1$ms", &word), EOF);
  ck_assert_int_eq(s21_sscanf("7%", "%*d%%%1$ms", &word), 0);
  ck_assert_int_eq(s21_sscanf("7", "%m[a-z]", &word), 0);
  ck_assert_int_eq(s21_sscanf("a", "%2mc", &word), 0);
  ck_assert_int_eq(s21_sscanf("a", "%2mlc", &wide), 0);
  ck_assert_int_eq(s21_sscanf("word!", "%m[^!]!%ms", &first, &word), 1);
  ck_assert_str_eq(first, "word");
  free(first);
  setlocale(LC_CTYPE, "C");
  errno = 0;
  int result = s21_sscanf("a\xff", "%mls", &wide);
  int error = errno;
  ck_assert_int_eq(result, EOF);
  ck_assert_int_eq(error, EILSEQ);
  errno = 0;
  result = s21_sscanf("ok \xff", "%2$ms %1$mC", &wide, &first);
  error = errno;
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(error, EILSEQ);
  ck_assert_str_eq(first, "ok");
  free(first);
  ck_assert_ptr_eq(word, saved);
  ck_assert_ptr_eq(wide, wide_saved);
}
END_TEST

START_TEST(invalid_position_and_allocation_formats) {
  char saved[] = "saved", *word = saved;
  const char *formats[] = {"%0$ms", "%999999999999999999999999$ms", "%md", "%m",
                           "%m[abc"};
  for (size_t i = 0; i < sizeof(formats) / sizeof(*formats); ++i)
    ck_assert_int_eq(s21_sscanf("123", formats[i], &word), 0);
  ck_assert_ptr_eq(word, saved);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *suite =
      suite_create("\n\033[37;1m=========S21S21_SSCANF=========\033[0m");
  TCase *tcase_core = tcase_create("sscanf_tc");
  tcase_add_test(tcase_core, sscanf_test_c_1);
  tcase_add_test(tcase_core, sscanf_test_c_2);
  tcase_add_test(tcase_core, sscanf_test_d_1);
  tcase_add_test(tcase_core, sscanf_test_d_2);
  tcase_add_test(tcase_core, sscanf_test_d_3);
  tcase_add_test(tcase_core, sscanf_test_d_4);
  tcase_add_test(tcase_core, sscanf_test_d_5);
  tcase_add_test(tcase_core, allocated_text_fields);
  tcase_add_test(tcase_core, allocated_wide_fields);
  tcase_add_test(tcase_core, wide_aliases_and_byte_counts);
  tcase_add_test(tcase_core, wide_field_boundaries);
  tcase_add_test(tcase_core, numbered_arguments);
  tcase_add_test(tcase_core, numbered_gaps_and_reuse);
  tcase_add_test(tcase_core, unassigned_allocations);
  tcase_add_test(tcase_core, invalid_position_and_allocation_formats);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
