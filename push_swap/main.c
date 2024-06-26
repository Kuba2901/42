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

int	after_push_operations(int num, t_stack stack)
{
	int	i;
	int	up;

	if (!stack.nums_count || stack.nums[stack.nums_count - 1] < num)
		return (0);
	if (stack.nums[0] > num)
		return (1);
	i = stack.nums_count;
	up = -1;
	while (--i > 0)
	{
		if (stack.nums[i] < num)
		{
			up = stack.nums_count - i - 1;
			break;
		}
	}
	return (up);
}

int	find_cheapest_index(t_stack from_stack, t_stack to_stack)
{
	int	i;
	int	mid;
	int	cheapest;
	int	temp_cost;
	int	ret;

	if (from_stack.nums_count == 1)
		return (0);
	if (to_stack.nums_count <= 1)
		return (from_stack.nums_count - 1);
	cheapest = from_stack.nums_count + 1;
	i = from_stack.nums_count;
	mid = from_stack.nums_count / 2 + 1;
	ret = from_stack.nums_count - 1;
	while (--i >= mid)
	{
		temp_cost = after_push_operations(from_stack.nums[i], to_stack);
		if (cheapest > temp_cost)
		{
			cheapest = temp_cost;
			ret = i;
		}
	}
	i = -1;
	while (++i <= mid)
	{
		temp_cost = after_push_operations(from_stack.nums[i], to_stack);
		if (cheapest > temp_cost)
		{
			cheapest = temp_cost;
			ret = i;
		}
	}
	return (ret);
}

void ft_print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], STDERR_FILENO);
}

int main(int ac, char **av)
{
	t_push_swap push_swap;

	if (get_parse_error(ac, av))
	{
		ft_print_error("Error\n");
		exit(1);
	}
	push_swap = initialize_push_swap();
	push_swap.stack_a = parse_input(ac, av);

	// Keep pushing to stack B until A has no more numbers
	while (push_swap.stack_a.nums_count > 3)
	{
		int ci = find_cheapest_index(push_swap.stack_a, push_swap.stack_b);
		int smaller_index = find_smaller(push_swap.stack_b, push_swap.stack_a.nums[ci]);
		move_num_to_top(&push_swap.stack_a, ci); 
		if (smaller_index != -1)
			move_num_to_top(&push_swap.stack_b, smaller_index);
		pa_pb(&push_swap, PB);
	}
	// Sort the remaining numbers in stack A
	printf("Stack A before simple sort\n");
	simple_sort(&push_swap.stack_a);
	printf("Stack A after simple sort\n");
	print_stacks(push_swap);

	// Push the remaining numbers in stack B to stack A
	while (push_swap.stack_b.nums_count)
	{
		int ci = find_cheapest_index(push_swap.stack_b, push_swap.stack_a);
		int smaller_index = find_smaller(push_swap.stack_a, push_swap.stack_b.nums[ci]);
		move_num_to_top(&push_swap.stack_b, ci); 
		if (smaller_index != -1)
			move_num_to_top(&push_swap.stack_a, smaller_index);
		pa_pb(&push_swap, PA);
	}
	print_stacks(push_swap);
	free_stacks(push_swap);
	return (0);
}