#include <pipex.h>

/// 4 arguments - valid
void	assign_fds(t_pipex *pipex, int ac, char **av)
{
	pipex->input_invalid = TRUE;
	pipex->in_fd = open(av[1], O_RDONLY);
	if (pipex->in_fd < 0)
		return ;
	pipex->out_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->out_fd < 0)
	{
		close(pipex->in_fd);
		return ;
	}
	pipex->input_invalid = FALSE;
}

void	print_split(char **split)
{
	while (*split)
		ft_printf("%s\n", *split++);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	**retrieve_cmd_paths(char **envp)
{
	char	**ret;
	char	*temp;
	char	**paths;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			break ;
	}
	temp = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	paths = ft_split(temp, ':');
	free(temp);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strdup("/");
		paths[i] = ft_join_reassign(paths[i], temp);
	}
	return (paths);
}

char	**compose_cmd_with_path(char **cmd_paths, char *cmd)
{
	char	*temp;
	int		i;
	int		found;

	i = -1;
	while (cmd_paths[++i] && !found)
	{
		temp = ft_strjoin(cmd_paths[i], cmd);
		if (execve(temp, NULL, NULL) == -1)
			free(temp);
		else
			found = 1;
	}
	if (found)
		return (temp);
	return (NULL);
}

t_cmd_args	*create_cmd_args(char *cmd, char *str)
{
	t_cmd_args	*ret;
	char		*temp;
	
	temp = ft_split(str, ' ');
	ret = malloc(sizeof(t_cmd_args));
	ret->cmd = cmd;
	ret->args = args;
	return (ret);
}

t_cmd_args	**parse_cmd_with_args(int ac, char **av)
{
	t_cmd_args	**ret;
	char	**temp;
	int		cmds;
	int		i;

	cmds = ac - 3;
	ret = malloc(sizeof(t_cmd_args *) * (ac - 3 + 1));
	i = 1;
	while (++i < ac - 1)
	{
		
		ret[i - 2] = create_cmd_args(temp[0], temp + 1);
	}
	ret[i - 2] = NULL;
	return (ret);
}

void	free_cmd_with_args(t_cmd_args **cmds)
{
	int	i;
	int	j;

	i = -1;
	while (cmds[++i])
	{
		j = -1;
		printf("Freeing command: %s\n", cmds[i]->cmd);
		free(cmds[i]->cmd);
		while (cmds[i]->args[++j])
		{
			printf("Freeing arg: %s\n", cmds[i]->args[j]);
			free(cmds[i]->args[j]);
		}
		free(cmds[i]);
	}
	free(cmds);
}

void	print_cmd_with_args(t_cmd_args **cmds)
{
	int	i;
	int	j;

	i = -1;
	while (cmds[++i])
	{
		j = -1;
		printf("Command: %s, args: ", cmds[i]->cmd);
		while (cmds[i]->args[++j])
			printf("%s ", cmds[i]->args[j]);
		printf("\n");
	}
}

t_pipex	parse_input(int ac, char **av)
{
	t_pipex	ret;

	assign_fds(&ret, ac, av);
	if (ret.input_invalid)
		return (ret);
	return (ret);
}

int main(int ac, char **av, char **envp)
{
	t_cmd_args	**cmds = parse_cmd_with_args(ac, av);	
	print_cmd_with_args(cmds);
	free_cmd_with_args(cmds);
	return (0);
}

