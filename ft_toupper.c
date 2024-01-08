char	*ft_toupper(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
			str[i] = c - 32;
		i++;
	}
	return (str);
}
