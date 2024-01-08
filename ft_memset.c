/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:59:20 by jnenczak          #+#    #+#             */
/*   Updated: 2024/01/08 15:59:22 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*char_ptr;

	i = 0;
	char_ptr = b;
	while(len--)
	{
		*char_ptr = c;
		char_ptr++;
	}
	return (b);
}
