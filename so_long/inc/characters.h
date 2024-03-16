#ifndef CHARACTERS_H
# define CHARACTERS_H

// Animations
# define PLAYER_ANIM_DELAY 9000
# define ENEMY_ANIM_DELAY 9000
# define ENEMY_MOVEMENT_DELAY 27000

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

#include <map.h>
struct s_point;
typedef struct	s_player
{
	struct s_point	location;
	char			*player_left_sprites[PLAYER_SPRITES_NUM];
	char			*player_right_sprites[PLAYER_SPRITES_NUM];
}	t_player;

typedef struct	s_enemies
{
	int				enemies_count;
	t_point			*enemies;
	char			*enemy_left_sprites[ENEMY_SPRITES_NUM];
	char			*enemy_right_sprites[ENEMY_SPRITES_NUM];
}	t_enemies;

void		move_player(t_game *game, int direction);
void		animate_player(t_game *game, t_point pt);
void		initialize_player(t_game *game);
void		initialize_enemies(t_game *game);
void		place_enemies(t_game *game);
void		move_enemies(t_game *game);
void		animate_enemy(t_game *game, int enemy_num, t_point pt);
void		change_enemies_sprites(t_game *game);
void		handle_enemy_movement(int axis, t_point enemy, t_game *game, int i);
void		put_enemy(t_game *game, t_point pt);
#endif