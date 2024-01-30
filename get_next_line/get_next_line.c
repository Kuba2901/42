
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
	if (!buff)
		return NULL;
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

	if (!buff)
		return (new);
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
	static char		*mark = NULL;
	char			*ret;
	char			*buff;
	int				len;


	// printf("buff: %s\n", buff);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buff = ft_read_line(fd);
	if (!buff || !buff[0])
	{
		if (mark != NULL && !(mark[0]))
		{
			free(mark);
			return (NULL);
		}
		buff = ft_strdup(mark);
		ret = ft_get_line(mark);
		free(mark);
		mark = ft_strdup(buff + ft_strlen(ret));
		free(buff);
		return (ret);
	}
	ret = ft_get_line(buff);
	len = ft_strlen(ret);
	if (mark != NULL)
		ret = ft_reassign(mark, ret);
	if (mark != NULL)
		free(mark);
	mark = ft_strdup(buff + len);
	free(buff);
	return (ret);
}

#include <string.h>

int	main(void)
{
	int fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	char *ret;
	while ((ret = get_next_line(fd)) != NULL)
	{
		// printf("line: %s", ret);
		free(ret);
	}
	close(fd);
	return (0);
}