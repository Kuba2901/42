#ifndef GAME_H
# define GAME_H

// Error codes and movement directions
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

typedef struct	s_game_stats
{
	int			collectibles;
	int			collected;
	int			steps;
	int			drawn;
	int			frames;
}	t_game_stats;

typedef struct	s_mlx_vars {
	void	*mlx;
	void	*win;
}				t_mlx_vars;

#include <map.h>
#include <characters.h>
typedef struct	s_game
{
	t_map			*map;
	t_mlx_vars		mlx_vars;
	t_game_stats	stats;
	t_player		player;
	t_enemies		enemies;
	int				running;
}	t_game;

t_game		*start_game(const char *file_name);
void		count_collectibles(t_game *orig);
int			key_hook(int keycode, t_game *game);
void		free_game(t_game *game);
void		print_error(int code);
void		quit_game(t_game *game);
int			game_won(t_game *game);

#endif 