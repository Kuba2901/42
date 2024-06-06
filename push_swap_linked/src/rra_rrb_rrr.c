/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:28:41 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/06 11:54:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rrx(t_stack *stack)
{
	int	first;
	int	i;
	
	if (!stack->nums_count)
		return ;
	first = stack->nums[0];
	i = -1;
	while (++i < stack->nums_count - 1)
		stack->nums[i] = stack->nums[i + 1];
	stack->nums[i] = first;
}

void	rra_rrb_rrr(t_push_swap *ps, int operation_code)
{
	if (operation_code == RRA)
		rrx(&(ps->stack_a));
	else if (operation_code == RRB)
		rrx(&(ps->stack_b));
	else if (operation_code == RRR) 
	{
		rrx(&(ps->stack_a));
		rrx(&(ps->stack_b));
	}
}
