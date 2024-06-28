/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:18:13 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/28 14:56:34 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_pop_last(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next->content);
	free(tmp->next);
	tmp->next = NULL;
}

void	ps_pop_head(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp->content);
	free(tmp);
}

void	ps_rx(t_list **stack, int code)
{
	int		head_val;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head_val = *((int *)(*stack)->content);
	ps_pop_head(stack);
	ft_lstadd_back(stack, ps_create_list_element(head_val));
	if (code == RA)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}