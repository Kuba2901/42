#include <so_long.h>

void	draw_rectangle(void *mlx, void *win, t_point pt)
{
	int	i;
	int	j;
    
	for (i = 0; i < TILE_SIZE; i++) {
        for (j = 0; j < TILE_SIZE; j++) {
            mlx_pixel_put(mlx, win, pt.x * TILE_SIZE + i, pt.y * TILE_SIZE + j, determine_color(pt));
        }
    }
}

void draw_board(t_game *game) {
    int		x;
	int		y;
	t_map	*map;

	map = game->map;
	mlx_clear_window(game->mlx_vars.mlx, game->mlx_vars.win);
	for (y = 0; y < map->map_dimensions->height; y++) {
        for (x = 0; x < map->map_dimensions->width; x++) {
            draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, map->map[y][x]);
        }
    }
	draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, game->player);
}

