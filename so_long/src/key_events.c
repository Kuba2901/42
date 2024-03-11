#include <so_long.h>

int	key_hook(int keycode, t_game *game)
{
	t_point player;

	player = game->player;
	if (keycode == ARROW_UP)
		move_player(game, player.x, player.y - 1);
	if (keycode == ARROW_LEFT)
		move_player(game, player.x - 1, player.y);
	if (keycode == ARROW_DOWN)
		move_player(game, player.x, player.y + 1);
	if (keycode == ARROW_RIGHT)
		move_player(game, player.x + 1, player.y);
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx_vars.mlx, game->mlx_vars.win);
		mlx_loop_end(game->mlx_vars.mlx);
	}
	printf("Key pressed: %d\n", keycode);
	return (0);
}