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

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}