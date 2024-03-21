/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:36:30 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:55:32 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	determine_error(int exits, int positions)
{
	if (!exits)
		return (MAP_NO_EXIT);
	if (!positions)
		return (MAP_NO_STARTING_POSITION);
	if (exits > 1)
		return (MAP_MULTIPLE_EXITS);
	if (positions > 1)
		return (MAP_MULTIPLE_STARTING_POSITIONS);
	return (0);
}

int	check_duplicates(t_map *map)
{
	int		exits;
	int		positions;
	int		x;
	int		y;

	exits = 0;
	positions = 0;
	y = -1;
	while (++y < map->map_dimensions->height)
	{
		x = 0;
		while (x < map->map_dimensions->width)
		{
			if (map->map[y][x].c == MS_EXIT)
				exits++;
			else if (map->map[y][x].c == MS_START)
				positions++;
			x++;
		}
	}
	if (determine_error(exits, positions))
		return (determine_error(exits, positions));
	return (0);
}

int	check_surrounded_by_walls(t_map *map)
{
	int		x;
	int		y;
	t_point	pt;

	y = -1;
	while (++y < map->map_dimensions->height)
	{
		x = -1;
		while (++x < map->map_dimensions->width)
		{
			pt = map->map[y][x];
			if (!y || y == map->map_dimensions->height - 1)
			{
				if (pt.c != '1')
					return (MAP_NOT_SURROUNDED_BY_WALLS);
			}
			else if (x == 0 || x == map->map_dimensions->width - 1)
			{
				if (pt.c != '1')
					return (MAP_NOT_SURROUNDED_BY_WALLS);
			}
		}
	}
	return (0);
}

int	path_exists(t_map *orig)
{
	t_map	*dup_map;
	int		path_exists;

	dup_map = duplicate_map(orig);
	path_exists = check_path_exists(dup_map);
	free_map(dup_map);
	if (path_exists)
		return (0);
	return (MAP_NO_PATH);
}

int	full_map_check(const char *file_name, t_map *map)
{
	int	error_code;

	error_code = check_map_rectangular(file_name);
	if (!error_code)
		error_code = check_duplicates(map);
	if (!error_code)
		error_code = check_surrounded_by_walls(map);
	if (!error_code)
		error_code = path_exists(map);
	if (error_code)
		print_error(error_code);
	return (error_code);
}
