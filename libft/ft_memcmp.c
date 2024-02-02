/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:44:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/02/02 14:40:12 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	ptr_1 = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ptr_1 != *ptr_2)
			return (*ptr_1 - *ptr_2);
		ptr_1++;
		ptr_2++;
	}
	return (0);
}
