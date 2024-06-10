/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:18:13 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 15:25:00 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ps_pop_head(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp->content);
	free(tmp);
}

void	ps_rx(t_list **stack)
{
	int	head_val;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head_val = *((int *)(*stack)->content);
	ps_pop_head(stack);
	ft_lstadd_back(stack, ps_create_list_element(head_val));
}