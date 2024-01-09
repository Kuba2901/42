/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:26:31 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/09 23:40:22 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret  = (char *)malloc(sizeof(char) * len);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		ret[i++] = s[start];
		start++;
	}
	return (ret);
}
// What about null termination?
