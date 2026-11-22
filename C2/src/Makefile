CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
CHECK_CFLAGS = $(shell pkg-config --cflags check)
CHECK_LIBS = $(shell pkg-config --libs check) -lm
BUILD = build
SRC := $(wildcard s21_*.c)
OBJ := $(SRC:%.c=$(BUILD)/obj/%.o)
COV := $(SRC:%.c=$(BUILD)/coverage/%.o)
TEST_SRC := $(wildcard tests/test*.c)
TEST_OBJ := $(TEST_SRC:%.c=$(BUILD)/%.o)
TEST_BIN = tests/test
LIB = s21_string.a
SAN_FLAGS = -fsanitize=address,undefined -fno-sanitize-recover=all -fno-omit-frame-pointer

.PHONY: all test test.a covered gcov_report style sanitize leaks clean rebuild

all: test

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

$(TEST_BIN): $(TEST_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(CHECK_LIBS) $(LDLIBS) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

covered: $(BUILD)/coverage/s21_string.a

$(BUILD)/coverage/s21_string.a: $(COV)
	$(AR) rcs $@ $^

$(BUILD)/coverage/test: $(TEST_OBJ) $(BUILD)/coverage/s21_string.a
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage $^ $(CHECK_LIBS) $(LDLIBS) -o $@

gcov_report: $(BUILD)/coverage/test
	$(RM) $(BUILD)/coverage/*.gcda
	./$(BUILD)/coverage/test
	@mkdir -p report
	gcovr --root . --filter '.*s21_[^/]*\.c$$' --exclude 'tests/' \
	      --html-details report/gcov_report.html --print-summary
	@LC_ALL=C gcov -fn $(COV:.o=.gcno) > report/functions.txt
	@LC_ALL=C awk -F '[:%]' '/^Function / { name = $$0 } \
	    /^Lines executed:/ && name { \
	        if (!count++ || $$2 + 0 < minimum) { minimum = $$2 + 0; lowest = name } \
	        if ($$2 + 0 < 80) print name, $$2 "%" ; name = "" \
	    } END { printf "Minimum line coverage across %d functions: %.2f%% (%s)\n", \
	            count, minimum, lowest; exit (!count || minimum < 80) }' report/functions.txt

style:
	clang-format --style=Google --dry-run --Werror $(SRC) $(wildcard s21_*.h)

$(BUILD)/sanitize/test: $(SRC) $(TEST_SRC) $(wildcard s21_*.h) tests/test.h
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(CHECK_CFLAGS) $(SAN_FLAGS) $(LDFLAGS) \
	      $(SRC) $(TEST_SRC) $(CHECK_LIBS) $(LDLIBS) -o $@

sanitize: $(BUILD)/sanitize/test
	ASAN_OPTIONS=detect_leaks=1 ./$(BUILD)/sanitize/test

leaks: sanitize

clean:
	$(RM) -r $(BUILD) report
	$(RM) $(LIB) $(TEST_BIN) tests/test.a

rebuild: clean
	$(MAKE) all

-include $(OBJ:.o=.d) $(COV:.o=.d) $(TEST_OBJ:.o=.d)
