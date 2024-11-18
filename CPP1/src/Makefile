SHELL := /bin/bash

PROJECT_NAME = s21_matrix_oop

CC = g++

OBJ_DIR = ./obj

LIB_DIR = ./s21_matrix

TEST_DIR = ./test

REPORT_DIR = ./report

DVI_DIR = ./../docs

CCFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

GCOV_FLAGS = --coverage -lgtest -g 

CHECK_FLAGS = -lgtest -pthread -lrt -lm -lsubunit

CPP_CHECK = cppcheck --enable=all --std=c++17 --suppress=missingIncludeSystem .

GCOVR = gcovr

GCOVRFLAGS = --html --html-details --exclude-throw-branches -o $(REPORT_DIR)/report.html

HEADERS = $(shell find $(LIB_DIR) -type f -name "*.h") \
           $(shell find $(TEST_DIR) -type f -name "*.h")

LIBRARY = $(PROJECT_NAME).a

TARGET = test

LIB_CPP = $(shell find $(LIB_DIR) -type f -name "*.cpp")

LIB_H = $(shell find $(LIB_DIR) -type f -name "*.h")

LIB_O = $(notdir $(LIB_CPP:%.cpp=%.o))

TEST_CPP = $(shell find $(TEST_DIR) -type f -name "*.cpp")

TEST_O = $(notdir $(TEST_CPP:%.cpp=%.o))

ALL_FILES = $(LIB_CPP) $(TEST_CPP)

vpath %.cpp $(shell find $(LIB_DIR) -type d) $(shell find $(TEST_DIR) -type d)
vpath %.o $(OBJ_DIR)

.PHONY: all clean rebuild test gcov_report dvi style leaks install-deps

all: clean style cpp_check dvi $(LIBRARY) gcov_report leaks

clean:
	@rm -rf *.o *.g* *.info *.a *.out $(REPORT_DIR)/*.a *.dSYM *.html *.css
	@rm -rf $(OBJ_DIR)
	@rm -rf $(REPORT_DIR)
	@rm -rf $(DVI_DIR)
	@printf "\033[1;33mClean-up completed.\n\033[0m"

rebuild: clean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(REPORT_DIR):
	@mkdir -p $(REPORT_DIR)

$(LIBRARY): $(OBJ_DIR) $(LIB_O) $(HEADERS)
	@ar rcs $@ $(LIB_O)
	@ranlib $@

$(OBJ_DIR)/%.o: %.cpp
	@$(CC) $(CCFLAGS) -c -o $@ __CODE_BLOCK_0__lt;

test: $(LIBRARY)
	@printf "\033[1;33mCompiling tests...\n\033[0m"
	@$(CC) $(CCFLAGS) $(TEST_CPP) $(LIBRARY) $(CHECK_FLAGS) -o $(addprefix $(OBJ_DIR)/,$(TARGET))
	@./$(addprefix $(OBJ_DIR)/,$(TARGET))
	@rm -rf *.gcda *.gcno

cpp_check:
	@printf "\033[1;33mRunning cppcheck...\n\033[0m"
	@$(CPP_CHECK) $(LIB_CPP)
	@printf "\033[1;33mcppcheck completed.\n\033[0m"

gcov_report: $(LIBRARY) test $(REPORT_DIR)
	@$(CC) $(CCFLAGS) $(TEST_CPP) $(LIB_CPP) $(LIBRARY) $(CHECK_FLAGS) $(GCOV_FLAGS) -o $(addprefix $(OBJ_DIR)/, $(TARGET))
	@./$(addprefix $(OBJ_DIR)/,$(TARGET))
	@$(GCOVR) $(GCOVRFLAGS)
	@printf "\033[1;33mGCOV report created: $(REPORT_DIR)/report.html \n\033[0m"
	@rm -rf *.gcda *.gcno *.a *.o
#	xdg-open $(REPORT_DIR)/report.html

dvi:
	@rm -rf $(DVI_DIR)
	doxygen Doxyfile
#	xdg-open $(DVI_DIR)/html/index.html

style:
	@cp ../materials/linters/.clang-format .clang-format
	@printf "\033[1;33mRunning clang-format with Google style on all files...\n\033[0m"
	@clang-format -style=Google -n $(ALL_FILES)
	@printf "\033[1;33mChecking formatting without making changes completed.\n\033[0m"
#	@printf "\033[1;33mApplying clang-format with Google style to all files...\n\033[0m"
#	@clang-format -style=Google -i $(ALL_FILES)
#	@printf "\033[1;33mCode formatting with clang-format completed.\n\033[0m"
	@rm -f .clang-format

leaks: clean $(TARGET)
	valgrind --tool=memcheck --leak-check=full -s $(addprefix $(OBJ_DIR)/,$(TARGET))
	@rm -rf *.gcda *.gcno *.a *.o

install-deps:
	sudo apt update
	sudo apt install -y clang-format cppcheck doxygen libgtest-dev
