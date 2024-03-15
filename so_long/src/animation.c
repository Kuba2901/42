#include <so_long.h>

void	animate_player(t_game *game, int direction)
{
	if (direction == ARROW_LEFT)
	{
		game->player.location.img_path = LEFT_PLAYER_1_TEX;
		game->player.location.img_num = 0;
		game->player.location.direction = ARROW_LEFT;
	}
	if (direction == ARROW_RIGHT)
	{
		game->player.location.img_path = RIGHT_PLAYER_1_TEX;
		game->player.location.img_num = 0;
		game->player.location.direction = ARROW_RIGHT;
	}
}

void sleep_ms(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}
