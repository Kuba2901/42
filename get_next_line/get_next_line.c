
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:37 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/20 18:26:47 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}


char	*get_next_line(int fd)
{
	char	*ret;
	size_t	rbytes;
	int		index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ret)
		return (NULL);
	rbytes = read(fd, ret, BUFFER_SIZE);
	index = 0;
	if (rbytes <= 0)
	{
		free(ret);
		return (NULL);
	}
	while (ret[index])
	{
		if (ret[index] == '\n')
		{
			
		}
	}
}

#include <string.h>

int	main(void)
{
	int fd = open("files/41_with_nl", O_RDONLY);
	char *ret;

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	close(fd);

	return (0);
}