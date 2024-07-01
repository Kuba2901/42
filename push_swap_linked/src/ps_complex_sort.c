/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:09:35 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/01 14:14:02 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_count_subsequence(t_list **stack)
{
	t_list	*temp;
	int		count;
	int		max;

	count = 0;
	temp = *stack;
	max = ps_elem_value(temp);
	while (temp != NULL)
	{
		if (max < ps_elem_value(temp))
		{
			max = ps_elem_value(temp);
			count++;
		}
		temp = temp->next;
	}
	return (count);
}

int	ps_stack_len(t_list **stack)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = *stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	ps_push_out_of_order(t_list	**a, t_list **b)
{
	int	pushed;
	int	subsequence_len;

	pushed = 0;
	subsequence_len = ps_count_subsequence(a);
	while (ps_stack_len(a) != subsequence_len && ps_stack_len(a) >= 5)
	{

	}
}