#include "./test.h"
#define BUFF_SIZE 512

START_TEST(test_dfcsupLglGxX) {
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

  char *format = "%d %f %c %s %u %p %Lg %lG %x %X";
  int integerVal_a = 42;
  float floatVal_a = 3.14159;
  long double floatVal_pi = 3.14159L;
  char charVal_a = 'A';
  char *stringVal_a = "Planet of the apes";
  unsigned int unsignedVal_a = 100;
  void *pointerVal_a = &integerVal_a;

  ck_assert_int_eq(
      s21_sprintf(str1, format, integerVal_a, floatVal_a, charVal_a,
                  stringVal_a, unsignedVal_a, pointerVal_a, floatVal_pi,
                  floatVal_pi, floatVal_a, floatVal_a),
      sprintf(str2, format, integerVal_a, floatVal_a, charVal_a, stringVal_a,
              unsignedVal_a, pointerVal_a, floatVal_pi, floatVal_pi, floatVal_a,
              floatVal_a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_dfcsup_width) {
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

  char *format = "%4d %4f %4c %4s %4u %4p";
  int integerVal_a = 42;
  float floatVal_a = 3.14159;
  char charVal_a = 'A';
  char *stringVal_a = "Planet of the apes";
  unsigned int unsignedVal_a = 100;
  void *pointerVal_a = &integerVal_a;

  ck_assert_int_eq(
      s21_sprintf(str1, format, integerVal_a, floatVal_a, charVal_a,
                  stringVal_a, unsignedVal_a, pointerVal_a),
      sprintf(str2, format, integerVal_a, floatVal_a, charVal_a, stringVal_a,
              unsignedVal_a, pointerVal_a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_dfcsup_width_minus) {
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
  char *stringVal_a = "Planet of the apes";
  unsigned int unsignedVal_a = 100;
  void *pointerVal_a = &integerVal_a;

  ck_assert_int_eq(
      s21_sprintf(str1, format, integerVal_a, floatVal_a, charVal_a,
                  stringVal_a, unsignedVal_a, pointerVal_a),
      sprintf(str2, format, integerVal_a, floatVal_a, charVal_a, stringVal_a,
              unsignedVal_a, pointerVal_a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\n\033[37;1m=========S21_SPRINTF=========\033[0m");
  tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, test_dfcsup);
  tcase_add_test(tc, test_dfcsup_width);
  tcase_add_test(tc, test_dfcsup_width_minus);
  suite_add_tcase(s, tc);
  return s;
}

// int integerVal_a = 42;
// float floatVal_a = 3.14159;
// char charVal_a = 'A';
// char *stringVal_a = "Hello, World!";
// unsigned int unsignedVal_a = 100;
// void *pointerVal_a = &integerVal_a;

// s21_sprintf(str3, "%-+5d %6.1f %c %s %u %p", integerVal_a, floatVal_a,
// charVal_a, stringVal_a, unsignedVal_a, pointerVal_a); sprintf(str4, "%-+5d
// %6.1f %c %s %u %p", integerVal_a, floatVal_a, charVal_a, stringVal_a,
// unsignedVal_a, pointerVal_a);

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
