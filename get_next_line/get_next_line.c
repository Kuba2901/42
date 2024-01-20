/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:37 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/20 14:53:25 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*ret;
	char		c;
	int			index;
	int			endl_reached;
	static int	mark = 0;

	endl_reached = 0;
	index = 0;
	ret = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (fd < 0 || ret == NULL)
		return (NULL);
	if (mark)
	{
		printf("Mark found at: %d\n", mark);
		index = mark;
		while (index--)
		{
			printf("Skipping %c at %d in the file\n", c, mark - index);
			read(fd, &c, 1);
		}
	}
	while (!endl_reached && read(fd, &c, 1) && index < (BUFFER_SIZE - 1))
	{
		if (c != '\n' && c != '\r')
		{
			printf("%c - %d: saved to buff at %d\n", c, (int)c, index);
			ret[index++] = c;
		}
		else
			endl_reached = 1;
	}
	if (!endl_reached)
		while (read(fd, &c, 1) && c != '\n' && c != '\r')
			;
	else
	{
		printf("Put \\n at %d\n", index);
		ret[index++] = '\n';
	}
	if (!index)
	{
		free(ret);
		return (NULL);
	}
	mark += index;
	printf("mark set to: %d\n", mark);
	ret[index] = '\0';
	printf("put terminator at %d\n", index);
	return (ret);
}

#include <string.h>

int	main(void)
{
	int fd = open("files/41_no_nl", O_RDONLY);
	char *ret = get_next_line(fd);
	printf("ret1: %s\n", ret);
	free(ret);
	return (0);
}