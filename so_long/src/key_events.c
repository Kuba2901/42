#include <so_long.h>

void	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_vars.mlx, game->mlx_vars.win);
	mlx_loop_end(game->mlx_vars.mlx);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit_game(game);
	move_player(game, keycode);
	return (0);
}