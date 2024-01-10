/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:30:36 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 14:50:35 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char *str, char *charset)
{
	while (*charset)
	{
		if (*str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
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
		while (is_sep(str, charset))
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

static char	*create_word(char *str, char *charset)
{
	char	*created;
	int		i;
	int		word_len;

	word_len = 0;
	while (*(str + word_len) && !is_sep(str + word_len, charset))
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

static int	handle_errors(char *str, char *charset, char ***split,
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
	if (charset == NULL)
	{
		*split = (char **)malloc(2 * 8);
		(*split)[0] = (char *)malloc(str_len + 1);
		(*split)[0] = create_word(str, "");
		(*split)[1] = 0;
		return (1);
	}
	*split = (char **)malloc(
			(count_words(str, charset) + 1) * sizeof(char *));
	*string_index = 0;
	(*split)[count_words(str, charset)] = 0;
	return (2);
}

char	**ft_split(char const *s1, char const *set)
{
	char	**split;
	int		string_index;

	if (handle_errors(s1, set, &split, &string_index) != 2)
		return (split);
	while (*(s1))
	{
		while (*s1 && is_sep(s1, set))
			s1++;
		if (*s1)
			split[string_index++] = create_word(s1, set);
		while (*s1 && !is_sep(s1, set))
			s1++;
	}
	split[string_index] = 0;
	return (split);
}
