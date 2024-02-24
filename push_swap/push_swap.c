#include "push_swap.h"

int	*parse_args(int argc, char **argv)
{
	int	i;
	int	*ret;

	i = 0;
	ret = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ret)
		return (NULL);
	while (i < argc - 1)
	{
		ret[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		int	*nums = parse_args(ac, av);
		int i = -1;
		while (++i < ac - 1)
			ft_printf("num {%d}\n",nums[i]);

	}
	return (0);
}