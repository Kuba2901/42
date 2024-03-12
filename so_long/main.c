#include "mlx.h"
#include <so_long.h>

int	random_num(int min, int max)
{
	int	ret;

	ret = rand() % (max + 1 - min) - min;
	return (ret);
}

int		count_free_available_fields(t_map *map)
{
	int		x;
	int		y;
	int		fields;

	y = 0;
	fields = 0;
	while (++y < map->map_dimensions->height - 1)
	{
		x = 0;
		while (++x < map->map_dimensions->width - 1)
		{
			if (map->map[y][x].c == '0')
				fields++;
		}
	}
	return (fields);
}

t_point	*get_free_available_fields(t_map *map)
{
	int		x;
	int		y;
	t_point *ret;
	int		i;

	ret = (t_point *)malloc(sizeof(t_point)
		* count_free_available_fields(map));
	y = 0;
	i = 0;
	while (++y < map->map_dimensions->height - 1)
	{
		x = 0;
		while (++x < map->map_dimensions->width - 1)
		{
			if (map->map[y][x].c == '0')
				ret[i++] = map->map[y][x];
		}
	}
	return (ret);
}

t_point	pick_random_point(t_game *game)
{
	t_point	pt;
	t_map	*dup_map;
	int		max_tries;
	t_point	*spots;

	max_tries = 10;
	dup_map = duplicate_map(game->map);
	spots = get_free_available_fields(game->map);
	while (max_tries--)
	{
		pt = spots[random_num(0, sizeof(spots) / sizeof(t_point))];
		dup_map->map[pt.y][pt.x].c = '1';
		if (path_exists(dup_map))
		{
			free_map(dup_map);
			free(spots);
			return (pt);
		}
	}
	free(spots);
	free_map(dup_map);
	return (create_point(-1, -1, 'Q'));
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
	enemies->enemies_count = ENEMIES_COUNT;
	enemies->enemies = (t_point *)malloc(sizeof(t_point) * ENEMIES_COUNT);

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

t_game		*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;

	game = (t_game *)malloc(sizeof(t_game));
	map = fill_map(file_name);
	game->map = map;
	if (full_map_check(file_name, map))
	{
		free_game(game);
		return (NULL);
	}
	count_collectibles(game);
	if (!game->game_stats.collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
		free_game(game);
		return (NULL);
	}
	game->player.player = create_point(map->start.x, map->start.y, 'A');
	game->player.player.img_path = RIGHT_PLAYER_1_TEX;
	game->player.player.img_num = 0;
	game->player.player.direction = ARROW_RIGHT;
	game->game_stats.running = 1;
	game->game_stats.steps = 0;
	game->game_stats.frames = 0;
	assign_sprites(game->map);
	assign_player_sprites(game);
	assign_enemy_sprites(game);
	return (game);
}

int	render_frame(t_game *game)
{
	if (game->game_stats.frames % PLAYER_ANIM_DELAY == 0)
	{
		if (game->player.player.direction == ARROW_LEFT)
		{

			game->player.player.img_path = game->player.player_left_sprites[++game->player.player.img_num % PLAYER_SPRITES_NUM];	
		}
		else 
			game->player.player.img_path = game->player.player_right_sprites[++game->player.player.img_num % PLAYER_SPRITES_NUM];
		custom_render_image(game, game->player.player);
	}
	game->game_stats.frames += 1;
	return (0);
}

int calculate_tile_size(t_map_dim *dims)
{
	int	x_tile;
	int	y_tile;

	x_tile = WINDOW_WIDTH / dims->width;
	y_tile = WINDOW_HEIGHT / dims->height;
	if (x_tile > y_tile)
		return (y_tile);
	else
		return (x_tile);
}

void	display_stroked_text(t_game *game, int tx, int ty, char *str)
{
	int	color;

	color = create_trgb(255, 255, 255, 255).col;
	mlx_string_put(game->mlx_vars.mlx, game->mlx_vars.win,
		tx + 1, ty, color, str);
	mlx_string_put(game->mlx_vars.mlx, game->mlx_vars.win,
		tx, ty + 1, color, str);
}

void display_steps_count(t_game *game)
{
	char	*steps;
	char	*steps_info;
	int		tx;
	int		ty;

	ty = game->map->map_dimensions->height * TILE_SIZE - (TILE_SIZE / 2); // Window decorations issue
	tx = game->map->map_dimensions->width * TILE_SIZE / 2;
	steps_info = ft_strdup("STEPS: ");
	steps = ft_itoa(game->game_stats.steps);
	steps_info = ft_join_reassign(steps_info, steps);
	display_stroked_text(game, tx, ty, steps_info);
	free(steps_info);
}

int main(int ac, char **av) {
	t_map_dim	*dims;
	t_game		*game;

	if (ac != 2)
		return (0);
	srand(time(0));
	game = start_game(av[1]);
	dims = game->map->map_dimensions;
    game->mlx_vars.mlx = mlx_init();
    game->mlx_vars.win = mlx_new_window(game->mlx_vars.mlx,
		TILE_SIZE * dims->width, TILE_SIZE * dims->height, WINDOW_TITLE);
	game->game_stats.drawn = 0;
	draw_board(game);
	mlx_key_hook(game->mlx_vars.win, key_hook, game);
	mlx_loop_hook(game->mlx_vars.mlx, render_frame, game);
	mlx_loop(game->mlx_vars.mlx);

	// CLEAR THE RESOURCES
    mlx_destroy_display(game->mlx_vars.mlx);
    free(game->mlx_vars.mlx);
	free_game(game);
    return (0);
}
