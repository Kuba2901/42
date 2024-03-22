/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:37:27 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/22 17:48:03 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map_dim	*get_map_dimensions(const char *file_name)
{
	char		*temp;
	int			fd;
	int			h;
	t_map_dim	*ret;

	fd = open(file_name, O_RDONLY);
	temp = get_next_line(fd);
	h = 0;
	ret = (t_map_dim *)malloc(sizeof(t_map_dim));
	while (temp != NULL)
	{
		if (!h)
			ret->width = ft_custom_strlen(temp);
		h++;
		free(temp);
		temp = get_next_line(fd);
	}
	ret->height = h;
	close (fd);
	return (ret);
}

t_map	*create_allocate_t_map(t_map_dim *dim)
{
	int		y;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map_dimensions = dim;
	map->map = (t_point **)malloc(sizeof(t_point *) * dim->height);
	y = 0;
	while (y < dim->height)
	{
		map->map[y] = (t_point *)malloc(sizeof(t_point) * dim->width);
		y++;
	}
	return (map);
}

void	set_start_exit(t_map *map, t_point pt)
{
	if (pt.c == MS_START)
		map->start = map->map[pt.y][pt.x];
	else if (pt.c == MS_EXIT)
		map->end = map->map[pt.y][pt.x];
}

t_map	*fill_map(const char *file_name)
{
	int			x;
	int			y;
	int			fd;
	char		*temp;
	t_map		*map;

	map = create_allocate_t_map(get_map_dimensions(file_name));
	fd = open(file_name, O_RDONLY);
	temp = get_next_line(fd);
	y = 0;
	while (temp != NULL)
	{
		x = 0;
		while (temp[x] && temp[x] != '\n')
		{
			map->map[y][x] = create_point(x, y, temp[x]);
			set_start_exit(map, map->map[y][x]);
			x++;
		}
		y++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (map);
}

// TODO: Test
void	print_map(t_map	*map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->map_dimensions->height)
	{
		x = 0;
		while (x < map->map_dimensions->width)
		{
			ft_printf("(%p)", map->map[y][x].img_path);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
