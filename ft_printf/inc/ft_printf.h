/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:20:42 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/16 18:55:49 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_dec_to_hex(unsigned int n, int lower, int *counter);
void	ft_print_pointer(void *ptr, int *counter, int index);
void	ft_handle_num(char c, int num, int *counter);
int		ft_get_num_size(int num, int is_unsigned);
void	ft_handle_string(char *temp, int *counter);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *counter);

#endif