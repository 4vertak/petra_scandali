CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
CHECK_CFLAGS = $(shell pkg-config --cflags check)
CHECK_LIBS = $(shell pkg-config --libs check) -lm
SAN_FLAGS = -fsanitize=address,undefined,float-cast-overflow,float-divide-by-zero \
            -fno-sanitize-recover=all -fno-omit-frame-pointer

LIB = s21_math.a
BUILD = build
TEST = tests/test
SRC := $(wildcard s21_*.c)
OBJ := $(SRC:%.c=$(BUILD)/obj/%.o)
COV := $(SRC:%.c=$(BUILD)/coverage/%.o)
TEST_SRC := $(wildcard tests/test*.c)
TEST_OBJ := $(TEST_SRC:%.c=$(BUILD)/%.o)

.PHONY: all test test.a covered gcov_report style leaks clean rebuild

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) rcs $@ $^

$(BUILD)/obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD)/tests/%.o: tests/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(CHECK_CFLAGS) -MMD -MP -c $< -o $@

$(BUILD)/coverage/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -O0 --coverage -MMD -MP -c $< -o $@

test.a: tests/test.a

tests/test.a: $(TEST_OBJ)
	$(AR) rcs $@ $^

$(TEST): $(TEST_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(CHECK_LIBS) $(LDLIBS) -o $@

test: $(TEST)
	./$(TEST)

covered: $(BUILD)/coverage/$(LIB)

$(BUILD)/coverage/$(LIB): $(COV)
	$(AR) rcs $@ $^

$(BUILD)/coverage/test: $(TEST_OBJ) $(BUILD)/coverage/$(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage $^ $(CHECK_LIBS) $(LDLIBS) -o $@

gcov_report: $(BUILD)/coverage/test
	$(RM) $(BUILD)/coverage/*.gcda
	./$(BUILD)/coverage/test
	@mkdir -p report
	gcovr --root . --filter '.*s21_[^/]*\.c$$' --html-details report/gcov_report.html --print-summary $(BUILD)/coverage
	@LC_ALL=C gcov -fn $(COV:.o=.gcno) > report/functions.txt
	@LC_ALL=C awk -F '[:%]' '/^Function / { name = $$0 } \
	    /^Lines executed:/ && name { \
	        if (!count++ || $$2 + 0 < minimum) { minimum = $$2 + 0; lowest = name } \
	        if ($$2 + 0 < 80) print name, $$2 "%"; name = "" \
	    } END { printf "Minimum line coverage across %d functions: %.2f%% (%s)\n", \
	        count, minimum, lowest; exit (!count || minimum < 80) }' report/functions.txt

style:
	clang-format --style=Google --dry-run --Werror $(SRC) $(wildcard *.h) $(TEST_SRC) tests/test.h

$(BUILD)/sanitize/test: $(SRC) $(TEST_SRC) $(wildcard *.h) tests/test.h
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(CHECK_CFLAGS) $(SAN_FLAGS) $(LDFLAGS) \
	      $(SRC) $(TEST_SRC) $(CHECK_LIBS) $(LDLIBS) -o $@

leaks: $(BUILD)/sanitize/test
	ASAN_OPTIONS=detect_leaks=1 ./$(BUILD)/sanitize/test

clean:
	$(RM) -r $(BUILD) report
	$(RM) $(LIB) $(TEST) tests/test.a
	$(RM) s21_*.o s21_*.gcno s21_*.gcda tests/test*.o tests/test*.gcno tests/test*.gcda

rebuild: clean
	$(MAKE) all

-include $(OBJ:.o=.d) $(COV:.o=.d) $(TEST_OBJ:.o=.d)
