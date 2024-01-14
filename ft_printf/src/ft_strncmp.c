/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:58:51 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 18:45:52 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*s1_ptr && *s2_ptr && *s1_ptr == *s2_ptr && n-- > 0)
	{
		s1_ptr++;
		s2_ptr++;
	}
	if (n > 0)
		return (*s1_ptr - *s2_ptr);
	return (0);
}
