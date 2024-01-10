/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:25:34 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/10 17:37:06 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*alloc;

	i = -1;
	alloc = (char *)malloc(ft_strlen((char *)s1 + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (s1[++i])
		alloc[i] = s1[i];
	alloc[i] = '\0';
	return (alloc);
}
