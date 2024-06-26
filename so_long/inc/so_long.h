/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:24 by jnenczak          #+#    #+#             */
/*   Updated: 2024/04/19 15:32:31 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <get_next_line.h>
# include <libft.h>
# include <mlx.h>
# include <time.h>
# ifndef MAP_FILE_NAME
#  define MAP_FILE_NAME "assets/maps/map_correct.ber"
# endif
# define MAP_NO_EXIT 1
# define MAP_NO_STARTING_POSITION 2
# define MAP_MULTIPLE_EXITS 3
# define MAP_MULTIPLE_STARTING_POSITIONS 4
# define MAP_NOT_RECTANGULAR 5
# define MAP_NOT_SURROUNDED_BY_WALLS 6
# define MAP_NO_COLLECTIBLES 7
# define MAP_NO_PATH 8
# define POINT_NOT_AVAILABLE 9
# define POINT_AVAILABLE 10
# define AXIS_VERTICAL 0
# define AXIS_HORIZONTAL 1
# define DARK_MODE 0

// Map structure
# define MS_FREE '0'
# define MS_WALL '1'
# define MS_START 'P'
# define MS_EXIT 'E'
# define MS_PLAYER 'A'
# define MS_ENEMY 'B'
# define MS_COLLECTIBLE 'C'
// Wall textures
# define LEFT_WALL_TEX "assets/textures/chosen_64x64/leftmost_wall.xpm" 
# define RIGHT_WALL_TEX "assets/textures/chosen_64x64/rightmost_wall.xpm" 
# define TOP_WALL_TEX "assets/textures/chosen_64x64/top_wall.xpm" 
# define BOTTOM_WALL_TEX "assets/textures/chosen_64x64/top_wall.xpm" 

// Character sprite
# define LEFT_PLAYER_1_TEX "assets/textures/chosen_64x64/left_1.xpm"
# define LEFT_PLAYER_2_TEX "assets/textures/chosen_64x64/left_2.xpm"
# define LEFT_PLAYER_3_TEX "assets/textures/chosen_64x64/left_3.xpm"
# define LEFT_PLAYER_4_TEX "assets/textures/chosen_64x64/left_4.xpm"
# define RIGHT_PLAYER_1_TEX "assets/textures/chosen_64x64/right_1.xpm"
# define RIGHT_PLAYER_2_TEX "assets/textures/chosen_64x64/right_2.xpm"
# define RIGHT_PLAYER_3_TEX "assets/textures/chosen_64x64/right_3.xpm"
# define RIGHT_PLAYER_4_TEX "assets/textures/chosen_64x64/right_4.xpm"
# define PLAYER_SPRITES_NUM 4

// Enemy sprite
# define ENEMY_SPRITES_NUM 4
# define ENEMIES_COUNT 1
# define LEFT_ENEMY_1_TEX "assets/textures/chosen_64x64/enemy/left_1.xpm"
# define LEFT_ENEMY_2_TEX "assets/textures/chosen_64x64/enemy/left_2.xpm"
# define LEFT_ENEMY_3_TEX "assets/textures/chosen_64x64/enemy/left_3.xpm"
# define LEFT_ENEMY_4_TEX "assets/textures/chosen_64x64/enemy/left_4.xpm"
# define RIGHT_ENEMY_1_TEX "assets/textures/chosen_64x64/enemy/right_1.xpm"
# define RIGHT_ENEMY_2_TEX "assets/textures/chosen_64x64/enemy/right_2.xpm"
# define RIGHT_ENEMY_3_TEX "assets/textures/chosen_64x64/enemy/right_3.xpm"
# define RIGHT_ENEMY_4_TEX "assets/textures/chosen_64x64/enemy/right_4.xpm"

// Environment sprites
# define TORCH_TEX "assets/textures/chosen_64x64/torch.xpm"
# define COLLECTIBLE_TEX "assets/textures/chosen_64x64/collectible.xpm" 
# define EDGE_TEX "assets/textures/chosen_64x64/edge.xpm" 
# define FLOOR_TEX "assets/textures/chosen_64x64/floor.xpm" 
# define EXIT_TEX "assets/textures/chosen_64x64/exit.xpm" 
# define START_TEX "assets/textures/chosen_64x64/start.xpm" 

// Window size
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define WINDOW_TITLE "SO_LONG"

// Tile size
# define TILE_SIZE 64

// Input keys
# define ESC 65307
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

// Animations
# define PLAYER_ANIM_DELAY 9000
# define ENEMY_ANIM_DELAY 9000
# define ENEMY_MOVEMENT_DELAY 27000

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	col;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	char	c;
	char	*img_path;
	int		direction;
	int		img_num;
}	t_point;

typedef struct s_map_dim
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

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
}				t_mlx_vars;

typedef struct s_game_stats
{
	int			collectibles;
	int			collected;
	int			steps;
	int			drawn;
	int			frames;
}	t_game_stats;

typedef struct s_player
{
	t_point			location;
	char			*player_left_sprites[PLAYER_SPRITES_NUM];
	char			*player_right_sprites[PLAYER_SPRITES_NUM];
}	t_player;

typedef struct s_enemies
{
	int				enemies_count;
	t_point			*enemies;
	char			*enemy_left_sprites[ENEMY_SPRITES_NUM];
	char			*enemy_right_sprites[ENEMY_SPRITES_NUM];
}	t_enemies;

typedef struct s_game
{
	t_map			*map;
	t_mlx_vars		mlx_vars;
	t_game_stats	stats;
	t_player		player;
	t_enemies		enemies;
	int				running;
}	t_game;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_free_points
{
	t_point	*points;
	int		count;
}	t_free_points;

const char		*get_error_message(int code);
t_game			*start_game(const char *file_name);
t_map_dim		*get_map_dimensions(const char *file_name);
t_map			*create_allocate_t_map(t_map_dim *dim);
t_point			create_point(int x, int y, char c);
t_map			*fill_map(const char *file_name);
void			print_map(t_map	*map);
void			free_map(t_map *map);
int				check_duplicates(t_map *map);
void			count_collectibles(t_game *orig);
int				check_map_rectangular(const char *file_name);
void			free_game(t_game *game);
void			print_error(int code);
int				check_surrounded_by_walls(t_map *map);
void			free_map_points(t_map *map);
size_t			ft_custom_strlen(char *str);
int				check_path_exists(t_map *map);
int				flood_fill(t_map *map, t_point pt);
int				is_out_of_bounds(t_map *map, t_point pt);
void			print_point_info(t_point pt);
t_map			*duplicate_map(t_map *map);
int				path_exists(t_map *orig);
int				full_map_check(const char *file_name, t_map *map);
t_color			create_trgb(int t, int r, int g, int b);
int				determine_color(t_point pt);
void			move_player(t_game *game, int direction);
int				key_hook(int keycode, t_game *game);
int				move_valid(t_game *game, t_point pt);
void			draw_rectangle(void *mlx, void *win, t_point pt);
void			draw_board(t_game *game);
void			assign_sprites(t_map *map);
char			*determine_sprite(t_map *map, t_point pt);
void			render_sprite(t_game *game, t_point pt);
void			animate_player(t_game *game, t_point pt);
void			quit_game(t_game *game);
void			display_steps_count(t_game *game);
void			initialize_player(t_game *game);
void			initialize_enemies(t_game *game);
int				render_frame(t_game *game);
void			display_stroked_text(t_game *game, int tx, int ty, char *str);
int				game_won(t_game *game);
int				field_available(t_game *game, t_point pt);
void			place_enemies(t_game *game);
void			display_enemies(t_game *game);
int				random_num(int min, int max);
void			move_enemies(t_game *game);
void			move_enemies_2(t_game *game, int dir, int axis, int i);
void			animate_enemy(t_game *game, int enemy_num, t_point pt);
void			change_enemies_sprites(t_game *game);
t_free_points	*get_free_points(t_game *game);
int				count_free_points(t_game *game);
int				enemy_at_point(t_game *game, t_point pt);
int				point_cmp(t_point pt1, t_point pt2);
void			put_enemy(t_game *game, t_point pt);
int				enemy_hit(t_game *game);
void			initialize_game_stats(t_game *game);
int				determine_error(int exits, int positions);
t_point			get_shifted_point(int direction, t_point pt, t_map *map);
void			set_start_exit(t_map *map, t_point pt);
void			handle_linear_placement(t_free_points *free_pts, t_game *game);
#endif