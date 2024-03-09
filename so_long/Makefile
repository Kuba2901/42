NAME = so_long
SRC = main.c
OBJ = $(SRC:.c=.o)
INC = -I/usr/include -Imlx_linux -Ilibft/inc/ -Ilibft/gnl/inc/
CC = cc
CFLAGS = -Wall -Wextra # -Werror
RM = rm -rf
LIBFT_INCLUDE = -L./libft -lft
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT_INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean .c.o
