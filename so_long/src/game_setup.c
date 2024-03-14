#include <so_long.h>

void	count_collectibles(t_game *orig)
{
	t_point	*row;
	int		collectibles;
	int		y;
	int		x;
	t_map	*map;

	collectibles = 0;
	y = -1;
	map = orig->map;
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
	orig->game_stats.collected = 0;
	orig->game_stats.collectibles = collectibles;
}

void	free_game(t_game *game)
{
	t_map	*map;

	map = game->map;
	free_map(map);
	free(game);
	printf("Game memory freed\n");
}

void	initialize_game(t_game *game)
{
	game->player.player = create_point(game->map->start.x, game->map->start.y, 'A');
	game->player.player.img_path = RIGHT_PLAYER_1_TEX;
	game->player.player.img_num = 0;
	game->player.player.direction = ARROW_RIGHT;
	game->game_stats.running = 1;
	game->game_stats.steps = 0;
	game->game_stats.frames = 0;
	assign_sprites(game->map);
	assign_player_sprites(game);
	assign_enemy_sprites(game);
}

void assign_enemy_sprites(t_game *game)
{
	t_enemies *enemies;

	enemies = &(game->enemies);
	enemies->enemy_left_sprites[0] = LEFT_ENEMY_1_TEX;
	enemies->enemy_left_sprites[1] = LEFT_ENEMY_2_TEX;
	enemies->enemy_left_sprites[2] = LEFT_ENEMY_3_TEX;
	enemies->enemy_left_sprites[3] = LEFT_ENEMY_4_TEX;
	enemies->enemy_right_sprites[0] = RIGHT_ENEMY_1_TEX;
	enemies->enemy_right_sprites[1] = RIGHT_ENEMY_2_TEX;
	enemies->enemy_right_sprites[2] = RIGHT_ENEMY_3_TEX;
	enemies->enemy_right_sprites[3] = RIGHT_ENEMY_4_TEX;
	enemies->enemies = (t_point *)malloc(sizeof(t_point) * ENEMIES_COUNT);
	place_enemies(game);
}

void assign_player_sprites(t_game *game)
{
	game->player.player_left_sprites[0] = LEFT_PLAYER_1_TEX;
	game->player.player_left_sprites[1] = LEFT_PLAYER_2_TEX;
	game->player.player_left_sprites[2] = LEFT_PLAYER_3_TEX;
	game->player.player_left_sprites[3] = LEFT_PLAYER_4_TEX;
	game->player.player_right_sprites[0] = RIGHT_PLAYER_1_TEX;
	game->player.player_right_sprites[1] = RIGHT_PLAYER_2_TEX;
	game->player.player_right_sprites[2] = RIGHT_PLAYER_3_TEX;
	game->player.player_right_sprites[3] = RIGHT_PLAYER_4_TEX;
}

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
		custom_render_image(game, game->enemies.enemies[i]);
}

int	enemy_hit(t_game *game)
{
	t_point enemy;
	t_point	player;
	int	i;

	i = -1;
	player = game->player.player;
	while (++i < game->enemies.enemies_count)
	{
		enemy = game->enemies.enemies[i];
		if (enemy.x == player.x && enemy.y == player.y)
			return (ENEMY_HIT);
	}
	return (0);
}