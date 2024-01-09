/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:19:14 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 13:25:27 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*char_ptr;

	i = 0;
	char_ptr = b;
	while(len--)
	{
		*char_ptr = c;
		char_ptr++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;
   	void	*ret;

	alloc = (void *)malloc(count * size);
	ret = ft_memset(alloc, 0, count);
	return (ret);
}
