/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:54:38 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 00:26:15 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static const char	*get_begin(char const *s1, char const *set)
{
	while (*s1 && ft_is_trim(*s1, set))
		s1++;
	return (s1);
}

static const char	*get_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen((char *)s1) - 1;
	while (s1[end] && ft_is_trim(s1[end], set))
		end--;
	return (&(s1[end]));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	int			size;
	const char	*beg;
	const char	*end;
	int			i;

	beg = get_begin(s1, set);
	end = get_end(s1, set) + 1;
	size = end - beg + 1;
	ret = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (beg - end)
	{
		ret[i] = *beg;
		i++;
		beg++;
	}
	return (ret);
}