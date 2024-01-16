/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:19:14 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/14 17:33:30 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;
	void	*ret;

	alloc = (void *)malloc(count * size);
	if (alloc == NULL)
		return (NULL);
	ret = ft_memset(alloc, 0, count);
	return (ret);
}
