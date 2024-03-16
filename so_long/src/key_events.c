#include <so_long.h>

void	quit_game(t_game *game)
{
	game->running = 0;
	mlx_destroy_window(game->mlx_vars.mlx, game->mlx_vars.win);
	mlx_loop_end(game->mlx_vars.mlx);
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