/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:07:56 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:23:26 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	draw_board(t_game *game)
{
	int		x;
	int		y;
	t_map	*map;
	t_point	pt;

	map = game->map;
	y = -1;
	while (++y < map->map_dimensions->height)
	{
		x = -1;
		while (++x < map->map_dimensions->width)
		{
			pt = map->map[y][x];
			if (!game->stats.drawn)
				draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win, pt);
			render_sprite(game, pt);
		}
	}
	render_sprite(game, game->player.location);
	display_enemies(game);
	display_steps_count(game);
	if (!game->stats.drawn)
		game->stats.drawn = 1;
}

void	render_sprite(t_game *game, t_point pt)
{
	int		width;
	int		height;
	void	*img;

	if (pt.img_path != NULL)
	{
		height = TILE_SIZE;
		width = TILE_SIZE;
		img = mlx_xpm_file_to_image(game->mlx_vars.mlx, pt.img_path, &width,
				&height);
		mlx_put_image_to_window(game->mlx_vars.mlx, game->mlx_vars.win, img,
			pt.x * TILE_SIZE, pt.y * TILE_SIZE);
		mlx_destroy_image(game->mlx_vars.mlx, img);
	}
}

void	assign_sprites(t_map *map)
{
	int		x;
	int		y;
	int		w;
	int		h;
	t_point	pt;

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

void	display_steps_count(t_game *game)
{
	char	*steps;
	char	*steps_info;
	int		tx;
	int		ty;
	int		i;

	ty = game->map->map_dimensions->height * TILE_SIZE + TILE_SIZE / 4;
	tx = game->map->map_dimensions->width * TILE_SIZE / 2;
	i = -1;
	while (++i < game->map->map_dimensions->width)
		draw_rectangle(game->mlx_vars.mlx, game->mlx_vars.win,
			create_point(i, game->map->map_dimensions->height, '0'));
	steps_info = ft_strdup("STEPS: ");
	steps = ft_itoa(game->stats.steps);
	steps_info = ft_join_reassign(steps_info, steps);
	display_stroked_text(game, tx, ty, steps_info);
	free(steps_info);
}
