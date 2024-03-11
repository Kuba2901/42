/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:24 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/11 22:41:40 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <get_next_line.h>
#include <libft.h>
#include <mlx.h>
# define MAP_FILE_NAME "assets/map_correct.ber"
# define MAP_NO_EXIT 1
# define MAP_NO_STARTING_POSITION 2
# define MAP_MULTIPLE_EXITS 3
# define MAP_MULTIPLE_STARTING_POSITIONS 4
# define MAP_NOT_RECTANGULAR 5
# define MAP_NOT_SURROUNDED_BY_WALLS 6
# define MAP_NO_COLLECTIBLES 7
# define MAP_NO_PATH 8

// Character sprite
# define CHARACTER_PATH "assets/textures/characters_tiles"
# define CHARACTER_1 "assets/textures/characters_tiles/tile025.png"
# define CHARACTER_2 "assets/textures/characters_tiles/tile026.png"
# define CHARACTER_3 "assets/textures/characters_tiles/tile027.png"

// Window size
# define WINDOW_HEIGHT 400
# define WINDOW_WIDTH 600
# define WINDOW_TITLE "SO_LONG"

// Tile size
# define TILE_SIZE 50
# define X_TILES (WINDOW_WIDTH / TILE_SIZE)
# define Y_TILES (WINDOW_HEIGHT / TILE_SIZE)

// Input keys
# define ESC 65307
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	col;
}	t_color;


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
	t_point		start;
	t_point		end;
}	t_map;

typedef struct	s_mlx_vars {
	void	*mlx;
	void	*win;
}				t_mlx_vars;

typedef struct	s_game
{
	t_map		*map;
	int			collectibles;
	int			collected;
	t_point		player;
	t_mlx_vars	mlx_vars;
	int			running;
	int			steps;
}	t_game;


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

const char	*get_error_message(int code);
t_game		*start_game(const char *file_name);
t_map_dim	*get_map_dimensions(const char *file_name);
t_map		*create_allocate_t_map(t_map_dim *dim);
t_point		create_point(int x, int y, char c);
t_map		*fill_map(const char *file_name);
void		print_map(t_map	*map);
void		free_map(t_map *map);
int			check_duplicates(t_map *map);
void		count_collectibles(t_game *orig);
int			check_map_rectangular(const char *file_name);
void		free_game(t_game *game);
void		print_error(int code);
int			check_surrounded_by_walls(t_map *map);
void		free_map_points(t_point **map, int h);
size_t		ft_custom_strlen(char *str);
int			check_path_exists(t_map *map);
int			floodFill(t_map *map, t_point pt);
int			is_out_of_bounds(t_map *map, t_point pt);
void		print_point_info(t_point pt);
t_map		*duplicate_map(t_map *map);
int			path_exists(t_map *orig);
int			full_map_check(const char *file_name, t_map *map);
t_color		create_trgb(int t, int r, int g, int b);
int			determine_color(t_point pt);
void		move_player(t_game *game, int x, int y);
int			key_hook(int keycode, t_game *game);
void		move_player(t_game *game, int x, int y);
int			move_valid(t_map *map, t_point pt);
void		draw_rectangle(void *mlx, void *win, t_point pt);
void		draw_board(t_game *game);
#endif