/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:20:50 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/14 16:18:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdarg.h> 

static void	ft_dec_to_hex(int n, int lower)
{
	char	a;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n <= 9)
	{
		a = n + 48;
		ft_putchar_fd(a, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}


int	ft_printf(const char *str, ...)
{
	va_list			args;
	char			c;
	unsigned int	i;

	va_start(args, str);

	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
		if (!*str)
			break ;
		str++;
		c = *str;
		if (c == 'c')
			ft_putchar_fd(va_arg(args, int), FT_STDOUT);
		else if (c == 's')
			ft_putstr_fd(va_arg(args, char *), FT_STDOUT);
		else if (c == 'd' || c == 'i')
			ft_putnbr_fd(va_arg(args, int), FT_STDOUT);
		else if (c == 'u')
			ft_putnbr_fd((unsigned int)va_arg(args, int), FT_STDOUT);
		else if (c == '%')
			ft_putchar_fd('%', FT_STDOUT);
		else if (c == 'X')
			decimalToHexadecimal(va_arg(args, int), 0);
		else if (c == 'x')
			decimalToHexadecimal(va_arg(args, int), 1);
		str++;
	}
	/*
		%c: Character
		%s: String
		%p: Pointer
		%d, %i: Signed decimal integer
		%u: Unsigned decimal integer
		%x, %X: Hexadecimal integer
		%%: Percent sign (literal)
	*/

	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("upper: %X and lower: %x", 12, 20);
	return (0);
}