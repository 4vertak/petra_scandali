#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <locale.h>
#include <math.h>
#include <sys/types.h>
#include <wchar.h>

#include "test.h"

START_TEST(byte_boundaries) {
  char data[] = {(char)0xff, 'x', '\0', 'x'};
  for (size_t n = 0; n <= sizeof(data); ++n) {
    for (int c = -1; c <= 255; ++c)
      ck_assert_ptr_eq(s21_memchr(data, c, n), memchr(data, c, n));
  }
  char ref[6] = "abc", got[6] = "abc";
  ck_assert_ptr_eq(s21_memset(got + 1, 0x1ff, 2), got + 1);
  memset(ref + 1, 0x1ff, 2);
  ck_assert_mem_eq(got, ref, sizeof(got));
  ck_assert_ptr_eq(s21_memcpy(got + 1, data, sizeof(data)), got + 1);
  memcpy(ref + 1, data, sizeof(data));
  ck_assert_mem_eq(got, ref, sizeof(got));

  char src[2] = {'x', 'y'};
  char buf[5] = "a";
  ck_assert_ptr_eq(s21_strncat(buf, src, sizeof(src)), buf);
  ck_assert_str_eq(buf, "axy");
  ck_assert_ptr_eq(s21_strncpy(buf, src, 2), buf);
  ck_assert_mem_eq(buf, "xyy\0", 4);
  ck_assert_ptr_eq(s21_strncpy(buf, "", 3), buf);
  ck_assert_mem_eq(buf, "\0\0\0\0", 4);
}
END_TEST

START_TEST(overlapping_moves) {
  for (size_t src = 0; src < 4; ++src) {
    for (size_t dest = 0; dest < 4; ++dest) {
      char ref[] = "abc\0defg", got[] = "abc\0defg";
      memmove(ref + dest, ref + src, 5);
      ck_assert_ptr_eq(s21_memmove(got + dest, got + src, 5), got + dest);
      ck_assert_mem_eq(ref, got, sizeof(got));
    }
  }
  char got[4];
  ck_assert_ptr_eq(s21_memmove(got, "abc", sizeof(got)), got);
  ck_assert_mem_eq(got, "abc", sizeof(got));
}
END_TEST

START_TEST(string_edges) {
  const char bytes[] = {(char)0xff, 'a', 'b', 0};
  const char empty[] = "";
  ck_assert_ptr_eq(s21_strchr(empty, 0), empty);
  ck_assert_ptr_eq(s21_strrchr(empty, 0), empty);
  ck_assert_ptr_null(s21_strrchr(empty, 'c'));
  for (int c = -1; c <= UCHAR_MAX + 1; ++c) {
    ck_assert_ptr_eq(s21_strchr(bytes, c), strchr(bytes, c));
    ck_assert_ptr_eq(s21_strrchr(bytes, c), strrchr(bytes, c));
  }
  ck_assert_int_gt(s21_strncmp(bytes, "abc", 1), 0);
  for (int error = -1; error < 140; ++error)
    ck_assert_str_eq(s21_strerror(error), strerror(error));
  ck_assert_str_eq(s21_strerror(INT_MIN), strerror(INT_MIN));
  ck_assert_str_eq(s21_strerror(INT_MAX), strerror(INT_MAX));
}
END_TEST

START_TEST(extra_string_operations) {
  char buf[10] = "xyz";
  ck_assert_ptr_eq(s21_strcat(buf, ""), buf);
  ck_assert_ptr_eq(s21_strcat(buf, "abc"), buf);
  ck_assert_str_eq(buf, "xyzabc");
  ck_assert_int_eq(s21_strcmp(buf, "xyzabc"), 0);
  ck_assert_int_gt(s21_strcmp("\xff", "\1"), 0);
  ck_assert_int_lt(s21_strcmp("a", "aa"), 0);
  ck_assert_ptr_eq(s21_strrev(buf), buf);
  ck_assert_str_eq(buf, "cbazyx");
  char odd[] = "abc", empty[] = "";
  ck_assert_str_eq(s21_strrev(odd), "cba");
  ck_assert_ptr_eq(s21_strrev(empty), empty);
}
END_TEST

START_TEST(owned_strings) {
  char source[8193];
  memset(source, 'a', sizeof(source) - 1);
  source[sizeof(source) - 1] = '\0';
  char *upper = s21_to_upper(source);
  char *again = s21_to_upper("xy");
  char *lower = s21_to_lower(upper);
  char *insert = s21_insert(source, "!", sizeof(source) - 1);
  char *trim = s21_trim("!!!a!b!!!", "!");
  char *trimmed_all = s21_trim("!!", "!");
  char *full = s21_trim(source, NULL);
  ck_assert_ptr_ne(upper, again);
  ck_assert_uint_eq(strlen(upper), strlen(source));
  ck_assert_int_eq(upper[8191], 'A');
  ck_assert_str_eq(again, "XY");
  ck_assert_str_eq(lower, source);
  ck_assert_str_eq(insert + 8191, "a!");
  ck_assert_str_eq(trim, "a!b");
  ck_assert_str_eq(trimmed_all, "");
  ck_assert_str_eq(full, source);
  ck_assert_ptr_null(s21_to_lower(NULL));
  ck_assert_ptr_null(s21_to_upper(NULL));
  free(full);
  free(trimmed_all);
  free(trim);
  free(insert);
  free(lower);
  free(again);
  free(upper);
}
END_TEST

// The byte after the terminator also catches writes based on requested
// precision.
#define CHECK_PRINT(...)                                \
  do {                                                  \
    char ref[20000], got[20000];                        \
    memset(ref, 0x55, sizeof(ref));                     \
    memset(got, 0x55, sizeof(got));                     \
    int n = snprintf(ref, sizeof(ref), __VA_ARGS__);    \
    ck_assert_int_ge(n, 0);                             \
    ck_assert_int_lt(n + 1, (int)sizeof(ref));          \
    ck_assert_int_eq(s21_sprintf(got, __VA_ARGS__), n); \
    ck_assert_mem_eq(got, ref, (size_t)n + 2);          \
  } while (0)

START_TEST(integer_fields) {
  const char *combined = "%+05d|% 05d|%-05d|%06.3d|%#08x|%.0u|%#.0o|%.0x|%+.0d";
  CHECK_PRINT(combined, 12, 12, 12, 12, 26U, 0U, 0U, 0U, 0);
  CHECK_PRINT("%*.*d|%*.*s|%.*u", -5, -3, 12, -5, -1, "key", -1, 0U);
  CHECK_PRINT("%d %ld %hd %hhd %lld %jd %td", INT_MIN, LONG_MIN,
              (short)SHRT_MIN, (signed char)SCHAR_MIN, LLONG_MIN, INTMAX_MIN,
              (ptrdiff_t)-12);
  CHECK_PRINT("%hu %hhu %#lo %llx %ju %zu %X", (unsigned short)USHRT_MAX,
              (unsigned char)UCHAR_MAX, ULONG_MAX, ULLONG_MAX, UINTMAX_MAX,
              SIZE_MAX, UINT_MAX);
  int object;
  CHECK_PRINT("[%18p][%-12p]", (void *)&object, (void *)NULL);
}
END_TEST

START_TEST(output_counts) {
  signed char tiny;
  short small;
  int normal;
  long large;
  long long largest;
  intmax_t max;
  ssize_t size;
  ptrdiff_t diff;
  char buf[12];
  ck_assert_int_eq(
      s21_sprintf(buf, "A%c%hhnB%hnC%nD%lnE%llnF%jnG%znH%tn", 0, &tiny, &small,
                  &normal, &large, &largest, &max, &size, &diff),
      9);
  ck_assert_mem_eq(buf, "A\0BCDEFGH", 10);
  ck_assert_int_eq(tiny, 2);
  ck_assert_int_eq(small, 3);
  ck_assert_int_eq(normal, 4);
  ck_assert_int_eq(large, 5);
  ck_assert_int_eq(largest, 6);
  ck_assert_int_eq(max, 7);
  ck_assert_int_eq(size, 8);
  ck_assert_int_eq(diff, 9);
}
END_TEST

START_TEST(bounded_output) {
  char src[3] = {'a', 'b', 'c'};
  wchar_t wide[2] = {L'a', L'b'};
  CHECK_PRINT("%-5.3s:%.*s", src, -1, "key");
  CHECK_PRINT("%.2ls:%ls:%lc", wide, L"", (wint_t)L'\0');
  char tiny[2];
  ck_assert_int_eq(s21_sprintf(tiny, "%.1000000s", "x"), 1);
  ck_assert_mem_eq(tiny, "x", sizeof(tiny));
  const char *bad[] = {"%",
                       "%-+",
                       "%12.",
                       "%l",
                       "%?",
                       "%999999999999999999999999d",
                       "%.99999999999999999999s"};
  for (size_t i = 0; i < sizeof(bad) / sizeof(*bad); ++i)
    ck_assert_int_lt(s21_sprintf(tiny, bad[i]), 0);
  ck_assert_int_lt(s21_sprintf(tiny, "%*s", INT_MIN, ""), 0);
  ck_assert_int_lt(s21_sprintf(tiny, "x%*s", INT_MAX, ""), 0);
  ck_assert_int_lt(s21_sprintf(tiny, "%.*f", INT_MAX, 1.0), 0);
  ck_assert_int_lt(s21_sprintf(tiny, "%+.*d", INT_MAX, 1), 0);
}
END_TEST

START_TEST(float_fields) {
  CHECK_PRINT("%+.0f %.0f %.0f %.0f %f %#.0f", 2.5, 3.5, -2.5, .099, -0.0,
              12.0);
  CHECK_PRINT("%.1e %.2E %.2Lg %#.3g %.1g %.0g", 9.99, 1000., .0012L, 10., 9.99,
              .1);
  CHECK_PRINT("%+08F|%08f|%-8G|%E", INFINITY, -INFINITY, NAN, -NAN);
  CHECK_PRINT("%.*f|%.*e|%.*g", -3, 1.25, -3, 12.5, -3, .0625);
  CHECK_PRINT("%.20Le|%.20Le|%.21Lg", LDBL_MAX, LDBL_TRUE_MIN, LDBL_MIN);
  CHECK_PRINT("%#.5000g", 0.125);
  CHECK_PRINT("%.800f|%.17g", DBL_TRUE_MIN, DBL_MAX);
  int saved = fegetround();
  const int modes[] = {FE_TONEAREST, FE_UPWARD, FE_DOWNWARD, FE_TOWARDZERO};
  for (size_t i = 0; i < sizeof(modes) / sizeof(*modes); ++i) {
    ck_assert_int_eq(fesetround(modes[i]), 0);
    CHECK_PRINT("%.2f %.2f %.0f %.0f %.3g %.1e", .00012, -.00012, 2.5, -3.9,
                999.875, 9.96);
  }
  fesetround(saved);
}
END_TEST

START_TEST(scan_integers) {
  const char *s = "+123 -077 0Xff 0 +0 17 FF aa -1";
  int d, oct, hex, zero, n, ref_n;
  unsigned u, o, x, upper, neg;
  const char *format = "%d%i%i%i%u%o%x%X%u%n";
  ck_assert_int_eq(s21_sscanf(s, format, &d, &oct, &hex, &zero, &u, &o, &x,
                              &upper, &neg, &n),
                   9);
  int refs[4];
  unsigned unsigned_refs[5];
  ck_assert_int_eq(
      sscanf(s, format, &refs[0], &refs[1], &refs[2], &refs[3],
             &unsigned_refs[0], &unsigned_refs[1], &unsigned_refs[2],
             &unsigned_refs[3], &unsigned_refs[4], &ref_n),
      9);
  int signed_results[] = {d, oct, hex, zero};
  unsigned unsigned_results[] = {u, o, x, upper, neg};
  ck_assert_mem_eq(signed_results, refs, sizeof(refs));
  ck_assert_mem_eq(unsigned_results, unsigned_refs, sizeof(unsigned_refs));
  ck_assert_int_eq(n, ref_n);
  signed char sc;
  short h, hn;
  long l, ln;
  long long ll;
  intmax_t j;
  char input[256];
  snprintf(input, sizeof(input), "%hhd %hd %ld %lld %jd", (signed char)-3,
           (short)-20, LONG_MIN, LLONG_MIN, INTMAX_MAX);
  ck_assert_int_eq(s21_sscanf(input, "%hhd %hd%hn %ld%ln %lld %jd", &sc, &h,
                              &hn, &l, &ln, &ll, &j),
                   5);
  ck_assert_int_eq(sc, -3);
  ck_assert_int_eq(h, -20);
  ck_assert_int_eq(hn, 6);
  ck_assert_int_eq(l, LONG_MIN);
  ck_assert_int_gt(ln, hn);
  ck_assert(ll == LLONG_MIN && j == INTMAX_MAX);
  unsigned char uc;
  unsigned short us;
  unsigned long ul;
  unsigned long long ull;
  uintmax_t uj;
  size_t z;
  ptrdiff_t t;
  ck_assert_int_eq(s21_sscanf("1 2 3 4 5 6 -7", "%hhu %hu %lu %llu %ju %zu %td",
                              &uc, &us, &ul, &ull, &uj, &z, &t),
                   7);
  ck_assert(uc == 1 && us == 2 && ul == 3 && ull == 4 && uj == 5 && z == 6 &&
            t == -7);
}
END_TEST

START_TEST(scan_fields_and_failures) {
  int a = -1, b = -1, n = -1, rn;
  const char *input =
      " \v12"
      "34  xy\t\t-17 %!";
  const char *fmt = "%2d%2d %*2s %d %%!%n";
  int c, ra, rb, rc;
  ck_assert_int_eq(s21_sscanf(input, fmt, &a, &b, &c, &n),
                   sscanf(input, fmt, &ra, &rb, &rc, &rn));
  ck_assert(a == ra && b == rb && c == rc && n == rn);
  const char *inputs[] = {"", " \v\f", "x", "+z", "-1 x", " +1"};
  for (size_t i = 0; i < sizeof(inputs) / sizeof(*inputs); ++i) {
    a = b = ra = rb = -99;
    ck_assert_int_eq(s21_sscanf(inputs[i], "%d%d", &a, &b),
                     sscanf(inputs[i], "%d%d", &ra, &rb));
    ck_assert(a == ra && b == rb);
  }
  ck_assert_int_eq(s21_sscanf("", "%n", &n), 0);
  ck_assert_int_eq(n, 0);
  ck_assert_int_eq(s21_sscanf("", " "), 0);
  ck_assert_int_eq(s21_sscanf("", "x"), EOF);
  ck_assert_int_eq(s21_sscanf("q", "x%d", &a), 0);
  ck_assert_int_eq(s21_sscanf(" x", "%%"), 0);
  ck_assert_int_eq(s21_sscanf("ab", "%*c%*c"), 0);
  ck_assert_int_eq(s21_sscanf("42", "%*2d%d", &a), 0);
}
END_TEST

START_TEST(scan_text_and_sets) {
  struct {
    char pair[3], word[4], capitals[4], tail[3], punctuation[3];
  } got, ref;
  memset(&got, '+', sizeof(got));
  memset(&ref, '+', sizeof(ref));
  int n, rn;
  const char *s = "xy \vabcDEF! -]";
  const char *fmt = "%2c %3s%3[A-Z]%[^-]%2[]-]%n";
  ck_assert_int_eq(sscanf(s, fmt, ref.pair, ref.word, ref.capitals, ref.tail,
                          ref.punctuation, &rn),
                   5);
  ck_assert_int_eq(s21_sscanf(s, fmt, got.pair, got.word, got.capitals,
                              got.tail, got.punctuation, &n),
                   5);
  ck_assert_mem_eq(&got, &ref, sizeof(ref));
  ck_assert_int_eq(n, rn);
  char word[4] = "xxx";
  ck_assert_int_eq(s21_sscanf("1", "%[a-z]", word), 0);
  ck_assert_str_eq(word, "xxx");
  ck_assert_int_eq(s21_sscanf("de!", "%3[a-c-e]", word), 1);
  ck_assert_str_eq(word, "de");
  ck_assert_int_eq(s21_sscanf("abc", "%*2[a-z]%c", word), 1);
  ck_assert_int_eq(word[0], 'c');
  ck_assert_int_eq(s21_sscanf("q", "%2c", word), 0);
  ck_assert_int_eq(word[0], 'c');
  ck_assert_int_eq(s21_sscanf("abc", "%[ab", word), 0);
  ck_assert_int_eq(s21_sscanf("abc", "%", word), 0);
  ck_assert_int_eq(s21_sscanf("abc", "%999999999999999999999999999s", word), 1);
  ck_assert_str_eq(word, "abc");
}
END_TEST

START_TEST(long_text_fields) {
  char input[8200], word[8193], actual[8200], ref[8200];
  memset(input, 'x', 8192);
  strcpy(input + 8192, ":123");
  int value, n;
  ck_assert_int_eq(s21_sscanf(input, "%8192[x]:%d%n", word, &value, &n), 2);
  ck_assert_int_eq(value, 123);
  ck_assert_int_eq(n, 8196);
  ck_assert_uint_eq(strlen(word), 8192);
  ck_assert_mem_eq(word, input, 8192);
  wchar_t wide[2049];
  for (size_t i = 0; i < 2048; ++i) wide[i] = L'z';
  wide[2048] = L'\0';
  ck_assert_int_eq(s21_sprintf(actual, "%3000.2000ls!", wide),
                   sprintf(ref, "%3000.2000ls!", wide));
  ck_assert_mem_eq(actual, ref, 3002);
}
END_TEST

START_TEST(scan_pointers_and_floats) {
  int object;
  void *pointers[] = {&object, NULL};
  for (size_t i = 0; i < sizeof(pointers) / sizeof(*pointers); ++i) {
    char field[64];
    void *actual = &object, *ref = &object;
    sprintf(field, "%p", pointers[i]);
    ck_assert_int_eq(s21_sscanf(field, "%p", &actual),
                     sscanf(field, "%p", &ref));
    ck_assert_ptr_eq(actual, ref);
  }
  float a, ra;
  double b, rb;
  long double c, rc;
  int n, rn;
  const char *fmt = "%4f %lg %Le %*a%n";
  const char *s = "-1.5 .0625 0x1.abp+5 1e-3";
  ck_assert_int_eq(s21_sscanf(s, fmt, &a, &b, &c, &n),
                   sscanf(s, fmt, &ra, &rb, &rc, &rn));
  ck_assert(a == ra && b == rb && c == rc && n == rn);
  float nan_value;
  ck_assert_int_eq(s21_sscanf("INFinity -INf NaN(payload)", "%A%F%G%n", &a, &ra,
                              &nan_value, &n),
                   3);
  ck_assert(isinf(a) && a > 0 && isinf(ra) && ra < 0 && isnan(nan_value));
  ck_assert_uint_eq((size_t)n, strlen("INFinity -INf NaN(payload)"));
}
END_TEST

START_TEST(scan_float_width) {
  char input[180];
  memset(input, '0', sizeof(input));
  input[148] = '1';
  input[149] = '2';
  input[150] = '3';
  input[151] = '\0';
  float a, ref;
  int n, rn;
  ck_assert_int_eq(s21_sscanf(input, "%150f%n", &a, &n),
                   sscanf(input, "%150f%n", &ref, &rn));
  ck_assert(a == ref && n == rn);
  ck_assert_int_eq(s21_sscanf("1.234", "%3f%n", &a, &n),
                   sscanf("1.234", "%3f%n", &ref, &rn));
  ck_assert(a == ref && n == rn);
  const char *invalid[] = {"+", "x1", ".", "1e-", "infi", "nan(x", "0x.p1"};
  for (size_t i = 0; i < sizeof(invalid) / sizeof(*invalid); ++i) {
    a = 5;
    ck_assert_int_eq(s21_sscanf(invalid[i], "%f", &a), 0);
    ck_assert(a == 5);
  }
  ck_assert_int_eq(s21_sscanf("+1", "%1f", &a), 0);
}
END_TEST

START_TEST(wide_conversions) {
  char text[16];
  setlocale(LC_CTYPE, "C");
  ck_assert_int_lt(s21_sprintf(text, "%lc", (wint_t)0x20ac), 0);
  ck_assert_int_lt(s21_sprintf(text, "%ls", L"\u20ac"), 0);
  wchar_t chars[5] = L"zzzz", ref[5] = L"zzzz";
  ck_assert_int_eq(s21_sscanf("\xff", "%lc", chars), EOF);
  int n, rn;
  if (setlocale(LC_CTYPE, "C.UTF-8") || setlocale(LC_CTYPE, "en_US.UTF-8") ||
      setlocale(LC_CTYPE, "UTF-8")) {
    CHECK_PRINT("[%lc][%5.3ls][%.2ls]", (wint_t)0x20ac, L"\u20acx", L"\u20acx");
    const char *s = "\xc3\xa9\xe2\x82\xac xy!";
    ck_assert_int_eq(s21_sscanf(s, "%2lc %2ls%n", chars, chars + 2, &n),
                     sscanf(s, "%2lc %2ls%n", ref, ref + 2, &rn));
    ck_assert_mem_eq(chars, ref, sizeof(ref));
    ck_assert_int_eq(n, rn);
    ck_assert_int_eq(
        s21_sscanf("\xc3\xa9\xc3\xaa!", "%l[\u00e8-\u00eb]%n", chars, &n), 1);
    ck_assert(wcscmp(chars, L"\u00e9\u00ea") == 0 && n == 4);
  }
  setlocale(LC_CTYPE, "C");
}
END_TEST

Suite *test_regressions(void) {
  Suite *suite = suite_create("Audit regressions");
  TCase *tc = tcase_create("boundaries and formats");
  tcase_add_test(tc, byte_boundaries);
  tcase_add_test(tc, overlapping_moves);
  tcase_add_test(tc, string_edges);
  tcase_add_test(tc, extra_string_operations);
  tcase_add_test(tc, owned_strings);
  tcase_add_test(tc, integer_fields);
  tcase_add_test(tc, output_counts);
  tcase_add_test(tc, bounded_output);
  tcase_add_test(tc, float_fields);
  tcase_add_test(tc, scan_integers);
  tcase_add_test(tc, scan_fields_and_failures);
  tcase_add_test(tc, scan_text_and_sets);
  tcase_add_test(tc, long_text_fields);
  tcase_add_test(tc, scan_pointers_and_floats);
  tcase_add_test(tc, scan_float_width);
  tcase_add_test(tc, wide_conversions);
  suite_add_tcase(suite, tc);
  return suite;
}
