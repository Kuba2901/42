#ifndef MAP_H
# define MAP_H

// Map structure
# define MS_FREE '0'
# define MS_WALL '1'
# define MS_START 'P'
# define MS_EXIT 'E'
# define MS_PLAYER 'A'
# define MS_ENEMY 'B'
# define MS_COLLECTIBLE 'C'

typedef struct	s_point
{
	int		x;
	int		y;
	char	c;
	char	*img_path;
	int		direction;
	int		img_num;
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
	t_point		start;
	t_point		end;
}	t_map;

typedef struct	s_free_points
{
	t_point	*points;
	int		count;
}	t_free_points;

const char		*get_error_message(int code);
t_map_dim		*get_map_dimensions(const char *file_name);
t_map			*create_allocate_t_map(t_map_dim *dim);
t_point			create_point(int x, int y, char c);
t_map			*fill_map(const char *file_name);
void			print_map(t_map	*map);
void			free_map(t_map *map);
int				check_duplicates(t_map *map);
int				check_map_rectangular(const char *file_name);
int				check_surrounded_by_walls(t_map *map);
void			free_map_points(t_map *map);
int				check_path_exists(t_map *map);
int				floodFill(t_map *map, t_point pt);
int				is_out_of_bounds(t_map *map, t_point pt);
void			print_point_info(t_point pt);
t_map			*duplicate_map(t_map *map);
int				full_map_check(const char *file_name, t_map *map);
int				path_exists(t_map *orig);
int				point_cmp(t_point pt1, t_point pt2);

#include <game.h>
int				move_valid(t_game *game, t_point pt);
int				field_available(t_game *game, t_point pt);
t_free_points	*get_free_points(t_game *game);
int				count_free_points(t_game *game);
int				enemy_at_point(t_game *game, t_point pt);
int				enemy_hit(t_game *game);
#endif