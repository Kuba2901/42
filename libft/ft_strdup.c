/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:25:34 by jnenczak          #+#    #+#             */
/*   Updated: 2024/02/02 14:58:07 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*alloc;

	i = 0;
	alloc = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (*s1)
		alloc[i++] = *s1++;
	alloc[i] = '\0';
	return (alloc);
}
