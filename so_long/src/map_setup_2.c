/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:33:10 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 17:23:36 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_point	get_shifted_point(int direction, t_point pt, t_map *map)
{
	t_point	ret;

	ret.x = pt.x;
	ret.y = pt.y;
	if (direction == ARROW_LEFT)
		ret.c = map->map[ret.y][--ret.x].c;
	else if (direction == ARROW_DOWN)
		ret.c = map->map[++ret.y][ret.x].c
	else if (direction == ARROW_RIGHT)
		ret.c = map->map[ret.y][++ret.x].c
	else if (direction == ARROW_UP)
		ret.c = map->map[--ret.y][ret.x].c
	return (ret);
}

t_point	create_point(int x, int y, char c)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	ret.c = c;
	return (ret);
}

size_t	ft_custom_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_map_rectangular(const char *file_name)
{
	char	*temp;
	int		fd;
	size_t	w;
	int		error;

	fd = open(file_name, O_RDONLY);
	w = 0;
	error = 0;
	temp = get_next_line(fd);
	while (temp != NULL && !error)
	{
		if (!w)
			w = ft_custom_strlen(temp);
		else if (ft_custom_strlen(temp) != w)
			error = MAP_NOT_RECTANGULAR;
		free(temp);
		temp = get_next_line(fd);
	}
	close (fd);
	return (error);
}
