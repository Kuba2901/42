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