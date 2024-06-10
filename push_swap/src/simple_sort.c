/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:55:24 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 13:10:40 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_reverse_sorted(t_stack *stack)
{
	int	i;

	i = stack->nums_count;
	while (--i > 0)
	{
		if (stack->nums[i] > stack->nums[i - 1])
			return (0);
	}
	return (1);
}

void	handle_not_sorted(t_stack *stack, int min_index)
{
	if (min_index == 0)
	{
		sx(stack);
		return;
	}
	if (min_index == 1)
	{
		rrx(stack);
		return;
	}
	rx(stack);
}

void	simple_sort(t_stack *stack)
{
	int	min_index;
	int	i;
	
	if (is_sorted(*stack))
		return;
	if (is_reverse_sorted(stack))
	{
		sx(stack);
		rx(stack);
		return;
	}
	i = 0;
	min_index = 0;
	while (++i < stack->nums_count)
	{
		if (stack->nums[i] < stack->nums[min_index])
			min_index = i;
	}
	handle_not_sorted(stack, min_index);
}

/*
3
4
5
*/