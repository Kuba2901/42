/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:26:31 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 15:53:32 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (s == NULL || ret == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		ret[i++] = s[start];
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
// What about null termination?

#include <stdio.h>

int	main(void)
{
	const char *str = "Hello world!";
	printf("orig: %s\n", str);
	printf("substr: %s\n", ft_substr(str, 2, 6));
	return (0);
}