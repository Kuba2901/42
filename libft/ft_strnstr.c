/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:55:03 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 23:03:08 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_str(char *needle, char *word, int word_index)
{
	int		same;
	size_t	i;
	size_t	j;

	same = 1;
	i = word_index;
	j = 0;
	while (j < ft_strlen(needle))
	{
		if (needle[j] != word[i] || word[i] == '\0')
			return (0);
		i++;
		j++;
	}
	return (1);
}

static char	needle_empty(char *to_find)
{
	int	needle_len;

	needle_len = ft_strlen(to_find);
	if (needle_len > 0)
		return (to_find[0]);
	else
		return (0);
}

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;
	char	c;
	char	first_to_find;
	int		found;

	i = 0;
	found = 0;
	first_to_find = needle_empty(to_find);
	if (first_to_find == 0)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		c = str[i];
		if (c == first_to_find)
		{
			found = compare_str(to_find, str, i);
			if (found)
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

