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
	t_point	new_pos;
	int		axis;
	int		dir;

	i = -1;
	while (++i < game->enemies.enemies_count)
	{
			enemy = game->enemies.enemies[i];
			if (!random_num(0, 1))
				axis = AXIS_VERTICAL;
			else
				axis = AXIS_HORIZONTAL;
			dir = random_num(0, 1);
			if (!dir)
				dir--;
			if (axis == AXIS_VERTICAL)
			{
				new_pos = create_point(enemy.x, enemy.y + dir, game->map->map[enemy.y + dir][enemy.x].c);
				if (move_valid(game, new_pos))
				{
					game->enemies.enemies[i].y += dir;
					draw_board(game);
				}
			}
			else
			{
				new_pos = create_point(enemy.x + dir, enemy.y, game->map->map[enemy.y][enemy.x + dir].c);
				if (dir > 0 && move_valid(game, new_pos))
					animate_enemy(game, i, ARROW_RIGHT);
				else if (move_valid(game, new_pos))
					animate_enemy(game, i, ARROW_LEFT);
			}
	}
}

void	change_enemies_sprites(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies.enemies_count)
	{
		if (game->enemies.enemies[i].direction == ARROW_LEFT)
			game->enemies.enemies[i].img_path = game->enemies.enemy_left_sprites[++game->enemies.enemies[i].img_num % ENEMY_SPRITES_NUM];	
		else 
			game->enemies.enemies[i].img_path = game->enemies.enemy_right_sprites[++game->enemies.enemies[i].img_num % ENEMY_SPRITES_NUM];	
		render_sprite(game, game->enemies.enemies[i]);
	}
}

void	animate_enemy(t_game *game, int enemy_num, int direction)
{
	if (direction == ARROW_LEFT)
	{
		game->enemies.enemies[enemy_num].img_path = LEFT_ENEMY_1_TEX;
		game->enemies.enemies[enemy_num].img_num = 0;
		game->enemies.enemies[enemy_num].direction = ARROW_LEFT;
		game->enemies.enemies[enemy_num].x -= 1;
	}
	if (direction == ARROW_RIGHT)
	{
		game->enemies.enemies[enemy_num].img_path = RIGHT_ENEMY_1_TEX;
		game->enemies.enemies[enemy_num].img_num = 0;
		game->enemies.enemies[enemy_num].direction = ARROW_RIGHT;
		game->enemies.enemies[enemy_num].x += 1;
		// render_sprite(game, game->enemies.enemies[enemy_num]); // TODO: Test rendering only the moved enemy
	}
	draw_board(game);
}

void	animate_player(t_game *game, int direction)
{
	t_point	orig;

	orig = game->map->map[game->player.location.y][game->player.location.x];
	if (direction == ARROW_LEFT)
	{
		game->player.location.img_path = LEFT_PLAYER_1_TEX;
		game->player.location.img_num = 0;
		game->player.location.direction = ARROW_LEFT;
		game->player.location.x -= 1;
	}
	if (direction == ARROW_RIGHT)
	{
		game->player.location.img_path = RIGHT_PLAYER_1_TEX;
		game->player.location.img_num = 0;
		game->player.location.direction = ARROW_RIGHT;
		game->player.location.x += 1;
		
	}
	game->stats.steps += 1;
	render_sprite(game, game->player.location); // TODO: Test rendering only the player
	render_sprite(game, orig);
	// draw_board(game);
}

void sleep_ms(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}


int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0)
		return (0);
	if (nb == 2147483647)
		return (1);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	while (1)
	{
		nb++;
		if (ft_is_prime(nb))
			return (nb);
	}
}