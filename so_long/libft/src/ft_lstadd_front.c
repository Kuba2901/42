/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:28:00 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/03/09 19:37:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_front(t_list **lst, t_list *new_elem)
{
	if (lst == NULL || new_elem == NULL)
		return ;
	new_elem->next = *lst;
	*lst = new_elem;
}
