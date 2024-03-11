#include <so_long.h>

t_game		*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;

	game = (t_game *)malloc(sizeof(t_game));
	map = fill_map(file_name);
	game->map = map;
	if (full_map_check(file_name, map))
	{
		free_game(game);
		return (NULL);
	}
	count_collectibles(game);
	if (!game->collectibles)
	{
		print_error(MAP_NO_COLLECTIBLES);
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
	printf("All good!\n");
	print_map(game->map);
	printf("\n\n");
	free_game(game);
	return (0);
}