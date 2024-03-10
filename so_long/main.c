#include <so_long.h>

t_game		*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;

	game = (t_game *)malloc(sizeof(t_game));
	map = fill_map(file_name);
	game->map = map;
	check_duplicates(&map);
	if (map->error_code)
	{
		printf("Something duplicated: %d\n", map->error_code);
		free_game(game);
		return (NULL);
	}
	count_collectibles(&game);
	return (game);
}

int	main(void)
{
	const char	*file_name = MAP_FILE_NAME;
	if (check_map_rectangular(file_name))
	{
		printf("Error in map shape");
		return (0);
	}
	t_game	*game = start_game(file_name);
	if (game == NULL)
		return (0);
	t_map	*map = game->map;
	printf("Collectibles count: %d\n", game->collectibles);
	printf("Printing map!\n");
	print_map(map);
	free_game(game);
	return (0);
}