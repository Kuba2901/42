/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:37 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/16 20:20:44 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*ret;
	char	c;
	int		index;

	ret = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	index = 0;
	while (read(fd, &c, 1) && index < BUFFER_SIZE)
	{
		if (c != '\n')
			ret[index++] = c;
		else
		{
			ret[index++] = '\n';
			break ;
		}
	}
	ret[index++] = '\0';
	return (ret);
}

int	main(void)
{
	int fd = open("test", O_RDONLY);
	char *ret = get_next_line(fd);
	char *ret2 = get_next_line(fd);
	printf("ret1: %s\n", ret);
	printf("ret2: %s\n", ret2);
	free(ret);
	free(ret2);
	return (0);
}