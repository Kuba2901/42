#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char converted;

	converted = (char)c;
	while (*s)
	{
		if ((*s) == converted)
			return (s);
		s++;
	}
	if ((*s) == '\0')
		return (s);
	return (NULL);
}
