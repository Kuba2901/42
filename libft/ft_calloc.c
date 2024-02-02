/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:19:14 by jnenczak          #+#    #+#             */
/*   Updated: 2024/02/02 14:52:19 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (count + size < count || count + size < size || total > 2147483424)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (total--)
		((char *)ptr)[total] = 0;
	return (ptr);
}
