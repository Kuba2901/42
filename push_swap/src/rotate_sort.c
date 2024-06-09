/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:32:52 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/09 13:38:10 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_single_stack(t_stack stack)
{
	int	i;

	i = stack.nums_count;
	while (--i >= 0)
		printf("[%d]: %d\n", i, stack.nums[i]);
}

int		find_smaller(t_stack stack, int num)
{
	int	i;

	i = stack.nums_count;
	while (--i >= 0)
	{
		if (stack.nums[i] < num)
			break ;
	}
	return (i);
}

void	move_num_to_top(t_stack *stack, int index)
{
	int	num;

	if (index == stack->nums_count - 1)
		return;
	num = stack->nums[index];
	if (index >= stack->nums_count / 2)
	{
		while (stack->nums[stack->nums_count - 1] != num)
			rx(stack);
	}
	else {
		while (stack->nums[stack->nums_count - 1] != num)
			rrx(stack);
	}
}

int	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (++i < stack.nums_count)
	{
		if (stack.nums[i - 1] > stack.nums[i])
			return (0);
	}
	return (1);
}

int calc_push_rotate(t_stack *stack)
{
	int	count;

	count = 0;
	if (is_sorted(*stack))
		return (0);
	while (!is_sorted(*stack))
	{
		rx(stack);
		count++;
	}
	return (count);
}
