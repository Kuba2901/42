/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:30:21 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/06 12:35:25 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_top(t_stack *stack, int num)
{
	t_stack_element	*new_top;

	new_top = malloc(sizeof(t_stack_element));
	if (!new_top)
		exit(1);
	new_top->value = num;
	new_top->next = stack->top;
	stack->top = new_top;
	stack->bottom->next = new_top;
}

void	remove_top(t_stack *stack)
{
	t_stack_element	*top;

	top = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = stack->top;
	free(top);
}

// void 	rx(t_stack *stack)
// {
// 	t_stack_element	*temp;
	
// 	temp = stack->top;
// 	while (temp != )
// }

void	ra_rb_rr(t_stack *stack, int operation_code)
{
	if (operation_code == RA)
	{
		push_top(&ps->stack_a, ps->stack_a.top->value);
		remove_top(&ps->stack_a);
	}
	else if (operation_code == RB)
	{
		push_top(&ps->stack_b, ps->stack_b.top->value);
		remove_top(&ps->stack_b);
	}
	else if (operation_code == RR)
	{
		ra_rb_rr(ps, RA);
		ra_rb_rr(ps, RB);
	}
}