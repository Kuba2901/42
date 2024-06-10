/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:39:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/10 15:27:12 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_value(void *content)
{
	ft_printf("%d\n", *((int *)content));
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
	if (parse_errors(ac, av))
	{
		ft_printf("Error\n");
		exit(1);
	}
	stack_a = parse_input(ac, av);
	ft_printf("Stack A:\n");
	ft_lstiter(*stack_a, print_value);
	printf("Is sorted: %d\n", is_sorted(stack_a));
	ps_rx(stack_a);
	ft_printf("Stack A:\n");
	ft_lstiter(*stack_a, print_value);
	ps_rx(stack_a);
	ft_printf("Stack A:\n");
	ft_lstiter(*stack_a, print_value);
	free_stacks(stack_a, NULL);
	return (0);
}