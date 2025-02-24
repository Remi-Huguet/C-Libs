TEST_EXEC = unit_tests

CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra -Werror -I../include
TESTFLAGS = -lcriterion

SRCDIR = ../src/string_lib ../src/memory_lib ../src/print_lib
TESTSRCDIR = src/string_lib src/memory_lib src/print_lib

SRC = $(foreach dir, $(SRCDIR), $(dir)/*.c)
TESTSSRC = $(foreach dir, $(TESTSRCDIR), $(dir)/*.c)

all: $(TEST_EXEC)

$(TEST_EXEC): $(SRC) $(TESTSSRC)
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	$(RM) $(TEST_EXEC)

fclean: clean

re: fclean all

.PHONY: all clean fclean re tests_run
