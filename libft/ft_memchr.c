#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	occ;
	char	curr;
	char	*str;

	occ = (unsigned char)c;
	str = (char *)s;
	while (*str)
	{
		curr = *str;
		if (curr == occ)
			return (str);
		str++;
	}
	return (NULL);
}
