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
	orig->stats.collected = 0;
	orig->stats.collectibles = collectibles;
}

void	free_game(t_game *game)
{
	t_map	*map;

	map = game->map;
	free_map(map);
	// free(game->enemies.enemies);
	free(game);
	printf("Game memory freed\n");
}

void	free_map(t_map *map)
{
	free_map_points(map);
	free(map->map);
	free(map->map_dimensions);
	free(map);
}

void	free_map_points(t_map *map)
{
	t_map_dim	*dims;
	int			y;

	dims = map->map_dimensions;
	y = -1;
	while (++y < dims->height)
		free(map->map[y]);
}

int			game_won(t_game *game)
{
	if (!(game->stats.collected == game->stats.collectibles))
	{
		printf("You have to collect all coins before finishing\n");
		return (0);
	}
	return (1);
}

void	initialize_player(t_game *game)
{
	game->player.player_left_sprites[0] = LEFT_PLAYER_1_TEX;
	game->player.player_left_sprites[1] = LEFT_PLAYER_2_TEX;
	game->player.player_left_sprites[2] = LEFT_PLAYER_3_TEX;
	game->player.player_left_sprites[3] = LEFT_PLAYER_4_TEX;
	game->player.player_right_sprites[0] = RIGHT_PLAYER_1_TEX;
	game->player.player_right_sprites[1] = RIGHT_PLAYER_2_TEX;
	game->player.player_right_sprites[2] = RIGHT_PLAYER_3_TEX;
	game->player.player_right_sprites[3] = RIGHT_PLAYER_4_TEX;
	game->player.location.img_path = RIGHT_PLAYER_1_TEX;
	game->player.location.img_num = 0;
	game->player.location.direction = ARROW_RIGHT;
}

void	initialize_enemies(t_game *game)
{
	game->enemies.enemy_left_sprites[0] = LEFT_PLAYER_1_TEX;
	game->enemies.enemy_left_sprites[1] = LEFT_PLAYER_2_TEX;
	game->enemies.enemy_left_sprites[2] = LEFT_PLAYER_3_TEX;
	game->enemies.enemy_left_sprites[3] = LEFT_PLAYER_4_TEX;
	game->enemies.enemy_right_sprites[0] = RIGHT_PLAYER_1_TEX;
	game->enemies.enemy_right_sprites[1] = RIGHT_PLAYER_2_TEX;
	game->enemies.enemy_right_sprites[2] = RIGHT_PLAYER_3_TEX;
	game->enemies.enemy_right_sprites[3] = RIGHT_PLAYER_4_TEX;
	game->enemies.enemies = (t_point *)malloc(sizeof(t_point) * ENEMIES_COUNT);
	game->enemies.enemies_count = 0;
	place_enemies(game);
}