/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:29:55 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/02/02 17:13:35 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	i = 1;
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
