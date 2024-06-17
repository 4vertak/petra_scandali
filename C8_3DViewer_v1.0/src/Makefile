SHELL :=/bin/bash
CC=gcc
FLAGS=-g -Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lpthread -pthread -lm -lrt -lsubunit -lgcov --coverage

HEADERS =  3DViewer.h $(wildcard ./*.c)
SRC = $(wildcard ./create_remove_functions/*.c) $(wildcard ./arithmetic_functions/*.c) $(wildcard ./comparison_function/*.c) $(wildcard ./transpose_function/*.c) $(wildcard ./other_functions/*.c) $(wildcard ./helper/*.c) 

OBJ = $(patsubst %.c, %.o, $(SRC))

TEST = tests/test
TEST_SRC = $(wildcard $(TEST)*.c)
TEST_OBJ = $(patsubst $(TEST)%.c, $(TEST)%.o, $(TEST_SRC))

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $

all: 

install:

uninstall:


all, install, uninstall, clean, dvi, dist, tests, gcov_report.

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info ./*/*.o ./*/*.a ./*/*.gcda ./*/*.gcno ./*/*.gcov ./*/*.info ./*/*.html $(TEST) gcov_report ./report

dvi:

dist:


tests: clean covered test.a


gcov_report: tests
	mkdir ./report
	mv ./*.gcda ./report/
	mv ./tests/*.gcda ./report/
	mv ./*.gcno ./report/
	mv ./tests/*.gcno ./report/
#	lcov -t "3DViewer" -o 3DViewer.info -c -d .
#	genhtml -o gcov_report 3DViewer.info
#	pip install gcovr
	~/.local/bin/gcovr -r . --html --html-nested --html-self-contained --txt-metric branch --exclude-unreachable-branches --exclude-lines="3DViewer" -o ./report/gcov_report.html
#	firefox report/gcov_report.html

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n $(SRC) $(TEST_SRC) ./*.h ./*/*.h
	rm .clang-format

leaks: test
	valgrind --leak-check=yes  ./$(TEST)


rebuild: clean all