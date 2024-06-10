/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:29:39 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 15:37:52 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_rrx(t_list **stack)
{
	int	last_val;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_val = *(int *)(ft_lstlast(*stack)->content);
	ps_pop_last(stack);
	ft_lstadd_front(stack, ps_create_list_element(last_val));
}