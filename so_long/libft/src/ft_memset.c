/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:59:20 by jnenczak          #+#    #+#             */
/*   Updated: 2024/03/09 19:37:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*char_ptr;

	char_ptr = (char *)b;
	while (len--)
	{
		*char_ptr = c;
		char_ptr++;
	}
	return (b);
}
