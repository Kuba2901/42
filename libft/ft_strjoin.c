/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:51:25 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/09 23:51:30 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;
	size_t	str_iter;
	size_t	curr;

	if (!s1 || !s2)
		return (NULL);
	size = (size_t)ft_strlen((char *)s1) + (size_t)ft_strlen((char *)s2);
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	str_iter = 0;
	curr = 0;
	while (s1[str_iter])
		ret[curr++] = s1[str_iter++];
	str_iter = 0;
	while (s2[str_iter])
		ret[curr++] = s2[str_iter++];
	return (ret);
}