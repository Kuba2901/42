#include "mlx.h"
#include <so_long.h>

int	random_num(int min, int max)
{
	int	ret;

	ret = rand() % (max + 1 - min) - min;
	return (ret);
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
	initialize_game(game);
	printf("Enemies count: %d\n", game->enemies.enemies_count);
	return (game);
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
		TILE_SIZE * dims->width, TILE_SIZE * (dims->height + 1), WINDOW_TITLE);
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
