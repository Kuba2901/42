#include <so_long.h>

void	count_collectibles(t_game **orig)
{
	t_point	*row;
	int		collectibles;
	int		y;
	int		x;
	t_map	*map;

	collectibles = 0;
	y = -1;
	map = (*orig)->map;
	while (++y < map->map_dimensions->height)
	{
		x = 0;
		row = map->map[y];
		while (x < map->map_dimensions->width)
		{
			if (row[x].c == 'C')
				collectibles++;
			x++;
		}
	}
	(*orig)->collected = 0;
	(*orig)->collectibles = collectibles;
}