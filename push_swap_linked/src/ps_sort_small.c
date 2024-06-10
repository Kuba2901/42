/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:21 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 16:20:14 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL)
		return (1);
	tmp = *list;
	while (tmp->next)
	{
		if (ps_elem_value(tmp) > ps_elem_value(tmp->next))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_reverse_sorted(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (ps_elem_value(tmp) < ps_elem_value(tmp->next))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ps_elem_value(t_list *list)
{
	return (*(int*)list->content);
}

static int	ps_find_min_index(t_list *elem)
{
	int		min;
	int		index;
	int		i;

	min = ps_elem_value(elem);
	index = 0;
	i = 0;
	while (elem)
	{
		if (ps_elem_value(elem) < min)
		{
			min = ps_elem_value(elem);
			index = i;
		}
		elem = elem->next;
		i++;
	}
	return (index);
}

static int	ps_find_max_index(t_list *elem)
{
	int		max;
	int		index;
	int		i;

	max = ps_elem_value(elem);
	index = 0;
	i = 0;
	while (elem)
	{
		if (ps_elem_value(elem) > max)
		{
			max = ps_elem_value(elem);
			index = i;
		}
		elem = elem->next;
		i++;
	}
	return (index);
}

void	ps_sort_three(t_list **list)
{
	int	min_index;
	int	max_index;
	
	if (is_sorted(list))
		return ;
	if (is_reverse_sorted(list))
	{
		ps_sx(list);
		ps_rrx(list);
		return;
	}
	// Cases
	min_index = ps_find_min_index(*list);
	
	// top
	if (min_index == 0)
	{
		ps_sx(list);
		ps_rx(list);
		return;
	}
	else if (min_index == 2)
		ps_rrx(list);
	else {
		max_index = ps_find_max_index(*list);
		if (max_index == 0)
			ps_rx(list);
		else
			ps_sx(list);
	}
}