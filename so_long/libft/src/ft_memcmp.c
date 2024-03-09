/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:44:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/09 19:37:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	i = 0;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1_ptr[i] && s2_ptr[i] && i < n - 1)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (s1_ptr[i] - s2_ptr[i]);
}
