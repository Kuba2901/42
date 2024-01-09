/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:25:34 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 17:46:12 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*alloc;

	alloc = (char *)malloc(ft_strlen(s1) * sizeof(char));
	while (s1[i])
	{
		alloc[i] = s1[i];
		i++;
	}
	return (alloc);
}
