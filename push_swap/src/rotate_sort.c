/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:32:52 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/06 14:57:41 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	printf("Reached! N.%d is not on top!\n", num);
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
		printf("Rotating stack!");
		rx(stack);
		count++;
	}
	return (count);
}
