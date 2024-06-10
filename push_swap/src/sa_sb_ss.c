/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:07:56 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 13:07:01 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sx(t_stack *stack)
{
	int	temp;
	int	last_index;

	if (stack->nums_count < 2)
		return;
	last_index = stack->nums_count - 1;
	temp = stack->nums[last_index - 1];
	stack->nums[last_index - 1] = stack->nums[last_index];
	stack->nums[last_index] = temp;
}

void 	sa_sb_ss(t_push_swap *ps, int operation_code)
{
	if (operation_code == SA)
		sx(&(ps->stack_a));
	else if (operation_code == SB)
		sx(&(ps->stack_b));
	else
	{
		sx(&(ps->stack_a));
		sx(&(ps->stack_b));
	}
}

