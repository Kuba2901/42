#include <pipex.h>

/// 4 arguments - valid
void	assign_fds(t_pipex *pipex, char **av)
{
	pipex->input_invalid = TRUE;
	pipex->in_fd = -1;
	pipex->out_fd = -1;
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

t_cmd_args	*create_cmd_args(char *cmd)
{
	t_cmd_args	*ret;
	char		**temp;
	
	temp = ft_split(cmd, ' ');
	ret = malloc(sizeof(t_cmd_args));
	ret->cmd = temp[0];
	ret->args = temp + 1;
	return (ret);
}

t_cmd_args	**parse_cmd_with_args(int ac, char **av)
{
	t_cmd_args	**ret;
	char	*temp;
	int		i;

	ret = malloc(sizeof(t_cmd_args *) * ((ac - 3) + 1));
	i = 1;
	while (++i < ac - 1)
	{
		temp = ft_strdup(av[i]);
		ret[i - 2] = create_cmd_args(temp);
		free(temp);
	}
	ret[i - 2] = NULL;
	return (ret);
}

void	free_cmd_with_args(t_cmd_args **cmds)
{
	int	i;

	i = -1;
	while (cmds[++i])
	{
		free_split((cmds[i]->args - 1));
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

void	free_resources(t_pipex pipex)
{
	if (pipex.in_fd != -1)
		close(pipex.in_fd);
	if (pipex.out_fd != -1)
		close(pipex.out_fd);
	free_cmd_with_args(pipex.cmd_args);
	free_split(pipex.cmd_paths);
}

t_pipex	parse_input(int ac, char **av, char **envp)
{
	t_pipex	ret;

	assign_fds(&ret, av);
	if (ret.input_invalid)
		return (ret);
	ret.cmd_args = parse_cmd_with_args(ac, av);
	ret.cmd_paths = retrieve_cmd_paths(envp);
	return (ret);
}

void	pipe_start_process(t_pipex pipex, int cmd_num, int pipe_end[2])
{
	int		i;
	char	*temp;

	dup2(pipex.in_fd, STDIN_FILENO);
	dup2(pipe_end[1], STDOUT_FILENO);
	close(pipe_end[0]);
	i = -1;
	while (pipex.cmd_paths[++i])
	{
		temp = ft_strjoin(pipex.cmd_paths[i], pipex.cmd_args[cmd_num]->cmd);
		execve(temp, pipex.cmd_args[cmd_num]->args - 1, pipex.envp);
		free(temp);
	}
	close(pipex.in_fd);
	if (access(pipex.cmd_args[cmd_num]->cmd, X_OK) < 0)
		perror(pipex.cmd_args[cmd_num]->cmd);
	exit(EXIT_FAILURE);
}

void	pipe_end_process(t_pipex pipex, int cmd_num, int pipe_end[2])
{
	int		i;
	char	*temp;

	dup2(pipex.out_fd, STDOUT_FILENO);
	dup2(pipe_end[0], STDIN_FILENO);
	close(pipe_end[1]);
	i = -1;
	while (pipex.cmd_paths[++i])
	{
		temp = ft_strjoin(pipex.cmd_paths[i], pipex.cmd_args[cmd_num]->cmd);
		execve(temp, pipex.cmd_args[cmd_num]->args - 1, pipex.envp);
		free(temp);
	}
	close(pipex.out_fd);
	if (access(pipex.cmd_args[cmd_num]->cmd, X_OK) < 0)
		perror(pipex.cmd_args[cmd_num]->cmd);
	exit(EXIT_FAILURE);
}

void	do_pipe(t_pipex pipex)
{
	int		end[2];
    int		status;
    pid_t	child1;
    pid_t	child2;

    pipe(end);
    child1 = fork();
    if (child1 < 0)
	{
		perror("");
        exit(EXIT_FAILURE);
	}
    if (child1 == 0)
		pipe_start_process(pipex, 0, end);
    child2 = fork();
    if (child2 < 0)
	{
		perror("");
        exit(EXIT_FAILURE);
	}
    if (child2 == 0)
		pipe_end_process(pipex, 1, end);
    close(end[0]);
    close(end[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
}

int main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac < 5)
		exit(EXIT_FAILURE);
	pipex = parse_input(ac, av, envp);
	if (pipex.input_invalid)
		return (0);
	pipex.cmd_count = ac - 3;
	pipex.envp = envp;
	do_pipe(pipex);
	free_resources(pipex);
	return (0);
}

