/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:43:34 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/18 17:57:18 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	random_num(int min, int max)
{
	int	ret;

	ret = rand() % (max + 1 - min) - min;
	return (ret);
}

void	move_enemies(t_game *game)
{
	int		i;
	int		axis;
	int		dir;

	i = -1;
	while (++i < game->enemies.enemies_count)
	{
		if (!random_num(0, 1))
			axis = AXIS_VERTICAL;
		else
			axis = AXIS_HORIZONTAL;
		dir = random_num(0, 1);
		if (!dir)
			dir--;
		move_enemies_2(game, dir, axis, i);
	}
}

void	move_enemies_2(t_game *game, int dir, int axis, int i)
{
	t_point	enemy;
	t_point	new_pos;

	enemy = game->enemies.enemies[i];
	if (axis == AXIS_VERTICAL)
	{
		new_pos = create_point(enemy.x, enemy.y + dir,
				game->map->map[enemy.y + dir][enemy.x].c);
		if (move_valid(game, new_pos) && !enemy_at_point(game, new_pos))
			animate_enemy(game, i, new_pos);
	}
	else
	{
		new_pos = create_point(enemy.x + dir, enemy.y,
				game->map->map[enemy.y][enemy.x + dir].c);
		if (dir > 0 && move_valid(game, new_pos) \
				&& !enemy_at_point(game, new_pos))
			animate_enemy(game, i, new_pos);
		else if (move_valid(game, new_pos) \
				&& !enemy_at_point(game, new_pos))
			animate_enemy(game, i, new_pos);
	}
}

void	change_enemies_sprites(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies.enemies_count)
	{
		if (game->enemies.enemies[i].direction == ARROW_LEFT)
			game->enemies.enemies[i].img_path = game->enemies
				.enemy_left_sprites[
				++game->enemies.enemies[i].img_num % ENEMY_SPRITES_NUM];
		else
			game->enemies.enemies[i].img_path = game->enemies
				.enemy_right_sprites[
				++game->enemies.enemies[i].img_num % ENEMY_SPRITES_NUM];
		render_sprite(game, game->enemies.enemies[i]);
	}
}

void	animate_enemy(t_game *game, int enemy_num, t_point pt)
{
	t_point	orig;

	orig = game->map->map[game->enemies.enemies[enemy_num].y]
	[game->enemies.enemies[enemy_num].x];
	if (orig.x > pt.x)
	{
		game->enemies.enemies[enemy_num].img_path = LEFT_ENEMY_1_TEX;
		game->enemies.enemies[enemy_num].img_num = 0;
		game->enemies.enemies[enemy_num].direction = ARROW_LEFT;
		game->enemies.enemies[enemy_num].x -= 1;
	}
	else if (orig.x < pt.x)
	{
		game->enemies.enemies[enemy_num].img_path = RIGHT_ENEMY_1_TEX;
		game->enemies.enemies[enemy_num].img_num = 0;
		game->enemies.enemies[enemy_num].direction = ARROW_RIGHT;
		game->enemies.enemies[enemy_num].x += 1;
	}
	else
		game->enemies.enemies[enemy_num].y
			+= (pt.y - game->enemies.enemies[enemy_num].y);
	render_sprite(game, game->enemies.enemies[enemy_num]);
	render_sprite(game, orig);
	if (enemy_hit(game))
		quit_game(game);
}
