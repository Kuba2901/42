/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:25:30 by jnenczak          #+#    #+#             */
/*   Updated: 2024/06/11 16:06:55 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' \
		|| c == '\f');
}

long	ft_atoi_long(const char *str)
{
	long	ret;
	int		sign;

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

int	ft_is_int(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] == '-' || str[i] == '+'))
			break ;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ps_contains_duplicate(int ac, char **av, int num, int index)
{
	int	i;

	i = index;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) == num)
			return (1);
	}
	return (0);
}

int	parse_errors(int ac, char **av)
{
	int		i;
	long	temp;

	i = 0;
	if (ac == 1)
		exit(0);
	while (++i < ac)
	{
		if (!ft_is_int(av[i]))
			return (ERROR_NOT_INTEGERS);
		temp = ft_atoi_long(av[i]);
		if (temp > MAX_INT || temp < MIN_INT)
			return (ERROR_INT_OVERFLOW);
		if (ps_contains_duplicate(ac, av, (int)temp, i))
			return (ERROR_CONTAINS_DUPLICATES);
	}
	return (NUMBERS_VALID);
}

t_list	*ps_create_list_element(int num)
{
	t_list	*element;
	int		*content;

	content = malloc(sizeof(int));
	*content = num;

	element = ft_lstnew(content);
	return (element);
}

t_list	**parse_input(int ac, char **av)
{
	int		i;
	t_list	**list;

	i = 0;
	list = malloc(sizeof(t_list *));
	*list = NULL;
	while (++i < ac)
		ft_lstadd_back(list, ps_create_list_element(ft_atoi(av[i])));
	return (list);
}