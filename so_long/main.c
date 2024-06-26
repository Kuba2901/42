/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:38:23 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/07 13:19:13 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <X11/X.h>

t_game	*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;

	game = (t_game *)malloc(sizeof(t_game));
	game->enemies.enemies = NULL;
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
	game->player.location = create_point(map->start.x, map->start.y, 'A');
	initialize_player(game);
	initialize_enemies(game);
	initialize_game_stats(game);
	assign_sprites(game->map);
	return (game);
}

int	on_destroy(t_game *game)
{
	quit_game(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_map_dim	*dims;
	t_game		*game;

	if (ac != 2)
		return (0);
	srand(time(0));
	game = start_game(av[1]);
	if (game == NULL)
		return (0);
	dims = game->map->map_dimensions;
	game->mlx_vars.mlx = mlx_init();
	game->mlx_vars.win = mlx_new_window(game->mlx_vars.mlx,
			(TILE_SIZE * dims->width), (TILE_SIZE * dims->height)
			+ TILE_SIZE / 2, WINDOW_TITLE);
	draw_board(game);
	mlx_hook(game->mlx_vars.win, DestroyNotify,
		StructureNotifyMask, &on_destroy, game);
	mlx_key_hook(game->mlx_vars.win, key_hook, game);
	mlx_loop_hook(game->mlx_vars.mlx, render_frame, game);
	mlx_loop(game->mlx_vars.mlx);
	return (0);
}
