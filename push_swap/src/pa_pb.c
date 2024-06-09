/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:22:08 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/09 13:33:51 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	remove_top(t_stack *stack)
{
	int	i;
	int	*updated_nums;

	if (!stack->nums_count)
		return ;
	updated_nums = malloc(sizeof(int) * (stack->nums_count - 1));
	i = -1;
	while (++i < stack->nums_count - 1)
		updated_nums[i] = stack->nums[i];
	if (stack->nums != NULL)
		free(stack->nums);
	stack->nums = updated_nums;
	stack->nums_count -= 1;
}

void	push_top(t_stack *stack, int num)
{
	int	i;
	int	*updated_nums;
	
	updated_nums = malloc(sizeof(int) * (stack->nums_count + 1));
	i = -1;
	while (++i < stack->nums_count)
		updated_nums[i] = stack->nums[i];
	updated_nums[i] = num;
	if (stack->nums != NULL)
		free(stack->nums);
	stack->nums = updated_nums;
	stack->nums_count += 1;
}

void	pa_pb(t_push_swap *ps, int operation_code)
{
	if (operation_code == PA)
	{
		if (!ps->stack_b.nums_count)
			return;
		push_top(&(ps->stack_a), TOP(ps->stack_b));
		remove_top(&(ps->stack_b));
		calc_push_rotate(&(ps->stack_a));
	}
	if (operation_code == PB)
	{
		if (!ps->stack_a.nums_count)
			return;
		push_top(&(ps->stack_b), TOP(ps->stack_a));
		remove_top(&(ps->stack_a));
		printf("Pushed to stack B\n");
		print_stacks(*ps);
		calc_push_rotate(&(ps->stack_b));
	}
}