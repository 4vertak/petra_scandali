SHELL :=/bin/bash
CC=gcc
FLAGS=-g -Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lpthread -pthread -lm -lrt -lsubunit -lgcov --coverage

SRC = $(wildcard ./c_mod/*/*.c)  

OBJ = $(patsubst c_mod/*/%.c, %.o, $(SRC))z

TEST = tests/test
TEST_SRC = $(wildcard $(TEST)*.c)
TEST_OBJ = $(patsubst $(TEST)%.c, $(TEST)%.o, $(TEST_SRC))

# all, install, uninstall, clean, dvi, dist, tests, gcov_report.
#	# @cat ./semigraphics/complete.txt
# all:

# install:

# uninstall:

clean:
	@rm -f *.o *.a ./*/*.o ./*/*.a
	@rm -rf *.gcda *.gcno ./*/*.gcda ./*/*.gcno
	@rm -rf *.info *.gcov *.html gcov_report ./report ./tests/test
	@rm -Rf report
	@rm -rf ./qt_mod/build/
	@rm -fR ./frontend/3DViewer/build
	@rm -rf ./qt_mod/qt_mod.pro.user

# dvi:

# dist:


c_mod.a: $(OBJ) $(HEADER)
	ar rc c_mod.a $(OBJ)
	ranlib c_mod.a
	rm -rf ./*.o


test.a: $(TEST_OBJ)
	ar rc $(TEST).a $(TEST_OBJ)
	ranlib $(TEST).a
	rm -rf ./*.o

covered:
	$(CC) $(FLAGS) $(TEST_FLAGS) -c $(SRC)
	ar rc c_mod.a ./*.o
	ranlib c_mod.a
	rm -rf ./*.o

test: clean covered test.a
	@cat ./semigraphics/pseudologo.txt
	$(CC) $(FLAGS) $(TEST_FLAGS) -o $(TEST).o $(TEST).c -c
	$(CC) $(TEST).o $(TEST).a c_mod.a -o $(TEST) $(FLAGS) $(TEST_FLAGS)
	-./$(TEST)
	rm -rf ./*.o

gcov_report: test
	mkdir ./report
	mv ./*.gcda ./report/
	mv ./tests/*.gcda ./report/
	mv ./*.gcno ./report/
	mv ./tests/*.gcno ./report/
#	lcov -t "c_mod" -o c_mod.info -c -d .
#	genhtml -o gcov_report c_mod.info
#	pip install gcovr
	~/.local/bin/gcovr -r . --html --html-nested --html-self-contained --txt-metric branch --exclude-unreachable-branches --exclude-lines="c_mod" -o ./report/gcov_report.html
#	firefox report/gcov_report.html


style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n $(SRC) $(TEST_SRC) ./*/*.h
	rm .clang-format

leaks: test
	valgrind --leak-check=full --show-leak-kinds=all  ./$(TEST)



rebuild: clean all