#include <push_swap.h>

int		find_smaller(t_list **stack, int num)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (ps_elem_value(tmp) < num)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	ps_lstat(t_list **stack, int index)
{
	t_list	*tmp;
	int		i;
	
	tmp = *stack;
	i = -1;
	while (++i != index && tmp)
		tmp = tmp->next;
	return (*((int *)tmp->content));
}

void	move_num_to_top(t_list **stack, int index)
{
	int	num;
	int	stack_size;

	stack_size = ft_lstsize(*stack);
	if (!index)
		return;
	num = ps_lstat(stack, index);
	if (index >= stack_size / 2)
	{
		while (ps_elem_value(*stack) != num)
			ps_rx(stack, RA);
	}
	else {
		while (ps_elem_value(*stack) != num)
			ps_rrx(stack, RRA);
	}
}

int calc_push_rotate(t_list **stack)
{
	int	count;

	count = 0;
	if (is_sorted(*stack))
		return (0);
	while (!is_sorted(*stack))
	{
		ps_rx(stack, RA);
		count++;
	}
	return (count);
}
