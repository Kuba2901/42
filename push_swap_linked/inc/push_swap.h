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
# define BOTTOM(stack) stack.nums[0]
# define TOP(stack) stack.nums[stack.nums_count - 1]

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

typedef struct s_stack_element
{
	int	value;
	struct s_stack_element	*next;
}	t_stack_element;

typedef struct s_stack
{
	t_stack_element	*top;
	t_stack_element	*bottom;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_push_swap;

int			get_parse_error(int ac, char **av);
t_stack 	parse_input(int ac, char **av);
int			is_number_invalid(const char *str);
long int	ft_atoi_long(const char *str);
void		remove_top(t_stack *stack);
void		push_top(t_stack *stack, int num);
void		pa_pb(t_push_swap *ps, int operation_code);
void		rx(t_stack *stack);
void		rra_rrb_rrr(t_push_swap *ps, int operation_code);
void		ra_rb_rr(t_push_swap *ps, int operation_code);
void		rx(t_stack *stack);
void		rx(t_stack *stack);
void		ra_rb_rr(t_push_swap *ps, int operation_code);
void 		sa_sb_ss(t_push_swap *ps, int operation_code);
void		sx(t_stack *stack);
#endif