#ifndef GRAPHICS_H
# define GRAPHICS_H
#include <map.h>
#include <game.h>

// Wall textures
# define LEFT_WALL_TEX "assets/textures/chosen_64x64/leftmost_wall.xpm" 
# define RIGHT_WALL_TEX "assets/textures/chosen_64x64/rightmost_wall.xpm" 
# define TOP_WALL_TEX "assets/textures/chosen_64x64/top_wall.xpm" 
# define BOTTOM_WALL_TEX "assets/textures/chosen_64x64/top_wall.xpm" 

// Environment sprites
# define TORCH_TEX "assets/textures/chosen_64x64/torch.xpm"
# define COLLECTIBLE_TEX "assets/textures/chosen_64x64/collectible.xpm" 
# define EDGE_TEX "assets/textures/chosen_64x64/edge.xpm" 
# define FLOOR_TEX "assets/textures/chosen_64x64/floor.xpm" 
# define EXIT_TEX "assets/textures/chosen_64x64/exit.xpm" 
# define START_TEX "assets/textures/chosen_64x64/start.xpm" 

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	col;
}	t_color;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

t_color		create_trgb(int t, int r, int g, int b);
int			determine_color(t_point pt);
void		draw_board(t_game *game);
void		draw_rectangle(void *mlx, void *win, t_point pt);
void		assign_sprites(t_map *map);
char		*determine_sprite(t_map *map, t_point pt);
void		render_sprite(t_game *game, t_point pt);
void 		display_steps_count(t_game *game);
int			render_frame(t_game *game);
void		display_stroked_text(t_game *game, int tx, int ty, char *str);
void		display_enemies(t_game *game);
void		display_information(t_game *game, char *info);
#endif