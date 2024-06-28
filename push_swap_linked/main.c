/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:39:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/28 15:06:50 by jnenczak         ###   ########.fr       */
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
		// 1. Push out of order until there are (<= 5 elements)
		ps_push_out_of_order(stack_a, stack_b);
		printf("Pushed out of order!\n");
		print_stacks(stack_a, stack_b);

		// 2. Do simple sort on stack_a
		ps_sort_small(stack_a, stack_b);
		printf("Done simple sort on A!\n");
		print_stacks(stack_a, stack_b);

		// 3. Push back elements, finding the cheapest, into the correct spots
	}
	else
	{
		ft_printf("ALREADY SORTED!\n");
	}
	print_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}