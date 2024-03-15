#include <so_long.h>

int	field_available(t_game *game, t_point pt)
{
	int		available;
	t_map	*dup_map;
	int		i;

	available = 0;
	dup_map = duplicate_map(game->map);
	dup_map->map[pt.y][pt.x].c = MS_WALL;
	if (!path_exists(dup_map))
		available = 1;
	free_map(dup_map);
	if (!available || enemy_at_point(game, pt))
		return (POINT_NOT_AVAILABLE);
	return (POINT_AVAILABLE);
}

int	point_cmp(t_point pt1, t_point pt2)
{
	return (pt1.x == pt2.x && pt1.y == pt2.y);
}

int	enemy_at_point(t_game *game, t_point pt)
{
	int	i;

	i = -1;
	while (++i < game->enemies.enemies_count)
	{
		if (point_cmp(game->enemies.enemies[i], pt))
			return (1);
	}
	return (0);
}

int	count_free_points(t_game *game)
{
	int		y;
	int		x;
	t_point	pt;
	t_map	*map;
	int		ret;

	ret = 0;
	map = game->map;
	y = 0;
	while (++y < map->map_dimensions->height - 1)
	{
		x = 0;
		while (++x < map->map_dimensions->width - 1)
		{
			pt = map->map[y][x];
			if (pt.c == MS_FREE && !enemy_at_point(game, pt) && field_available(game, pt) == POINT_AVAILABLE)
				ret++;
		}
	}
	return (ret);
}

t_free_points get_free_points(t_game *game)
{
	t_free_points	ret;
	printf("Free points: %d\n", count_free_points(game));
	return (ret);
}

void	place_enemies(t_game *game)
{
	int		y;
	int		x;
	t_point	pt;

	get_free_points(game);
	y = 0;
	while (++y < game->map->map_dimensions->height - 1)
	{
		x = 0;
		while (++x < game->map->map_dimensions->width - 1)
		{
			pt = game->map->map[y][x];
			if (pt.c == MS_FREE && field_available(game, pt) == POINT_AVAILABLE)
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
