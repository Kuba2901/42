/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:32:40 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 13:32:57 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	while (n--)
		*(dst_ptr++) = *(src_ptr++);
	return (dst);
}
