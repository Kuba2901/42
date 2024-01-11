/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:54:38 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/11 16:09:03 by jnenczak         ###   ########.fr       */
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

static int	get_begin(char const *s1, char const *set)
{
	int	ret;

	ret = 0;
	while (s1[ret] && ft_is_trim(s1[ret], set))
		ret++;
	return (ret);
}

static int	get_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_is_trim(s1[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;

	beg = get_begin(s1, set);
	end = get_end(s1, set);
	if (beg > end)
		return (ft_strdup(""));
	return (ft_substr(s1, beg, end - beg + 1));
}
