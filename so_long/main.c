#include <so_long.h>

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
	if (!game->stats.collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
		free_game(game);
		return (NULL);
	}
	game->player.location = create_point(map->start.x, map->start.y, 'A');;
	game->running = 1;
	game->stats.steps = 0;
	game->stats.frames = 0;
	assign_sprites(game->map);
	initialize_player(game);
	// initialize_enemies(game);
	return (game);
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

int main(int ac, char **av) {
	t_map_dim	*dims;
	t_game		*game;

	if (ac != 2)
		return (0);
	game = start_game(av[1]);
	dims = game->map->map_dimensions;
    game->mlx_vars.mlx = mlx_init();
    game->mlx_vars.win = mlx_new_window(game->mlx_vars.mlx,
		TILE_SIZE * dims->width, TILE_SIZE * dims->height, WINDOW_TITLE);
	game->stats.drawn = 0;
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
 