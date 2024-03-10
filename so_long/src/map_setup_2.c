#include <so_long.h>

t_point	create_point(int x, int y, char c)
{
	t_point ret;
	
	ret.x = x;
	ret.y = y;
	ret.c = c;
	return (ret);
}

size_t	ft_custom_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_map_rectangular(const char *file_name)
{
	char	*temp;
	int		fd;
	size_t	w;
	int		error;

	fd = open(file_name, O_RDONLY);
	w = 0;
	error = 0;
	temp = get_next_line(fd);
	while (temp != NULL && !error)
	{
		if (!w)
			w = ft_custom_strlen(temp);
		else if (ft_custom_strlen(temp) != w)
			error = 1;
		free(temp);
		temp = get_next_line(fd);
	}
	close (fd);
	return (error);
}

/// Check for exit / starting position duplicates in the map
/// Return values:
/// - 0 - exactly one exit and one starting position
///	- 1 - no exit on the map
/// - 2 - no starting position on the map
/// - 3 - multiple exits on the map
/// - 4 - multiple starting positions on the map
void	check_duplicates(t_map **orig)
{
	int		exits;
	int		positions;
	int		x;
	int		y;
	t_map	*map;

	exits = 0;
	positions = 0;
	y = -1;
	map = *orig;
	while (++y < map->map_dimensions->height)
	{
		x = 0;
		while (x < map->map_dimensions->width)
		{
			if (map->map[y][x].c == 'E')
				exits++;
			else if (map->map[y][x].c == 'P')
				positions++;
			x++;
		}
	}
	if (!exits)
		map->error_code = 1;
	if (!positions)
		map->error_code = 2;
	if (exits > 1)
		map->error_code = 3;
	if (positions > 1)
		map->error_code = 4;
	else
		map->error_code = 0;
}

int	check_surrounded_by_walls(t_game **orig)
{
	t_map	*map;
	int		x;
	int		y;

	map = (*orig)->map;
	y = 0;
	while (y < map->map_dimensions->height)
	{
		x = 0;
		while (x < map->map_dimensions->width)
		{
			if (!y || y == map->map_dimensions->height - 1)
			{
				if (map->map[y][x].c != '1')
					return (1);
			}
			else if (x == 0 || x == map->map_dimensions->width - 1)
			{
				if (map->map[y][x].c != '1')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}