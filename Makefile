NAME = libc.a

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror -Iinclude
LFLAGS = -g -Llib/my -lmy

SRCDIR = src
OBJDIR = obj

SRC = $(SRCDIR)/*.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | mkdir
	$(CC) $(CFLAGS) -c $< -o $@

mkdir:
	mkdir -p $(OBJDIR)

all: $(NAME)

tests_run:
	$(MAKE) -C tests re

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C tests clean

fclean: clean
	$(RM) $(NAME) $(TESTS_NAME)
	$(MAKE) -C tests fclean

re: fclean all

.PHONY: re fclean clean all tests_run mkdir
