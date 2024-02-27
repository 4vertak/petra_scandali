// #include <stdarg.h>

// int s21_sprintf(char *str, const char *format, ...) {

//Содержимое stdarg.h часто используют в функциях с произвольным количеством аргументов (к примеру, printf, scanf). Заголовочный файл определяет тип va_list и набор функций для операций над ним: va_start, va_arg, va_copy (C99), va_end
Пример: #include <stdio.h>

// #include <stdarg.h>
// #include <string.h>

// void var(char *format, ...)
// {
// 	va_list ap;
// 	va_start(ap, format);
// 	if(!strcmp(format, "%d"))
// 	{
// 		int x = va_arg (ap, int);
// 		printf ("You passed decimal object with value %d\n", x);
// 	}

// 	if(!strcmp(format, "%s"))
// 	{
// 		char *p = va_arg (ap, char *);
// 		printf ("You passed c-string \"%s\"\n", p);
// 	}
// 	va_end (ap);
// }

// int main(void)
// {
// 	var("%d", 255);
// 	var("%s", "test string");
// 	return 0;
// }

//}
