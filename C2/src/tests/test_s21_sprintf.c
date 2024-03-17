#include "./test.h"

START_TEST(test_1) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%d %5o %% %-5o %5o %f %c %s %u %p %Lg %LG %x %X";
  int integerVal_a = 42;
  float floatVal_a = 3.14159;
  long double floatVal_pi = 3.14159L;
  char charVal_a = 'A';
  char *test_114Val_a = "Planet of the apes";
  unsigned int unsignedVal_a = 100;
  void *pointerVal_a = &integerVal_a;

  ck_assert_int_eq(
      s21_sprintf(str1, format, integerVal_a, integerVal_a, integerVal_a,
                  integerVal_a, floatVal_a, charVal_a, test_114Val_a,
                  unsignedVal_a, pointerVal_a, floatVal_pi, floatVal_pi,
                  integerVal_a, integerVal_a),
      sprintf(str2, format, integerVal_a, integerVal_a, integerVal_a,
              integerVal_a, floatVal_a, charVal_a, test_114Val_a, unsignedVal_a,
              pointerVal_a, floatVal_pi, floatVal_pi, integerVal_a,
              integerVal_a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_2) {
  char str1[] =
      "Обезьяны, пытающиеся посчитать значение числа Пи (3.1415)с помощью "
      "пальцев, с удивлением обнаруживают, что их пальцы могут быть изменены "
      "на указатели, и они начинают размышлять o том, что с их помощью можно "
      "достичь высшего понимания вселенной и стать легендой в истории "
      "человечества ";
  char str2[] =
      "Обезьяны, пытающиеся посчитать значение числа Пи (3.1415)с помощью "
      "пальцев, с удивлением обнаруживают, что их пальцы могут быть изменены "
      "на указатели, и они начинают размышлять o том, что с их помощью можно "
      "достичь высшего понимания вселенной и стать легендой в истории "
      "человечества ";

  char *format = "%-+4d %4f %4c %4s %4o %4p";
  int integerVal_a = -4205;
  float floatVal_a = 3.14159;
  char charVal_a = 'A';
  char *test_114Val_a = "Planet of the apes";
  unsigned int unsignedVal_a = 100;
  void *pointerVal_a = &integerVal_a;

  ck_assert_int_eq(
      s21_sprintf(str1, format, integerVal_a, floatVal_a, charVal_a,
                  test_114Val_a, unsignedVal_a, pointerVal_a),
      sprintf(str2, format, integerVal_a, floatVal_a, charVal_a, test_114Val_a,
              unsignedVal_a, pointerVal_a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_3) {
  char str1[] =
      "Обезьяны, пытающиеся посчитать значение числа Пи (3.1415)с помощью "
      "пальцев, с удивлением обнаруживают, что их пальцы могут быть изменены "
      "на указатели, и они начинают размышлять o том, что с их помощью можно "
      "достичь высшего понимания вселенной и стать легендой в истории "
      "человечества ";
  char str2[] =
      "Обезьяны, пытающиеся посчитать значение числа Пи (3.1415)с помощью "
      "пальцев, с удивлением обнаруживают, что их пальцы могут быть изменены "
      "на указатели, и они начинают размышлять o том, что с их помощью можно "
      "достичь высшего понимания вселенной и стать легендой в истории "
      "человечества ";

  char *format = "%-4d %-4f %-4c %-4s %-4u %-4p";
  int integerVal_a = 42;
  float floatVal_a = 3.14159;
  char charVal_a = 'A';
  char *test_114Val_a = "Planet of the apes";
  unsigned int unsignedVal_a = 100;
  void *pointerVal_a = &integerVal_a;

  ck_assert_int_eq(
      s21_sprintf(str1, format, integerVal_a, floatVal_a, charVal_a,
                  test_114Val_a, unsignedVal_a, pointerVal_a),
      sprintf(str2, format, integerVal_a, floatVal_a, charVal_a, test_114Val_a,
              unsignedVal_a, pointerVal_a));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(test_4) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = 5;
  int system = 5;
  s21_sprintf(s21_buff, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_5) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = -19;
  int system = -19;
  s21_sprintf(s21_buff, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_6) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = 1024;
  int system = 1024;
  s21_sprintf(s21_buff, "This is %d number", s21);
  sprintf(buff, "This is %d number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_7) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "Planet of the apes";
  char *system = "Planet of the apes";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_8) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "";
  char *system = "";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_9) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "Planet of the apes";
  char *system = "Planet of the apes";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_10) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "Planet";
  char *system = "Planet";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_11) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 4.3;
  float system = 4.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_12) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 0.34;
  float system = 0.34;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_13) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 9.3425789;
  float system = 9.3425789;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_14) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 10.3;
  float system = 10.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_15) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 0;
  float system = 0;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_16) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.322;
  float system = 2.322;
  s21_sprintf(s21_buff, "This is %.2f number", s21);
  sprintf(buff, "This is %.2f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_17) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_18) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_19) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = -2.3228;
  float system = -2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_20) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", 'c');
  sprintf(buff, "%c", 'c');

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_21) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", 67);
  sprintf(buff, "%c", 67);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_22) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", '8');
  sprintf(buff, "%c", '8');
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_23) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", ' ');
  sprintf(buff, "%c", ' ');
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_24) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", 21);
  sprintf(buff, "%+d", 21);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_25) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", -250);
  sprintf(buff, "%+d", -250);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_26) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "result: %+d", 0);
  sprintf(buff, "result: %+d", 0);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_27) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "result: % d", 25);
  sprintf(buff, "result: % d", 25);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_28) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", -1000);
  sprintf(buff, "% d", -1000);

  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_29) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", 0);
  sprintf(buff, "% d", 0);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_30) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 15);
  sprintf(buff, "%x", 15);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_31) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 11);
  sprintf(buff, "%X", 11);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_32) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 1505);
  sprintf(buff, "%x", 1505);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_33) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 12345678);
  sprintf(buff, "%X", 12345678);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_34) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 0);
  sprintf(buff, "%x", 0);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_35) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 0);
  sprintf(buff, "%X", 0);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_36) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 10);
  sprintf(buff, "%o", 10);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_before_eight) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 7);
  sprintf(buff, "%o", 7);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 0);
  sprintf(buff, "%o", 0);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_37) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 12345678);
  sprintf(buff, "%o", 12345678);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_38) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned int number = UINT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_39) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = INT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_53) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = -100;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_54) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned int number = (unsigned int)INT_MAX + 100;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_55) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = 0;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_40) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%5d", 1568);
  sprintf(buff, "%5d", 1568);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_41) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%4f", 15.15);
  sprintf(buff, "%4f", 15.15);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_42) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%10c", 'z');
  sprintf(buff, "%10c", 'z');
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_43) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%3s", "Planet of the apes");
  sprintf(buff, "%3s", "Planet of the apes");
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_44) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%4o", 256);
  sprintf(buff, "%4o", 256);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_45) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%15x", 15);
  sprintf(buff, "%15x", 15);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_46) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%8u", 15678940);
  sprintf(buff, "%8u", 15678940);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_47) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%% %d", 1);
  sprintf(buff, "%% %d", 1);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_48) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%%%%%% %f", 1.0);
  sprintf(buff, "%%%%%% %f", 1.0);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_49) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int d = 1234567890;
  s21_sprintf(s21_buff, "%ld", d);
  sprintf(buff, "%ld", d);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_50) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int o = 84518;
  s21_sprintf(s21_buff, "%lo", o);
  sprintf(buff, "%lo", o);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_51) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned long int u = 1234567890;
  s21_sprintf(s21_buff, "%lu", u);
  sprintf(buff, "%lu", u);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_52) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int x = 15;
  s21_sprintf(s21_buff, "%lx", x);
  sprintf(buff, "%lx", x);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_56) {
  char s21_buff[100] = "";
  char buff[100] = "";
  short int y = 16;
  unsigned short int x = 15;
  s21_sprintf(s21_buff, "%hd %hu %ho %hx", y, x, x, x);
  sprintf(buff, "%hd %hu %ho %hx", y, x, x, x);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_58) {
  char s21_buff[100] = "";
  char buff[100] = "";
  short int y = 16;
  unsigned short int x = 15;
  s21_sprintf(s21_buff, "%-10hd %-5hu %-7ho %-2hx", y, x, x, x);
  sprintf(buff, "%-10hd %-5hu %-7ho %-2hx", y, x, x, x);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_57) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int x = 15;
  s21_sprintf(s21_buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  sprintf(buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_59) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned short x = USHRT_MAX;
  short int y = SHRT_MAX;
  s21_sprintf(s21_buff, "%hd %hu %hx %ho", y, x, x, x);
  sprintf(buff, "%hd %hu %hx %ho", y, x, x, x);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_60) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_61) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_62) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_63) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_64) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_65) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_66) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_67) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_73) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_68) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_69) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_70) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_71) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%LG";
  long double hex = 0.000005;
  // https://valgrind-developers.narkive.com/uao2Y1Fh/valgrind-and-subtle-floating-point-problem
  // - проблемы валгринда чисел с плавающей точкой)))

  int res1 = s21_sprintf(str1, format, hex);
  int res2 = sprintf(str2, format, hex);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST

START_TEST(test_72) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  // ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4,
  // hex5),
  //                  sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));
  // ck_assert_str_eq(str1, str2);
  int res1 = s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5);
  int res2 = sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST
START_TEST(test_74) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.17Le";
  long double val = 15.35;
  // ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
  // val));

  // ck_assert_str_eq(str1, str2);
  int res1 = s21_sprintf(str1, format, val);
  int res2 = sprintf(str2, format, val);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST
START_TEST(test_75) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_76) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_77) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  // ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
  // val));

  // ck_assert_str_eq(str1, str2);

  int res1 = s21_sprintf(str1, format, val);
  int res2 = sprintf(str2, format, val);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST

START_TEST(test_78) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.15Le";
  long double val = -15.35581134;
  // ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
  // val));
  // ck_assert_str_eq(str1, str2);

  int res1 = s21_sprintf(str1, format, val);
  int res2 = sprintf(str2, format, val);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST

START_TEST(test_79) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_82) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_81) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_80) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(Test_83) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.14LE";
  long double val = 4134121;
  int res1 = s21_sprintf(str1, format, val);
  int res2 = sprintf(str2, format, val);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST

START_TEST(test_85) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_86) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_87) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_88) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_92) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_93) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_89) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_90) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_91) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_84) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_94) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_95) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_96) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_97) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_98) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_99) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_100) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_101) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_102) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_103) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_104) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_105) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_106) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_107) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_108) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_109) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.15Lf";
  long double val = 15.35;
  // ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
  // val));

  // ck_assert_str_eq(str1, str2);

  int res1 = s21_sprintf(str1, format, val);
  int res2 = sprintf(str2, format, val);
  ck_assert_int_eq(((res1 - res2) <= 1 || (res2 - res1) <= 1) ? 0 : 1, 0);
}
END_TEST

START_TEST(test_110) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%.10Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_112) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_113) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_114) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%s";
  char *val = "Monkeys trying to calculate the value of Pi using their fingers";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_115) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.15s";
  char *val = "Monkeys trying to calculate the value of Pi using their fingers";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_116) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%15s";
  char *val = "5 fingers on hand";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_117) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%-15.9s";
  char *val = "5 fingers on hand";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_118) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%s";
  char *val = "Monkeys trying to calculate the value of Pi using their fingers";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_119) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%s%s%s%s";
  char *val =
      "Monkeys trying to calculate the value of Pi using their 5 fingers";
  char *s1 = "";
  char *s2 = "87418347813748913749571389480913";
  char *s3 = "PLANETMONKYES";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_120) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_121) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_122) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_124) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_123) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  int ret = 0;
  char *format = "Monkeys trying to calculate the value of Pi %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_125) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "Monkeys trying to calculate the value of Pi %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_126) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_127) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_128) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_129) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_130) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_131) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_132) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_133) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_134) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_135) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_136) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_137) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_138) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_139) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_140) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_141) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_142) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_143) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_144) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_145) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_146) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_147) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_148) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_149) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_150) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_151) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Monkeys Donkey Kong"),
                   sprintf(str2, "%s", "Monkeys Donkey Kong"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_152) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Monkeys", " ", "Donkey", " ", "Kong"),
      sprintf(str2, "%s%s%s%s%s", "Monkeys", " ", "Donkey", " ", "Kong"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_153) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_154) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_155) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_156) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_157) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_158) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_159) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_160) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_161) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_162) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_163) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_164) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_165) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_166) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_167) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_168) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_169) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_170) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_171) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_172) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_173) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_174) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_175) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_176) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_177) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_178) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_179) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_180) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_181) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_182) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_183) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_184) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_185) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_186) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_187) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_188) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_189) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_190) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_191) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_192) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_193) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_194) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_195) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_196) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_197) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_198) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%3.7Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_199) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_200) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_201) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_202) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_203) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_204) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_205) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_206) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Обезьяны, пытающиеся посчитать значение числа Пи с "
                  "помощью пальцев, с удивлением обнаруживают, что их пальцы "
                  "могут быть изменены на указатели, и они начинают размышлять "
                  "o том, что с их помощью можно достичь высшего понимания "
                  "вселенной и стать легендой в истории человечества ",
                  11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Обезьяны, пытающиеся посчитать значение числа Пи с "
              "помощью пальцев, с удивлением обнаруживают, что их пальцы "
              "могут быть изменены на указатели, и они начинают размышлять "
              "o том, что с их помощью можно достичь высшего понимания "
              "вселенной и стать легендой в истории человечества ",
              11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_207) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_208) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_209) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_210) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_211) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_212) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_213) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_214) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_215) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_216) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_217) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_218) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%e DONKEY %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_219) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%#e Komg %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_220) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_221) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_222) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_223) {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_224) {
  char buffer1[100];
  char buffer2[100];
  int number = 123;
  double real_number = 123.456789;
  int count_n = 0;
  wchar_t wcharacter = L'A';
  wchar_t *wstrings = L"Hello";
  char character = 'A';
  char *strings = "Hello";

  // Примеры использования cпецификаторов без флага
  // printf("=======Примеры использования cпецификаторов без флага=======\n");

  s21_sprintf(buffer1, "Character: %c", 'A');
  sprintf(buffer2, "Character: %c", 'A');
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Character_s21: %s\n", buffer1);
  // printf("Character_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %d", number);
  sprintf(buffer2, "Signed decimal (d): %d", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal: %s\n", buffer1);
  // printf("Signed decimal: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %i", number);
  sprintf(buffer2, "Signed decimal (d): %i", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal: %s\n", buffer1);
  // printf("Signed decimal: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (E): %E", real_number);
  sprintf(buffer2, "Научная форма записи (E): %E", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (e): %e", real_number);
  sprintf(buffer2, "Научная форма записи (e): %e", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "f format: %f", real_number);
  sprintf(buffer2, "f format: %f", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  s21_sprintf(buffer1, "g format: %g", real_number);
  sprintf(buffer2, "g format: %g", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("g format_s21: %s\n", buffer1);
  // printf("g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "G format: %G", real_number);
  sprintf(buffer2, "G format: %G", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("G format_s21: %s\n", buffer1);
  // printf("G format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %o", number);
  sprintf(buffer2, "Octal: %o", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "String: %s", "Hello");
  sprintf(buffer2, "String: %s", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  // printf("String_s21: %s\n", buffer1);
  // printf("String_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %u", -123);
  sprintf(buffer2, "Unsigned decimal: %u", -123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %x", number);
  sprintf(buffer2, "Hexadecimal: %x", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %X", number);
  sprintf(buffer2, "Hexadecimal: %X", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Pointer address: %p", "Hello");
  sprintf(buffer2, "Pointer address: %p", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Pointer address_s21: %s\n", buffer1);
  // printf("Pointer address_org: %s\n", buffer2);

  s21_sprintf(buffer1, "format: %d%n", number, &count_n);
  sprintf(buffer2, "format: %d%n", number, &count_n);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Count char_s21: %s\n", buffer1);
  // printf("Count char_org: %s\n", buffer2);

  // Примеры использования cпецификаторов c флагом 'L'
  // printf("\n\n=======Примеры использования cпецификаторов c флагом
  // L=======\n");

  s21_sprintf(
      buffer1, "Научная форма записи (LE): %LE",
      (long double)real_number);  // если с флагом L и у перемeнной нет явного
                                  // переназначения типа на long double должна
                                  // выводить 0 - впадает в кому)))
  sprintf(buffer2, "Научная форма записи (LE): %LE", (long double)real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (Le): %Le",
              (long double)real_number);
  sprintf(buffer2, "Научная форма записи (Le): %Le", (long double)real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(
      buffer1, "Lg format: %Lg",
      (long double)real_number);  // если с флагом L и у перемнной нет явного
                                  // переназначения типа на long double должна
                                  // выводить 0 - впадает в кому)))
  sprintf(buffer2, "Lg format: %Lg", (long double)real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Long double g format_s21: %s\n", buffer1);
  // printf("Long double g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "LG format: %LG", (long double)real_number);
  sprintf(buffer2, "LG format: %LG", (long double)real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Long double G format_s21: %s\n", buffer1);
  // printf("Long double G format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Lf format: %Lf", (long double)real_number);
  sprintf(buffer2, "Lf format: %Lf", (long double)real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  // Примеры использования cпецификаторов 'c' и 's' c флагом l
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов 'c' и 's' c флагом "
  //     "'l'=======\n");

  s21_sprintf(buffer1, "Character and string: %lc %ls", wcharacter, wstrings);
  sprintf(buffer2, "Character and string: %lc %ls", wcharacter, wstrings);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Wide_character_s21: %s\n", buffer1);
  // printf("Wide_character_org: %s\n", buffer2);

  // Примеры использования cпецификаторов c флагом l
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов c флагом
  //     'l'=======\n");

  s21_sprintf(buffer1, "Signed decimal (d): %ld", (long)number);
  sprintf(buffer2, "Signed decimal (d): %ld", (long)number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal: %s\n", buffer1);
  // printf("Signed decimal: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %li", (long)number);
  sprintf(buffer2, "Signed decimal (d): %li", (long)number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal: %s\n", buffer1);
  // printf("Signed decimal: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %lo", (long)number);
  sprintf(buffer2, "Octal: %lo", (long)number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %lu", (long)-123);
  sprintf(buffer2, "Unsigned decimal: %lu", (long)-123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %lx", (long)number);
  sprintf(buffer2, "Hexadecimal: %lx", (long)number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %lX", (long)number);
  sprintf(buffer2, "Hexadecimal: %lX", (long)number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  // Примеры использования cпецификаторов c флагом h
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов c флагом
  //     'h'=======\n");

  s21_sprintf(buffer1, "Signed decimal (d): %hd", number);
  sprintf(buffer2, "Signed decimal (d): %hd", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal: %s\n", buffer1);
  // printf("Signed decimal: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %hi", number);
  sprintf(buffer2, "Signed decimal (d): %hi", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal: %s\n", buffer1);
  // printf("Signed decimal: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %ho", number);
  sprintf(buffer2, "Octal: %ho", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %hu", -123);
  sprintf(buffer2, "Unsigned decimal: %hu", -123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %hx", number);
  sprintf(buffer2, "Hexadecimal: %hx", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %hX", number);
  sprintf(buffer2, "Hexadecimal: %hX", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  // Примеры использования cпецификаторов c флагом точности '.'
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов diouxX c точность'.' "
  //     "=======\n");

  s21_sprintf(buffer1, "Signed decimal (d): %.4d", number);
  sprintf(buffer2, "Signed decimal (d): %.4d", number);
  ck_assert_str_eq(buffer1, buffer2);
  //  printf("Signed decimal_s21: %s\n", buffer1);
  // printf("Signed decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %.4i", number);
  sprintf(buffer2, "Signed decimal (d): %.4i", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed integer_s21: %s\n", buffer1);
  // printf("Signed integer_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %.4o", number);
  sprintf(buffer2, "Octal: %.4o", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %.4u", 123);
  sprintf(buffer2, "Unsigned decimal: %.4u", 123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %.4x", number);
  sprintf(buffer2, "Hexadecimal: %.4x", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %.4X", number);
  sprintf(buffer2, "Hexadecimal: %.4X", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  // printf(
  //     "\n\n=======Примеры использования cпецификаторов diouxX c точностью'.0'
  //     "
  //     "=======\n");
  s21_sprintf(buffer1, "Signed decimal (d): %.0d", number);
  sprintf(buffer2, "Signed decimal (d): %.0d", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal_s21: %s\n", buffer1);
  // printf("Signed decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed integer (d): %.0i", number);
  sprintf(buffer2, "Signed integer (d): %.0i", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed integer_s21: %s\n", buffer1);
  // printf("Signed integer_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %.0o", number);
  sprintf(buffer2, "Octal: %.0o", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %.0u", 123);
  sprintf(buffer2, "Unsigned decimal: %.0u", 123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %.0x", number);
  sprintf(buffer2, "Hexadecimal: %.0x", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %.0X", number);
  sprintf(buffer2, "Hexadecimal: %.0X", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  // printf(
  //     "=======Примеры использования cпецификаторов eEf c
  //     точность'.'=======\n");

  s21_sprintf(buffer1, "Научная форма записи (E): %.1E", real_number);
  sprintf(buffer2, "Научная форма записи (E): %.1E", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (e): %.1e", real_number);
  sprintf(buffer2, "Научная форма записи (e): %.1e", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "f format: %.1f", real_number);
  sprintf(buffer2, "f format: %.1f", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  // printf(
  //     "=======Примеры использования cпецификаторов eEf c "
  //     "точность'.0'=======\n");

  s21_sprintf(buffer1, "Научная форма записи (E): %.0E", real_number);
  sprintf(buffer2, "Научная форма записи (E): %.0E", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (e): %.0e", real_number);
  sprintf(buffer2, "Научная форма записи (e): %.0e", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "f format: %.0f", real_number);
  sprintf(buffer2, "f format: %.0f", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  // printf(
  //     "\n\n=======Примеры использования cпецификаторов gG c "
  //     "точность'.'=======\n");

  s21_sprintf(buffer1, "g format: %.1g", real_number);
  sprintf(buffer2, "g format: %.1g", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("g format_s21: %s\n", buffer1);
  // printf("g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "G format: %.1G", real_number);
  sprintf(buffer2, "G format: %.1G", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("G format_s21: %s\n", buffer1);
  // printf("G format_org: %s\n", buffer2);

  // printf(
  //     "\n\n=======Примеры использования cпецификаторов gG c "
  //     "точность'.0'=======\n");

  s21_sprintf(buffer1, "g format: %.0g", real_number);
  sprintf(buffer2, "g format: %.0g", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("g format_s21: %s\n", buffer1);
  // printf("g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "G format: %.0G", real_number);
  sprintf(buffer2, "G format: %.0G", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("G format_s21: %s\n", buffer1);
  // printf("G format_org: %s\n", buffer2);

  // printf(
  //     "\n\n=======Примеры использования cпецификаторов 's' c "
  //     "точность'.'=======\n");

  s21_sprintf(buffer1, "String: %.4s", strings);
  sprintf(buffer2, "String: %.4s", strings);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("String_s21: %s\n", buffer1);
  // printf("String_org: %s\n", buffer2);

  // printf(
  //     "\n\n=======Примеры использования cпецификаторов 'c' и 's' c "
  //     "точность'.0'=======\n");

  s21_sprintf(buffer1, "Character and string: %.0c %.0s", character, strings);
  ck_assert_str_eq(buffer1, "Character and string: A ");
  // printf("Character and string_s21: %s\n", buffer1);
  // printf("Character and string_org: %s\n", buffer2);

  // Примеры использования cпецификаторов c флагом точности '.*'
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов diouxX eEf gG cs c "
  //     "точность'.*' =======\n");

  s21_sprintf(buffer1, "Signed decimal (d): %.*d", 4, number);
  sprintf(buffer2, "Signed decimal (d): %.*d", 4, number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal_s21: %s\n", buffer1);
  // printf("Signed decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %.*i", 4, number);
  sprintf(buffer2, "Signed decimal (d): %.*i", 4, number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed integer_s21: %s\n", buffer1);
  // printf("Signed integer_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %.*o", 4, number);
  sprintf(buffer2, "Octal: %.*o", 4, number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %.*u", 4, 123);
  sprintf(buffer2, "Unsigned decimal: %.*u", 4, 123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %.*x", 4, number);
  sprintf(buffer2, "Hexadecimal: %.*x", 4, number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %.*X", 4, number);
  sprintf(buffer2, "Hexadecimal: %.*X", 4, number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (E): %.1E", real_number);
  sprintf(buffer2, "Научная форма записи (E): %.1E", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (e): %.1e", real_number);
  sprintf(buffer2, "Научная форма записи (e): %.1e", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "f format: %.1f", real_number);
  sprintf(buffer2, "f format: %.1f", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Lg format: %.*g", 1, real_number);
  sprintf(buffer2, "Lg format: %.*g", 1, real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("g format_s21: %s\n", buffer1);
  // printf("g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "LG format: %.*G", 1, real_number);
  sprintf(buffer2, "LG format: %.*G", 1, real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("G format_s21: %s\n", buffer1);
  // printf("G format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Character and string: %.*c %.*s", 0, character, 4,
              strings);
  ck_assert_str_eq(buffer1, "Character and string: A Hell");
  // printf("Character and string_s21: %s\n", buffer1);
  // printf("Character and string_org: %s\n", buffer2);

  // Примеры использования cпецификаторов подспецификатором ширины
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов подспецификатором "
  //     "ширины=======\n");

  s21_sprintf(buffer1, "Character: %10c", 'A');
  sprintf(buffer2, "Character: %10c", 'A');
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Character_s21: %s\n", buffer1);
  // printf("Character_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %10d", number);
  sprintf(buffer2, "Signed decimal (d): %10d", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal_s21: %s\n", buffer1);
  // printf("Signed decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %10i", number);
  sprintf(buffer2, "Signed decimal (d): %10i", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed integer_s21: %s\n", buffer1);
  // printf("Signed integer_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (E): %10E", real_number);
  sprintf(buffer2, "Научная форма записи (E): %10E", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (e): %10e", real_number);
  sprintf(buffer2, "Научная форма записи (e): %10e", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "f format: %10f", real_number);
  sprintf(buffer2, "f format: %10f", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  s21_sprintf(buffer1, "g format: %10g", real_number);
  sprintf(buffer2, "g format: %10g", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("g format_s21: %s\n", buffer1);
  // printf("g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "G format: %10G", real_number);
  sprintf(buffer2, "G format: %10G", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("G format_s21: %s\n", buffer1);
  // printf("G format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %10o", number);
  sprintf(buffer2, "Octal: %10o", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "String: %10s", "Hello");
  sprintf(buffer2, "String: %10s", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  // printf("String_s21: %s\n", buffer1);
  // printf("String_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %10u", 123);
  sprintf(buffer2, "Unsigned decimal: %10u", 123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %10x", number);
  sprintf(buffer2, "Hexadecimal: %10x", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %10X", number);
  sprintf(buffer2, "Hexadecimal: %10X", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Pointer address: %10p", "Hello");
  sprintf(buffer2, "Pointer address: %10p", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Pointer address_s21: %s\n", buffer1);
  // printf("Pointer address_org: %s\n", buffer2);

  s21_sprintf(buffer1, "format: %10d%n", number, &count_n);
  sprintf(buffer2, "format: %10d%n", number, &count_n);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Count char_s21: %s\n", buffer1);
  // printf("Count char_org: %s\n", buffer2);

  // Примеры использования cпецификаторов с флагом '-' и подспецификатором
  // ширины
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов с флагом '-' и "
  //     "подспецификатором ширины=======\n");
  // s21_memset(buffer1, '\0', sizeof(buffer1));
  s21_sprintf(buffer1, "Character: %-10c", 'A');
  sprintf(buffer2, "Character: %-10c", 'A');
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Character_s21: %s\n", buffer1);
  // printf("Character_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %-10d", number);
  sprintf(buffer2, "Signed decimal (d): %-10d", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed decimal_s21: %s\n", buffer1);
  // printf("Signed decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Signed decimal (d): %-10i", number);
  sprintf(buffer2, "Signed decimal (d): %-10i", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Signed integer_s21: %s\n", buffer1);
  // printf("Signed integer_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (E): %-10E", real_number);
  sprintf(buffer2, "Научная форма записи (E): %-10E", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Научная форма записи (e): %-10e", real_number);
  sprintf(buffer2, "Научная форма записи (e): %-10e", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Научная форма записи_s21: %s\n", buffer1);
  // printf("Научная форма записи_org: %s\n", buffer2);

  s21_sprintf(buffer1, "f format: %-10f", real_number);
  sprintf(buffer2, "f format: %-10f", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Fixed-point notation_s21: %s\n", buffer1);
  // printf("Fixed-point notation_org: %s\n", buffer2);

  s21_sprintf(buffer1, "g format: %-10g", real_number);
  sprintf(buffer2, "g format: %-10g", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("g format_s21: %s\n", buffer1);
  // printf("g format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "G format: %-10G", real_number);
  sprintf(buffer2, "G format: %-10G", real_number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("G format_s21: %s\n", buffer1);
  // printf("G format_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Octal: %-10o", number);
  sprintf(buffer2, "Octal: %-10o", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Octal_s21: %s\n", buffer1);
  // printf("Octal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "String: %-10s", "Hello");
  sprintf(buffer2, "String: %-10s", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  // printf("String_s21: %s\n", buffer1);
  // printf("String_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Unsigned decimal: %-10u", -123);
  sprintf(buffer2, "Unsigned decimal: %-10u", -123);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Unsigned decimal_s21: %s\n", buffer1);
  // printf("Unsigned decimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %-10x", number);
  sprintf(buffer2, "Hexadecimal: %-10x", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Hexadecimal: %-10X", number);
  sprintf(buffer2, "Hexadecimal: %-10X", number);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Hexadecimal_s21: %s\n", buffer1);
  // printf("Hexadecimal_org: %s\n", buffer2);

  s21_sprintf(buffer1, "Pointer address: %-10p", "Hello");
  sprintf(buffer2, "Pointer address: %-10p", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Pointer address_s21: %s\n", buffer1);
  // printf("Pointer address_org: %s\n", buffer2);

  s21_sprintf(buffer1, "format: %-10d%n", number, &count_n);
  sprintf(buffer2, "format: %-10d%n", number, &count_n);
  ck_assert_str_eq(buffer1, buffer2);
  // printf("Count char_s21: %s\n", buffer1);
  // printf("Count char_org: %s\n", buffer2);

  // Примеры использования cпецификаторов с флагамм '-' и ' ' и
  // подспецификатором ширины
  // printf(
  //     "\n\n=======Примеры использования cпецификаторов с флагом '-' и "
  //     "подспецификатором ширины=======\n");
  // s21_memset(buffer1, '\0', sizeof(buffer1));
  //   s21_sprintf(buffer1, "Character: %- 9c", 'A');
  //   sprintf(buffer2, "Character: %- 9c", 'A');
  //   printf("Character_s21: %s\n", buffer1);
  //   printf("Character_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Signed decimal (d): %- 10d", number);
  //   sprintf(buffer2, "Signed decimal (d): %- 10d", number);
  //   printf("Signed decimal_s21: %s\n", buffer1);
  //   printf("Signed decimal_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Signed decimal (d): %- 10i", number);
  //   sprintf(buffer2, "Signed decimal (d): %- 10i", number);
  //   printf("Signed integer_s21: %s\n", buffer1);
  //   printf("Signed integer_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Научная форма записи (E): %- 10E", real_number);
  //   sprintf(buffer2, "Научная форма записи (E): %- 10E", real_number);
  //   printf("Научная форма записи_s21: %s\n", buffer1);
  //   printf("Научная форма записи_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Научная форма записи (e): %- 10e", real_number);
  //   sprintf(buffer2, "Научная форма записи (e): %- 10e", real_number);
  //   printf("Научная форма записи_s21: %s\n", buffer1);
  //   printf("Научная форма записи_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "f format: %- 10f", real_number);
  //   sprintf(buffer2, "f format: %- 10f", real_number);
  //   printf("Fixed-point notation_s21: %s\n", buffer1);
  //   printf("Fixed-point notation_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "g format: %- 10g", real_number);
  //   sprintf(buffer2, "g format: %- 10g", real_number);
  //   printf("g format_s21: %s\n", buffer1);
  //   printf("g format_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "G format: %- 10G", real_number);
  //   sprintf(buffer2, "G format: %- 10G", real_number);
  //   printf("G format_s21: %s\n", buffer1);
  //   printf("G format_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Octal: %- 10o", number);
  //   sprintf(buffer2, "Octal: %- 10o", number);
  //   printf("Octal_s21: %s\n", buffer1);
  //   printf("Octal_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "String: %- 10s", "Hello");
  //   sprintf(buffer2, "String: %- 10s", "Hello");
  //   printf("String_s21: %s\n", buffer1);
  //   printf("String_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Unsigned decimal: %- 10u", -123);
  //   sprintf(buffer2, "Unsigned decimal: %- 10u", -123);
  //   printf("Unsigned decimal_s21: %s\n", buffer1);
  //   printf("Unsigned decimal_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Hexadecimal: %- 10x", number);
  //   sprintf(buffer2, "Hexadecimal: %- 10x", number);
  //   printf("Hexadecimal_s21: %s\n", buffer1);
  //   printf("Hexadecimal_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Hexadecimal: %- 10X", number);
  //   sprintf(buffer2, "Hexadecimal: %- 10X", number);
  //   printf("Hexadecimal_s21: %s\n", buffer1);
  //   printf("Hexadecimal_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "Pointer address: %- 10p", "Hello");
  //   sprintf(buffer2, "Pointer address: %- 10p", "Hello");
  //   printf("Pointer address_s21: %s\n", buffer1);
  //   printf("Pointer address_org: %s\n", buffer2);

  //   s21_sprintf(buffer1, "format: %- 10d%n", number, &count_n);
  //   sprintf(buffer2, "format: %- 10d%n", number, &count_n);
  //   printf("Count char_s21: %s\n", buffer1);
  //   printf("Count char_org: %s\n", buffer2);

  //   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
  //   hex));

  //   ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m==========|S21_SPRINTF|=========\033[0m");
  tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  tcase_add_test(tc, test_12);
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);
  tcase_add_test(tc, test_18);
  tcase_add_test(tc, test_19);
  tcase_add_test(tc, test_20);
  tcase_add_test(tc, test_21);
  tcase_add_test(tc, test_22);
  tcase_add_test(tc, test_23);
  tcase_add_test(tc, test_24);
  tcase_add_test(tc, test_25);
  tcase_add_test(tc, test_26);
  tcase_add_test(tc, test_27);
  tcase_add_test(tc, test_28);
  tcase_add_test(tc, test_29);
  tcase_add_test(tc, test_30);
  tcase_add_test(tc, test_31);
  tcase_add_test(tc, test_32);
  tcase_add_test(tc, test_33);
  tcase_add_test(tc, test_34);
  tcase_add_test(tc, test_33);
  tcase_add_test(tc, test_34);
  tcase_add_test(tc, test_35);
  tcase_add_test(tc, test_36);
  tcase_add_test(tc, test_37);
  tcase_add_test(tc, test_38);
  tcase_add_test(tc, test_39);
  tcase_add_test(tc, test_40);
  tcase_add_test(tc, test_41);
  tcase_add_test(tc, test_42);
  tcase_add_test(tc, test_43);
  tcase_add_test(tc, test_44);
  tcase_add_test(tc, test_45);
  tcase_add_test(tc, test_46);
  tcase_add_test(tc, test_47);
  tcase_add_test(tc, test_48);
  tcase_add_test(tc, test_49);
  tcase_add_test(tc, test_50);
  tcase_add_test(tc, test_51);
  tcase_add_test(tc, test_52);
  tcase_add_test(tc, test_53);
  tcase_add_test(tc, test_54);
  tcase_add_test(tc, test_55);
  tcase_add_test(tc, test_56);
  tcase_add_test(tc, test_57);
  tcase_add_test(tc, test_58);
  tcase_add_test(tc, test_59);
  tcase_add_test(tc, test_60);
  tcase_add_test(tc, test_61);
  tcase_add_test(tc, test_62);
  tcase_add_test(tc, test_63);
  tcase_add_test(tc, test_64);
  tcase_add_test(tc, test_65);
  tcase_add_test(tc, test_66);
  tcase_add_test(tc, test_67);
  tcase_add_test(tc, test_68);
  tcase_add_test(tc, test_69);
  tcase_add_test(tc, test_70);
  tcase_add_test(tc, test_71);
  tcase_add_test(tc, test_72);
  tcase_add_test(tc, test_73);
  tcase_add_test(tc, test_74);
  tcase_add_test(tc, test_75);
  tcase_add_test(tc, test_76);
  tcase_add_test(tc, test_77);
  tcase_add_test(tc, test_78);
  tcase_add_test(tc, test_79);
  tcase_add_test(tc, test_80);
  tcase_add_test(tc, test_81);
  tcase_add_test(tc, test_82);
  tcase_add_test(tc, Test_83);
  tcase_add_test(tc, test_84);
  tcase_add_test(tc, test_85);
  tcase_add_test(tc, test_86);
  tcase_add_test(tc, test_87);
  tcase_add_test(tc, test_88);
  tcase_add_test(tc, test_89);
  tcase_add_test(tc, test_90);
  tcase_add_test(tc, test_91);
  tcase_add_test(tc, test_92);
  tcase_add_test(tc, test_93);
  tcase_add_test(tc, test_94);
  tcase_add_test(tc, test_95);
  tcase_add_test(tc, test_96);
  tcase_add_test(tc, test_97);
  tcase_add_test(tc, test_98);
  tcase_add_test(tc, test_99);
  tcase_add_test(tc, test_100);
  tcase_add_test(tc, test_101);
  tcase_add_test(tc, test_102);
  tcase_add_test(tc, test_103);
  tcase_add_test(tc, test_104);
  tcase_add_test(tc, test_105);
  tcase_add_test(tc, test_106);
  tcase_add_test(tc, test_107);
  tcase_add_test(tc, test_108);
  tcase_add_test(tc, test_109);
  tcase_add_test(tc, test_110);
  tcase_add_test(tc, test_111);
  tcase_add_test(tc, test_112);
  tcase_add_test(tc, test_113);
  tcase_add_test(tc, test_114);
  tcase_add_test(tc, test_115);
  tcase_add_test(tc, test_116);
  tcase_add_test(tc, test_117);
  tcase_add_test(tc, test_118);
  tcase_add_test(tc, test_119);
  tcase_add_test(tc, test_120);
  tcase_add_test(tc, test_121);
  tcase_add_test(tc, test_122);
  tcase_add_test(tc, test_123);
  tcase_add_test(tc, test_124);
  tcase_add_test(tc, test_125);
  tcase_add_test(tc, test_126);
  tcase_add_test(tc, test_127);
  tcase_add_test(tc, test_128);
  tcase_add_test(tc, test_129);
  tcase_add_test(tc, test_130);
  tcase_add_test(tc, test_131);
  tcase_add_test(tc, test_132);
  tcase_add_test(tc, test_133);
  tcase_add_test(tc, test_134);
  tcase_add_test(tc, test_135);
  tcase_add_test(tc, test_136);
  tcase_add_test(tc, test_137);
  tcase_add_test(tc, test_138);
  tcase_add_test(tc, test_139);
  tcase_add_test(tc, test_140);
  tcase_add_test(tc, test_141);
  tcase_add_test(tc, test_142);
  tcase_add_test(tc, test_143);
  tcase_add_test(tc, test_144);
  tcase_add_test(tc, test_145);
  tcase_add_test(tc, test_146);
  tcase_add_test(tc, test_147);
  tcase_add_test(tc, test_148);
  tcase_add_test(tc, test_149);
  tcase_add_test(tc, test_150);
  tcase_add_test(tc, test_151);
  tcase_add_test(tc, test_152);
  tcase_add_test(tc, test_153);
  tcase_add_test(tc, test_154);
  tcase_add_test(tc, test_155);
  tcase_add_test(tc, test_156);
  tcase_add_test(tc, test_157);
  tcase_add_test(tc, test_158);
  tcase_add_test(tc, test_159);
  tcase_add_test(tc, test_160);
  tcase_add_test(tc, test_161);
  tcase_add_test(tc, test_162);
  tcase_add_test(tc, test_163);
  tcase_add_test(tc, test_164);
  tcase_add_test(tc, test_165);
  tcase_add_test(tc, test_166);
  tcase_add_test(tc, test_167);
  tcase_add_test(tc, test_168);
  tcase_add_test(tc, test_169);
  tcase_add_test(tc, test_170);
  tcase_add_test(tc, test_171);
  tcase_add_test(tc, test_172);
  tcase_add_test(tc, test_173);
  tcase_add_test(tc, test_174);
  tcase_add_test(tc, test_175);
  tcase_add_test(tc, test_176);
  tcase_add_test(tc, test_177);
  tcase_add_test(tc, test_178);
  tcase_add_test(tc, test_179);
  tcase_add_test(tc, test_180);
  tcase_add_test(tc, test_181);
  tcase_add_test(tc, test_182);
  tcase_add_test(tc, test_183);
  tcase_add_test(tc, test_184);
  tcase_add_test(tc, test_185);
  tcase_add_test(tc, test_186);
  tcase_add_test(tc, test_187);
  tcase_add_test(tc, test_188);
  tcase_add_test(tc, test_189);
  tcase_add_test(tc, test_190);
  tcase_add_test(tc, test_191);
  tcase_add_test(tc, test_192);
  tcase_add_test(tc, test_193);
  tcase_add_test(tc, test_194);
  tcase_add_test(tc, test_195);
  tcase_add_test(tc, test_196);
  tcase_add_test(tc, test_197);
  tcase_add_test(tc, test_198);
  tcase_add_test(tc, test_199);
  tcase_add_test(tc, test_200);
  tcase_add_test(tc, test_201);
  tcase_add_test(tc, test_202);
  tcase_add_test(tc, test_203);
  tcase_add_test(tc, test_204);
  tcase_add_test(tc, test_205);
  tcase_add_test(tc, test_206);
  tcase_add_test(tc, test_207);
  tcase_add_test(tc, test_208);
  tcase_add_test(tc, test_209);
  tcase_add_test(tc, test_210);
  tcase_add_test(tc, test_211);
  tcase_add_test(tc, test_212);
  tcase_add_test(tc, test_213);
  tcase_add_test(tc, test_214);
  tcase_add_test(tc, test_215);
  tcase_add_test(tc, test_216);
  tcase_add_test(tc, test_217);
  tcase_add_test(tc, test_218);
  tcase_add_test(tc, test_219);
  tcase_add_test(tc, test_220);
  tcase_add_test(tc, test_221);
  tcase_add_test(tc, test_222);
  tcase_add_test(tc, test_223);
  tcase_add_test(tc, test_224);

  suite_add_tcase(s, tc);
  return s;
}