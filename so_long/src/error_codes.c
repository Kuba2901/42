/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:26 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/22 17:47:15 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

const char	*get_error_message(int code)
{
	if (code == MAP_NO_EXIT)
		return ("No exit on the map!");
	if (code == MAP_NO_STARTING_POSITION)
		return ("No starting position on the map!");
	if (code == MAP_MULTIPLE_EXITS)
		return ("Multiple exits on the map!");
	if (code == MAP_MULTIPLE_STARTING_POSITIONS)
		return ("Multiple starting positions on the map!");
	if (code == MAP_NOT_RECTANGULAR)
		return ("The Map is not rectangular!");
	if (code == MAP_NOT_SURROUNDED_BY_WALLS)
		return ("The Map is not surrounded by walls!");
	if (code == MAP_NO_COLLECTIBLES)
		return ("There are no collectibles on the map!");
	if (code == MAP_NO_PATH)
		return ("Path doesn't exist!");
	return ("Unknown error!");
}

// TODO: Test that this is working
void	print_error(int code)
{
	ft_printf("%s\n", get_error_message(code));
}
