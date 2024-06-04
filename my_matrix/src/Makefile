SHELL :=/bin/bash
CC=gcc
FLAGS=-g -Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lpthread -pthread -lm -lrt -lsubunit -lgcov --coverage

HEADERS =  s21_matrix.h $(wildcard ./*.c)
SRC = $(wildcard ./create_remove_functions/*.c) $(wildcard ./arithmetic_functions/*.c) $(wildcard ./comparison_function/*.c) $(wildcard ./transpose_function/*.c) $(wildcard ./other_functions/*.c) $(wildcard ./helper/*.c) 

OBJ = $(patsubst %.c, %.o, $(SRC))

TEST = tests/test
TEST_SRC = $(wildcard $(TEST)*.c)
TEST_OBJ = $(patsubst $(TEST)%.c, $(TEST)%.o, $(TEST_SRC))

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJ) $(HEADER)
	ar rc s21_matrix.a $(OBJ)
	ranlib s21_matrix.a


test.a: $(TEST_OBJ)
	ar rc $(TEST).a $(TEST_OBJ)
	ranlib $(TEST).a

covered:
	$(CC) $(FLAGS) $(TEST_FLAGS) -c $(SRC)
	ar rc s21_matrix.a ./*.o
	ranlib s21_matrix.a
	rm -rf ./*.o

test: clean covered test.a
	$(CC) $(FLAGS) $(TEST_FLAGS) -o $(TEST).o $(TEST).c -c
	$(CC) $(TEST).o $(TEST).a s21_matrix.a -o $(TEST) $(FLAGS) $(TEST_FLAGS)
	-./$(TEST)

gcov_report: test
	mkdir ./report
	mv ./*.gcda ./report/
	mv ./tests/*.gcda ./report/
	mv ./*.gcno ./report/
	mv ./tests/*.gcno ./report/
#	lcov -t "s21_matrix" -o s21_matrix.info -c -d .
#	genhtml -o gcov_report s21_matrix.info
#	pip install gcovr
	~/.local/bin/gcovr -r . --html --html-nested --html-self-contained --txt-metric branch --exclude-unreachable-branches --exclude-lines="s21_matrix" -o ./report/gcov_report.html
#	firefox report/gcov_report.html

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n $(SRC) $(TEST_SRC) ./*.h ./*/*.h
	rm .clang-format

leaks: test
	valgrind --leak-check=yes  ./$(TEST)

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info ./*/*.o ./*/*.a ./*/*.gcda ./*/*.gcno ./*/*.gcov ./*/*.info ./*/*.html $(TEST) gcov_report ./report


rebuild: clean all