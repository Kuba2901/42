#include <so_long.h>

int	field_available(t_game *game, t_point pt)
{
	int		available;
	t_map	*dup_map;

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
		{
			printf("Enemy overlapping stopped!\n");
			return (1);
		}
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
			if (pt.c == MS_FREE && !enemy_at_point(game, pt) \
				&& field_available(game, pt) == POINT_AVAILABLE)
				ret++;
		}
	}
	return (ret);
}

t_free_points	*get_free_points(t_game *game)
{
	int				y;
	int				x;
	t_point			pt;
	t_free_points	*ret;
	int				i;

	ret = (t_free_points *)malloc(sizeof(t_free_points));
	ret->count = count_free_points(game);
	ret->points = (t_point *)malloc(sizeof(t_point) * ret->count);
	y = 0;
	i = 0;
	while (++y < game->map->map_dimensions->height - 1)
	{
		x = 0;
		while (++x < game->map->map_dimensions->width - 1)
		{
			pt = game->map->map[y][x];
			if (pt.c == MS_FREE && !enemy_at_point(game, pt) \
				&& field_available(game, pt) == POINT_AVAILABLE)
			{
				ret->points[i++] = create_point(pt.x, pt.y, pt.c);
			}
		}
	}
	return (ret);
}

void	put_enemy(t_game *game, t_point pt)
{
	game->enemies.enemies[
		game->enemies.enemies_count++] = create_point(pt.x, pt.y, MS_ENEMY);
	game->enemies.enemies[
		game->enemies.enemies_count - 1].img_path = LEFT_ENEMY_1_TEX;
	printf("Enemy placed at: (%d, %d)\n", pt.x, pt.y);
}

void	place_enemies(t_game *game)
{
	int				i;
	t_point			pt;
	t_free_points	*free_pts;
	int 			iter;

	free_pts = get_free_points(game);
	i = -1;
	while (++i < ENEMIES_COUNT && i < free_pts->count \
		&& game->enemies.enemies_count < ENEMIES_COUNT)
	{
		pt = free_pts->points[random_num(0, free_pts->count - 1)];
		if (!enemy_at_point(game, pt))
			put_enemy(game, pt);
		else
		{
			iter = -1;
			while (++iter < free_pts->count)
			{
				pt = free_pts->points[iter];
				if (!enemy_at_point(game, pt))
				{
					put_enemy(game, pt);
					break ;
				}
			}
		}
	}
	free(free_pts->points);
	free(free_pts);
}

void	display_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies.enemies_count)
		render_sprite(game, game->enemies.enemies[i]);
}
