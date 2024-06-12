/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:29:39 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/11 16:16:21 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_rrx(t_list **stack, int code)
{
	int	last_val;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_val = ps_elem_value(ft_lstlast(*stack));
	ps_pop_last(stack);
	ft_lstadd_front(stack, ps_create_list_element(last_val));
	if (code == RRA)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}