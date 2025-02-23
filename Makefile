NAME = libc.a

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror -Iinclude
LFLAGS = -g -Llib/my -lmy

SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

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
	rm -rf $(OBJDIR)
	$(MAKE) -C tests clean

fclean: clean
	rm -f $(NAME) $(TESTS_NAME)
	$(MAKE) -C tests fclean

re: fclean all

.PHONY: re fclean clean all tests_run mkdir
