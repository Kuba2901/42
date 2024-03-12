#include "mlx.h"
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
	if (!game->collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
		free_game(game);
		return (NULL);
	}
	game->player = create_point(map->start.x, map->start.y, 'A');
	game->player.img_path = RIGHT_PLAYER_1_TEX;
	game->running = 1;
	game->steps = 0;
	assign_sprites(game->map);
	return (game);
}

int main() {
	t_mlx_vars	vars;
	t_map_dim	*dims;
	t_game		*game;

	game = start_game(MAP_FILE_NAME);
	dims = game->map->map_dimensions;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, dims->width * TILE_SIZE,
		dims->height * TILE_SIZE, WINDOW_TITLE);
	game->mlx_vars = vars;
	game->drawn = 0;
	draw_board(game);
	mlx_key_hook(vars.win, key_hook, game);
	mlx_loop(vars.mlx);

	// CLEAR THE RESOURCES
    mlx_destroy_display(vars.mlx);
    free(vars.mlx);
	free_game(game);
    return (0);
}
