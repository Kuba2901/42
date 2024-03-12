#include <so_long.h>
#include <time.h>

void sleep_ms(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

void	draw_rectangle(void *mlx, void *win, t_point pt)
{
	int	x;
	int	y;
    
	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
		{
			mlx_pixel_put(mlx, win, pt.x * TILE_SIZE + x, pt.y * TILE_SIZE + y,
				create_trgb(255, 255, 255, 255).col);
		}
	}
}

void draw_board(t_game *game) {
    int		x;
	int		y;
	t_map	*map;
	t_point	pt;

	map = game->map;
	// mlx_clear_window(game->mlx_vars.mlx, game->mlx_vars.win);
	for (y = 0; y < map->map_dimensions->height; y++) {
        for (x = 0; x < map->map_dimensions->width; x++) {
			pt = map->map[y][x];
			if (!game->drawn)
				draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, pt);
			custom_render_image(game, pt);
		}
    }
	custom_render_image(game, game->player);
	if (!game->drawn)
		game->drawn = 1;
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

void	animate_player(t_game *game, int direction)
{
	if (direction == ARROW_LEFT)
		game->player.img_path = LEFT_PLAYER_1_TEX;
	if (direction == ARROW_RIGHT)
		game->player.img_path = RIGHT_PLAYER_1_TEX;
}