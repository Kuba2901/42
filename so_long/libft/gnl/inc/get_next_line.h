/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   <get_next_line.h>                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:43:23 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/03/09 19:15:42 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_join_reassign(char *buffer, char *to_join);
char	*ft_get_line_from_buff(char *buff);
char	*ft_read_until_nl(int fd);
char	*get_next_line(int fd);

#endif
