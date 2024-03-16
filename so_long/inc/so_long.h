/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:24 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/16 21:31:45 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <get_next_line.h>
#include <libft.h>
#include <mlx.h>
#include <time.h>
#include <game.h>

// Input keys
# define ESC 65307
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364

# define WINDOW_TITLE "SO_LONG"
# define TILE_SIZE 64

size_t		ft_custom_strlen(char *str);
int			random_num(int min, int max);
#endif