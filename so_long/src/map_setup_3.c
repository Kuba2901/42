/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:41:59 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:55:29 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	*duplicate_map(t_map *map)
{
	t_map	*ret;
	int		x;
	int		y;

	ret = (t_map *)malloc(sizeof(t_map));
	ret->map_dimensions = (t_map_dim *)malloc(sizeof(t_map_dim));
	ret->map_dimensions->height = map->map_dimensions->height;
	ret->map_dimensions->width = map->map_dimensions->width;
	ret->map = (t_point **)malloc(sizeof(t_point *)
			* map->map_dimensions->height);
	ret->end = map->end;
	ret->start = map->start;
	y = -1;
	while (++y < map->map_dimensions->height)
	{
		x = 0;
		ret->map[y] = (t_point *)malloc(sizeof(t_point)
				* map->map_dimensions->width);
		while (x < map->map_dimensions->width)
		{
			ret->map[y][x] = create_point(x, y, map->map[y][x].c);
			x++;
		}
	}
	return (ret);
}

int	flood_fill(t_map *map, t_point pt)
{
	if (is_out_of_bounds(map, pt) || pt.c == 'V' || pt.c == MS_WALL)
		return (0);
	if (pt.x == map->end.x && pt.y == map->end.y)
		return (1);
	map->map[pt.y][pt.x].c = 'V';
	if (flood_fill(map, get_shifted_point(ARROW_RIGHT, pt, game)) \
		|| flood_fill(map, get_shifted_point(ARROW_LEFT, pt, game)) \
			|| flood_fill(map, get_shifted_point(ARROW_DOWN, pt, game)) \
				|| flood_fill(map, get_shifted_point(ARROW_UP, pt, game)))
		return (1);
	return (0);
}

int	check_path_exists(t_map *map)
{
	t_point	start;
	t_point	end;

	start = map->start;
	end = map->end;
	if (is_out_of_bounds(map, start) || is_out_of_bounds(map, end) \
		|| map->map[start.y][start.x].c == 'V' \
			|| map->map[end.y][end.x].c == 'V')
		return (0);
	return (flood_fill(map, start));
}

int	is_out_of_bounds(t_map *map, t_point pt)
{
	return (pt.x < 1 || pt.y < 1 \
			|| pt.x >= map->map_dimensions->width \
				|| pt.y >= map->map_dimensions->height);
}

void	print_point_info(t_point pt)
{
	printf("PT: (x,y,c) => (%d,%d,%c)\n", pt.x, pt.y, pt.c);
}
