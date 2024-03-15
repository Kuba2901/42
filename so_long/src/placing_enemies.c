#include <so_long.h>

int	field_available(t_game *game, t_point pt)
{
	int		available;
	t_map	*dup_map;
	int		i;

	dup_map = duplicate_map(game->map);
	dup_map->map[pt.y][pt.x].c = '1';
	if (!path_exists(dup_map))
		available = 1;
	free_map(dup_map);
	i = -1;
	while (++i < game->enemies.enemies_count)
	{
		if (game->enemies.enemies[i].x == pt.x \
			&& game->enemies.enemies[i].y == pt.y)
				return (POINT_NOT_AVAILABLE);
	}
	if (available)
		return (POINT_AVAILABLE);
	return (POINT_NOT_AVAILABLE);
}