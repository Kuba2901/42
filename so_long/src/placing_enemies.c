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

void	place_enemies(t_game *game)
{
	int		y;
	int		x;
	t_point	pt;

	y = 0;
	while (++y < game->map->map_dimensions->height - 1)
	{
		x = 0;
		while (++x < game->map->map_dimensions->width - 1)
		{
			pt = game->map->map[y][x];
			if (pt.c == MS_FREE && field_available(game, pt))
			{
				game->enemies.enemies[
					game->enemies.enemies_count++] = create_point(x, y, MS_ENEMY);
				game->enemies.enemies[
					game->enemies.enemies_count - 1].img_path = LEFT_ENEMY_1_TEX;
				if (game->enemies.enemies_count == ENEMIES_COUNT)
					return ;
			}
		}
	}
}

void	display_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies.enemies_count)
		render_sprite(game, game->enemies.enemies[i]);
}
