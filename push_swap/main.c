#include <push_swap.h>

void	free_stacks(t_push_swap push_swap)
{
	if (push_swap.stack_a.nums != NULL && push_swap.stack_a.nums_count)
		free(push_swap.stack_a.nums);
	if (push_swap.stack_b.nums != NULL && push_swap.stack_b.nums_count)
		free(push_swap.stack_b.nums);
}

void	print_stacks(t_push_swap push_swap)
{
	int	i;
	int	max_height;

	i = -1;
	if (push_swap.stack_a.nums_count > push_swap.stack_b.nums_count)
		max_height = push_swap.stack_a.nums_count;
	else
		max_height = push_swap.stack_b.nums_count;
	while (--max_height >= 0)
	{
		i = max_height;
		if (i < push_swap.stack_a.nums_count)
			ft_printf("%d", push_swap.stack_a.nums[i]);
		else
			ft_printf(" ");
		if (i < push_swap.stack_b.nums_count)
			ft_printf(" %d", push_swap.stack_b.nums[i]);
		else
			ft_printf(" ");
		ft_printf("\n");
	}
	ft_printf("a b\n");
	ft_printf("_ _\n");
}

t_push_swap	initialize_push_swap()
{
	t_push_swap ps;

	ps.stack_a.nums = NULL;
	ps.stack_a.nums_count = 0;
	ps.stack_b.nums = NULL;
	ps.stack_b.nums_count = 0;
	return (ps);
}

int main(int ac, char **av)
{
	t_push_swap push_swap;

	if (get_parse_error(ac, av))
	{
		ft_printf("Error\n");
		exit(1);
	}
	push_swap = initialize_push_swap();
	push_swap.stack_a = parse_input(ac, av);
	print_stacks(push_swap);
	pa_pb(&push_swap, PB);
	print_stacks(push_swap);
	pa_pb(&push_swap, PB);
	print_stacks(push_swap);
	ra_rb_rr(&push_swap, RA);
	print_stacks(push_swap);
	rra_rrb_rrr(&push_swap, RRA);
	print_stacks(push_swap);
	pa_pb(&push_swap, PA);
	print_stacks(push_swap);
	free_stacks(push_swap);
	return (0);
}