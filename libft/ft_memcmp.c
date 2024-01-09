/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:44:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 17:40:59 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*s1_ptr;
	const char		*s2_ptr;
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (s1_ptr[i] && s2_ptr[i] && i < n)
	{
		c1 = (unsigned char)s1_ptr[i];
		c2 = (unsigned char)s2_ptr[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (c1 - c2);
}
