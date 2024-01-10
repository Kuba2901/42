/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:46:33 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 18:27:17 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	end;

	end = 0;
	while (s[end])
		end++;
	while (end >= 0)
	{
		if (s[end] == (char)c)
			return ((char *)&s[end]);
		end--;
	}
	return (NULL);
}
