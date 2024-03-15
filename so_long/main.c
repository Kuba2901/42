#include "mlx.h"
#include <so_long.h>


void assign_player_sprites(t_game *game)
{
	game->player_left_sprites[0] = LEFT_PLAYER_1_TEX;
	game->player_left_sprites[1] = LEFT_PLAYER_2_TEX;
	game->player_left_sprites[2] = LEFT_PLAYER_3_TEX;
	game->player_left_sprites[3] = LEFT_PLAYER_4_TEX;
	game->player_right_sprites[0] = RIGHT_PLAYER_1_TEX;
	game->player_right_sprites[1] = RIGHT_PLAYER_2_TEX;
	game->player_right_sprites[2] = RIGHT_PLAYER_3_TEX;
	game->player_right_sprites[3] = RIGHT_PLAYER_4_TEX;
}

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
	if (!game->stats.collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
		free_game(game);
		return (NULL);
	}
	game->player = create_point(map->start.x, map->start.y, 'A');
	game->player.img_path = RIGHT_PLAYER_1_TEX;
	game->player.img_num = 0;
	game->player.direction = ARROW_RIGHT;
	game->running = 1;
	game->stats.steps = 0;
	game->stats.frames = 0;
	assign_sprites(game->map);
	assign_player_sprites(game);

	printf("Printing player sprites!\n");
	for (int i = 0; i < PLAYER_SPRITES_NUM; i++)
	{
		printf("Left (%d): (%s)\n", i, game->player_left_sprites[i]);
		printf("Right (%d): (%s)\n", i, game->player_right_sprites[i]);
	}
	
	return (game);
}

int	render_frame(t_game *game)
{
	if (game->stats.frames % PLAYER_ANIM_DELAY == 0)
	{
		if (game->player.direction == ARROW_LEFT)
			game->player.img_path = game->player_left_sprites[++game->player.img_num % PLAYER_SPRITES_NUM];	
		else 
			game->player.img_path = game->player_right_sprites[++game->player.img_num % PLAYER_SPRITES_NUM];
		custom_render_image(game, game->player);
	}
	game->stats.frames += 1;
	return (0);
}

int calculate_tile_size(t_map_dim *dims)
{
	int	x_tile;
	int	y_tile;

	x_tile = WINDOW_WIDTH / dims->width;
	y_tile = WINDOW_HEIGHT / dims->height;
	if (x_tile > y_tile)
		return (y_tile);
	else
		return (x_tile);
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

int main(int ac, char **av) {
	t_map_dim	*dims;
	t_game		*game;

	if (ac != 2)
		return (0);
	game = start_game(av[1]);
	dims = game->map->map_dimensions;
    game->mlx_vars.mlx = mlx_init();
    game->mlx_vars.win = mlx_new_window(game->mlx_vars.mlx,
		TILE_SIZE * dims->width, TILE_SIZE * dims->height, WINDOW_TITLE);
	game->stats.drawn = 0;
	draw_board(game);
	mlx_key_hook(game->mlx_vars.win, key_hook, game);
	mlx_loop_hook(game->mlx_vars.mlx, render_frame, game);
	mlx_loop(game->mlx_vars.mlx);

	// CLEAR THE RESOURCES
    mlx_destroy_display(game->mlx_vars.mlx);
    free(game->mlx_vars.mlx);
	free_game(game);
    return (0);
}
