NAME = so_long
SRC = main.c src/map_setup.c src/map_setup_2.c src/map_setup_3.c src/map_setup_4.c \
		src/game_setup.c src/game_setup_2.c src/error_codes.c src/graphics_utils.c \
		src/key_events.c src/movement.c src/drawing.c src/drawing_2.c src/animation.c \
		src/animation_2.c src/placing_enemies.c src/placing_enemies_2.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/ -Ilibft/inc_ft_printf/
INC = -Iinc/ -I/usr/include -Imlx_linux $(INC_LIBFT_GNL)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT_INCLUDE = -L./libft -lft
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT_INCLUDE)
MLX_NAME = mlx_linux

# RUNNING ON MAC
IMG_NAME = 42_testing
DISPLAY_WIRELESS = -e $(shell ipconfig getifaddr en0):0
DISPLAY_WIRED = -e DISPLAY=$(shell ipconfig getifaddr en1):0
RUN_FLAGS = -it --rm
NET_IS_WIRELESS = $(shell ipconfig getifaddr en0 | wc -l | tr -d ' ')
NET_IS_WIRED = $(shell ipconfig getifaddr en1 | wc -l | tr -d ' ')
MOUNT_VOL = -v $$PWD:/42_cursus/so_long
ENTRYPOINT= --entrypoint /bin/bash /42_cursus/so_long/so_long

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

run_preconf:
	@echo "Running preconf"
	make first_run
	xhost +

run_wired:
	make run_preconf
	@echo "Running wired"
	open -a Xquartz
	docker run $(RUN_FLAGS) $(DISPLAY_WIRED) $(MOUNT_VOL) $(ENTRYPOINT) $(IMG_NAME)

run_wireless:
	make run_preconf
	@echo Running SO_LONG Game
	open -a Xquartz
	docker run $(RUN_FLAGS) $(DISPLAY_WIRELESS) $(MOUNT_VOL) $(ENTRYPOINT) $(IMG_NAME)

first_run:
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_NAME)
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
