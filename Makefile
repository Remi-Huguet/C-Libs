NAME = stringlib.a

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror
LFLAGS = -g -Llib/my -lmy
TESTFLAGS = --coverage -lcriterion

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

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all mkdir
