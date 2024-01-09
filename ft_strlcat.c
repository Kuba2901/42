/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:26 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 13:12:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	int	dst_end;
	int	i;
	int	max;

	i = ft_strlen(src);
	src_i = 0;
	max = i - dst_end;
	while (i < max)
	{
		dst[i] = src[src_i];
		i++;
		src_i++;
	}
	dst[i] = '\0';
	return (i);
}
