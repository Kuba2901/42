#include <get_next_line.h>

int	main(void)
{
	const char	*file_name = "map.ber";
	char	*temp;
	int	fd = open(file_name, O_RDONLY);

	while ((temp = get_next_line(fd)))
	{
		printf("%s", temp);
		free(temp);
	}
	close (fd);
}