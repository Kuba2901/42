# COMMON PART
NAME = so_long
SRC = main.c src/map_setup.c src/map_setup_2.c src/map_setup_3.c src/game_setup.c src/error_codes.c src/graphics_utils.c src/key_events.c src/movement.c src/drawing.c src/animation.c src/animation_2.c src/placing_enemies.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/
CC = cc
CFLAGS = -Wall -Wextra # -Werror
RM = rm -rf
LIBFT_INCLUDE = -L./libft -lft

# LINUX
# INC_LINUX = -Iinc/ -I/usr/include -Imlx_linux $(INC_LIBFT_GNL)
# LIBS_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT_INCLUDE)

# %.o: %.c
# 	$(CC) $(CFLAGS) $(INC_LINUX) -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	cd libft && make
# 	$(CC) $(OBJ) $(LIBS) -o $(NAME)

# MACOS
INC_MAC = -Iinc/ -Imlx_mac $(INC_LIBFT_GNL)
LIBS_MAC = -Lmlx_mac -lmlx -framework OpenGL -Imlx_mac -framework AppKit $(LIBFT_INCLUDE)
%.o: %.c
	$(CC) $(CFLAGS) $(INC_MAC) -c $< -o $@

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(OBJ) $(LIBS_MAC) -o $(NAME)

# COMMON
all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

re: fclean all

clean_rebuild: all clean

.PHONY: all clean fclean .c.o
	