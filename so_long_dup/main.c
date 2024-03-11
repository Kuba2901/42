#include <libft.h>
#include <get_next_line.h>

int	main(void)
{
	const char	*file_name = "map.ber";
	int	fd = open(file_name, O_RDONLY);
	char	*temp;

	while ((temp = get_next_line(fd)) != NULL)
	{
		printf("%s", temp);
		free(temp);
	}
	close(fd);
	return (0);
}