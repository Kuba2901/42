NAME = so_long
SRC = main.c src/map_setup.c src/map_setup_2.c src/map_setup_3.c src/map_setup_4.c src/game_setup.c src/game_setup_2.c src/error_codes.c src/graphics_utils.c src/key_events.c src/movement.c src/drawing.c src/drawing_2.c src/animation.c src/animation_2.c src/placing_enemies.c src/placing_enemies_2.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/
INC = -Iinc/ -I/usr/include -Imlx_linux $(INC_LIBFT_GNL)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_INCLUDE = -L./libft -lft
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT_INCLUDE)
MLX_NAME = mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

first_run:
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_NAME)
	cd $(MLX_NAME) && ./configure
	make clean_rebuild

all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

re: fclean all

clean_rebuild: all clean

.PHONY: all clean fclean .c.o clean_rebuild
