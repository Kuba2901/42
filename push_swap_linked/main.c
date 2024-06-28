/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:39:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/28 15:50:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_value(void *content)
{
	ft_printf("%d\n", *((int *)content));
}

void	print_stacks(t_list **a, t_list **b)
{
	ft_printf("Stack A:\n");
	if (a != NULL && *a != NULL)
		ft_lstiter(*a, print_value);
	else
		ft_printf("Null\n");
		
	ft_printf("Stack B:\n");
	if (b != NULL && *b != NULL)
		ft_lstiter(*b, print_value);
	else
		ft_printf("Null\n");
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (parse_errors(ac, av))
	{
		ft_printf("Error\n");
		exit(1);
	}
	stack_a = parse_input(ac, av);
	stack_b = malloc(sizeof(t_list *));
	if (!is_sorted(stack_a))
	{
		// 0. If <= 5 elements -> do simple sort
		if (ps_count_elements_in_stack(stack_a) > 5)
		{
			// 1. Push out of order until there are (<= 5 elements)
			ps_push_out_of_order(stack_a, stack_b);

			// 2. Do simple sort on stack_a
			ps_sort_small(stack_a, stack_b);

			// 3. Push back elements, finding the cheapest, into the correct spots
			while (ps_count_elements_in_stack(stack_b))
			{
				int ci = ps_find_cheapest_index(stack_b, stack_a, 
					ps_count_elements_in_stack(stack_b), ps_count_elements_in_stack(stack_a));
				int smaller_index = ps_find_smaller(stack_a, ps_elem_value(ps_get_at_index(stack_b, ci)));
				ps_move_num_to_top(stack_b, ci); 
				if (smaller_index != -1)
					ps_move_num_to_top(stack_a, smaller_index);
				ps_px(stack_b, stack_a, PA);
			}
		}
		else
			ps_sort_small(stack_a, stack_b);
	}
	// print_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}