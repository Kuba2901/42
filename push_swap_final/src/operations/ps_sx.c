/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:13:33 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/11 16:16:45 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sx(t_list **stack, int code)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (code == SA)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}