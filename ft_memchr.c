#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	occ;
	char	curr;
	char	*str;

	occ = (char)c;
	str = (char *)s;
	while (*(str++))
	{
		curr = *str;
		if (curr == occ)
			return (str);
	}
	return (NULL);
}
