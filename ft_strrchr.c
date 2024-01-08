#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	converted;
	int		len;

	converted = (char)c;
	len = ft_strlen(s);
	while (--len)
	{
		if (s[len] == converted)
			return (&(s[len]);
	}
	return (NULL);
}
