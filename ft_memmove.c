/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:44:59 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 12:48:34 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	int		i;

	i = 0;
	dst_ptr = dst;
	while (i < len)
	{
		dst_ptr[i] = src[i];
		i++;
	}
	return (dst);
}
