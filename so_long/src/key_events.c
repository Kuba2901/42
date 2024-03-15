#include <so_long.h>

void	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_vars.mlx, game->mlx_vars.win);
	mlx_loop_end(game->mlx_vars.mlx);
}

int	key_hook(int keycode, t_game *game)
{
	t_point player_location;

	player_location = game->player.location;
	if (keycode == ARROW_UP)
		move_player(game, player_location.x, player_location.y - 1, keycode);
	if (keycode == ARROW_LEFT)
		move_player(game, player_location.x - 1, player_location.y, keycode);
	if (keycode == ARROW_DOWN)
		move_player(game, player_location.x, player_location.y + 1, keycode);
	if (keycode == ARROW_RIGHT)
		move_player(game, player_location.x + 1, player_location.y, keycode);
	if (keycode == ESC)
		quit_game(game);
	printf("Key pressed: %d\n", keycode);
	return (0);
}