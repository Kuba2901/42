/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:55:03 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/14 17:33:30 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_str(const char *needle, const char *word, int word_index)
{
	size_t	i;
	size_t	j;

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

static char	needle_empty(const char *to_find)
{
	size_t	needle_len;

	needle_len = ft_strlen(to_find);
	if (needle_len > 0)
		return (to_find[0]);
	else
		return (0);
}

const char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	char	c;
	char	first_to_find;
	int		found;

	i = 0;
	found = 0;
	first_to_find = needle_empty(to_find);
	if (!len)
		return (NULL);
	if (first_to_find == 0)
		return (str);
	while (str[i] != '\0' && i < len - ft_strlen(to_find) - 1)
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
