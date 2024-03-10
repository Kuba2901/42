NAME = libgnl.a
SRC = src_gnl/get_next_line.c src_gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
INC = inc_gnl/
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBS = -L./libgnl -lgnl

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o
