/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:50:18 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 12:54:46 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (i < dstsize)
	{
		if (src[i])
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			break ;
		}
		i++;
	}
	return (i);
}
