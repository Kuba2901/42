/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:31:52 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/06 12:45:13 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_duplicates(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
		{
			if (ft_strncmp(av[i], av[j], ft_strlen(av[i])) == 0)
				return (1);
		}
	}
	return (0);
}

int	get_parse_error(int ac, char **av)
{
	int	i;
	long	temp_num;

	if ((ac - 1) == 0) return (ERROR_NO_ARGUMENTS);
	if (contains_duplicates(ac, av))
		return (ERROR_CONTAINS_DUPLICATES);
	i = 0;
	while (++i < ac)
	{
		temp_num = ft_atoi_long(av[i]);
		if (temp_num > MAX_INT || temp_num < MIN_INT)
			return (ERROR_INT_OVERFLOW);
		if (is_number_invalid(av[i]))
			return (ERROR_NOT_INTEGERS);
	}
	return (NUMBERS_VALID);
}

t_stack parse_input(int ac, char **av)
{
	int		i;
	t_stack	ret;

	ret.nums_count = ac - 1;
	ret.nums = malloc(sizeof(int) * ret.nums_count);
	i = 0;
	while (++i < ac)
		ret.nums[i - 1] = ft_atoi(av[i]);
	return (ret);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' \
		|| c == '\f');
}

int	is_number_invalid(const char *str)
{
	int	i;
	int	plus_count;
	int	minus_count;

	plus_count = 0;
	minus_count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			plus_count++;
		else if (str[i] == '-')
			minus_count++;
		else if (str[i] < '0' || str[i] > '9')
			return (ERROR_NOT_INTEGERS);
		if (plus_count > 1 || minus_count > 1 || (plus_count && minus_count))
			return (ERROR_NOT_INTEGERS);
	}
	return (NUMBERS_VALID);
}

long int	ft_atoi_long(const char *str)
{
	long int	ret;
	int			sign;

	ret = 0;
	sign = 0;
	while (is_whitespace((char)*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (sign)
		return (-ret);
	return (ret);
}
