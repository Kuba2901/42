/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:45:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/27 18:15:39 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_tuple	*ps_tuple_create(t_list *elem_a, t_list *elem_b, int price, int code)
{
	t_tuple	*ret;

	ret = malloc(sizeof(t_tuple));
	ret->elem_a = elem_a;
	ret->elem_b = elem_b;
	ret->price = price;
	ret->code = code;
	return (ret);
}

void	ps_tuple_free(t_tuple *tuple)
{
	free(tuple);
}