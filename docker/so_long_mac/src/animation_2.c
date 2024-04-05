/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:58:50 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/18 18:00:13 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	animate_player(t_game *game, t_point pt)
{
	t_point	orig;

	orig = game->map->map[game->player.location.y][game->player.location.x];
	if (orig.x > pt.x)
	{
		game->player.location.img_path = LEFT_PLAYER_1_TEX;
		game->player.location.img_num = 0;
		game->player.location.direction = ARROW_LEFT;
		game->player.location.x -= 1;
	}
	else if (orig.x < pt.x)
	{
		game->player.location.img_path = RIGHT_PLAYER_1_TEX;
		game->player.location.img_num = 0;
		game->player.location.direction = ARROW_RIGHT;
		game->player.location.x += 1;
	}
	else
		game->player.location.y += (pt.y - game->player.location.y);
	game->stats.steps += 1;
	render_sprite(game, game->player.location);
	render_sprite(game, orig);
	if (enemy_hit(game))
		quit_game(game);
}
