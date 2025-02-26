NAME = unit_tests

CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra -Werror -I../include
TESTFLAGS = -lcriterion
LFLAGS = -L../ -lsc

TESTSRCDIR = src/string_lib src/memory_lib src/print_lib

TESTSSRC = $(foreach dir, $(TESTSRCDIR), $(wildcard $(dir)/*.c))
TESTOBJ = $(TESTSSRC:.c=.o)

all: $(NAME)

$(NAME): $(TESTOBJ)
	$(CC) -o $(NAME) $(TESTOBJ) $(CFLAGS) $(TESTFLAGS) $(LFLAGS)
	./$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TESTOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re