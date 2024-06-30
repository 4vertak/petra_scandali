SHELL :=/bin/bash
CC=gcc
FLAGS=-g -Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lpthread -pthread -lm -lrt -lsubunit -lgcov --coverage

HEADERS =  ./backend/backend.h $(wildcard ./backend.c), ./backend/affine_transformations.h $(wildcard ./affine_transformations.c)
SRC = $(wildcard ./backend/*.c)  

OBJ = $(patsubst %.c, %.o, $(SRC))

TEST = tests/test
TEST_SRC = $(wildcard $(TEST)*.c)
TEST_OBJ = $(patsubst $(TEST)%.c, $(TEST)%.o, $(TEST_SRC))

# %.o: %.c $(HEADER)
# 	$(CC) $(FLAGS) -c $< -o $

# all:

# install:

# uninstall:


# all, install, uninstall, clean, dvi, dist, tests, gcov_report.

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info ./*/*.o ./*/*.a ./*/*.gcda ./*/*.gcno ./*/*.gcov ./*/*.info ./*/*.html $(TEST) gcov_report ./report

# dvi:

# dist:


backend.a: $(OBJ) $(HEADER)
	ar rc backend.a $(OBJ)
	ranlib backend.a


test.a: $(TEST_OBJ)
	ar rc $(TEST).a $(TEST_OBJ)
	ranlib $(TEST).a

covered:
	$(CC) $(FLAGS) $(TEST_FLAGS) -c $(SRC)
	ar rc backend.a ./*.o
	ranlib backend.a
	rm -rf ./*.o

test: clean covered test.a
	$(CC) $(FLAGS) $(TEST_FLAGS) -o $(TEST).o $(TEST).c -c
	$(CC) $(TEST).o $(TEST).a backend.a -o $(TEST) $(FLAGS) $(TEST_FLAGS)
	-./$(TEST)

gcov_report: test
	mkdir ./report
	mv ./*.gcda ./report/
	mv ./tests/*.gcda ./report/
	mv ./*.gcno ./report/
	mv ./tests/*.gcno ./report/
#	lcov -t "backend" -o backend.info -c -d .
#	genhtml -o gcov_report backend.info
#	pip install gcovr
	~/.local/bin/gcovr -r . --html --html-nested --html-self-contained --txt-metric branch --exclude-unreachable-branches --exclude-lines="backend" -o ./report/gcov_report.html
#	firefox report/gcov_report.html

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n $(SRC) $(TEST_SRC) ./*/*.h
	rm .clang-format

leaks: test
	valgrind --leak-check=full --show-leak-kinds=all  ./$(TEST)


rebuild: clean all