/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:30:36 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/11 16:21:53 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char *str, char sep)
{
	return (*str == sep);
}

static int	count_words(char *str, char sep)
{
	int		wc;
	int		jumped;
	int		i;
	char	*con;

	wc = 0;
	i = 0;
	con = str;
	while (*str)
	{
		jumped = 0;
		while (is_sep(str, sep))
		{
			jumped++;
			str++;
			if (!(*str))
				return (wc);
		}
		if (!(con - str) || jumped)
			wc++;
		str++;
	}
	return (wc);
}

static char	*create_word(char *str, char sep)
{
	char	*created;
	int		i;
	int		word_len;

	word_len = 0;
	while (*(str + word_len) && !is_sep(str + word_len, sep))
		word_len++;
	i = -1;
	created = (char *)malloc(word_len + 1);
	while (++i < word_len)
	{
		created[i] = *str;
		str++;
	}
	created[i] = '\0';
	return (created);
}

static int	handle_errors(char *str, char sep, char ***split,
		int *string_index)
{
	int	str_len;

	if (str == NULL)
	{
		*split = (char **)malloc(1 * 8);
		(*split)[0] = 0;
		return (0);
	}
	str_len = -1;
	while (str[++str_len])
		;
	*split = (char **)malloc(
			(count_words(str, sep) + 1) * sizeof(char *));
	*string_index = 0;
	(*split)[count_words(str, sep)] = 0;
	return (2);
}

char	**ft_split(char const *s1, char c)
{
	char	**split;
	int		string_index;

	if (handle_errors((char *)s1, c, &split, &string_index) != 2)
		return (split);
	while (*s1)
	{
		while (*s1 && is_sep((char *)s1, c))
			s1++;
		if (*s1)
			split[string_index++] = create_word((char *)s1, c);
		while (*s1 && !is_sep((char *)s1, c))
			s1++;
	}
	split[string_index] = 0;
	return (split);
}
