
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

char	*ft_get_line(char *buff)
{
	int		i;
	char	*ret;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
	}
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (--i >= 0)
		ret[i] = buff[i];
	return (ret);
}

char	*ft_reassign(char *buff, char *new)
{
	char	*ret;

	ret = ft_strjoin(buff, new);
	free(buff);
	free(new);
	return (ret);
}

char	*ft_read_line(int fd)
{
	char			*line;
	char			*temp;
	unsigned int	rbytes;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	rbytes = read(fd, line, BUFFER_SIZE);
	if (rbytes <= 0)
	{
		free(line);
		return (NULL);
	}
	line[rbytes] = '\0';
	while (!ft_strchr(line, '\n') && rbytes > 0)
	{
		temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			break ;
		rbytes = read(fd, temp, BUFFER_SIZE);
		if (!rbytes)
		{
			free(temp);
			break ; 
		}
		temp[rbytes] = '\0';
		line = ft_reassign(line, temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mark = NULL;
	char		*ret;
	char		*buff;


	buff = ft_read_line(fd);
	if (!buff)
	{
		ret = ft_strdup(mark);
		mark = NULL;
		return (ret);
	}
	ret = ft_get_line(buff);
	mark = ft_strdup(buff + ft_strlen(ret));
	free(buff);
	return (ret);
}

// #include <string.h>

// int	main(void)
// {
// 	int fd = open("files/41_with_nl_copy", O_RDONLY);
// 	char *ret;
// 	while ((ret = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", ret);
// 		free(ret);
// 	}
// 	close(fd);
// 	return (0);
// }