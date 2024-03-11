#include "mlx.h"
#include <so_long.h>

t_game		*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;

	game = (t_game *)malloc(sizeof(t_game));
	map = fill_map(file_name);
	game->map = map;
	if (full_map_check(file_name, map))
	{
		free_game(game);
		return (NULL);
	}
	count_collectibles(game);
	if (!game->collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
		free_game(game);
		return (NULL);
	}
	game->player = create_point(map->start.x, map->start.y, 'A');
	game->running = 1;
	game->steps = 0;
	return (game);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void d_rect(t_image *img, int x, int y, int width, int height, int color) {
    int i, j;

    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            my_mlx_pixel_put(img, i, j, color);
        }
    }
}

int main() {
	t_mlx_vars	vars;
	t_map_dim	*dims;
	t_game		*game;
	// t_image		img;

	game = start_game(MAP_FILE_NAME);
	dims = game->map->map_dimensions;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, dims->width * TILE_SIZE,
		dims->height * TILE_SIZE, WINDOW_TITLE);
	game->mlx_vars = vars;
	// img.img = mlx_new_image(vars.mlx, dims->width * TILE_SIZE, dims->height * TILE_SIZE);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	
    // d_rect(&img, 100, 100, 200, 150, 0xFF0000);

	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	draw_board(game);
	mlx_key_hook(vars.win, key_hook, game);
	mlx_loop(vars.mlx);

	// CLEAR THE RESOURCES
	// mlx_destroy_image(vars.mlx, img.img);
    mlx_destroy_display(vars.mlx);
    free(vars.mlx);
	free_game(game);
    return (0);
}
