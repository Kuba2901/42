/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:40:27 by jnenczak          #+#    #+#             */
/*   Updated: 2024/02/03 15:40:32 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;
	size_t	curr;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	curr = 0;
	while (*s1)
		ret[curr++] = *s1++;
	ft_strlcpy(ret + curr, s2, size - ft_strlen(s1));
	return (ret);
}
