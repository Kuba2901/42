#include <so_long.h>

t_color	create_trgb(int t, int r, int g, int b)
{
	t_color ret;
	ret.t = t;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret.col = (t << 24 | r << 16 | g << 8 | b);
	return (ret);
}

int	determine_color(t_point pt)
{
	if (pt.c == '0')
		return create_trgb(255,0,0,0).col;
	if (pt.c == '1')
		return create_trgb(255,255,255,255).col;
	if (pt.c == 'C')
		return create_trgb(255,0,255,0).col;
	if (pt.c == 'E')
		return create_trgb(255,255,0,0).col;
	if (pt.c == 'A')
		return create_trgb(255,255,0,255).col;
	return create_trgb(255,0,0,255).col;
}

char	*determine_sprite(t_map *map, t_point pt)
{
	if (pt.x == 0)
		return (LEFT_WALL_TEX);
	if (pt.x == map->map_dimensions->width - 1)
		return (RIGHT_WALL_TEX);
	if (pt.y == 0)
	{
		if (!(pt.x % 3))
			return (TORCH_TEX);
		return (TOP_WALL_TEX);
	}
	if (pt.y == map->map_dimensions->height - 1)
		return (BOTTOM_WALL_TEX);
	if (pt.c == '0')
		return (FLOOR_TEX);
	if (pt.c == 'C')
		return (COLLECTIBLE_TEX);
	if (pt.c == 'E')
		return (EXIT_TEX);
	if (pt.c == '1')
		return (TOP_WALL_TEX);
	if (pt.c == 'P')
		return (START_TEX);
	return (EDGE_TEX);
}
