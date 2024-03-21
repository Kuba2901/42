/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:23:33 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:23:41 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display_stroked_text(t_game *game, int tx, int ty, char *str)
{
	int	color;

	color = create_trgb(255, 255, 255, 255).col;
	mlx_string_put(game->mlx_vars.mlx, game->mlx_vars.win,
		tx + 1, ty, color, str);
	mlx_string_put(game->mlx_vars.mlx, game->mlx_vars.win,
		tx, ty + 1, color, str);
}

int	render_frame(t_game *game)
{
	if (!game->running)
		return (0);
	if (game->stats.frames % PLAYER_ANIM_DELAY == 0)
	{
		if (game->player.location.direction == ARROW_LEFT)
			game->player.location.img_path = game->player.player_left_sprites[
				++game->player.location.img_num % PLAYER_SPRITES_NUM];
		else
			game->player.location.img_path = game->player.player_right_sprites[
				++game->player.location.img_num % PLAYER_SPRITES_NUM];
		render_sprite(game, game->player.location);
	}
	if (game->stats.frames % ENEMY_ANIM_DELAY == 0)
		change_enemies_sprites(game);
	if (game->stats.frames % ENEMY_MOVEMENT_DELAY == 0)
		move_enemies(game);
	game->stats.frames += 1;
	return (0);
}
