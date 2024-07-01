/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:15:59 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/01 14:08:47 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ps_count_elements_in_stack(t_list **stack)
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
	while (temp != NULL)
	{
		if (ps_elem_value(temp) > max_num)
		{
			max_num = ps_elem_value(temp);
			sub_len++;
		}
		temp = temp->next;
	}
	return (sub_len + 1);
}

void	ps_bring_to_top(t_list **stack, int value)
{
	t_list	*head;

	head = *stack;
	while (ps_elem_value(head) != value)
	{
		ps_rx(stack, RB);
		head = *stack;
	}
}

void	ps_bring_to_bottom(t_list **stack, int value)
{
	t_list	*head;

	head = *stack;
	while (ps_elem_value(head) != value)
	{
		ps_rx(stack, RB);
		head = *stack;
	}
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
	temp = NULL;
}

int		ps_find_elem_index(t_list **stack, t_list *elem)
{
	int		index;
	t_list	*temp;

	temp = *stack;
	index = 0;
	while (temp != NULL)
	{
		if (temp == elem)
			return (index);
		temp = temp->next;
		index++;
	}
	return (index);
}

t_list	*ps_find_smallest_element(t_list **stack)
{
	t_list	*temp;
	t_list	*max_elem;

	temp = *stack;
	max_elem = temp;
	while (temp != NULL)
	{
		if (ps_elem_value(temp) > ps_elem_value(max_elem))
			max_elem = temp;
		temp = temp->next;
	}
	return (max_elem);
}

t_list	*ps_find_biggest_element(t_list **stack)
{
	t_list	*temp;
	t_list	*max_elem;

	temp = *stack;
	max_elem = temp;
	while (temp != NULL)
	{
		if (ps_elem_value(temp) < ps_elem_value(max_elem))
			max_elem = temp;
		temp = temp->next;
	}
	return (max_elem);
}

int		ps_is_smallest(t_list **stack, t_list *elem)
{
	int	min;
	int	curr;

	min = ps_elem_value(ps_find_smallest_element(stack));
	curr = ps_elem_value(elem);
	if (curr < min)
		return (1);
	return (0);
}

int		ps_is_biggest(t_list **stack, t_list *elem)
{
	int	max;
	int	curr;

	max = ps_elem_value(ps_find_biggest_element(stack));
	curr = ps_elem_value(elem);
	if (curr > max)
		return (1);
	return (0);
}

int	ps_get_stack_size(t_list **stack)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = *stack;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

t_tuple	*ps_calculate_common_price(t_list *elem_a, t_list *elem_b, t_list **a, t_list **b)
{
	int	price_up_a;
	int	price_up_b;
	int	price_down_a;
	int	price_down_b;

	price_up_a = ps_find_elem_index(a, elem_a);
	price_down_a = ps_get_stack_size(a) - ps_find_elem_index(a, elem_a);
	price_up_b = ps_find_elem_index(b, elem_b);
	price_down_b = ps_get_stack_size(b) - ps_find_elem_index(b, elem_b);
	// TODO: HANDLE CHEAPEST ONE AFTER ANOTHER
	if (ps_abs(price_down_a - price_down_b) < ps_abs(price_up_a - price_up_b))
		return (ps_tuple_create(elem_a, elem_b, ps_abs(price_down_a - price_down_b), RR));
	return (ps_tuple_create(elem_a, elem_b, ps_abs(price_down_a - price_down_b), RRR));
}

int	ps_get_last_element_value(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (ps_elem_value(temp));
}

t_list	*ps_get_at_index(t_list **stack, int index)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp != NULL)
	{
		if (i == index)
			return (temp);
		temp = temp->next;
		i++;
	}
	return NULL;
}

int	ps_after_push_operations(int num, t_list **stack)
{
	int	i;
	int	up;
	int	stack_num_count;

	stack_num_count = ps_count_elements_in_stack(stack);
	if (!stack_num_count || ps_get_last_element_value(stack) < num)
		return (0);
	if (ps_elem_value(*stack) > num)
		return (1);
	i = stack_num_count;
	up = -1;
	while (--i > 0)
	{
		if (ps_elem_value(ps_get_at_index(stack, i)) < num)
		{
			up = stack_num_count - i - 1;
			break;
		}
	}
	return (up);
}

int	ps_find_cheapest_index(t_list **from_stack, t_list **to_stack, int from_num_count, int to_num_count)
{
	int	i;
	int	mid;
	int	cheapest;
	int	temp_cost;
	int	ret;

	if (from_num_count == 1)
		return (0);
	if (to_num_count <= 1)
		return (from_num_count - 1);
	cheapest = from_num_count + 1;
	i = from_num_count;
	mid = from_num_count / 2 + 1;
	ret = from_num_count - 1;
	while (--i >= mid)
	{
		temp_cost = ps_after_push_operations(ps_elem_value(ps_get_at_index(from_stack, i)), to_stack);
		if (cheapest > temp_cost)
		{
			cheapest = temp_cost;
			ret = i;
		}
	}
	i = -1;
	while (++i < mid)
	{
		temp_cost = ps_after_push_operations(ps_elem_value(ps_get_at_index(from_stack, i)), to_stack);
		if (cheapest > temp_cost)
		{
			cheapest = temp_cost;
			ret = i;
		}
	}
	return (ret);
}

int		ps_find_smaller(t_list **stack, int num)
{
	int	i;

	i = ps_count_elements_in_stack(stack);
	while (--i >= 0)
	{
		if (ps_elem_value(ps_get_at_index(stack, i)) < num)
			break ;
	}
	return (i);
}

void	ps_move_num_to_top(t_list **stack, int index)
{
	int	num;
	int	stack_num_count;

	stack_num_count = ps_count_elements_in_stack(stack);
	if (index == stack_num_count - 1)
		return;
	num = ps_elem_value(ps_get_at_index(stack, index));
	if (index >= stack_num_count / 2)
	{
		while (ps_elem_value(*stack) != num)
			ps_rx(stack, RB);
	}
	else {
		while (ps_elem_value(*stack) != num)
			ps_rrx(stack, RRB);
	}
}