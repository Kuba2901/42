#include <so_long.h>

void	quit_game(t_game *game)
{
	game->running = 0;
	// TODO: REMOVE THESE COMMENtS
	// mlx_destroy_window(game->mlx_vars.mlx, game->mlx_vars.win);
    // mlx_destroy_display(game->mlx_vars.mlx);
    free(game->mlx_vars.mlx);
	free_game(game);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		quit_game(game);
		return (0);
	}
	move_player(game, keycode);
	return (0);
}