/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:20:50 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/14 17:02:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdarg.h> 

static void	ft_dec_to_hex(int n, int lower)
{
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', FT_STDOUT);
	}
	else if (n < 16)
		ft_putchar_fd('A' + n - 10, FT_STDOUT);
	else
	{
		ft_dec_to_hex(n / 16, lower);
		ft_dec_to_hex(n % 16, lower);
	}
}

void	ft_print_pointer(void *ptr)
{
	uintptr_t	address;
	int			remainder;
	char		buffer[20];
	int			index;

	index = 0;
	address = (uintptr_t)ptr;
	while (address > 0)
	{
		remainder = address % 16;
		if (remainder < 10)
			buffer[index++] = '0' + remainder;
		else
			buffer[index++] = 'a' + remainder - 10;
		address /= 16;
	}
	buffer[index++] = 'x';
	buffer[index++] = '0';
	while (index > 0)
		ft_putchar_fd(buffer[--index], FT_STDOUT);
}



int	ft_printf(const char *str, ...)
{
	va_list			args;
	char			c;

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
			ft_dec_to_hex(va_arg(args, int), 0);
		else if (c == 'x')
			ft_dec_to_hex(va_arg(args, int), 1);
		else if (c == 'p')
			ft_print_pointer(va_arg(args, void *));
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
	char	*test = (char *)malloc(sizeof(char) * 16);
	printf("upper: %X and lower: %p\n", 12, test);
	ft_printf("upper: %X and lower: %p", 12, test);
	free(test);
	return (0);
}