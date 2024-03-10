#include <so_long.h>

t_game		*start_game(const char *file_name)
{
	t_game	*game;
	t_map	*map;

	map = fill_map(file_name);
	game = (t_game *)malloc(sizeof(t_game));
	game->map = map;
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
	t_map	*map = game->map;
	printf("Collectibles count: %d\n", game->collectibles);
	printf("Printing map!\n");
	print_map(map);
	free_map(map);
	free(game);
	return (0);
}