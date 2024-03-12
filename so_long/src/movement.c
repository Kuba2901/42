#include <so_long.h>

int			move_valid(t_map *map, t_point pt)
{
	return (!(is_out_of_bounds(map, pt) || pt.c == '1'));
}

void		move_player(t_game *game, int x, int y, int direction)
{
	if (move_valid(game->map, game->map->map[y][x]))
	{
		game->player.x = x;
		game->player.y = y;
		game->steps += 1;
		animate_player(game, direction);
		printf("Steps: (%d)\n", game->steps);
		draw_board(game);
	}
}