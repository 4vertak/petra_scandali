CC=gcc
FLAGS=-g -Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lpthread -pthread -lm -lrt -lsubunit -lgcov
TEST = tests/test
SRC = $(wildcard s21_*.c)
OBJ = $(patsubst s21_%.c, s21_%.o, $(SRC))

TEST_SRC = $(wildcard $(TEST)*.c)
TEST_OBJ = $(patsubst $(TEST)%.c, $(TEST)%.o, $(TEST_SRC))

all: s21_string.a test.a covered

s21_string.a: $(OBJ)
	ar rc s21_string.a $(OBJ)
	ranlib s21_string.a

test.a: $(TEST_OBJ)
	ar rc $(TEST).a $(TEST_OBJ)
	ranlib $(TEST).a

covered:
	$(CC) $(FLAGS) -c $(SRC) --coverage
	ar rc s21_string.a $(OBJ)
	ranlib s21_string.a 

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n *.c *.h
	rm .clang-format

test: clean covered test.a
	$(CC) $(FLAGS) --coverage -o $(TEST).o $(TEST).c -c
	$(CC) $(TEST).o $(TEST).a s21_string.a -o $(TEST) --coverage $(FLAGS) $(TEST_FLAGS)
	./$(TEST)
	mkdir ./report
	mv *.gcda ./report/
	mv *.gcno ./report/

leaks: test
	valgrind --leak-check=yes  ./$(TEST)

clean:
	rm -rf *.o *.a *.gcda *.gcno *.gcov *.info *.html $(TEST)*.gcda $(TEST)*.gcno $(TEST)*.o $(TEST)*.a $(TEST) gcov_report ./report


rebuild: clean all

gcov_report: test
#	lcov -t "s21_string" -o s21_string.info -c -d .
#	genhtml -o gcov_report s21_string.info
	gcovr -r . --html --html-nested --html-self-contained --txt-metric branch --exclude-unreachable-branches --exclude-lines="s21_string" -o ./report/gcov_report.html