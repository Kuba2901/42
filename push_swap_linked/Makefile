NAME = push_swap
SRC = main.c src/ps_parse_input.c src/ps_sort_small.c src/operations/ps_rx.c src/operations/ps_sx.c src/operations/ps_rrx.c src/operations/ps_px.c src/ps_radix.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/ -Ilibft/inc_ft_printf/
INC = -Iinc/ $(INC_LIBFT_GNL)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT_INCLUDE = -L./libft -lft
LIBS = $(LIBFT_INCLUDE)

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
