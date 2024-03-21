/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_enemies_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:27:06 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/21 16:48:15 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_enemy(t_game *game, t_point pt)
{
	game->enemies.enemies[
		game->enemies.enemies_count++] = create_point(pt.x, pt.y, MS_ENEMY);
	game->enemies.enemies[
		game->enemies.enemies_count - 1].img_path = LEFT_ENEMY_1_TEX;
}

void	place_enemies(t_game *game)
{
	int				i;
	t_point			pt;
	t_free_points	*free_pts;
	int				iter;

	free_pts = get_free_points(game);
	i = -1;
	while (++i < ENEMIES_COUNT && i < free_pts->count \
		&& game->enemies.enemies_count < ENEMIES_COUNT)
	{
		pt = free_pts->points[random_num(0, free_pts->count - 1)];
		if (!enemy_at_point(game, pt))
			put_enemy(game, pt);
		else
			handle_linear_placement(free_pts, game);
	}
	free(free_pts->points);
	free(free_pts);
}

void	handle_linear_placement(t_free_points *free_pts, t_game *game)
{
	int		iter;
	t_point	pt;

	iter = -1;
	while (++iter < free_pts->count)
	{
		pt = free_pts->points[iter];
		if (!enemy_at_point(game, pt))
		{
			put_enemy(game, pt);
			break ;
		}
	}
}

void	display_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies.enemies_count)
		render_sprite(game, game->enemies.enemies[i]);
}
