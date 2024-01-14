/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:49:36 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/10 18:13:16 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	converted;

	converted = (char)c;
	while (*s)
	{
		if ((*s) == converted)
			return ((char *)s);
		s++;
	}
	if ((*s) == converted)
		return ((char *)s);
	return (NULL);
}
