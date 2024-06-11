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

long	ft_atoi_long(const char *str);
int		ft_is_int(const char *str);
int		parse_errors(int ac, char **av);
t_list	**parse_input(int ac, char **av);
int		is_sorted(t_list **list);
t_list	*ps_create_list_element(int num);
void	ps_rx(t_list **stack);
void	ps_sx(t_list **stack);
void	ps_rrx(t_list **stack);
void	ps_pop_last(t_list **stack);
void	ps_pop_head(t_list **stack);
void	ps_px(t_list **from, t_list **to);
int		ps_elem_value(t_list *list);
void	ps_radix_sort(t_list **stack, t_list **other_stack);
void	ps_sort_small(t_list **a, t_list **b);

#endif