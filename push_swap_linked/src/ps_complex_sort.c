/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:09:35 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/01 16:38:13 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*ps_elem_at_index(t_list **stack, int index)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	while (temp != NULL)
	{
		if (i == index)
			break;
		i++;
		temp = temp->next;
	}
	return (temp);
}

int	ps_elem_at_index_value(t_list **stack, int index)
{
	return ps_elem_value(ps_elem_at_index(stack, index));
}

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
	int		pushed;
	int		subsequence_len;
	int		max;
	t_list	*temp;

	temp = *a;
	pushed = 0;
	subsequence_len = ps_count_subsequence(a);
	max = ps_elem_value(temp);
	printf("Pushing out of order!\n");
	while (pushed != subsequence_len && ps_stack_len(a) >= 5)
	{
		if (max > ps_elem_value(temp)) {
			ps_px(a, b, PB);
			pushed++;
		}
		else
			ps_rx(a, RA);
		temp = *a;
	}
}

t_list	**ps_copy_stack(t_list **stack)
{
	t_list	*temp;
	t_list	**ret;

	ret = malloc(sizeof(t_list *) * ps_stack_len(stack));
	*ret = NULL;
	temp = *stack;
	while (temp != NULL)
	{
		ft_lstadd_back(ret, ps_create_list_element(ps_elem_value(temp)));
		temp = temp->next;
	}
	return (ret);
}

