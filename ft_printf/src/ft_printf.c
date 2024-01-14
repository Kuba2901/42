/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:20:50 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/14 17:19:38 by jnenczak         ###   ########.fr       */
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

static void	ft_print_pointer(void *ptr)
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

static void	ft_handle_num(char c, int num)
{
	if (c == 'u')
	{
		num = (unsigned int)num;
		ft_putnbr_fd(num, FT_STDOUT);
	}
	else if (c == 'c')
		ft_putchar_fd(num, FT_STDOUT);
	else if (c == 'x' || c == 'X')
		ft_dec_to_hex(num, c == 'x');
	else
		ft_putnbr_fd(num, FT_STDOUT);
}

static void	ft_print_data(const char *str, va_list args)
{
	char			c;

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
		if (c == '%')
			ft_putchar_fd('%', FT_STDOUT);
		else if (c == 'c' || c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X')
			ft_handle_num(c, va_arg(args, int));
		else if (c == 's')
			ft_putstr_fd(va_arg(args, char *), FT_STDOUT);
		else if (c == 'p')
			ft_print_pointer(va_arg(args, void *));
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			args;

	va_start(args, str);
	ft_print_data(str, args);
	va_end(args);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test = (char *)malloc(sizeof(char) * 16);
// 	printf("upper: %c and lower: %p\n", 'A', test);
// 	ft_printf("upper: %c and lower: %p\n", 'A', test);
// 	free(test);
// 	return (0);
// }