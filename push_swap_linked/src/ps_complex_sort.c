/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:15:59 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/27 14:20:47 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int ps_count_elements_in_stack(t_list **stack)
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

/// Counts all the elements belonging to the longest increasing subsequence
int		ps_count_longest_increasing_subsequence(t_list **stack_a)
{
	t_list	*temp;
	int		max_num;
	int		sub_len;

	temp = *stack_a;
	max_num = ps_elem_value(temp);
	sub_len = 0;
	printf("Largest at the beginning: %d\n", max_num);
	while (temp != NULL)
	{
		if (ps_elem_value(temp) > max_num)
		{
			max_num = ps_elem_value(temp);
			printf("New largest: %d\n", max_num);
			sub_len++;
		}
		temp = temp->next;
	}
	return (sub_len);
}

/// Push elements the are not in the longest increasing subsequence
void	ps_push_out_of_order(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		max_num;
	int		found_nums;
	int		sub_len;
	int		stack_len;

	temp = *stack_a;
	found_nums = 0;
	sub_len = ps_count_longest_increasing_subsequence(stack_a);
	printf("Sub len: %d\n", sub_len);
	max_num = ps_elem_value(temp);
	stack_len = ps_count_elements_in_stack(stack_a);
	while (found_nums < stack_len - sub_len)
	{
		if (max_num > ps_elem_value(temp))
		{
			ps_px(stack_a, stack_b, RA);
			found_nums++;
		}
		else
		{
			max_num = ps_elem_value(temp);
			ps_rx(stack_a, RA);
		}
		temp = *stack_a;
	}
}