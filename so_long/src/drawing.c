#include <so_long.h>

void	draw_rectangle(void *mlx, void *win, t_map_dim *dims, t_point pt)
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
			if (!game->stats.drawn)
				draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, game->map->map_dimensions, pt);
			render_sprite(game, pt);
		}
    }
	render_sprite(game, game->player.location);
	display_steps_count(game);
	display_enemies(game);
	if (!game->stats.drawn)
		game->stats.drawn = 1;
}

void	render_sprite(t_game *game, t_point pt)
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
			map->map[y][x].img_path = determine_sprite(map, pt);
		}
	}
}


void display_steps_count(t_game *game)
{
	char	*steps;
	char	*steps_info;
	int		tx;
	int		ty;

	ty = game->map->map_dimensions->height * TILE_SIZE - (TILE_SIZE / 2); // Window decorations issue
	tx = game->map->map_dimensions->width * TILE_SIZE / 2;
	steps_info = ft_strdup("STEPS: ");
	steps = ft_itoa(game->stats.steps);
	steps_info = ft_join_reassign(steps_info, steps);
	display_stroked_text(game, tx, ty, steps_info);
	free(steps_info);
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


int	render_frame(t_game *game)
{
	if (game->stats.frames % PLAYER_ANIM_DELAY == 0)
	{
		if (game->player.location.direction == ARROW_LEFT)
			game->player.location.img_path = game->player.player_left_sprites[++game->player.location.img_num % PLAYER_SPRITES_NUM];	
		else 
			game->player.location.img_path = game->player.player_right_sprites[++game->player.location.img_num % PLAYER_SPRITES_NUM];
		render_sprite(game, game->player.location);
	}
	// display_enemies(game);
	game->stats.frames += 1;
	return (0);
}