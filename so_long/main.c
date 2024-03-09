/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:35:29 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/09 23:51:47 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <get_next_line.h>
#include <ft_printf.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) {
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

int	count_lines(const char *file_name)
{
	char	*ret;
	char	*temp;
	int		fd;
	int		count;

	fd = open(file_name, O_RDONLY);
	count = 0;
	while ((temp = get_next_line(fd)) != NULL)
	{
		count++;
		free(temp);
	}
	close(fd);
	return (count);
}

char	**duplicate_map(const char *file_name)
{
	char	**ret;
	char	*temp;
	int		fd;
	int		lines_count;
	int		i;
	
	lines_count = count_lines(file_name);
	ret = (char **)malloc(sizeof(char *) * (lines_count + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while ((temp = get_next_line(fd)) != NULL)
	{
		ret[i++] = ft_strdup(temp);
		free(temp);
	}
	ret[i] = NULL;
	return (ret);
}

void	print_map(char **map) {
	while (*map != NULL)
		ft_printf("%s", *map++);
}

int main(void)
{
	const char	*map_name = "map.ber";
	char	**map = duplicate_map(map_name);
	print_map(map);
	free_map(map);
    // void    *mlx;
    // void    *mlx_window;
    // t_data	img;

    // mlx = mlx_init();
	// mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	// mlx_loop(mlx);
}