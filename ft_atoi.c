/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:12:18 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/09 13:18:15 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnum(const char *str)
{
	char c;

	c = *str;
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int ret;

	ret = 0;
	while (!ft_isnum(str))
		str++;
	while (ft_isnum(str))
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret);
}
