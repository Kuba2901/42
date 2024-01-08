#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
