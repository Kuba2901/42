
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

char	*ft_reassign(char *buff, char *new)
{
	char	*ret;

	ret = ft_strjoin(buff, new);
	free(buff);
	free(new);
	return (ret);
}

char	*ft_read_buffer(int fd)
{
	char	*ret;
	char	*temp;
	size_t	rbytes;

	ret = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!ret)
		return (NULL);
	rbytes = read(fd, ret, BUFFER_SIZE);
	ret[rbytes] = '\0';
	while (rbytes > 0)
	{
		temp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		rbytes = read(fd, temp, BUFFER_SIZE);
		if (!rbytes)
		{
			free(temp);
			break ;
		}
		ret = ft_reassign(ret, temp);
	}
	printf("ret: %s\n", ret);
	return (ret);
}

char	*ft_get_line(const char *str)
{
	unsigned int	i;

	i = -1;
	if (str == NULL || *str == '\0')
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
	}
	char *ret = ft_substr(str, 0, i);
	return (ret);
}

char	*get_next_line(int fd)
{
	static const char	*mark = NULL;
	char				*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!mark)
		mark = ft_read_buffer(fd);
	ret = ft_get_line(mark);
	if (ret != NULL)
		mark += ft_strlen(ret);
	return (ret);
}

// #include <string.h>

// int	main(void)
// {
// 	int fd = open("files/41_with_nl_copy", O_RDONLY);
// 	char *ret;

// 	while ((ret = get_next_line(fd)) != NULL)
// 	{
// 		printf("line: %s\n", ret);
// 		free(ret);
// 	}
// 	close(fd);
// 	return (0);
// }