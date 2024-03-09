/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:32:40 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/09 19:37:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;

	if (dst == NULL || src == NULL)
		return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (n--)
	{
		*dst_ptr = *src_ptr;
		dst_ptr++;
		src_ptr++;
	}
	return (dst);
}
