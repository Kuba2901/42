#include <so_long.h>

int			move_valid(t_map *map, t_point pt)
{
	return (!(is_out_of_bounds(map, pt) || pt.c == '1'));
}

int			game_won(t_game *game)
{
	if (!(game->game_stats.collected == game->game_stats.collectibles))
	{
		printf("You have to collect all coins before finishing\n");
		return (0);
	}
	return (1);
}

void	collect_item(t_game *game)
{
	t_point	player;

	player = game->player.player;
	game->map->map[player.y][player.x].c = '0';
	game->map->map[player.y][player.x].img_path = FLOOR_TEX;
	game->game_stats.collected += 1;
	printf("Item collected!\n");
}

void		move_player(t_game *game, int x, int y, int direction)
{
	if (move_valid(game->map, game->map->map[y][x]))
	{
		game->player.player.x = x;
		game->player.player.y = y;
		game->game_stats.steps += 1;
		if (enemy_hit(game))
		{
			printf("You lost!\n");
			quit_game(game);
		}
		if (game->map->map[y][x].c == 'C')
			collect_item(game);
		draw_board(game);
		change_player_direction(game, direction);
		if (game->player.player.x == game->map->end.x \
			&& game->player.player.y == game->map->end.y)
		{
			if (game_won(game))
			{
				printf("Congratulatins! You won!\n");
				quit_game(game);
			}
		}
	}
}