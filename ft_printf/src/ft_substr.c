/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:26:31 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/11 15:29:26 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	len_substr;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	len_substr = ft_strlen(s) - start;
	if (len > (unsigned int)len_substr)
		len = len_substr;
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	printf("res: %s\n", ft_substr(str, 0, 0));
// 	return (0);
// }
