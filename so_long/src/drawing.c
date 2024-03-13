#include <so_long.h>

void	draw_rectangle(void *mlx, void *win, t_point pt)
{
	int	x;
	int	y;
    int	color;

	color = create_trgb(255, 61, 37, 59).col;
	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
		{
			mlx_pixel_put(mlx, win, pt.x * TILE_SIZE + x, pt.y * TILE_SIZE + y,
				color);
		}
	}
}

void draw_board(t_game *game) {
    int		x;
	int		y;
	t_map	*map;
	t_point	pt;

	map = game->map;
	for (y = 0; y < map->map_dimensions->height; y++) {
        for (x = 0; x < map->map_dimensions->width; x++) {
			pt = map->map[y][x];
			if (!game->game_stats.drawn)
				draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, pt);
			custom_render_image(game, pt);
		}
    }
	custom_render_image(game, game->player.player);
	y = game->map->map_dimensions->height;
	x = -1;
	while (++x < game->map->map_dimensions->width)
		draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, create_point(x, y, '1'));
	print_steps_count(game);
	if (!game->game_stats.drawn)
		game->game_stats.drawn = 1;
}

void	custom_render_image(t_game *game, t_point pt)
{
	int 	width;
	int 	height;
	void	*img;

	if (pt.img_path != NULL)
	{
		height = TILE_SIZE;
		width = TILE_SIZE;
		img = mlx_xpm_file_to_image(game->mlx_vars.mlx, pt.img_path, &width, &height);
		mlx_put_image_to_window(game->mlx_vars.mlx, game->mlx_vars.win, img, pt.x * TILE_SIZE, pt.y * TILE_SIZE);
		mlx_destroy_image(game->mlx_vars.mlx, img);
	}
}

void	assign_sprites(t_map *map)
{
	int		x;
	int		y;
	int		w;
	int		h;
	t_point pt;

	w = map->map_dimensions->width;
	h = map->map_dimensions->height;
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			pt = map->map[y][x];
			map->map[y][x].img_path = get_sprite(map, pt);
		}
	}
}

char	*get_sprite(t_map *map, t_point pt)
{
	if (pt.x == 0)
		return (LEFT_WALL_TEX);
	if (pt.x == map->map_dimensions->width - 1)
		return (RIGHT_WALL_TEX);
	if (pt.y == 0)
	{
		if (!(pt.x % 3))
			return (TORCH_TEX);
		return (TOP_WALL_TEX);
	}
	if (pt.y == map->map_dimensions->height - 1)
		return (BOTTOM_WALL_TEX);
	if (pt.c == '0')
		return (FLOOR_TEX);
	if (pt.c == 'C')
		return (COLLECTIBLE_TEX);
	if (pt.c == 'E')
		return (EXIT_TEX);
	if (pt.c == '1')
		return (TOP_WALL_TEX);
	if (pt.c == 'P')
		return (START_TEX);
	return (EDGE_TEX);
}

void	change_player_direction(t_game *game, int direction)
{
	if (direction == ARROW_LEFT)
	{
		game->player.player.img_path = LEFT_PLAYER_1_TEX;
		game->player.player.img_num = 0;
		game->player.player.direction = ARROW_LEFT;
	}
	if (direction == ARROW_RIGHT)
	{
		game->player.player.img_path = RIGHT_PLAYER_1_TEX;
		game->player.player.img_num = 0;
		game->player.player.direction = ARROW_RIGHT;
	}
}

void print_steps_count(t_game *game)
{
	char	*steps;
	char	*steps_info;
	int		tx;
	int		ty;

	ty = (game->map->map_dimensions->height + 1) * TILE_SIZE - (TILE_SIZE / 2); // Window decorations issue
	tx = game->map->map_dimensions->width * TILE_SIZE / 2;
	steps_info = ft_strdup("STEPS: ");
	steps = ft_itoa(game->game_stats.steps);
	steps_info = ft_join_reassign(steps_info, steps);
	display_stroked_text(game, tx, ty, steps_info);
	free(steps_info);
}

int	render_frame(t_game *game)
{
	if (game->game_stats.frames % PLAYER_ANIM_DELAY == 0)
	{
		if (game->player.player.direction == ARROW_LEFT)
		{
			game->player.player.img_path = game->player.player_left_sprites[
				++game->player.player.img_num % PLAYER_SPRITES_NUM
			];	
		}
		else 
			game->player.player.img_path = game->player.player_right_sprites[
				++game->player.player.img_num % PLAYER_SPRITES_NUM
			];
		custom_render_image(game, game->player.player);
	}
	game->game_stats.frames += 1;
	return (0);
}

void	display_stroked_text(t_game *game, int tx, int ty, char *str)
{
	int	color;

	color = create_trgb(255, 255, 255, 255).col;
	mlx_string_put(game->mlx_vars.mlx, game->mlx_vars.win,
		tx + 1, ty, color, str);
	mlx_string_put(game->mlx_vars.mlx, game->mlx_vars.win,
		tx, ty + 1, color, str);
}