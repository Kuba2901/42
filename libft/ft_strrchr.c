/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:46:33 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 14:48:35 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	end;
	char	converted;

	end = ft_strlen(s);
	converted = (char)c;
	while (--end >= 0)
	{
		if (s[end] == converted)
			return (&(s[end]));
	}
	return (NULL);
}
