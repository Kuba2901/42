NAME = so_long
SRC = main.c
OBJ = $(SRC:.c=.o)
INC = inc/
CC = cc
CFLAGS = -Wall -Wextra # -Werror
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -Ignl -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	cd ft_printf && make

all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd ft_printf && make clean

fclean: clean
	$(RM) $(NAME)
	cd ft_printf && make clean

re: fclean all

.PHONY: all clean fclean .c.o
