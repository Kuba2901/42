/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:46:33 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/09 22:58:07 by jakubnencza      ###   ########.fr       */
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