NAME = libft.a
GNL_SRC = gnl/src/get_next_line.c
FT_PRINTF_SRC = src/ft_printf.c src/ft_printf_con.c
SRC = src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c \
src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putstr_fd.c \
src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c src/ft_strncmp.c \
src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c src/ft_substr.c src/ft_tolower.c src/ft_toupper.c $(GNL_SRC) $(FT_PRINTF_SRC)
BONUS	= src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c src/ft_lstlast.c \
		  src/ft_lstadd_back.c src/ft_lstdelone.c src/ft_lstclear.c src/ft_lstiter.c src/ft_lstmap.c
OBJBONUS = $(BONUS:%.c=%.o)
OBJ = $(SRC:.c=.o)
INC = -I gnl/inc/ -I inc/
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(NAME) $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re .c.o