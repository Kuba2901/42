/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:25:28 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/20 16:26:01 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	count_collectibles(t_game *orig)
{
	t_point	*row;
	int		collectibles;
	int		y;
	int		x;
	t_map	*map;

	collectibles = 0;
	y = -1;
	map = orig->map;
	while (++y < map->map_dimensions->height)
	{
		x = 0;
		row = map->map[y];
		while (x < map->map_dimensions->width)
		{
			if (row[x].c == 'C')
				collectibles++;
			x++;
		}
	}
	orig->stats.collected = 0;
	orig->stats.collectibles = collectibles;
}

void	free_game(t_game *game)
{
	t_map	*map;

	map = game->map;
	free_map(map);
	free(game->enemies.enemies);
	free(game);
}

void	free_map(t_map *map)
{
	free_map_points(map);
	free(map->map);
	free(map->map_dimensions);
	free(map);
}

void	free_map_points(t_map *map)
{
	t_map_dim	*dims;
	int			y;

	dims = map->map_dimensions;
	y = -1;
	while (++y < dims->height)
		free(map->map[y]);
}

int	game_won(t_game *game)
{
	if (!(game->stats.collected == game->stats.collectibles))
	{
		printf("You have to collect all coins before finishing\n");
		return (0);
	}
	return (1);
}
