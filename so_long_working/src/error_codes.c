#include <so_long.h>

/// Function that returns on error message for the given error code.
/// Codes
/// - (1) - No exit on the map
/// - (2) - No starting position on the map
/// - (3) - Multiple exits on the map
/// - (4) - Multiple starting positions on the map
/// - (5) - The Map is not rectangular
const char	*get_error_message(int code)
{
	if (code == MAP_NO_EXIT)
		return "No exit on the map!";
	if (code == MAP_NO_STARTING_POSITION)
		return "No starting position on the map!";
	if (code == MAP_MULTIPLE_EXITS)
		return "Multiple exits on the map!";
	if (code == MAP_MULTIPLE_STARTING_POSITIONS)
		return "Multiple starting positions on the map!";
	if (code == MAP_NOT_RECTANGULAR)
		return "The Map is not rectangular!";
	if (code == MAP_NOT_SURROUNDED_BY_WALLS)
		return "The Map is not surrounded by walls!";
	if (code == MAP_NO_COLLECTIBLES)
		return "There are no collectibles on the map!";
	if (code == MAP_NO_PATH)
		return "Path doesn't exist!";
	return "Unknown error!";
}

void	print_error(int code)
{
	printf("%s\n", get_error_message(code)); // TODO: Change to ft_printf
}