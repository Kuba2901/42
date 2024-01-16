/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:20:50 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/16 14:15:51 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void ft_dec_to_hex(int n, int lower)
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

static void ft_print_pointer(void *ptr)
{
	uintptr_t address;
	int remainder;
	char buffer[20];
	int index;

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

static void ft_handle_num(char c, int num)
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

static void ft_print_data(const char *str, va_list args)
{
	char c;

	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
		if (!*str)
			break;
		str++;
		c = *str;
		if (c == '%')
			ft_putchar_fd('%', FT_STDOUT);
		else if (c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
			ft_handle_num(c, va_arg(args, int));
		else if (c == 's')
			ft_putstr_fd(va_arg(args, char *), FT_STDOUT);
		else if (c == 'p')
			ft_print_pointer(va_arg(args, void *));
		str++;
	}
	ft_putchar_fd('\0', FT_STDOUT);
}

int ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	ft_print_data(str, args);
	va_end(args);
	return (0);
}

#include <stdio.h>

int main(void)
{
	ft_printf("[*] CHAR\n");
	int num = printf("%d\n", 120);
	printf("%d\n", num);


	// ft_printf(" %c \n", '0');
	// printf(" %c \n", '0');

	// ft_printf(" %c\n", '0' - 256);
	// printf(" %c\n", '0' - 256);

	// ft_printf("%c \n", '0' + 256);
	// printf("%c \n", '0' + 256);

	// ft_printf(" %c %c %c \n", '0', 0, '1');
	// printf(" %c %c %c \n", '0', 0, '1');

	// ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	// printf(" %c %c %c \n", ' ', ' ', ' ');

	// ft_printf(" %c %c %c \n", '1', '2', '3');
	// printf(" %c %c %c \n", '1', '2', '3');

	// ft_printf(" %c %c %c \n", '2', '1', 0);
	// printf(" %c %c %c \n", '2', '1', 0);

	// ft_printf(" %c %c %c \n", 0, '1', '2');
	// printf(" %c %c %c \n", 0, '1', '2');

	// ft_printf("[*] STRING\n");
	// char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	// ft_printf("%s\n", "");
	// printf("%s\n", "");

	// ft_printf(" %s\n", "");
	// printf(" %s\n", "");

	// ft_printf("%s \n", "");
	// printf("%s \n", "");

	// ft_printf(" %s \n", "");
	// printf(" %s \n", "");

	// ft_printf(" %s \n", "-");
	// printf(" %s \n", "-");

	// ft_printf(" %s %s \n", "", "-");
	// printf(" %s %s \n", "", "-");

	// ft_printf(" %s %s \n", " - ", "");
	// printf(" %s %s \n", " - ", "");

	// ft_printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
	// printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);

	// ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	// printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");

	// ft_printf(" NULL %s NULL \n", NULL);
	// printf(" NULL %s NULL \n", NULL);

	return (0);
}