#include "libft.h"
#include <stdarg.h>

static void ft_dec_to_hex(int n, int lower, int *counter)
{
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', FT_STDOUT);
		*counter += 1;
	}
	else if (n < 16)
	{
		ft_putchar_fd('A' + n - 10, FT_STDOUT);
		*counter += 1;
	}
	else
	{
		ft_dec_to_hex(n / 16, lower, counter);
		ft_dec_to_hex(n % 16, lower, counter);
	}
}

static void ft_print_pointer(void *ptr, int *counter)
{
	uintptr_t	address;
	int			remainder;
	char		buffer[20];
	int			index;

	if (ptr == NULL)
	{
		ft_putstr_fd("0x0", FT_STDOUT);
		*counter += 3;
		return ;	
	}
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
	{
		ft_putchar_fd(buffer[--index], FT_STDOUT);
		*counter += 1;
	}
}

static int	ft_get_num_size(int num, int is_unsigned)
{
	int	size;

	size = 0;
	if (!num)
		return (1);
	if (is_unsigned)
		num = (unsigned int)num;
	if (num < 0)
	{
		size++;
		num *= -1;
	}
	while (num)
	{
		size++;
		num /= 10;
	}
	return (size);
}


static void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *counter)
{
	char	a;

	if (n <= 9)
	{
		a = n + 48;
		ft_putchar_fd(a, fd);
		*counter += 1;
	}
	else
	{
		ft_putnbr_unsigned_fd(n / 10, fd, counter);
		ft_putnbr_unsigned_fd(n % 10, fd, counter);
	}
}

#include <stdio.h>

static void ft_handle_num(char c, int num, int *counter)
{
	unsigned int	converted;

	if (c == 'u')
	{
		converted = (unsigned int)num;
		ft_putnbr_unsigned_fd(converted, FT_STDOUT, counter);
	}
	else if (c == 'c')
	{
		ft_putchar_fd(num, FT_STDOUT);
		*counter += 1;
	}
	else if (c == 'x' || c == 'X')
		ft_dec_to_hex(num, c == 'x', counter);
	else
	{
		ft_putnbr_fd(num, FT_STDOUT);
		*counter += ft_get_num_size(num, 0);
	}
}


int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	c;
	int		counter;
	char	*temp;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar_fd(*str, 1);
			str++;
			counter++;
		}
		if (!*str)
			break ;
		str++;
		c = *str;
		if (c == '%')
		{
			ft_putchar_fd('%', FT_STDOUT);
			counter++;
		}
		else if (c == 'c' || c == 'd' || c == 'i' \
			|| c == 'u' || c == 'x' || c == 'X')
		{
			ft_handle_num(c, va_arg(args, int), &counter);
		}
		else if (c == 's')
		{
			temp = va_arg(args, char *);
			if (!(temp == NULL))
			{
				counter += ft_strlen(temp);
				ft_putstr_fd(temp, FT_STDOUT);
			}
			else
			{
				ft_putstr_fd("(null)", FT_STDOUT);
				counter += 6;
			}
		}
		else if (c == 'p')
			ft_print_pointer(va_arg(args, void *), &counter);
		str++;
	}
	va_end(args);
	return (counter);
}

// int main(void)
// {
// 	printf("STANDARD\n");
// 	int num = printf(" %u ", -1);
// 	printf("num: %d\n", num);

// 	ft_printf("CUSTOM\n");
// 	num = ft_printf(" %u ", -1);
// 	ft_printf("num: %d\n", num);

// 	return (0);
// }