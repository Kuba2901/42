/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:24 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/11 02:17:06 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <get_next_line.h>
#include <libft.h>
# define MAP_FILE_NAME "assets/map_test.ber"
# define MAP_NO_EXIT 1
# define MAP_NO_STARTING_POSITION 2
# define MAP_MULTIPLE_EXITS 3
# define MAP_MULTIPLE_STARTING_POSITIONS 4
# define MAP_NOT_RECTANGULAR 5
# define MAP_NOT_SURROUNDED_BY_WALLS 6
# define MAP_NO_COLLECTIBLES 7

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


const char	*get_error_message(int code);
t_game		*start_game(const char *file_name);
t_map_dim	*get_map_dimensions(const char *file_name);
t_map	*create_allocate_t_map(t_map_dim *dim);
t_point	create_point(int x, int y, char c);
t_map	*fill_map(const char *file_name);
void	print_map(t_map	*map);
void	free_map(t_map *map);
int	check_duplicates(t_map *map);
void	count_collectibles(t_game **orig);
int	check_map_rectangular(const char *file_name);
void	free_game(t_game *game);
void	print_error(int code);
int	check_surrounded_by_walls(t_map *map);
void	free_map_points(t_point **map, int h);
size_t	ft_custom_strlen(char *str);
#endif