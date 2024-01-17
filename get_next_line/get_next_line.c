/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:37 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/17 17:35:14 by jakubnencza      ###   ########.fr       */
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
	// static int	last;
	int			endl_reached;

	// last = 0;
	endl_reached = 0;
	ret = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	index = 0;
	while ( !endl_reached && read(fd, &c, 1) && index < BUFFER_SIZE)
	{
		if (c != '\n')
			ret[index++] = c;
		else
			endl_reached = 1;
	}
	if (!endl_reached)
	{
		while (read(fd, &c, 1))
			if (c == '\n')
				break ;
		// last = read(fd, &c, 1);
	}
	else
		ret[index++] = '\n';
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