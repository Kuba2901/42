#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;
	size_t	curr;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	curr = 0;
	while (*s1)
		ret[curr++] = *s1++;
	ft_strlcpy(ret + curr, s2, size - ft_strlen(s1));
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	len_substr;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	len_substr = ft_strlen(s) - start;
	if (len > (unsigned int)len_substr)
		len = len_substr;
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*alloc;

	if (!s1)
		return (NULL);
	i = 0;
	alloc = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (*s1)
		alloc[i++] = *s1++;
	alloc[i] = '\0';
	return (alloc);
}
