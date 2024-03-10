#include <so_long.h>

t_point	**duplicate_map(t_map *map)
{
	t_point	**ret;
	int		x;
	int		y;

	ret = (t_point **)malloc(sizeof(t_point *) * map->map_dimensions->height);
	y = -1;
	while (++y < map->map_dimensions->height)
	{
		x = 0;
		ret[y] = (t_point *)malloc(sizeof(t_point) * map->map_dimensions->width);
		while (x < map->map_dimensions->width)
		{
			ret[y][x] = create_point(x, y, map->map[y][x].c);
			x++;
		}
	}
	return (ret);
}

int	path_exists(t_map *map) {
	t_point	**map_copy;

	map_copy = duplicate_map(map);
	free_map_points(map_copy, map->map_dimensions->height);
	return (0);
}