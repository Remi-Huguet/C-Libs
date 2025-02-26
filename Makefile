NAME = libsc.a

CC_LIB = ar rcs
CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra -Werror -Iinclude

SRCDIRS = src/string_lib src/memory_lib src/print_lib

SRC = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC_LIB) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

tests_run: $(NAME)
	$(MAKE) -C tests re

clean:
	$(RM) $(OBJ)
	$(MAKE) -C tests clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C tests fclean

re: fclean all

.PHONY: re fclean clean all tests_run mkdir