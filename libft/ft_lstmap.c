/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:56:29 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/12 20:19:38 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);

	new_list = ft_lstnew(lst->content);
	lst = lst->next;
	while (lst)
	{
		temp = lst;
		ft_lstadd_back(&new_list, ft_lstnew(lst->content));
		ft_lstdelone(temp, del);
		lst = lst->next;
	}
	return (new_list);
}