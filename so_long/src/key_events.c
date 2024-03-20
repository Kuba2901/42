/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:32:04 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:36 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	quit_game(t_game *game)
{
	game->running = 0;
	mlx_destroy_window(game->mlx_vars.mlx, game->mlx_vars.win);
	mlx_destroy_display(game->mlx_vars.mlx);
	free(game->mlx_vars.mlx);
	free_game(game);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		quit_game(game);
		return (0);
	}
	move_player(game, keycode);
	return (0);
}
