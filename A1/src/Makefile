SHELL :=/bin/bash

PROJECT_NAME = maze
CC = gcc

OBJ_DIR = ./obj
LOGIC_DIR = ./backend
GUI_DIR = ./gui
TEST_DIR = ./tests
REPORT_DIR = ./report
DVI_DIR = ./../docs
DIST_DIR = ./../dist
BUILD = ./../bin

CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11
LDGUI = -lncurses
TEST_FLAGS =-lcheck -lpthread -ldl -pthread -lm -lrt -lsubunit -lgcov --coverage
VALGRIND_FLAGS = --tool=memcheck --leak-check=full

HEADERS = $(shell find $(LIB_DIR) -type f -name "*.h") \
           $(shell find $(TEST_DIR) -type f -name "*.h") \
		   $(shell find $(GUI_DIR) -type f -name "*.h")

LIBRARY = $(PROJECT_NAME).a
GUI_LIBRARY = $(PROJECT_NAME)_gui.a

TARGET = test
GCOV = gcov_report

MAIN_C = main.c
MAIN_H = main.h

LOGIC_DIRS = $(shell find $(LOGIC_DIR) -type d)
LOGIC_C = $(shell find $(LOGIC_DIR) -type f -name "*.c")
LOGIC_H = $(shell find $(LOGIC_DIR) -type f -name "*.h")
LOGIC_O = $(notdir $(LOGIC_C:%.c=%.o))

GUI_DIRS = $(shell find $(GUI_DIR) -type d)
GUI_C = $(shell find $(GUI_DIR) -type f -name "*.c")
GUI_H = $(shell find $(GUI_DIR) -type f -name "*.h")
GUI_O = $(notdir $(GUI_C:%.c=%.o))

LOGIC_OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(LOGIC_O))
GUI_OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(GUI_O))


TEST_DIRS = $(shell find $(TEST_DIR) -type d)
TEST_C = $(shell find $(TEST_DIR) -type f -name "*_test.c")
TEST_H = $(shell find $(TEST_DIR) -type f -name "*_test.h")
TEST_O = $(notdir $(TEST_C:%.c=%.o))
TEST_OBJ_PATH = $(OBJ_DIR)/*_test.o
EXCLUDE = $(filter-out $(wildcard $(LOGIC_DIR)/debug/*),$(LOGIC_C))

C_FILES = $(LOGIC_C) $(GUI_C) $(TEST_C)
H_FILES = $(LOGIC_H) $(GUI_H) $(MAIN_H) $(TEST_H)
ALL_FILES = $(C_FILES) $(H_FILES)

vpath %.c $(LOGIC_DIRS) : $(SQL_DIRS) : $(GUI_DIRS) : $(TEST_DIRS)
vpath %.o $(OBJ_DIR)

.PHONY: $(LIBRARY) $(TARGET) $(GCOV)

all: install run

install: uninstall $(LIBRARY) $(GUI_LIBRARY)
	@mkdir -p $(BUILD)
	@$(CC) $(CFLAGS) $(MAIN_C) $(LIBRARY) $(GUI_LIBRARY) $(LDGUI) -o $(BUILD)/$(PROJECT_NAME)


uninstall: clean
	@rm -rf $(BUILD)

$(LIBRARY): $(OBJ_DIR) $(LOGIC_O) $(LOGIC_H) $(MAIN_H)
	@ar rcs $@ $(LOGIC_OBJ_PATH)
	@ranlib $@

$(GUI_LIBRARY): $(OBJ_DIR) $(GUI_O) $(GUI_H) $(MAIN_H)
	@ar rcs $@ $(GUI_OBJ_PATH)
	@ranlib $@

test: clean $(OBJ_DIR) $(TEST_O) $(LIBRARY)
	@$(CC) $(TEST_OBJ_PATH) $(LIBRARY) $(TEST_FLAGS) -o $@
	@-./$@
	@printf "\033[1;33mTesting completed.\n\033[0m"

gcov_report: clean $(OBJ_DIR) $(REPORT_DIR) $(TEST_O)
	@$(CC) $(TEST_OBJ_PATH) $(EXCLUDE) $(TEST_FLAGS) -o $(addprefix $(OBJ_DIR)/, $(TARGET))
	@-./$(addprefix $(OBJ_DIR)/, $(TARGET))
	lcov -t "$(PROJECT_NAME)" -o $(REPORT_DIR)/gcov_report.info -c -d .
	genhtml -o $(REPORT_DIR) $(REPORT_DIR)/gcov_report.info
#	gcovr -r . --html --html-details  -o $(REPORT_DIR)/gcov_report.html
	@printf "\033[1;33mGCOV report created: $(REPORT_DIR)/gcov_report.html \n\033[0m"
	# xdg-open $(REPORT_DIR)/index.html

dvi:
	@rm -rf $(DVI_DIR)
	doxygen Doxyfile
	xdg-open $(DVI_DIR)/html/index.html

dist: uninstall
	@rm -rf $(DIST_DIR)
	@printf "\033[1;33mCreating a distribution...\n\033[0m"
	@mkdir -p $(DIST_DIR)/$(PROJECT_NAME)
	@cp -r ./ $(DIST_DIR)/$(PROJECT_NAME) && rm -rf $(DIST_DIR)/$(PROJECT_NAME)/tests
	@printf "\033[1;33mDistribution packaging...\n\033[0m"
	@tar -czf $(DIST_DIR)/$(PROJECT_NAME).tar.gz -C $(DIST_DIR) $(PROJECT_NAME)
	@printf "\033[1;33mDistribution created: $(DIST_DIR)/$(PROJECT_NAME).tar.gz\n\033[0m"
	@rm -rf $(DIST_DIR)/$(PROJECT_NAME)

run:
	@./$(BUILD)/$(PROJECT_NAME)


style:
	@cp ../materials/linters/.clang-format .clang-format
	@printf "\033[1;33mRunning clang-format with Google style on all files...\n\033[0m"
	@clang-format -style=Google -n $(ALL_FILES)
	@printf "\033[1;33mChecking formatting without making changes completed.\n\033[0m"
	@printf "\033[1;33mApplying clang-format with Google style to all files...\n\033[0m"
	@clang-format -style=Google -i $(ALL_FILES)
	@printf "\033[1;33mCode formatting with clang-format completed.\n\033[0m"
	@rm -f .clang-format

valgrind: clean $(TARGET)
	@$@ $(VAL) ./$(TARGET)

rebuild: uninstall install

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(REPORT_DIR)
	@rm -rf $(DVI_DIR)
	@rm -rf $(DIST_DIR)
	@rm -rf $(BUILD)
	@rm -rf $(GCOV)
	@rm -f $(TARGET)
	@rm -f *.a *.o
	@rm -f *.gc*
	@printf "\033[1;33mClean-up completed.\n\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(REPORT_DIR):
	@mkdir -p $(REPORT_DIR)

%.o: %.c $(LOGIC_H)
	@$(CC) $(CFLAGS) -c -o $(addprefix $(OBJ_DIR)/, $@) $<

%_gui.o: gui_%.c $(GUI_H)
	@$(CC) $(CFLAGS) -c -o $(addprefix $(OBJ_DIR)/, $@) $<

%_test.o: %_test.c
	@$(CC) $(CFLAGS) -c -o $(addprefix $(OBJ_DIR)/, $@) $<


install-deps:
	sudo apt update
	sudo apt install -y clang-format check doxygen libncurses5-dev sudo graphviz
