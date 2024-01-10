/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:25 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/10 15:27:05 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		ft_putchar_fd('-2', fd);
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr(-n);
	}
	else if (n <= 9)
	{
		a = n + 48;
		ft_putchar_fd(a, fd);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
