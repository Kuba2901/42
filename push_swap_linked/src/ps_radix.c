/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:53 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 17:32:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_abs(int num)
{
	if (num < 0)
		return -num;
	return num;
}

void	ps_radix_sort(t_list **stack, t_list **other_stack)
{
	t_list	*temp;
	int		max_num;
	int		max_bits;
	int		size;

	temp = *stack;
	max_num = ps_abs(ps_elem_value(temp));
	while (temp)
	{
		if (abs(ps_elem_value(temp)) > max_num)
			max_num = ps_abs(ps_elem_value(temp));
		temp = temp->next;
	}

    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Since integers can be negative, we need an additional bit for the sign
    max_bits++;

    for (int i = 0; i < max_bits; i++) {
        size = ft_lstsize(*stack);
        while (size--) {
            int value = ps_elem_value(*stack);
            // If we are checking the sign bit
            if (i == max_bits - 1) {
                if (value < 0)
                    ps_rx(stack);
                else
                    ps_px(stack, other_stack);
            } else {
                if (((value >> i) & 1) == 1)
                    ps_rx(stack);
                else
                    ps_px(stack, other_stack);
            }
        }
        while (ft_lstsize(*other_stack) > 0)
            ps_px(other_stack, stack);
    }

	// Check if negative numbers did not break the order and rotate
	while (!is_sorted(stack))
		ps_rrx(stack);
}
