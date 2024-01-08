ft_tolower(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			str[i] = c + 32;
		i++;
	}
	return (str);
}
