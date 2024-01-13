/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:42:23 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/12 20:18:41 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*temp;

	if (lst == NULL || new_elem == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_elem;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem;
}
