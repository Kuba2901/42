#include <so_long.h>

t_game		*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;
	int		map_surrounded;

	game = (t_game *)malloc(sizeof(t_game));
	map = fill_map(file_name);
	map->error_code = check_duplicates(map);
	game->map = map;
	if (map->error_code)
	{
		print_error(map->error_code);
		free_game(game);
		return (NULL);
	}
	count_collectibles(&game);
	if (!game->collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
		free_game(game);
		return (NULL);
	}
	map_surrounded = check_surrounded_by_walls(game->map);
	if (map_surrounded)
	{
		print_error(MAP_NOT_SURROUNDED_BY_WALLS);
		free_game(game);
		return (NULL);
	}
	return (game);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	const char	*file_name = av[1];
	int	map_rectangular = check_map_rectangular(file_name);
	if (map_rectangular)
	{
		print_error(map_rectangular);
		return (0);
	}
	t_game	*game = start_game(file_name);
	if (game == NULL)
		return (0);
	t_map	*map = game->map;
	print_map(map);
	free_game(game);
	return (0);
}