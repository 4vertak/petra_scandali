SHELL :=/bin/bash

FLAG= -Wall -Wextra -Werror -std=c11 -pedantic
FILE= ../test/1.txt ../test/2.txt ../test/3.txt
PATTERNS=../test/patterns.txt

all: clean s21_grep

s21_grep: Makefile s21_grep.h s21_grep.c
	@gcc $(FLAG) s21_grep.c -o s21_grep

style:
	@cp ../../../materials/linters/.clang-format ./.clang-format
	@printf "\033[1;33mRunning clang-format with Google style on all files...\n\033[0m"
	@clang-format -style=Google -n *.c *.h
	@printf "\033[1;33mChecking formatting without making changes completed.\n\033[0m"
	@rm -f ./.clang-format

leaks: s21_grep
	-valgrind  ./s21_grep Li $(FILE)
	-valgrind  ./s21_grep -v Li $(FILE)
	-valgrind  ./s21_grep -iv Li $(FILE)
	-valgrind  ./s21_grep -in Li $(FILE)
	-valgrind  ./s21_grep -ie "^li" $(FILE)
	-valgrind  ./s21_grep -ince "^li" $(FILE)
	-valgrind  ./s21_grep -lh tor $(FILE)
	-valgrind  ./s21_grep -e Li -e li $(FILE)
	-valgrind  ./s21_grep -f $(PATTERNS) -f $(FILE)
	-valgrind  ./s21_grep -oi li  $(FILE)
	-valgrind  ./s21_grep -ohf li $(PATTERNS) $(FILE)
	-valgrind  ./s21_grep -oihlnc -e li -e He -f $(PATTERNS) $(FILE)

test:
	@-diff <(./s21_grep Li $(FILE)) <(grep Li $(FILE))
	@-diff <(./s21_grep -v Li $(FILE)) <(grep -v Li $(FILE))
	@-diff <(./s21_grep --line-number Li $(FILE)) <(grep --line-number Li $(FILE))
	@-diff <(./s21_grep -c Li $(FILE)) <(grep --count Li $(FILE))
	@-diff <(./s21_grep --files-with-matches Li $(FILE)) <(grep -l Li $(FILE))
	@-diff <(./s21_grep -i Li $(FILE)) <(grep -i Li $(FILE))
	@-diff <(./s21_grep -iv Li $(FILE)) <(grep -iv Li $(FILE))
	@-diff <(./s21_grep -in Li $(FILE)) <(grep -in Li $(FILE))
	@-diff <(./s21_grep -ie "^li" $(FILE)) <(grep -ie "^li" $(FILE))
	@-diff <(./s21_grep -ince "^li" $(FILE)) <(grep -ince "^li" $(FILE))
	@-diff <(./s21_grep -lh tor $(FILE)) <(grep -lh tor $(FILE))
	@-diff <(./s21_grep -hc Li $(FILE)) <(grep -hc Li $(FILE))
	@-diff <(./s21_grep -e Li -e li $(FILE)) <(grep -e Li -e li $(FILE))
	@-diff <(./s21_grep -f $(PATTERNS) $(FILE)) <(grep  -f $(PATTERNS) $(FILE))
	@-diff <(./s21_grep -oi li $(FILE)) <(grep -oi li  $(FILE))
	@-diff <(./s21_grep -oinc li $(FILE)) <(grep -oinc li  $(FILE))
	@-diff <(./s21_grep -oihlnc -e li -e He -f $(PATTERNS) $(FILE)) <(grep -oihlnc -e li -e He -f $(PATTERNS) $(FILE))
	@-diff <(./s21_grep $(FILE)) <(grep $(FILE))
	@printf "\033[1;33mTesting completed.\n\033[0m"

rebuild:
	make clean
	make all

clean:
	@rm -f s21_grep
	@printf "\033[1;33mClean-up completed.\n\033[0m"
