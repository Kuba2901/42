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
	t_point	enemy;
	int		axis;

	i = -1;
	while (++i < game->enemies.enemies_count)
	{
			enemy = game->enemies.enemies[i];
			if (!random_num(0, 1))
				axis = AXIS_VERTICAL;
			else
				axis = AXIS_HORIZONTAL;
			handle_enemy_movement(axis, enemy, game, i);
	}
}

void	handle_enemy_movement(int axis, t_point enemy, t_game *game, int i)
{
	t_point	new_pos;
	int		dir;

	dir = random_num(0, 1);
	if (!dir)
		dir--;
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
			game->enemies.enemies[i].img_path =
				game->enemies.enemy_left_sprites[
						++game->enemies.enemies[i].img_num % ENEMY_SPRITES_NUM];
		else 
			game->enemies.enemies[i].img_path =
				game->enemies.enemy_right_sprites[
						++game->enemies.enemies[i].img_num % ENEMY_SPRITES_NUM];	
		render_sprite(game, game->enemies.enemies[i]);
	}
}

void	animate_enemy(t_game *game, int enemy_num, t_point pt)
{
	t_point	orig;

	orig = game->map->map[game->enemies.enemies
		[enemy_num].y][game->enemies.enemies[enemy_num].x];
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