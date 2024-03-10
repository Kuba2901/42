NAME = libft.a
SRC = src_libft/ft_atoi.c src_libft/ft_bzero.c src_libft/ft_calloc.c src_libft/ft_isalnum.c src_libft/ft_isalpha.c src_libft/ft_isascii.c src_libft/ft_isdigit.c src_libft/ft_isprint.c src_libft/ft_itoa.c \
src_libft/ft_memchr.c src_libft/ft_memcmp.c src_libft/ft_memcpy.c src_libft/ft_memmove.c src_libft/ft_memset.c src_libft/ft_putchar_fd.c src_libft/ft_putendl_fd.c src_libft/ft_putnbr_fd.c src_libft/ft_putstr_fd.c \
src_libft/ft_split.c src_libft/ft_strchr.c src_libft/ft_strdup.c src_libft/ft_striteri.c src_libft/ft_strjoin.c src_libft/ft_strlcat.c src_libft/ft_strlcpy.c src_libft/ft_strlen.c src_libft/ft_strmapi.c src_libft/ft_strncmp.c \
src_libft/ft_strnstr.c src_libft/ft_strrchr.c src_libft/ft_strtrim.c src_libft/ft_substr.c src_libft/ft_tolower.c src_libft/ft_toupper.c

BONUS	= src_libft/ft_lstnew.c src_libft/ft_lstadd_front.c src_libft/ft_lstsize.c src_libft/ft_lstlast.c \
		  src_libft/ft_lstadd_back.c src_libft/ft_lstdelone.c src_libft/ft_lstclear.c src_libft/ft_lstiter.c src_libft/ft_lstmap.c
OBJBONUS = $(BONUS:%.c=%.o)

OBJ = $(SRC:.c=.o)
INC = inc_libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

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