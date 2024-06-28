#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# define ERROR_NO_ARGUMENTS 1
# define ERROR_NOT_INTEGERS 2
# define ERROR_INT_OVERFLOW 3
# define ERROR_CONTAINS_DUPLICATES 4
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define NUMBERS_VALID 0

typedef struct s_stack_element
{
	int				value;
	t_stack_element	*next;
	t_stack_element	*prev;
}	t_stack_element;

typedef struct s_stack
{
	t_stack_element* head;
	t_stack_element* tail;
}	t_stack;

// Operation codes
# define SA 30
# define SB 31
# define SS 32
# define RA 33
# define RB 34
# define RR 35
# define RRA 36
# define RRB 37
# define RRR 38
# define PA 39
# define PB 40
# define RX 41
# define RRX 42

void	ps_stack_pop_head(t_stack *stack);
#endif