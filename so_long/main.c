// #include <so_long.h>

// t_game		*start_game(const char *file_name)
// {
// 	t_game	*game;
// 	t_map	*map;

// 	game = (t_game *)malloc(sizeof(t_game));
// 	map = fill_map(file_name);
// 	game->map = map;
// 	if (full_map_check(file_name, map))
// 	{
// 		free_game(game);
// 		return (NULL);
// 	}
// 	count_collectibles(game);
// 	if (!game->collectibles)
// 	{
// 		print_error(MAP_NO_COLLECTIBLES);
// 		free_game(game);
// 		return (NULL);
// 	}
// 	return (game);
// }

// void	draw_rectangle(void *mlx, void *win, int x, int y, int color) {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT / TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH / TILE_SIZE)
// 		{
// 			mlx_pixel_put(mlx, win, j + x, i + y, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	color_map_1(void *mlx, void *win)
// {
// 	int	even_color;
// 	int	uneven_color;

// 	even_color = create_trgb(255, 255, 0, 0).col;
// 	uneven_color = create_trgb(255, 0, 255, 0).col;
	
// 	for (int y = 0; y < WINDOW_HEIGHT / TILE_SIZE; y++)
// 	{
// 		for (int x = 0; x < WINDOW_WIDTH / TILE_SIZE; x++)
// 		{
// 			draw_rectangle(mlx, win, x * TILE_SIZE, y * TILE_SIZE, even_color);
// 			// if ((x + y) % 2 != 0)
// 			// 	draw_rectangle(mlx, win, x * TILE_SIZE, y * TILE_SIZE, even_color);
// 			// else
// 			// 	draw_rectangle(mlx, win, x * TILE_SIZE, y * TILE_SIZE, uneven_color);
// 			printf("(%d,%d)", x, y);
// 		}
// 		printf("\n");
// 	}
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
// 	color_map_1(mlx, mlx_win);
// 	mlx_loop(mlx);
// }

#include "mlx.h"
#include <so_long.h>

#define SQUARE_SIZE 50
#define BOARD_SIZE 8

void	draw_rectangle(void *mlx, void *win, t_point pt, int color)
{
	int	i;
	int	j;
    
	for (i = 0; i < TILE_SIZE; i++) {
        for (j = 0; j < TILE_SIZE; j++) {
            mlx_pixel_put(mlx, win, pt.x * SQUARE_SIZE + i, pt.y * SQUARE_SIZE + j, color);
        }
    }
}

void draw_board(void *mlx_ptr, void *win_ptr) {
    int x, y;
    int color = create_trgb(255, 0, 0, 0).col; // white color

    for (y = 0; y < Y_TILES; y++) {
        for (x = 0; x < X_TILES; x++) {
            if ((x + y) % 2 == 0)
                color = 0x000000; // black color
            else
                color = 0xFFFFFF; // white color

            draw_rectangle(mlx_ptr, win_ptr, create_point(x, y, 'L'), color);
        }
    }
}

int main() {
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Checkers Board");

    draw_board(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}
