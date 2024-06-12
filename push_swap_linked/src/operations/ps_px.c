/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:38:40 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/11 16:16:03 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_px(t_list **from, t_list **to, int code)
{
	int	value;

	if (from == NULL || *from == NULL)
		return ;
	value = ps_elem_value(*from);
	ps_pop_head(from);
	ft_lstadd_front(to, ps_create_list_element(value));
	if (code == PA)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");

}