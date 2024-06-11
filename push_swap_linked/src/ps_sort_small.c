/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:21 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/11 15:58:47 by jnenczak         ###   ########.fr       */
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

static void	ps_sort_three(t_list **list)
{
	int	min_index;
	int	max_index;
	
	if (is_sorted(list) || ft_lstsize(*list) == 1)
		return ;
	if (ft_lstsize(*list) == 2)
	{
		ps_rx(list);
		return;
	}
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

static void	ps_sort_four(t_list **a, t_list **b)
{
	int	min_index;

	if (is_sorted(a))
		return;
	min_index = ps_find_min_index(*a);
	if (min_index == 1)
		ps_rx(a);
	else if (min_index == 2)
	{
		while (min_index-- > 0)
			ps_rx(a);
	}
	else
		ps_rrx(a);
	if (is_sorted(a))
		return;
	ps_px(a, b);
	ps_sort_three(a);
	ps_px(b, a);
}

static void	ps_sort_five(t_list **a, t_list **b)
{
	int	min_index;

	min_index = ps_find_min_index(*a);
	if (min_index == 1)
		ps_rx(a);
	else if (min_index == 2)
	{
		while (min_index-- > 0)
			ps_rx(a);
	}
	else if (min_index == 3)
	{
		while (--min_index > 0)
			ps_rx(a);
	}
	else
		ps_rrx(a);
	if (is_sorted(a))
		return ;
	ps_px(a, b);
	ps_sort_four(a, b);
	ps_px(b, a);
}

void	ps_sort_small(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (is_sorted(a) || size_a <= 1)
		return ;
	if (size_a == 2)
		ps_sx(a);
	else if (size_a == 3)
		ps_sort_three(a);
	else if (size_a == 4)
		ps_sort_four(a, b);
	else
		ps_sort_five(a, b);
}