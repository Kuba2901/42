NAME = push_swap
SRC = main.c src/input_parsing.c src/pa_pb.c src/ra_rb_rr.c src/rra_rrb_rrr.c src/sa_sb_ss.c src/rotate_sort.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/ -Ilibft/inc_ft_printf/
INC = -Iinc/ $(INC_LIBFT_GNL)
CC = cc
CFLAGS = -Wall -Wextra -g # -Werror
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
