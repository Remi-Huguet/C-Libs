CC = gcc
CFLAGS = -W -Wall -Wextra -Werror -I../include
TESTFLAGS = --coverage -lcriterion
SRCDIR = ../src
TESTSRCDIR = ./src
SRC = $(wildcard $(SRCDIR)/*.c)
TESTSSRC = $(wildcard $(TESTSRCDIR)/*.c)
TEST_EXEC = unit_tests

all: $(TEST_EXEC)

$(TEST_EXEC): $(SRC) $(TESTSSRC)
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -f $(TEST_EXEC) *.gcda *.gcno

fclean: clean

re: fclean all

.PHONY: all clean fclean re tests_run
