#include <so_long.h>

int	enemy_hit(t_game *game)
{
	return (enemy_at_point(game, game->player.location));
}

int	move_valid(t_game *game, t_point pt)
{
	if (is_out_of_bounds(game->map, pt) || pt.c == '1')
		return (0);
	return (1);
}

void	collect_item(t_game *game)
{
	t_point	player;

	player = game->player.location;
	game->map->map[player.y][player.x].c = '0';
	game->map->map[player.y][player.x].img_path = FLOOR_TEX;
	game->stats.collected += 1;
	printf("Item collected!\n");
}

void		move_player(t_game *game, int x, int y, int direction)
{
	if (move_valid(game, game->map->map[y][x]))
	{
		if (y != game->player.location.y)
			game->player.location.y += (y - game->player.location.y);
		animate_player(game, direction);
		printf("Steps: (%d)\n", game->stats.steps);
		if (game->map->map[y][x].c == 'C')
			collect_item(game);
		if (game->player.location.x == game->map->end.x && game->player.location.y == game->map->end.y)
		{
			if (game_won(game))
			{
				printf("Congratulatins! You won!\n");
				quit_game(game);
			}
		}
	}
}