/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:25:20 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 17:26:24 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	enemy_hit(t_game *game)
{
	return (enemy_at_point(game, game->player.location));
}

int	move_valid(t_game *game, t_point pt)
{
	if (is_out_of_bounds(game->map, pt) || pt.c == MS_WALL)
		return (0);
	return (1);
}

void	collect_item(t_game *game)
{
	t_point	player;

	player = game->player.location;
	game->map->map[player.y][player.x].c = MS_FREE;
	game->map->map[player.y][player.x].img_path = FLOOR_TEX;
	game->stats.collected += 1;
	printf("Item collected!\n");
}

void	move_player(t_game *game, int direction)
{
	t_point	pt;
	t_point	map_pt;

	pt = create_point(game->player.location.x, game->player.location.y,
			game->player.location.c);
	if (direction == ARROW_RIGHT)
		pt.x += 1;
	else if (direction == ARROW_LEFT)
		pt.x -= 1;
	else if (direction == ARROW_UP)
		pt.y -= 1;
	else if (direction == ARROW_DOWN)
		pt.y += 1;
	map_pt = game->map->map[pt.y][pt.x];
	if (move_valid(game, map_pt))
	{
		animate_player(game, map_pt);
		if (game->map->map[map_pt.y][map_pt.x].c == MS_COLLECTIBLE)
			collect_item(game);
		display_steps_count(game);
		if (point_cmp(game->player.location, game->map->end) && game_won(game))
			quit_game(game);
	}
}
