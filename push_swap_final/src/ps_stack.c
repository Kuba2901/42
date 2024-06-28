/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:48:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/28 14:56:15 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ps_stack_init()
{
	t_stack* stack;
	
	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	return stack;
}

t_stack_element	*ps_stack_create_element(int value)
{
	t_stack_element*	new_node;
	
	new_node = malloc(sizeof(t_stack_element));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void	ps_stack_push_front(t_stack *stack, int value)
{
	t_stack_element* new_node;
	
	new_node = create_node(value);
	if (stack->head == NULL) {
		stack->head = new_node;
		stack->tail = new_node;
	} else {
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
}

void	ps_stack_append(t_stack *stack, int value)
{
	t_stack_element* new_node;
	
	new_node = create_node(value);
	if (stack->tail == NULL) {
        stack->head = new_node;
        stack->tail = new_node;
    } else {
        stack->tail->next = new_node;
        new_node->prev = stack->tail;
        stack->tail = new_node;
    }
}

void	ps_stack_pop_head(t_stack *stack)
{
    t_stack_element*	temp;
	int					value;
	
	if (stack->head == NULL) {
		return;
    }
	temp = stack->head;
    value = temp->value;
    stack->head = stack->head->next;
    if (stack->head == NULL) {
        stack->tail = NULL;
    } else {
        stack->head->prev = NULL;
    }
    free(temp);
}

int	ps_stack_at_index(t_stack* stack, int index)
{
    t_stack_element* temp;
	int				count;
	
	temp = stack->head;
    count = 0;
    while (temp != NULL) {
        if (count == index) {
            return temp->value;
        }
        count++;
        temp = temp->next;
    }
    printf("Index out of bounds\n");
    return -1;
}

void print_stack(t_stack* stack)
{
    t_stack_element* current;
	
	current = stack->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void	ps_stack_free(t_stack *stack)
{
    t_stack_element* current;
    t_stack_element* next_node;
	
	current = stack->head;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(stack);
}

int ps_stack_pop_last(t_stack *stack) {
    t_stack_element* temp;
	int				data;
	
    if (stack->tail == NULL)
		return;
	temp = stack->tail;
    data = temp->value;
    stack->tail = stack->tail->prev;
    if (stack->tail == NULL) {
        stack->head = NULL;
    } else {
        stack->tail->next = NULL;
    }
    free(temp);
    return data;
}
