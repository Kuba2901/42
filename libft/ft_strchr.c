/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:49:36 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/10 14:49:46 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	converted;

	converted = (char)c;
	while (*s)
	{
		if ((*s) == converted)
			return (s);
		s++;
	}
	if ((*s) == '\0')
		return (s);
	return (NULL);
}
