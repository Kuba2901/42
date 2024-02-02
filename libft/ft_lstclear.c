/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:49:35 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/02/02 17:13:19 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
