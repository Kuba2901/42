/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:26:07 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:26:20 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	initialize_player(t_game *game)
{
	game->player.player_left_sprites[0] = LEFT_PLAYER_1_TEX;
	game->player.player_left_sprites[1] = LEFT_PLAYER_2_TEX;
	game->player.player_left_sprites[2] = LEFT_PLAYER_3_TEX;
	game->player.player_left_sprites[3] = LEFT_PLAYER_4_TEX;
	game->player.player_right_sprites[0] = RIGHT_PLAYER_1_TEX;
	game->player.player_right_sprites[1] = RIGHT_PLAYER_2_TEX;
	game->player.player_right_sprites[2] = RIGHT_PLAYER_3_TEX;
	game->player.player_right_sprites[3] = RIGHT_PLAYER_4_TEX;
	game->player.location.img_path = RIGHT_PLAYER_1_TEX;
	game->player.location.img_num = 0;
	game->player.location.direction = ARROW_RIGHT;
}

void	initialize_enemies(t_game *game)
{
	game->enemies.enemy_left_sprites[0] = LEFT_ENEMY_1_TEX;
	game->enemies.enemy_left_sprites[1] = LEFT_ENEMY_2_TEX;
	game->enemies.enemy_left_sprites[2] = LEFT_ENEMY_3_TEX;
	game->enemies.enemy_left_sprites[3] = LEFT_ENEMY_4_TEX;
	game->enemies.enemy_right_sprites[0] = RIGHT_ENEMY_1_TEX;
	game->enemies.enemy_right_sprites[1] = RIGHT_ENEMY_2_TEX;
	game->enemies.enemy_right_sprites[2] = RIGHT_ENEMY_3_TEX;
	game->enemies.enemy_right_sprites[3] = RIGHT_ENEMY_4_TEX;
	game->enemies.enemies = (t_point *)malloc(sizeof(t_point) * ENEMIES_COUNT);
	game->enemies.enemies_count = 0;
	place_enemies(game);
}

void	initialize_game_stats(t_game *game)
{
	game->running = 1;
	game->stats.drawn = DARK_MODE;
	game->stats.steps = 0;
	game->stats.frames = 0;
}
