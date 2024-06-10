/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:21 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 15:23:22 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (*((int *)tmp->content) > *((int *)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// static int	ps_next_elem_value(t_list *list)
// {
// 	return (*(int*)list->next->content);
// }