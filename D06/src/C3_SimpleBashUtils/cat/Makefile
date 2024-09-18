SHELL :=/bin/bash

all: clean s21_cat

s21_cat: s21_cat.h s21_cat.c
	@gcc -Wall -Wextra -Werror -std=c11 s21_cat.c -o s21_cat

style:
	@cp ../../../materials/linters/.clang-format ./.clang-format
	@printf "\033[1;33mRunning clang-format with Google style on all files...\n\033[0m"
	@clang-format -style=Google -n *.c *.h
	@printf "\033[1;33mChecking formatting without making changes completed.\n\033[0m"
	@rm -f ./.clang-format

leaks: s21_cat
	valgrind --tool=memcheck --leak-check=yes ./s21_cat

test: s21_cat
	@-diff <(./s21_cat -A ../test/*.txt) <(cat -A ../test/*.txt)
	@-diff <(./s21_cat -s ../test/*.txt) <(cat -s ../test/*.txt)
	@-diff <(./s21_cat -b ../test/*.txt) <(cat -b ../test/*.txt)
	@-diff <(./s21_cat -n ../test/*.txt) <(cat -n ../test/*.txt)
	@-diff <(./s21_cat -bn ../test/*.txt) <(cat -bn ../test/*.txt)
	@-diff <(./s21_cat -sbn ../test/*.txt) <(cat -sbn ../test/*.txt)
	@-diff <(./s21_cat -t ../test/*.txt) <(cat -t ../test/*.txt)
	@-diff <(./s21_cat -T ../test/*.txt) <(cat -T ../test/*.txt)
	@-diff <(./s21_cat -E ../test/*.txt) <(cat -E ../test/*.txt)
	@-diff <(./s21_cat -AbEnsT ../test/*.txt) <(cat -bevEnstT ../test/*.txt)
	@printf "\033[1;33mTesting completed.\n\033[0m"

rebuild:
	make clean
	make all

clean:
	@rm -f s21_cat
	@printf "\033[1;33mClean-up completed.\n\033[0m"

