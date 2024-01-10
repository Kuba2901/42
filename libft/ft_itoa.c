/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:34:46 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 01:24:12 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

static char	*ft_get_ret(int n)
{
	int		size;
	char	*ret;

	size = ft_get_size(n) + 1;
	if (n < 0)
		size++;
	ret = (char *)malloc(sizeof(char) * (size));
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_single(int n)
{
	char	*ret;

	if (n >= 0 && n <= 9)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret[0] = n + '0';
		ret[1] = '\0';
		return (ret);
	}
	else if (n < 0 && n >= -9)
	{
		n *= -1;
		ret = (char *)malloc(sizeof(char) * 3);
		ret[0] = '-';
		ret[1] = n + '0';
		ret[2] = '\0';
		return (ret);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		negative;

	if (n > -10 && n < 10)
		return (ft_single(n));
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	ret = ft_get_ret(n);
	i = ft_get_size(n) + negative;
	ret[--i] = '\0';
	while (n > 0)
	{
		ret[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (negative)
		ret[i] = '-';
	return (ret);
}