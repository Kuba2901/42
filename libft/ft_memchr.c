/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:54 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/10 14:51:09 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	occ;
	char			curr;
	char			*str;

	occ = (unsigned char)c;
	str = (char *)s;
	while (*str)
	{
		curr = *str;
		if (curr == occ)
			return (str);
		str++;
	}
	return (NULL);
}
