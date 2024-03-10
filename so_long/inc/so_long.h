/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:24 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/10 19:01:19 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <get_next_line.h>
#include <libft.h>
# define MAP_FILE_NAME "assets/map_test.ber"

typedef struct	s_point
{
	int		x;
	int		y;
	char	c;
}	t_point;

typedef struct	s_map_dim
{
	int	height;
	int	width;
}	t_map_dim;

typedef struct s_map
{
	t_point		**map;
	t_map_dim	*map_dimensions;
	int			error_code;
}	t_map;


typedef struct	s_game
{
	t_map		*map;
	int			collectibles;
	int			collected;
}	t_game;


t_game		*start_game(const char *file_name);
t_map_dim	*get_map_dimensions(const char *file_name);
t_map	*create_allocate_t_map(t_map_dim *dim);
t_point	create_point(int x, int y, char c);
t_map	*fill_map(const char *file_name);
void	print_map(t_map	*map);
void	free_map(t_map *map);
void	check_duplicates(t_map **orig);
void	count_collectibles(t_game **orig);
int	check_map_rectangular(const char *file_name);
void	free_game(t_game *game);
#endif