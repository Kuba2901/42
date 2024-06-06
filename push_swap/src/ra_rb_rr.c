/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:29:21 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/06 12:05:06 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rx(t_stack *stack)
{
	int	i;
	
	if (stack->nums_count <= 1) {
        return;
    }
    
    int lastElement = stack->nums[stack->nums_count - 1];
    
	i = stack->nums_count;
	while (--i > 0) 
        stack->nums[i] = stack->nums[i - 1];
    stack->nums[0] = lastElement;
}

void	ra_rb_rr(t_push_swap *ps, int operation_code)
{
	if (operation_code == RA)
		rx(&(ps->stack_a));
	else if (operation_code == RB)
		rx(&(ps->stack_b));
	else if (operation_code == RR)
	{
		rx(&(ps->stack_a));
		rx(&(ps->stack_b));
	}
}