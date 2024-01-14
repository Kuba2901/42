/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:49:35 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/12 20:18:55 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (lst == NULL || del == NULL || (*lst) == NULL)
		return ;
	current = *lst;
	while (current->next)
	{
		temp = current;
		current = current->next;
		del(temp->content);
		free(temp);
	}
	del(current->content);
	free(current);
	*lst = NULL;
}
