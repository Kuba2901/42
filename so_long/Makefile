NAME = so_long
SRC = main.c src/map_setup.c src/map_setup_2.c src/map_setup_3.c src/game_setup.c src/error_codes.c src/color_utils.c src/key_events.c src/movement.c src/drawing.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/
INC = -Iinc/ -I/usr/include -Imlx_linux $(INC_LIBFT_GNL)
CC = cc
CFLAGS = -Wall -Wextra # -g -Werror
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
